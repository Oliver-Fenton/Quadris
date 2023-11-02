#ifndef OBLOCK_H
#define OBLOCK_H

#include "abstractblock.h"


class oBlock : public AbstractBlock {
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
    oBlock(int level, Score *sb);
    ~oBlock();

    void setOrientation(int orientation) override;
};

#endif // OBLOCK_H
