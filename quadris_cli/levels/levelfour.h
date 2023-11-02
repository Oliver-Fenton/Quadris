#ifndef LEVELFOUR_H
#define LEVELFOUR_H

#include <string>

#include "abstractlevel.h"
#include "../score.h"


class levelFour: public AbstractLevel{
    char selectBlock() override;
public:
    levelFour(Score *sb, std::string sequencefile);
    ~levelFour();
};

#endif



