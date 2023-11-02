#include "score.h"


Score::Score() : theScore{0}, theHighScore{0} {}

Score::~Score() {}

int Score::getScore() const {
    return theScore;
}

int Score::getHighScore() const {
    return theHighScore;
}

void Score::setHighScore(int highScore) {
    theHighScore = highScore;
    emit highScoreChanged(theHighScore);
}

void Score::increaseScore(int amount) {
    theScore += amount;
    emit scoreChanged(theScore);

    if (theScore > theHighScore) {
        theHighScore = theScore;
        emit highScoreChanged(theHighScore);
    }
}

void Score::reset() {
    theScore = 0;
    emit scoreChanged(theScore);
}
