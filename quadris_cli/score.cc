#include "score.h"

using namespace std;


Score::Score(): theScore{0}, theHighScore{0}{}


Score::~Score(){}


int Score::getScore() const{
    return theScore;
}


int Score::getHighScore() const{
    return theHighScore;
}


void Score::increaseScore(int amount){
    theScore += amount;
    if (theScore > theHighScore){
        theHighScore = theScore;
    }
    notifyObservers();
}


void Score::reset(){
    theScore = 0;
    notifyObservers();
}
