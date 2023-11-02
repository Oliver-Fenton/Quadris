#include "zblock.h"


zBlock::zBlock(int level, Score *sb) : AbstractBlock{'Z', level, sb, 4, 0, 0} {}

zBlock::~zBlock() {}

int zBlock::cell1_row(int orientation) const {
    return myRow - 1;
}

int zBlock::cell2_row(int orientation) const {
    if (orientation % 2 == 0) {
        return myRow - 1;
    } else {
        return myRow;
    }
}

int zBlock::cell3_row(int orientation) const {
    if (orientation % 2 == 0) {
        return myRow;
    } else {
        return myRow - 2;
    }
}

int zBlock::cell4_row(int orientation) const {
    if (orientation % 2 == 0) {
        return myRow;
    } else {
        return myRow - 1;
    }
}

int zBlock::cell1_col(int orientation) const {
    return myCol;
}

int zBlock::cell2_col(int orientation) const {
    if (orientation % 2 == 0) {
        return myCol + 1;
    } else {
        return myCol;
    }
}

int zBlock::cell3_col(int orientation) const {
    return myCol + 1;
}

int zBlock::cell4_col(int orientation) const {
    if (orientation % 2 == 0) {
        return myCol + 2;
    } else {
        return myCol + 1;
    }
}

void zBlock::setOrientation(int orientation) {
    orientation %= 2;
    myOrientation = orientation;
}
