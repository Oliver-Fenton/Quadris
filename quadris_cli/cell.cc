#include <memory>

#include "cell.h"
#include "blocks/abstractblock.h"

using namespace std;

Cell::Cell(int r, int c): row{r}, col{c}, theBlock{nullptr}{}


Cell::~Cell(){}

void Cell::setBlock(shared_ptr<AbstractBlock> block){
    theBlock = block;
    notifyObservers();
}


void Cell::clearBlock(){
    theBlock = nullptr;
    notifyObservers();
}


void Cell::clearBlockSB(){
    if (theBlock){
        theBlock->setSB(nullptr);
    }
}


bool Cell::isValid(shared_ptr<AbstractBlock> block) const{
    if (theBlock == nullptr){
        return true;
    }
    else if (theBlock == block){
        return true;
    }
    return false;
}


bool Cell::isEmpty() const{
    return theBlock == nullptr;
}


shared_ptr<AbstractBlock> Cell::getBlock() const{
    return theBlock;
}


char Cell::getType() const{
    if (theBlock != nullptr){
        return theBlock->getType();
    }
    else{
        return ' ';
    }
}


int Cell::getRow() const{
    return row;
}

int Cell::getCol() const{
    return col;
}


