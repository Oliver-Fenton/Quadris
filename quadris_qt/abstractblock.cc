#include "abstractblock.h"

#include "score.h"

using namespace std;


AbstractBlock::AbstractBlock(char type, int level, Score *sb, int row, int col, int orientation):
    myType{type},
    myLevel{level},
    scoreBoard{sb},
    myRow{row},
    myCol{col},
    myOrientation{orientation}
{}

AbstractBlock::~AbstractBlock(){
    if (scoreBoard){
        scoreBoard->increaseScore((myLevel + 1) * (myLevel + 1));
    }
}

std::vector<std::pair<int, int>> AbstractBlock::getCoords(int orientation) const {
    vector<pair<int, int>> coords;
    coords.emplace_back( make_pair(cell1_row(orientation), cell1_col(orientation)) );
    coords.emplace_back( make_pair(cell2_row(orientation), cell2_col(orientation)) );
    coords.emplace_back( make_pair(cell3_row(orientation), cell3_col(orientation)) );
    coords.emplace_back( make_pair(cell4_row(orientation), cell4_col(orientation)) );
    return coords;
}

int AbstractBlock::getType() const {
    return myType;
}

int AbstractBlock::getRow() const {
    return myRow;
}

int AbstractBlock::getCol() const {
    return myCol;
}

int AbstractBlock::getOrientation() const {
    return myOrientation;
}

void AbstractBlock::setSB(Score *sb) {
    scoreBoard = sb;
}

void AbstractBlock::setRow(int row) {
    myRow = row;
}

void AbstractBlock::setCol(int col) {
    myCol = col;
}

void AbstractBlock::setOrientation(int orientation) {
    myOrientation = orientation;
}
