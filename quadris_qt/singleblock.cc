#include "singleblock.h"


singleBlock::singleBlock(int level, Score *sb, int row, int col) : AbstractBlock{'-', level, sb, row, col, 0} {}

singleBlock::~singleBlock() {}

int singleBlock::cell1_row(int orientation) const {
    return myRow;
}

int singleBlock::cell2_row(int orientation) const {
    return myRow;
}

int singleBlock::cell3_row(int orientation) const {
    return myRow;
}

int singleBlock::cell4_row(int orientation) const {
    return myRow;
}

int singleBlock::cell1_col(int orientation) const {
    return myCol;
}

int singleBlock::cell2_col(int orientation) const {
    return myCol;
}

int singleBlock::cell3_col(int orientation) const {
    return myCol;
}

int singleBlock::cell4_col(int orientation) const {
    return myCol;
}

void singleBlock::setOrientation(int orientation) {}
