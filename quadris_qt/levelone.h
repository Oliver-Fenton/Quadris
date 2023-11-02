#ifndef LEVELONE_H
#define LEVELONE_H

#include <string>

#include "abstractlevel.h"
#include "score.h"


class levelOne : public AbstractLevel {
    char selectBlock() override;

public:
    levelOne(Score *sb, std::string sequencefile);
    ~levelOne();
};

#endif // LEVELONE_H
