#include "iblock.h"


iBlock::iBlock(int level, Score *sb): AbstractBlock{'I', level, sb, 3, 0, 0}{}


iBlock::~iBlock(){}


void iBlock::setOrientation(int orientation){
    orientation %= 2;
    myOrientation = orientation;
}


int iBlock::cell1_row(int orientation) const{
    if (orientation % 2 == 0){
        return myRow;
    }
    else{
        return myRow - 3;
    }
}


int iBlock::cell2_row(int orientation) const{
    if (orientation % 2 == 0){
        return myRow;
    }
    else{
        return myRow - 2;
    }
}


int iBlock::cell3_row(int orientation) const{
    if (orientation % 2 == 0){
        return myRow;
    }
    else{
        return myRow - 1;
    }
}


int iBlock::cell4_row(int orientation) const{
    return myRow;
}


int iBlock::cell1_col(int orientation) const{
    return myCol;
}


int iBlock::cell2_col(int orientation) const{
    if (orientation % 2 == 0){
        return myCol + 1;
    }
    else{
        return myCol;
    }
}


int iBlock::cell3_col(int orientation) const{
    if (orientation % 2 == 0){
        return myCol + 2;
    }
    else{
        return myCol;
    }
}


int iBlock::cell4_col(int orientation) const{
    if (orientation % 2 == 0){
        return myCol + 3;
    }
    else{
        return myCol;
    }
}

