#include <cstdlib>

#include "leveltwo.h"


levelTwo::levelTwo(Score *sb, std::string sequencefile): AbstractLevel{2, sb, sequencefile}{}


levelTwo::~levelTwo(){}


char levelTwo::selectBlock(){
    int randomNum = rand() % 10000 + 1;
    if (randomNum < (10000 / 7) + 1){               // rn <= 1/12
        return 'S';
    }
    else if (randomNum < ((10000 / 7) * 2) + 1){    // 1/12 < rn <= 1/6
        return 'Z';
    }
    else if (randomNum < ((10000 / 7) * 3) + 1){    // 1/6 < rn <= 1/3
        return 'I';
    }
    else if (randomNum < ((10000 / 7) * 4) + 1){    // 1/3 < rn <= 1/2
        return 'J';
    }
    else if (randomNum < ((10000 / 7) * 5) + 1){    // 1/2 < rn <= 2/3
        return 'L';
    }
    else if (randomNum < ((10000 / 7) * 6) + 1){    // 2/3 < rn <= 5/6
        return 'T';
    }
    else{                                           // 5/6 < rn <= 1
        return 'O';
    }
}



