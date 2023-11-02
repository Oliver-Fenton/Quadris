#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "../observer.h"
#include "../subject.h"
#include "../blocks/abstractblock.h"

#include <vector>
#include <iostream>


class TextDisplay: public Observer{
    std::vector<std::vector<char>> theDisplay;
    std::string iBlock() const;
    std::string jBlock() const;
    std::string lBlock() const;
    std::string oBlock() const;
    std::string sBlock() const;
    std::string zBlock() const;
    std::string tBlock() const;
    std::string Block(char type) const;
public:
    TextDisplay(int level, AbstractBlock *nextblock);
    void update(Subject &whoNotified) override;
    void updateLevel(int level) override;
    void updateNext(AbstractBlock *nb) override;
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};



#endif

