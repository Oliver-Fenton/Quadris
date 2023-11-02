#include "oblock.h"


oBlock::oBlock(int level, Score *sb) : AbstractBlock{'O', level, sb, 4, 0, 0} {}

oBlock::~oBlock() {}

int oBlock::cell1_row(int orientation) const {
    return myRow - 1;
}

int oBlock::cell2_row(int orientation) const {
    return myRow;
}

int oBlock::cell3_row(int orientation) const {
    return myRow - 1;
}

int oBlock::cell4_row(int orientation) const {
    return myRow;
}

int oBlock::cell1_col(int orientation) const {
    return myCol;
}

int oBlock::cell2_col(int orientation) const {
    return myCol;
}

int oBlock::cell3_col(int orientation) const {
    return myCol + 1;
}

int oBlock::cell4_col(int orientation) const {
    return myCol + 1;
}

void oBlock::setOrientation(int orientation) {
    myOrientation = 0;
}
