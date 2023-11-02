#include "lblock.h"


lBlock::lBlock(int level, Score *sb): AbstractBlock{'L', level, sb, 4, 0, 0}{}


lBlock::~lBlock(){}


void lBlock::setOrientation(int orientation){
    orientation %= 4;
    myOrientation = orientation;
}


int lBlock::cell1_row(int orientation) const{
    if (orientation % 4 == 0){
        return myRow;
    }
    else if (orientation % 4 == 2){
        return myRow - 1;
    }
    else{
        return myRow - 2;
    }
}


int lBlock::cell2_row(int orientation) const{
    if (orientation % 4 == 1){
        return myRow - 1;
    }
    else if (orientation % 4 == 3){
        return myRow - 2;
    }
    else{
        return myRow;
    }
}


int lBlock::cell3_row(int orientation) const{
    if (orientation % 4 == 1){
        return myRow;
    }
    else{
        return myRow - 1;
    }
}


int lBlock::cell4_row(int orientation) const{
    if (orientation % 4 == 2){
        return myRow - 1;
    }
    else{
        return myRow;
    }
}


int lBlock::cell1_col(int orientation) const{
    return myCol;
}


int lBlock::cell2_col(int orientation) const{
    if (orientation % 4 == 0 || myOrientation % 4 == 3){
        return myCol + 1;
    }
    else{
        return myCol;
    }
}


int lBlock::cell3_col(int orientation) const{
    if (orientation % 4 == 0){
        return myCol + 2;
    }
    else if (orientation % 4 == 1){
        return myCol;
    }
    else{
        return myCol + 1;
    }
}


int lBlock::cell4_col(int orientation) const{
    if (orientation % 2 == 1){
        return myCol + 1;
    }
    else{
        return myCol + 2;
    }
}



