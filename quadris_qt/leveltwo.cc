#include "leveltwo.h"

#include <cstdlib>


levelTwo::levelTwo(Score *sb, std::string sequencefile) : AbstractLevel{2, sb, sequencefile} {}

levelTwo::~levelTwo() {}

char levelTwo::selectBlock() {
    int randomNum = rand() % 10000 + 1;
    if (randomNum < (10000 / 7) + 1) return 'S';            // rn <= 1/12
    else if (randomNum < ((10000 / 7) * 2) + 1) return 'Z'; // 1/12 < rn <= 1/6
    else if (randomNum < ((10000 / 7) * 3) + 1) return 'I'; // 1/6 < rn <= 1/3
    else if (randomNum < ((10000 / 7) * 4) + 1) return 'J'; // 1/3 < rn <= 1/2
    else if (randomNum < ((10000 / 7) * 5) + 1) return 'L'; // 1/2 < rn <= 2/3
    else if (randomNum < ((10000 / 7) * 6) + 1) return 'T'; // 2/3 < rn <= 5/6
    else return 'O';                                        // 5/6 < rn <= 1
}
