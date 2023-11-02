#include "levelzero.h"

#include <string>

#include "score.h"


levelZero::levelZero(Score *sb, std::string sequencefile) : AbstractLevel{0, sb, sequencefile} {}

levelZero::~levelZero() {}

char levelZero::selectBlock() {
    if (bQ_pos >= bQ_length) {
        bQ_pos = 0;
    }
    if (bQ_length == 0) {
        return '-';
    }
    return blockQ[bQ_pos++];
}
