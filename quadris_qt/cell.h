#ifndef CELL_H
#define CELL_H

#include <memory>
#include <QObject>

#include "abstractblock.h"


class Cell : public QObject {
    Q_OBJECT

private:
    const int row, col;
    std::shared_ptr<AbstractBlock> theBlock;

public:
    Cell(int r, int c);
    ~Cell();

    void setBlock(std::shared_ptr<AbstractBlock> block);
    void clearBlock();
    void clearBlockSB();
    bool isValid(std::shared_ptr<AbstractBlock> block) const;
    bool isHintBlock() const;
    bool isEmpty() const;
    std::shared_ptr<AbstractBlock> getBlock() const;
    char getType() const;
    int getRow() const;
    int getCol() const;

signals:
    void cellChanged(int row, int col, char type);
};

#endif // CELL_H
