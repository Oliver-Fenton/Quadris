#include "quadris.h"

#include <memory>
#include <iostream>
#include <fstream>
#include <QTimer>
#include <vector>
#include <utility>
#include <QStandardPaths>
#include <QDir>

#include "grid.h"
#include "score.h"
#include "abstractlevel.h"
#include "abstractblock.h"
#include "levelzero.h"
#include "levelone.h"
#include "leveltwo.h"
#include "levelthree.h"
#include "levelfour.h"

using namespace std;


Quadris::Quadris(std::istream &in, std::ostream &out, std::string sequencefile, int level)
    : inStream{in}
    , outStream{out}
    , SequenceFile{sequencefile}
    , myScore{make_unique<Score>()}
    , myLevel{makeLevel(level)}
    , curBlock{myLevel->getBlock()}
    , nextBlock{myLevel->getBlock()}
    , myBoard{make_unique<Grid>(level, &(*myScore))}
    , hintGenerator{make_unique<Hint>()}
{
        myBoard->placeBlock(curBlock);

        // using a single shot QTimer to emit the signal after construction
        QTimer::singleShot(0, [this]() { emit nextBlockChanged(nextBlock); });
        readHighScore();
}

Quadris::~Quadris() {
    curBlock->setSB(nullptr);
    nextBlock->setSB(nullptr);
    writeHighScore();
}

void Quadris::resetGame() {
    curBlock->setSB(nullptr);
    nextBlock->setSB(nullptr);
    myBoard->reset();
    myLevel->reset();
    myScore->reset();
    curBlock = myLevel->getBlock();
    setNextBlock(myLevel->getBlock());
    myBoard->placeBlock(curBlock);
}

unique_ptr<AbstractLevel> Quadris::makeLevel(int level) {
    if (level == 1) return make_unique<levelOne>(&(*myScore), SequenceFile);
    else if (level == 2) return make_unique<levelTwo>(&(*myScore), SequenceFile);
    else if (level == 3) return make_unique<levelThree>(&(*myScore), SequenceFile);
    else if (level == 4) return make_unique<levelFour>(&(*myScore), SequenceFile);
    else return make_unique<levelZero>(&(*myScore), SequenceFile);
}

void Quadris::setNextBlock(std::shared_ptr<AbstractBlock> newBlock) {
    nextBlock = newBlock;
    emit nextBlockChanged(nextBlock);
}

void Quadris::readHighScore() {
    QString dataLocation = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir().mkpath(dataLocation);
    std::filesystem::path highScoreFilePath = std::filesystem::path(dataLocation.toStdString()) / HIGH_SCORE_FILE;
    std::ifstream infile(highScoreFilePath);

    int fileHighScore = 0;
    if (infile) {
        infile >> fileHighScore;
        infile.close();
    }
    myScore->setHighScore(fileHighScore);
}

void Quadris::writeHighScore() {
    QString dataLocation = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir().mkpath(dataLocation);
    std::filesystem::path highScoreFilePath = std::filesystem::path(dataLocation.toStdString()) / HIGH_SCORE_FILE;
    std::ifstream infile(highScoreFilePath);

    int fileHighScore = 0;
    if (infile) {
        infile >> fileHighScore;
        infile.close();
    }

    if (myScore->getHighScore() > fileHighScore) {
        std::ofstream outfile(highScoreFilePath);
        if (!outfile) {
            std::cerr << "Error: Could not open file for writing: " << highScoreFilePath << std::endl;
            return;
        }
        outfile << myScore->getHighScore();
        outfile.close();
    }
}

Grid& Quadris::getGrid() const {
    return *myBoard;
}

Score& Quadris::getScore() const {
    return *myScore;
}

void Quadris::executeCommand(const string &command)  {
    if (command == "I") {
        shared_ptr<AbstractBlock> newBlock =  myLevel->makeBlock('I');
        myBoard->replaceBlock(curBlock, newBlock);
        curBlock = newBlock;
    } else if (command == "J") {
        shared_ptr<AbstractBlock> newBlock =  myLevel->makeBlock('J');
        myBoard->replaceBlock(curBlock, newBlock);
        curBlock = newBlock;
    } else if (command == "L")  {
        shared_ptr<AbstractBlock> newBlock =  myLevel->makeBlock('L');
        myBoard->replaceBlock(curBlock, newBlock);
        curBlock = newBlock;
    } else if (command == "S") {
        shared_ptr<AbstractBlock> newBlock =  myLevel->makeBlock('S');
        myBoard->replaceBlock(curBlock, newBlock);
        curBlock = newBlock;
    } else if (command == "Z") {
        shared_ptr<AbstractBlock> newBlock =  myLevel->makeBlock('Z');
        myBoard->replaceBlock(curBlock, newBlock);
        curBlock = newBlock;
    } else if (command == "O") {
        shared_ptr<AbstractBlock> newBlock =  myLevel->makeBlock('O');
        myBoard->replaceBlock(curBlock, newBlock);
        curBlock = newBlock;
    } else if (command == "T") {
        shared_ptr<AbstractBlock> newBlock =  myLevel->makeBlock('T');
        myBoard->replaceBlock(curBlock, newBlock);
        curBlock = newBlock;
    } else if (command == "Hint") {
        if (!myBoard->hintShown()) {
            vector<pair<int,int>> hint = hintGenerator->getHint(myBoard->getBoard(curBlock), curBlock->getType());
            myBoard->showHint(hint);
        }
    } else if (command == "Sequence") {
    } else if (command == "NoRandom") {
        string file = "sequence.txt";
        if (myLevel->getLevel() > 2) {
            myLevel->setRandom(false);
            myLevel->updateSequence(file);
        }
    } else if (command == "Left") {
        myBoard->shiftLeft(curBlock, 1);
        if (myLevel->getLevel() > 2) {
            myBoard->shiftDown(curBlock, 1);
        }
    } else if (command == "Right") {
        myBoard->shiftRight(curBlock, 1);
        if (myLevel->getLevel() > 2) {
            myBoard->shiftDown(curBlock, 1);
        }
    } else if (command == "Random") {
        if (myLevel->getLevel() > 2) {
            myLevel->setRandom(true);
            myLevel->reset();
        }
    } else if (command == "Restart") {
        this->resetGame();
    } else if (command == "Down") {
        bool atBottom = myBoard->shiftDown(curBlock, 1);
        if (atBottom) {
            myBoard->Drop(curBlock);
            curBlock = nextBlock;
            setNextBlock(myLevel->getBlock());
            if (!myBoard->placeBlock(curBlock)) {
                this->resetGame();
            }
        }
        if (myLevel->getLevel() > 2 && !atBottom) {
            myBoard->shiftDown(curBlock, 1);
        }
    } else if (command == "Drop") {
        myBoard->Drop(curBlock);
        curBlock = nextBlock;
        setNextBlock(myLevel->getBlock());
        if (!myBoard->placeBlock(curBlock)) {
            this->resetGame();
        }
    } else if (command == "ClockWise") {
        myBoard->rotateCW(curBlock, 1);
        if (myLevel->getLevel() > 2) {
            myBoard->shiftDown(curBlock, 1);
        }
    } else if (command == "CounterClockWise") {
        myBoard->rotateCCW(curBlock, 1);
        if (myLevel->getLevel() > 2) {
            myBoard->shiftDown(curBlock, 1);
        }
    } else if (command == "LevelUp") {
        int times = 1;
        while (times > 0) {
            int curLevel = myLevel->getLevel();
            if (curLevel < 4) {
                int newLevel = curLevel + 1;
                myLevel = makeLevel(newLevel);
                myBoard->setLevel(newLevel);
            } else {
                break;
            }
            --times;
        }
        emit levelChanged(myLevel->getLevel());
    } else if (command == "LevelDown") {
        int times = 1;
        while (times > 0) {
            int curLevel = myLevel->getLevel();
            if (curLevel > 0) {
                int newLevel = curLevel - 1;
                myLevel = makeLevel(newLevel);
                myBoard->setLevel(newLevel);
            } else {
                break;
            }
            --times;
        }
        emit levelChanged(myLevel->getLevel());
    }
}
