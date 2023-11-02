#ifndef JBLOCK_H
#define JBLOCK_H

#include "abstractblock.h"


class jBlock : public AbstractBlock {
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
    jBlock(int level, Score *sb);
    ~jBlock();

    void setOrientation(int orientation) override;
};

#endif // JBLOCK_H
