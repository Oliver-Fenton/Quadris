#include <memory>
#include <iostream>
#include <fstream>

#include "quadris.h"
#include "grid.h"
#include "commandinterpreter.h"
#include "displays/textdisplay.h"
#include "displays/graphicsdisplay.h"
#include "score.h"
#include "levels/abstractlevel.h"
#include "blocks/abstractblock.h"
#include "levels/levelzero.h"
#include "levels/levelone.h"
#include "levels/leveltwo.h"
#include "levels/levelthree.h"
#include "levels/levelfour.h"

using namespace std;


Quadris::Quadris(std::istream &in, std::ostream &out, std::string sequencefile, bool graphicsOn, int level):
inStream{in},
outStream{out},
SequenceFile{sequencefile},
myScore{make_unique<Score>()},
myLevel{makeLevel(level)},
curBlock{myLevel->getBlock()},
nextBlock{myLevel->getBlock()},
myTD{make_unique<TextDisplay>(level, &(*nextBlock))},
myGD{graphicsOn ? make_unique<GraphicsDisplay>(level, &(*nextBlock), 325, 700) : nullptr},
myBoard{make_unique<Grid>(level, &(*myTD), &(*myGD), &(*myScore))},
myInterpreter{make_unique<CommandInterpreter>()}{
    myScore->attach(&(*myTD));
    myScore->attach(&(*myGD));
    myBoard->placeBlock(curBlock);
}


Quadris::~Quadris(){
    curBlock->setSB(nullptr);
    nextBlock->setSB(nullptr);
}


unique_ptr<AbstractLevel> Quadris::makeLevel(int level){
    if (level == 1){
        return make_unique<levelOne>(&(*myScore), SequenceFile);
    }
    else if (level == 2){
        return make_unique<levelTwo>(&(*myScore), SequenceFile);
    }
    else if (level == 3){
        return make_unique<levelThree>(&(*myScore), SequenceFile);
    }
    else if (level == 4){
        return make_unique<levelFour>(&(*myScore), SequenceFile);
}
    else{
        return make_unique<levelZero>(&(*myScore), SequenceFile);
    }
}


void Quadris::resetGame(){
    curBlock->setSB(nullptr);
    nextBlock->setSB(nullptr);
    myBoard->reset();
    myLevel->reset();
    myScore->reset();
    curBlock = myLevel->getBlock();
    nextBlock = myLevel->getBlock();
    if (myGD){
        myGD->clearGrid();
        myGD->updateNext(&(*nextBlock));
    }
    myTD->updateNext(&(*nextBlock));
    myBoard->placeBlock(curBlock);
}


void Quadris::executeCommand(){
    string command = myInterpreter->getCommand();
    if (command == "I"){
        shared_ptr<AbstractBlock> newBlock =  myLevel->makeBlock('I');
        myBoard->replaceBlock(curBlock, newBlock);
        curBlock = newBlock;
    }
    else if (command == "J"){
        shared_ptr<AbstractBlock> newBlock =  myLevel->makeBlock('J');
        myBoard->replaceBlock(curBlock, newBlock);
        curBlock = newBlock;
    }
    else if (command == "L"){
        shared_ptr<AbstractBlock> newBlock =  myLevel->makeBlock('L');
        myBoard->replaceBlock(curBlock, newBlock);
        curBlock = newBlock;
    }
    else if (command == "S"){
        shared_ptr<AbstractBlock> newBlock =  myLevel->makeBlock('S');
        myBoard->replaceBlock(curBlock, newBlock);
        curBlock = newBlock;
    }
    else if (command == "Z"){
        shared_ptr<AbstractBlock> newBlock =  myLevel->makeBlock('Z');
        myBoard->replaceBlock(curBlock, newBlock);
        curBlock = newBlock;
    }
    else if (command == "O"){
        shared_ptr<AbstractBlock> newBlock =  myLevel->makeBlock('O');
        myBoard->replaceBlock(curBlock, newBlock);
        curBlock = newBlock;
    }
    else if (command == "T"){
        shared_ptr<AbstractBlock> newBlock =  myLevel->makeBlock('T');
        myBoard->replaceBlock(curBlock, newBlock);
        curBlock = newBlock;
    }
    else if (command == "Hint"){}
    else if (command == "Sequence"){
        string file = myInterpreter->getFile();
        ifstream ifs{file};
        while (ifs >> command){
            myInterpreter->updateCommand(command);
            executeCommand();
        }
    }
    else if (command == "NoRandom"){
        string file = myInterpreter->getFile();
        if (myLevel->getLevel() > 2){
            myLevel->setRandom(false);
            myLevel->updateSequence(file);
        }
    }
    else if (command == "Left"){
        myBoard->shiftLeft(curBlock, myInterpreter->getMultiplier());
        if (myLevel->getLevel() > 2){
            myBoard->shiftDown(curBlock, 1);
        }
    }
    else if (command == "Right"){
        myBoard->shiftRight(curBlock, myInterpreter->getMultiplier());
        if (myLevel->getLevel() > 2){
            myBoard->shiftDown(curBlock, 1);
        }
    }
    else if (command == "Random"){
        if (myLevel->getLevel() > 2){
            myLevel->setRandom(true);
            myLevel->reset();
        }
    }
    else if (command == "Restart"){
        this->resetGame();
    }
    else if (command == "Down"){
        myBoard->shiftDown(curBlock, myInterpreter->getMultiplier());
        if (myLevel->getLevel() > 2){
            myBoard->shiftDown(curBlock, 1);
        }
    }
    else if (command == "Drop"){
        for (int times = myInterpreter->getMultiplier(); times > 0; --times){
            myBoard->Drop(curBlock);
            curBlock = nextBlock;
            nextBlock = myLevel->getBlock();
            myTD->updateNext(&(*nextBlock));
            if (myGD){
                myGD->updateNext(&(*nextBlock));
            }
            if (!myBoard->placeBlock(curBlock)){
                this->resetGame();
            }
        }
    }
    else if (command == "ClockWise"){
        myBoard->rotateCW(curBlock, myInterpreter->getMultiplier());
        if (myLevel->getLevel() > 2){
            myBoard->shiftDown(curBlock, 1);
        }
    }
    else if (command == "CounterClockWise"){
        myBoard->rotateCCW(curBlock, myInterpreter->getMultiplier());
        if (myLevel->getLevel() > 2){
            myBoard->shiftDown(curBlock, 1);
        }
    }
    else if (command == "LevelUp"){
        int times = myInterpreter->getMultiplier();
        while (times > 0){
            int curLevel = myLevel->getLevel();
            if (curLevel < 4){
                int newLevel = curLevel + 1;
                myLevel = makeLevel(newLevel);
                myTD->updateLevel(newLevel);
                if (myGD){
                    myGD->updateLevel(newLevel);
                }
                myBoard->setLevel(newLevel);
            }
            else{
                break;
            }
            --times;
        }
    }
    else if (command == "LevelDown"){
        int times = myInterpreter->getMultiplier();
        while (times > 0){
            int curLevel = myLevel->getLevel();
            if (curLevel > 0){
                int newLevel = curLevel - 1;
                myLevel = makeLevel(newLevel);
                myTD->updateLevel(newLevel);
                if (myGD){
                    myGD->updateLevel(newLevel);
                }
                myBoard->setLevel(newLevel);
            }
            else{
                break;
            }
            --times;
        }
    }
}


void Quadris::playGame(){
    string command;
    outStream << *myTD;
    while (getline(inStream, command)){
        if (myInterpreter->updateCommand(command)){
            executeCommand();
        }
        outStream << *myTD;
    }
}


