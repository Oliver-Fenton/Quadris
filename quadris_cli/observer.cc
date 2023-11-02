#include "observer.h"
#include "blocks/abstractblock.h"

Observer::Observer(int level, AbstractBlock *nextblock):
gridHeight{18},
gridWidth{11},
theLevel{level},
theScore{0},
theHighScore{0},
nextBlock{nextblock}{}

