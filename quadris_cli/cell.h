#ifndef CELL_H
#define CELL_H

#include <memory>

#include "subject.h"
#include "blocks/abstractblock.h"


class Cell: public Subject{
    const int row, col;
    std::shared_ptr<AbstractBlock> theBlock;
public:
    Cell(int r, int c);
    ~Cell();
    void setBlock(std::shared_ptr<AbstractBlock> block);
    void clearBlock();
    void clearBlockSB();
    bool isValid(std::shared_ptr<AbstractBlock> block) const;
    bool isEmpty() const;
    std::shared_ptr<AbstractBlock> getBlock() const;
    char getType() const;
    int getRow() const;
    int getCol() const;
};

#endif


