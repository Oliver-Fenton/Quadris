#include "sblock.h"


sBlock::sBlock(int level, Score *sb): AbstractBlock{'S', level, sb, 4, 0, 0}{}


sBlock::~sBlock(){}


void sBlock::setOrientation(int orientation){
    orientation %= 2;
    myOrientation = orientation;
}



int sBlock::cell1_row(int orientation) const{
    if (orientation % 2 == 0){
        return myRow;
    }
    else{
        return myRow - 2;
    }
}


int sBlock::cell2_row(int orientation) const{
    return myRow - 1;
}


int sBlock::cell3_row(int orientation) const{
    if (orientation % 2 == 0){
        return myRow;
    }
    else{
        return myRow - 1;
    }
}


int sBlock::cell4_row(int orientation) const{
    if (orientation % 2 == 0){
        return myRow - 1;
    }
    else{
        return myRow;
    }
}


int sBlock::cell1_col(int orientation) const{
    return myCol;
}


int sBlock::cell2_col(int orientation) const{
    if (orientation % 2 == 0){
        return myCol + 1;
    }
    else{
        return myCol;
    }
}


int sBlock::cell3_col(int orientation) const{
    return myCol + 1;
}


int sBlock::cell4_col(int orientation) const{
    if (orientation % 2 == 0){
        return myCol + 2;
    }
    else{
        return myCol + 1;
    }
}


