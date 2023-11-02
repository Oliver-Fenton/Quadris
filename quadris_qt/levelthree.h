#ifndef LEVELTHREE_H
#define LEVELTHREE_H

#include <string>

#include "abstractlevel.h"
#include "score.h"


class levelThree : public AbstractLevel {
    char selectBlock() override;

public:
    levelThree(Score *sb, std::string sequencefile);
    ~levelThree();
};

#endif // LEVELTHREE_H
