#include <memory>
#include <string>
#include <iomanip>
#include <fstream>

#include "abstractlevel.h"
#include "../blocks/abstractblock.h"
#include "../blocks/iblock.h"
#include "../blocks/lblock.h"
#include "../blocks/jblock.h"
#include "../blocks/oblock.h"
#include "../blocks/sblock.h"
#include "../blocks/zblock.h"
#include "../blocks/tblock.h"
#include "../blocks/singleblock.h"
#include "../score.h"

using namespace std;

AbstractLevel::AbstractLevel(int level, Score *sb, string sequencefile): myLevel{level}, scoreBoard{sb}, bQ_pos{0}, bQ_length{0}, randomBool{true}{
    char type;
    ifstream sequencestream{sequencefile};
    while (sequencestream >> skipws >> type){
        blockQ.emplace_back(type);
    }
    bQ_length = blockQ.size();
}


int AbstractLevel::getLevel() const{
    return myLevel;
}


AbstractLevel::~AbstractLevel(){}


shared_ptr<AbstractBlock> AbstractLevel::makeBlock(char type){
    shared_ptr<AbstractBlock> theBlock;
    if (type == 'I'){
        theBlock = make_shared<iBlock>(myLevel, scoreBoard);
    }
    else if (type == 'J'){
        theBlock = make_shared<jBlock>(myLevel, scoreBoard);
    }
    else if (type == 'L'){
        theBlock = make_shared<lBlock>(myLevel, scoreBoard);
    }
    else if (type == 'O'){
        theBlock = make_shared<oBlock>(myLevel, scoreBoard);
    }
    else if (type == 'S'){
        theBlock = make_shared<sBlock>(myLevel, scoreBoard);
    }
    else if (type == 'Z'){
        theBlock = make_shared<zBlock>(myLevel, scoreBoard);
    }
    else if (type == 'T'){
        theBlock = make_shared<tBlock>(myLevel, scoreBoard);
    }
    else{
        theBlock = make_shared<singleBlock>(myLevel, scoreBoard, 0, 5);
    }
    return theBlock;
}


shared_ptr<AbstractBlock> AbstractLevel::makeSingle(int level, Score *sb, int row, int col){
    return make_shared<singleBlock>(myLevel, scoreBoard, row, col);
}


shared_ptr<AbstractBlock> AbstractLevel::getBlock(){
    return makeBlock(selectBlock());
}

void AbstractLevel::reset(){
    bQ_pos = 0;
}

bool AbstractLevel::isRandom(){
    return randomBool;
}

void AbstractLevel::setRandom(bool r){
    randomBool = r;
}

void AbstractLevel::updateSequence(string file){
    bQ_pos = 0;
    bQ_length = 0;
    blockQ.clear();
    char type;
    ifstream sequencestream{file};
    while (sequencestream >> skipws >> type){
        blockQ.emplace_back(type);
    }
    bQ_length = blockQ.size();
}


