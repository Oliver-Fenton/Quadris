#ifndef SINGLEBLOCK_H
#define SINGLEBLOCK_H

#include "abstractblock.h"


class singleBlock: public AbstractBlock{
public:
    singleBlock(int level, Score *sb, int row, int col);
    ~singleBlock();
    void setOrientation(int orientation) override;
    int cell1_row(int orientation) const override;
    int cell2_row(int orientation) const override;
    int cell3_row(int orientation) const override;
    int cell4_row(int orientation) const override;
    int cell1_col(int orientation) const override;
    int cell2_col(int orientation) const override;
    int cell3_col(int orientation) const override;
    int cell4_col(int orientation) const override;
};


#endif




