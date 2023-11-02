#include <vector>

#include "subject.h"
#include "observer.h"


Subject::~Subject(){}


void Subject::attach(Observer *ob){
    if (ob){
        observers.emplace_back(ob);
    }
}


void Subject::detach(Observer *ob){
    for (size_t i = 0; i < observers.size(); ++i){
        if (observers[i] == ob){
            observers.erase(observers.begin() + i);
            break;
        }
    }
}


void Subject::notifyObservers(){
    for (auto &ob : observers) ob->update(*this);
}


