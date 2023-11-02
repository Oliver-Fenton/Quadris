#ifndef OBSERVER_H
#define OBSERVER_H

#include "blocks/abstractblock.h"
#include "subject.h"


class Observer{
protected:
    const int gridHeight;
    const int gridWidth;
    int theLevel;
    int theScore;
    int theHighScore;
    AbstractBlock *nextBlock;
public:
    Observer(int level, AbstractBlock *nextblock);
    virtual ~Observer() = default;
    virtual void update(Subject &whoNotified) = 0;
    void virtual updateNext(AbstractBlock *nb) = 0;
    void virtual updateLevel(int level) = 0;
};

#endif


