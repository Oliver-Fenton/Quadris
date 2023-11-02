#ifndef QUADRIS_H
#define QUADRIS_H

#include <memory>
#include <iostream>
#include <fstream>
#include <string>

#include "quadris.h"
#include "grid.h"
#include "commandinterpreter.h"
#include "observer.h"
#include "displays/textdisplay.h"
#include "displays/graphicsdisplay.h"
#include "score.h"
#include "levels/abstractlevel.h"
#include "blocks/abstractblock.h"


class Quadris{
    std::istream &inStream;
    std::ostream &outStream;
    std::string SequenceFile;
    std::unique_ptr<Score> myScore;
    std::unique_ptr<AbstractLevel> myLevel;
    std::shared_ptr<AbstractBlock> curBlock;
    std::shared_ptr<AbstractBlock> nextBlock;
    std::unique_ptr<TextDisplay> myTD;
    std::unique_ptr<GraphicsDisplay> myGD;
    std::unique_ptr<Grid> myBoard;
    std::unique_ptr<CommandInterpreter> myInterpreter;
    void resetGame();
    std::unique_ptr<AbstractLevel> makeLevel(int level);
    void executeCommand();
public:
    Quadris(std::istream &in, std::ostream &out, std::string sequencefile, bool graphicsOn, int level);
    ~Quadris();
    void playGame();
};

#endif
