#ifndef LEVELTWO_H
#define LEVELTWO_H

#include <string>

#include "abstractlevel.h"
#include "score.h"


class levelTwo : public AbstractLevel {
    char selectBlock() override;

public:
    levelTwo(Score *sb, std::string sequencefile);
    ~levelTwo();
};

#endif // LEVELTWO_H
