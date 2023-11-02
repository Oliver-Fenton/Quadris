#ifndef GRID_H
#define GRID_H

#include <vector>
#include <memory>

#include "observer.h"
#include "cell.h"
#include "score.h"
#include "blocks/abstractblock.h"


class Grid{
    const int myHeight;
    const int myWidth;
    int theLevel;
    int turnsSinceClear;
    Observer * const theTD;
    Observer * const theGD;
    Score * const theScore;
    std::vector<std::vector<Cell>> myGrid;
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
public:
    Grid(int level, Observer *td, Observer *gd, Score *sb);
    ~Grid();
    void setLevel(int level);
    void reset();
    bool placeBlock(std::shared_ptr<AbstractBlock> block);
    void replaceBlock(std::shared_ptr<AbstractBlock> oldBlock, std::shared_ptr<AbstractBlock> newBlock);
    void shiftLeft(std::shared_ptr<AbstractBlock> block, int times);
    void shiftRight(std::shared_ptr<AbstractBlock> block, int times);
    void shiftDown(std::shared_ptr<AbstractBlock> block, int times);
    void rotateCW(std::shared_ptr<AbstractBlock> block, int times);
    void rotateCCW(std::shared_ptr<AbstractBlock> block, int times);
    void Drop(std::shared_ptr<AbstractBlock> block);
};
    

#endif


