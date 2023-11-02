#include <memory>
#include <string>
#include <fstream>

#include "levelzero.h"
#include "../score.h"

using namespace std;


levelZero::levelZero(Score *sb, string sequencefile):
AbstractLevel{0, sb, sequencefile}{}


levelZero::~levelZero(){}


char levelZero::selectBlock(){
    if (bQ_pos >= bQ_length){
        bQ_pos = 0;
    }
    if (bQ_length == 0){
        return '-';
    }
    return blockQ[bQ_pos++];
}


