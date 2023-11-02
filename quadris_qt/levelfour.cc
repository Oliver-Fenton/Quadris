#include "levelfour.h"

#include <cstdlib>


levelFour::levelFour(Score *sb, std::string sequencefile) : AbstractLevel{4, sb, sequencefile} {}

levelFour::~levelFour() {}

char levelFour::selectBlock() {
    if (randomBool) {
        int randomNum = rand() % 10000 + 1;
        if (randomNum < ((10000 / 9) * 2) + 1) return 'S';          // rn <= 1/12
        else if (randomNum < ((10000 / 9) * 4) + 1) return 'Z';     // 1/12 < rn <= 1/6
        else if (randomNum < ((10000 / 9) * 5) + 1) return 'I';     // 1/6 < rn <= 1/3
        else if (randomNum < ((10000 / 9) * 6) + 1) return 'J';     // 1/3 < rn <= 1/2
        else if (randomNum < ((10000 / 9) * 7) + 1) return 'L';     // 1/2 < rn <= 2/3
        else if (randomNum < ((10000 / 9) * 8) + 1) return 'T';     // 2/3 < rn <= 5/6
        else return 'O';                                            // 5/6 < rn <= 1
    } else {
        if (bQ_pos >= bQ_length) {
            bQ_pos = 0;
        }
        if (blockQ.size() == 0) {
            return 'I';
        }
        return blockQ[bQ_pos++];
    }
}
