#include "jblock.h"


jBlock::jBlock(int level, Score *sb): AbstractBlock{'J', level, sb, 4, 0, 0}{}


jBlock::~jBlock(){}


void jBlock::setOrientation(int orientation){
    orientation %= 4;
    myOrientation = orientation;
}


int jBlock::cell1_row(int orientation) const{
    if (orientation % 2 == 0){
        return myRow - 1;
    }
    else if (orientation % 4 == 1){
        return myRow - 2;
    }
    else{
        return myRow;
    }
}


int jBlock::cell2_row(int orientation) const{
    if (orientation % 4 == 0){
        return myRow;
    }
    else if (orientation % 4 == 3){
        return myRow - 2;
    }
    else{
        return myRow - 1;
    }
}


int jBlock::cell3_row(int orientation) const{
    if (orientation % 4 == 0 || myOrientation % 4 == 1){
        return myRow;
    }
    else{
        return myRow - 1;
    }
}


int jBlock::cell4_row(int orientation) const{
    if (orientation % 4 == 1){
        return myRow - 2;
    }
    else{
        return myRow;
    }
}


int jBlock::cell1_col(int orientation) const{
    return myCol;
}


int jBlock::cell2_col(int orientation) const{
    if (orientation % 4 == 0 || myOrientation % 4 == 1){
        return myCol;
    }
    else{
        return myCol + 1;
    }
}


int jBlock::cell3_col(int orientation) const{
    if (orientation % 4 == 1){
        return myCol;
    }
    else if (orientation % 4 == 2){
        return myCol + 2;
    }
    else{
        return myCol + 1;
    }
}


int jBlock::cell4_col(int orientation) const{
    if (orientation % 2 == 0){
        return myCol + 2;
    }
    else{
        return myCol + 1;
    }
}


