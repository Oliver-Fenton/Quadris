#include "hintblock.h"

hintBlock::hintBlock(int row, int col):
    AbstractBlock{'?', 0, nullptr, row, col, 0}{}

hintBlock::~hintBlock(){}


void hintBlock::setOrientation(int orientation) {}


int hintBlock::cell1_row(int orientation) const{
    return myRow;
}

int hintBlock::cell2_row(int orientation) const{
    return myRow;
}

int hintBlock::cell3_row(int orientation) const{
    return myRow;
}

int hintBlock::cell4_row(int orientation) const{
    return myRow;
}

int hintBlock::cell1_col(int orientation) const{
    return myCol;
}

int hintBlock::cell2_col(int orientation) const{
    return myCol;
}

int hintBlock::cell3_col(int orientation) const{
    return myCol;
}

int hintBlock::cell4_col(int orientation) const{
    return myCol;
}
