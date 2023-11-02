#include "abstractblock.h"
#include "../score.h"

using namespace std;


AbstractBlock::AbstractBlock(char type, int level, Score *sb, int row, int col, int orientation):
myType{type},
myLevel{level},
scoreBoard{sb},
myRow{row},
myCol{col},
myOrientation{orientation}{}


AbstractBlock::~AbstractBlock(){
    if (scoreBoard){
        scoreBoard->increaseScore((myLevel + 1) * (myLevel + 1));
    }
}



vector<int> AbstractBlock::getRows(int orientation) const{
    vector<int> theVec;
    theVec.emplace_back(cell1_row(orientation));
    theVec.emplace_back(cell2_row(orientation));
    theVec.emplace_back(cell3_row(orientation));
    theVec.emplace_back(cell4_row(orientation));
    return theVec;
}


vector<int> AbstractBlock::getCols(int orientation) const{
    vector<int> theVec;
    theVec.emplace_back(cell1_col(orientation));
    theVec.emplace_back(cell2_col(orientation));
    theVec.emplace_back(cell3_col(orientation));
    theVec.emplace_back(cell4_col(orientation));
    return theVec;
}


void AbstractBlock::setSB(Score *sb){
    scoreBoard = sb;
}


int AbstractBlock::getType() const{
    return myType;
}

int AbstractBlock::getRow() const{
    return myRow;
}


int AbstractBlock::getCol() const{
    return myCol;
}


int AbstractBlock::getOrientation() const{
    return myOrientation;
}


void AbstractBlock::setRow(int row){
    myRow = row;
}


void AbstractBlock::setCol(int col){
    myCol = col;
}


void AbstractBlock::setOrientation(int orientation){
    myOrientation = orientation;
}
