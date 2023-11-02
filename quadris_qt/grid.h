#ifndef GRID_H
#define GRID_H

#include <vector>
#include <memory>

#include "cell.h"
#include "score.h"
#include "abstractblock.h"


class Grid {
private:
    const int myHeight;
    const int myWidth;
    int theLevel;
    int turnsSinceClear;
    Score* const theScore;
    std::vector<std::pair<int, int>> hint;
    bool isHintShown = false;
    std::vector<std::vector<std::unique_ptr<Cell>>> myGrid;

    void setCell(int row, int col, std::shared_ptr<AbstractBlock> block);
    void clearCell(int row, int col);
    void clearCellSB(int row, int col);
    bool isValid(int rowShift, int colShift, int oShift, std::shared_ptr<AbstractBlock> block) const;
    void drawBlock(std::shared_ptr<AbstractBlock> block);
    void eraseBlock(std::shared_ptr<AbstractBlock> block);
    bool isFull(int row) const;
    bool isEmptyRow(int row) const;
    void clearRow(int row);
    void shiftRowsDown(int aboveThisRow);
    void dropCentreBlock();
    void hideHint();

public:
    Grid(int level, Score *sb);
    ~Grid();

    void setLevel(int level);
    void reset();
    bool placeBlock(std::shared_ptr<AbstractBlock> block);
    void replaceBlock(std::shared_ptr<AbstractBlock> oldBlock, std::shared_ptr<AbstractBlock> newBlock);
    void shiftLeft(std::shared_ptr<AbstractBlock> block, int times);
    void shiftRight(std::shared_ptr<AbstractBlock> block, int times);
    bool shiftDown(std::shared_ptr<AbstractBlock> block, int times);
    void rotateCW(std::shared_ptr<AbstractBlock> block, int times);
    void rotateCCW(std::shared_ptr<AbstractBlock> block, int times);
    void Drop(std::shared_ptr<AbstractBlock> block);
    const Cell& getCell(int row, int col) const;
    const std::vector<std::vector<char>> getBoard(std::shared_ptr<AbstractBlock> curBlock = nullptr) const;
    void showHint(std::vector<std::pair<int, int>> newHint);
    bool hintShown() const;
};

#endif // GRID_H
