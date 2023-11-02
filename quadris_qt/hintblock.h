#ifndef HINTBLOCK_H
#define HINTBLOCK_H

#include "abstractblock.h"


class hintBlock : public AbstractBlock {
private:
    int cell1_row(int orientation) const override;
    int cell2_row(int orientation) const override;
    int cell3_row(int orientation) const override;
    int cell4_row(int orientation) const override;

    int cell1_col(int orientation) const override;
    int cell2_col(int orientation) const override;
    int cell3_col(int orientation) const override;
    int cell4_col(int orientation) const override;

public:
    hintBlock(int row, int col);
    ~hintBlock();

    void setOrientation(int orientation) override;
};

#endif // HINTBLOCK_H
