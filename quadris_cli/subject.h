#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include <memory>

class Observer;

class Subject{
    std::vector<Observer *> observers;
public:
    virtual ~Subject() = 0;
    void attach(Observer *ob);
    void detach(Observer *ob);
    void notifyObservers();
};


#endif


