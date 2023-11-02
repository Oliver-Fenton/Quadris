#include "abstractlevel.h"

#include <memory>
#include <string>
#include <iomanip>
#include <fstream>

#include "abstractblock.h"
#include "iblock.h"
#include "lblock.h"
#include "jblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "tblock.h"
#include "singleblock.h"
#include "score.h"

using namespace std;


AbstractLevel::AbstractLevel(int level, Score *sb, string sequencefile)
    : myLevel{level}, scoreBoard{sb}, bQ_pos{0}, bQ_length{0}, randomBool{true} {
    char type;
    ifstream sequencestream{sequencefile};
    while (sequencestream >> skipws >> type) {
        blockQ.emplace_back(type);
    }
    bQ_length = blockQ.size();
}

AbstractLevel::~AbstractLevel() {}

int AbstractLevel::getLevel() const {
    return myLevel;
}

shared_ptr<AbstractBlock> AbstractLevel::makeBlock(char type) {
    shared_ptr<AbstractBlock> theBlock;

    switch(type) {
    case 'I':
        theBlock = make_shared<iBlock>(myLevel, scoreBoard);
        break;
    case 'J':
        theBlock = make_shared<jBlock>(myLevel, scoreBoard);
        break;
    case 'L':
        theBlock = make_shared<lBlock>(myLevel, scoreBoard);
        break;
    case 'O':
        theBlock = make_shared<oBlock>(myLevel, scoreBoard);
        break;
    case 'S':
        theBlock = make_shared<sBlock>(myLevel, scoreBoard);
        break;
    case 'Z':
        theBlock = make_shared<zBlock>(myLevel, scoreBoard);
        break;
    case 'T':
        theBlock = make_shared<tBlock>(myLevel, scoreBoard);
        break;
    default:
        theBlock = make_shared<singleBlock>(myLevel, scoreBoard, 0, 5);
        break;
    }

    return theBlock;
}

shared_ptr<AbstractBlock> AbstractLevel::makeSingle(int level, Score *sb, int row, int col) {
    return make_shared<singleBlock>(myLevel, scoreBoard, row, col);
}

shared_ptr<AbstractBlock> AbstractLevel::getBlock() {
    return makeBlock(selectBlock());
}

bool AbstractLevel::isRandom() {
    return randomBool;
}

void AbstractLevel::setRandom(bool r) {
    randomBool = r;
}

void AbstractLevel::updateSequence(string file) {
    bQ_pos = 0;
    bQ_length = 0;
    blockQ.clear();
    char type;
    ifstream sequencestream{file};
    while (sequencestream >> skipws >> type) {
        blockQ.emplace_back(type);
    }
    bQ_length = blockQ.size();
}

void AbstractLevel::reset() {
    bQ_pos = 0;
}
