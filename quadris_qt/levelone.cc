#include "levelone.h"

#include <cstdlib>


levelOne::levelOne(Score *sb, std::string sequencefile): AbstractLevel{1, sb, sequencefile}{}

levelOne::~levelOne(){}

char levelOne::selectBlock(){
    int randomNum = rand() % 10000 + 1;
    if (randomNum < (10000 / 12) + 1) return 'S';           // rn <= 1/12
    else if (randomNum < (10000 / 6) + 1) return 'Z';       // 1/12 < rn <= 1/6
    else if (randomNum < (10000 / 3) + 1) return 'I';       // 1/6 < rn <= 1/3
    else if (randomNum < (10000 / 2) + 1) return 'J';       // 1/3 < rn <= 1/2
    else if (randomNum < ((10000 / 3) * 2) + 1) return 'L'; // 1/2 < rn <= 2/3
    else if (randomNum < ((10000 / 6) * 5) + 1) return 'T'; // 2/3 < rn <= 5/6
    else return 'O';                                        // 5/6 < rn <= 1
}
