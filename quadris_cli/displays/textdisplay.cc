#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#include "textdisplay.h"
#include "../subject.h"
#include "../cell.h"
#include "../score.h"
#include "../blocks/abstractblock.h"

using namespace std;


TextDisplay::TextDisplay(int level, AbstractBlock *nextblock): Observer{level, nextblock}{
    theDisplay.resize(gridHeight);
    for (int row = 0; row < gridHeight; ++row){
        theDisplay[row].resize(gridWidth);
    }
}


string TextDisplay::iBlock() const{
    stringstream ss;
    ss << endl;
    ss << "IIII" << endl;
    return ss.str();
}


string TextDisplay::jBlock() const{
    stringstream ss;
    ss << "J" << endl;
    ss << "JJJ" << endl;
    return ss.str();
}


string TextDisplay::lBlock() const{
    stringstream ss;
    ss << "  L" << endl;
    ss << "LLL" << endl;
    return ss.str();
}


string TextDisplay::oBlock() const{
    stringstream ss;
    ss << "OO" << endl;
    ss << "OO" << endl;
    return ss.str();
}


string TextDisplay::sBlock() const{
    stringstream ss;
    ss << " SS" << endl;
    ss << "SS" << endl;
    return ss.str();
}


string TextDisplay::zBlock() const{
    stringstream ss;
    ss << "ZZ " << endl;
    ss << " ZZ" << endl;
    return ss.str();
}


string TextDisplay::tBlock() const{
    stringstream ss;
    ss << "TTT" << endl;
    ss << " T" << endl;
    return ss.str();
}


string TextDisplay::Block(char type) const{
    if (type == 'I'){
        return iBlock();
    }
    else if (type == 'J'){
        return jBlock();
    }
    else if (type == 'L'){
        return lBlock();
    }
    else if (type == 'S'){
        return sBlock();
    }
    else if (type == 'Z'){
        return zBlock();
    }
    else if (type == 'O'){
        return oBlock();
    }
    else{
        return tBlock();
    }
}


void TextDisplay::updateLevel(int level){
    theLevel = level;
}


void TextDisplay::updateNext(AbstractBlock *nb){
    nextBlock = nb;
}


void TextDisplay::update(Subject &whoNotified){
    if (dynamic_cast<Cell *>(&whoNotified)){
        Cell *cp = dynamic_cast<Cell *>(&whoNotified);
        theDisplay[cp->getRow()][cp->getCol()] = cp->getType();
    }
    else if (dynamic_cast<Score *>(&whoNotified)){
        Score *sp = dynamic_cast<Score *>(&whoNotified);
        theScore = sp->getScore();
        theHighScore = sp->getHighScore();
    }
}


ostream &operator<<(ostream &out, const TextDisplay &td){
    string unicodeOverscore = "\u203E";
    out << endl;
    out.fill(' ');
    out.width(15);
    out << left << "Level:";
    out << right << td.theLevel << endl;
    out.width(15);
    out << left << "Score:";
    out << right << td.theScore << endl;
    out.width(15);
    out << left << "HiScore:";
    out << right << td.theHighScore << endl;
    for (int i = 0; i < 13; ++i){
        out << unicodeOverscore;
    }
    out << endl << "Next:" << endl;
    char nextBlockType = td.nextBlock->getType();
    out << td.Block(nextBlockType);
    out << string(13, '_') << endl;
    for (int row = 0; row < td.gridHeight; ++row){
        out << '|';
        for (int col = 0; col < td.gridWidth; ++col){
            out << td.theDisplay[row][col];
        }
        out << '|' << endl;
    }
    for (int i = 0; i < 13; ++i){
        out << unicodeOverscore;
    }
    out << endl << endl;
    return out;
}

