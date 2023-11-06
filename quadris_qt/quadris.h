#ifndef QUADRIS_H
#define QUADRIS_H

#include <memory>
#include <iostream>
#include <fstream>
#include <string>

#include "grid.h"
#include "hint.h"
#include "score.h"
#include "abstractlevel.h"
#include "abstractblock.h"


class Quadris : public QObject {
    Q_OBJECT

private:
    std::istream &inStream;
    std::ostream &outStream;
    std::string SequenceFile;
    const std::string HIGH_SCORE_FILE = "quadris_highscore.txt";

    std::unique_ptr<Score> myScore;
    std::unique_ptr<AbstractLevel> myLevel;
    std::shared_ptr<AbstractBlock> curBlock;
    std::shared_ptr<AbstractBlock> nextBlock;
    std::unique_ptr<Grid> myBoard;
    std::unique_ptr<Hint> hintGenerator;

    void resetGame();
    std::unique_ptr<AbstractLevel> makeLevel(int level);
    void setNextBlock(std::shared_ptr<AbstractBlock> newBlock);
    void readHighScore();
    void writeHighScore();

public:
    Quadris(std::istream &in, std::ostream &out, std::string sequencefile, int level);
    ~Quadris();
    Grid& getGrid() const;
    Score& getScore() const;

public slots:
    void executeCommand(const std::string &command);

signals:
    void levelChanged(int newLevel);
    void nextBlockChanged(std::shared_ptr<AbstractBlock> newBlock);
};

#endif
