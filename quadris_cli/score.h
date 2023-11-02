#ifndef SCORE_H
#define SCORE_H

#include "subject.h"


class Score: public Subject{
    int theScore;
    int theHighScore;
public:
    Score();
    ~Score();
    int getScore() const;
    int getHighScore() const;
    void increaseScore(int amount);
    void reset();
};


#endif


