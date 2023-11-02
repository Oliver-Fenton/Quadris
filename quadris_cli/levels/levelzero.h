#ifndef LEVELZERO_H
#define LEVELZERO_H

#include <string>

#include "abstractlevel.h"
#include "../score.h"


class levelZero: public AbstractLevel{
    char selectBlock() override;
public:
    levelZero(Score *sb, std::string sequencefile);
    ~levelZero();
};

#endif


