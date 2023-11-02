#include "tblock.h"


tBlock::tBlock(int level, Score *sb): AbstractBlock{'T', level, sb, 4, 0, 0}{}


tBlock::~tBlock(){}


void tBlock::setOrientation(int orientation){
    orientation %= 4;
    myOrientation = orientation;
}


int tBlock::cell1_row(int orientation) const{
    if (orientation % 4 == 2){
        return myRow;
    }
    else if (orientation % 4 == 3){
        return myRow - 2;
    }
    else{
        return myRow - 1;
    }
}


int tBlock::cell2_row(int orientation) const{
    if (orientation % 4 == 1){
        return myRow - 2;
    }
    else{
        return myRow - 1;
    }
}


int tBlock::cell3_row(int orientation) const{
    if (orientation % 4 == 1){
        return myRow - 1;
    }
    else{
        return myRow;
    }
}


int tBlock::cell4_row(int orientation) const{
    if (orientation % 4 == 0 || orientation % 4 == 3){
        return myRow - 1;
    }
    else{
        return myRow;
    }
}


int tBlock::cell1_col(int orientation) const{
    return myCol;
}


int tBlock::cell2_col(int orientation) const{
    if (orientation % 4 == 3){
        return myCol;
    }
    else{
        return myCol + 1;
    }
}


int tBlock::cell3_col(int orientation) const{
    if (orientation % 4 == 3){
        return myCol;
    }
    else{
        return myCol + 1;
    }
}


int tBlock::cell4_col(int orientation) const{
    if (orientation % 2 == 0){
        return myCol + 2;
    }
    else{
        return myCol + 1;
    }
}



