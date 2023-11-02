#ifndef ZBLOCK_H
#define ZBLOCK_H

#include "abstractblock.h"


class zBlock : public AbstractBlock {
    int cell1_row(int orientation) const override;
    int cell2_row(int orientation) const override;
    int cell3_row(int orientation) const override;
    int cell4_row(int orientation) const override;

    int cell1_col(int orientation) const override;
    int cell2_col(int orientation) const override;
    int cell3_col(int orientation) const override;
    int cell4_col(int orientation) const override;

public:
    zBlock(int level, Score *sb);
    ~zBlock();

    void setOrientation(int orientation) override;
};

#endif // ZBLOCK_H
