#ifndef TBLOCK_H
#define TBLOCK_H

#include "abstractblock.h"


class tBlock: public AbstractBlock{
    int cell1_row(int orientation) const override;
    int cell2_row(int orientation) const override;
    int cell3_row(int orientation) const override;
    int cell4_row(int orientation) const override;
    int cell1_col(int orientation) const override;
    int cell2_col(int orientation) const override;
    int cell3_col(int orientation) const override;
    int cell4_col(int orientation) const override;
public:
    tBlock(int level, Score *sb);
    ~tBlock();
    void setOrientation(int orientation) override;
};


#endif


