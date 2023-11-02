#ifndef ABSTRACTBLOCK_H
#define ABSTRACTBLOCK_H

#include <vector>

#include "score.h"


class AbstractBlock {
private:
    const char myType;
    const int myLevel;
    Score* scoreBoard;

protected:
    int myRow;
    int myCol;
    int myOrientation;

    virtual int cell1_row(int orientation) const = 0;
    virtual int cell2_row(int orientation) const = 0;
    virtual int cell3_row(int orientation) const = 0;
    virtual int cell4_row(int orientation) const = 0;

    virtual int cell1_col(int orientation) const = 0;
    virtual int cell2_col(int orientation) const = 0;
    virtual int cell3_col(int orientation) const = 0;
    virtual int cell4_col(int orientation) const = 0;

public:
    AbstractBlock(char type, int level, Score* sb, int row, int col, int orientation);
    virtual ~AbstractBlock();

    std::vector<std::pair<int, int>> getCoords(int orientation) const;
    int getType() const;
    int getRow() const;
    int getCol() const;
    int getOrientation() const;

    void setSB(Score* sb);
    void setRow(int row);
    void setCol(int col);
    virtual void setOrientation(int orientation) = 0;
};

#endif // ABSTRACTBLOCK_H
