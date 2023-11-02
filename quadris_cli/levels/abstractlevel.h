#ifndef ABSTRACTLEVEL_H
#define ABSTRACTLEVEL_H

#include <memory>
#include <string>

#include "../blocks/abstractblock.h"
#include "../score.h"


class AbstractLevel{
protected:
    const int myLevel;
    Score * const scoreBoard;
    int bQ_pos;
    int bQ_length;
    bool randomBool;
    std::vector<char> blockQ;
    virtual char selectBlock() = 0;
public:
    AbstractLevel(int level, Score *sb, std::string sequencefile);
    virtual ~AbstractLevel() = 0;
    int getLevel() const;
    std::shared_ptr<AbstractBlock> makeBlock(char type);
    std::shared_ptr<AbstractBlock> makeSingle(int level, Score *sb, int row, int col);
    std::shared_ptr<AbstractBlock> getBlock();
    bool isRandom();
    void setRandom(bool r);
    void updateSequence(std::string file);
    void reset();
};


#endif



