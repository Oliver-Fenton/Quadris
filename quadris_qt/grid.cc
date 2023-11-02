#include "grid.h"

#include <vector>
#include <memory>
#include <iostream>

#include "score.h"
#include "abstractblock.h"
#include "singleblock.h"
#include "hintblock.h"

using namespace std;


Grid::Grid(int level, Score *sb):
    myHeight{18},
    myWidth{11},
    theLevel{level},
    turnsSinceClear{0},
    theScore{sb}
{
    myGrid.resize(myHeight);
    for (int row = 0; row < myHeight; ++row) {
        myGrid[row].resize(myWidth);
        for (int col = 0; col < myWidth; ++col) {
            myGrid[row][col] = std::make_unique<Cell>(row, col);
        }
    }
}

Grid::~Grid() {
    for (int row = 0; row < myHeight; ++row) {
        for (int col = 0; col < myWidth; ++col) {
            clearCellSB(row, col);
        }
    }
}

void Grid::setCell(int row, int col, shared_ptr<AbstractBlock> block) {
    myGrid[row][col]->setBlock(block);
}

void Grid::clearCell(int row, int col) {
    myGrid[row][col]->clearBlock();
}

void Grid::clearCellSB(int row, int col) {
    myGrid[row][col]->clearBlockSB();
}

bool Grid::isValid(int rowShift, int colShift, int oShift, shared_ptr<AbstractBlock> block) const {
    int newRow;
    int newCol;
    int newO = (block->getOrientation() + oShift) % 4;
    vector<pair<int,int>> coords = block->getCoords(newO);
    for (int i = 0; i < 4; ++ i) {
        newRow = coords[i].first + rowShift;
        newCol = coords[i].second + colShift;
        if (newRow < 0 || newRow >= myHeight) {
            return false;
        }
        if (newCol < 0 || newCol >= myWidth) {
            return false;
        }
        if (!myGrid[newRow][newCol]->isValid(block)) {
            return false;
        }
    }
    return true;
}

void Grid::drawBlock(shared_ptr<AbstractBlock> block) {
    vector<pair<int,int>> coords = block->getCoords(block->getOrientation());
    for (int i = 0; i < 4; ++i) {
        myGrid[coords[i].first][coords[i].second]->setBlock(block);
    }
}

void Grid::eraseBlock(shared_ptr<AbstractBlock> block) {
    vector<pair<int,int>> coords = block->getCoords(block->getOrientation());
    for (int i = 0; i < 4; ++i) {
        myGrid[coords[i].first][coords[i].second]->clearBlock();
    }
}

bool Grid::isFull(int row) const {
    for (int col = 0; col < myWidth; ++col) {
        if (myGrid[row][col]->isEmpty()) {
            return false;
        }
    }
    return true;
}

bool Grid::isEmptyRow(int row) const {
    for (int col = 0; col < myWidth; ++col) {
        if (!myGrid[row][col]->isEmpty()) {
            return false;
        }
    }
    return true;
}

void Grid::clearRow(int row) {
    for (int col = 0; col < myWidth; ++col) {
        myGrid[row][col]->clearBlock();
    }
}

void Grid::shiftRowsDown(int aboveThisRow) {
    for (int row = aboveThisRow; row > 0; --row) {
        if (isEmptyRow(row - 1)) {
            break;
        }
        for (int col = 0; col < myWidth; ++col) {
            setCell(row, col, myGrid[row - 1][col]->getBlock());
            clearCell(row - 1, col);
        }
    }
}

void Grid::dropCentreBlock(){
    int row = 0;
    int col = 5;
    for (int r = row; r < myHeight; ++r) {
        if (myGrid[r][col]->isEmpty()) {
            row = r;
        }
        else {
            break;
        }
    }
    myGrid[row][col]->setBlock(make_shared<singleBlock>(theLevel, theScore, row, col));
}

void Grid::hideHint() {
    if (!hint.empty()) {
        for (auto cell : hint) {
            if (myGrid[cell.first][cell.second] != nullptr && !myGrid[cell.first][cell.second]->isHintBlock()) continue;
            setCell(cell.first, cell.second, nullptr);
        }
    }
    hint.clear();
    isHintShown = false;
}

void Grid::setLevel(int level) {
    theLevel = level;
}

void Grid::reset() {
    for (int row = 0; row < myHeight; ++row) {
        for (int col = 0; col < myWidth; ++col) {
            clearCellSB(row, col);
            clearCell(row, col);
        }
    }
}

bool Grid::placeBlock(std::shared_ptr<AbstractBlock> block) {
    if (!isValid(0, 0, 0, block)) {
        return false;
    }
    drawBlock(block);
    return true;
}

void Grid::replaceBlock(std::shared_ptr<AbstractBlock> oldBlock, std::shared_ptr<AbstractBlock> newBlock) {
    oldBlock->setSB(nullptr);
    eraseBlock(oldBlock);
    drawBlock(newBlock);
}

void Grid::shiftLeft(std::shared_ptr<AbstractBlock> block, int times) {
    int shiftValue = 0;
    if (times < 0) {
        times *= -1;
    }
    while (isValid(0, 0 - shiftValue - 1, 0, block) && shiftValue < times) {
        ++shiftValue;
    }
    if (shiftValue != 0) {
        int newCol = block->getCol() - shiftValue;
        eraseBlock(block);
        block->setCol(newCol);
        drawBlock(block);
    }
    if (!hint.empty()) showHint(hint);
}

void Grid::shiftRight(std::shared_ptr<AbstractBlock> block, int times) {
    int shiftValue = 0;
    if (times < 0) {
        times *= -1;
    }
    while (isValid(0, 0 + shiftValue + 1, 0, block) && shiftValue < times) {
        ++shiftValue;
    }
    if (shiftValue != 0) {
        int newCol = block->getCol() + shiftValue;
        eraseBlock(block);
        block->setCol(newCol);
        drawBlock(block);
    }
    if (!hint.empty()) showHint(hint);
}

bool Grid::shiftDown(std::shared_ptr<AbstractBlock> block, int times) {
    if (!isValid(1, 0, 0, block)) {
        if (!hint.empty()) showHint(hint);
        return true;
    }
    int newRow = block->getRow() + 1;
    eraseBlock(block);
    block->setRow(newRow);
    drawBlock(block);
    if (!hint.empty()) showHint(hint);
    return false;
}

void Grid::rotateCW(std::shared_ptr<AbstractBlock> block, int times) {
    if (times < 0) {
        times *= -1;
    }
    int shiftValue = times % 4;
    if (isValid(0, 0, shiftValue, block)) {
        if (shiftValue != 0) {
            int newO = (block->getOrientation() + shiftValue) % 4;
            eraseBlock(block);
            block->setOrientation(newO);
            drawBlock(block);
        }
    }
    if (!hint.empty()) showHint(hint);
}

void Grid::rotateCCW(std::shared_ptr<AbstractBlock> block, int times) {
    if (times < 0) {
        times *= -1;
    }
    int cwTimes = 4 - (times % 4);
    rotateCW(block, cwTimes);
}

void Grid::Drop(std::shared_ptr<AbstractBlock> block) {
    if (!hint.empty()) {
        hideHint();
    }
    while (!shiftDown(block, 1)) {
        continue;
    }
    int blockRow = block->getRow();
    int clearCount = 0;
    for (int r = blockRow; r > blockRow - 4; --r) {
        if (isFull(r)) {
            ++clearCount;
            clearRow(r);
            shiftRowsDown(r);
            ++r;
        }
    }
    if (clearCount != 0) {
        theScore->increaseScore((theLevel + clearCount) * (theLevel + clearCount));
        turnsSinceClear = 0;
    }
    else {
        if (theLevel == 4) {
            ++turnsSinceClear;
            if (turnsSinceClear >= 5) {
                turnsSinceClear = 0;
                dropCentreBlock();
            }
        } else {
            turnsSinceClear = 0;
        }
    }
}

const Cell& Grid::getCell(int row, int col) const {
    return *(myGrid[row][col]);
}

const vector<vector<char>> Grid::getBoard(shared_ptr<AbstractBlock> curBlock) const {
    std::vector<std::vector<char>> board(18, std::vector<char>(11, ' '));
    for (int row = 0; row < myHeight; row++) {
        for (int col = 0; col < myWidth; col++) {
            board[row][col] = myGrid[row][col]->getType();
        }
    }
    if (curBlock != nullptr) {
        vector<pair<int,int>> curBlockCoords = curBlock->getCoords(curBlock->getOrientation());

        for (int i = 0; i < 4; i++) {
            board[curBlockCoords[i].first][curBlockCoords[i].second] = ' ';
        }
    }
    return board;
}

void Grid::showHint(vector<pair<int, int>> newHint) {
    if (!hint.empty()) {
        hideHint();
    }
    hint = newHint;
    for (auto cell : hint) {
        if (!myGrid[cell.first][cell.second]->isEmpty()) continue;
        setCell(cell.first, cell.second, make_shared<hintBlock>(cell.first, cell.second));
    }
    isHintShown = true;
}

bool Grid::hintShown() const {
    return isHintShown;
}
