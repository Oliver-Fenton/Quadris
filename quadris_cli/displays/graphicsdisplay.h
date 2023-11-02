#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include <iostream>
#include <vector>
#include "../observer.h"
#include "window.h"
#include "../blocks/abstractblock.h"

struct Vec{
    int x, y;
};


class GraphicsDisplay: public Observer{
    int windowWidth, windowHeight;
    Xwindow xw;
    const Vec nextStrVec;
    const Vec levelStrVec;
    const Vec scoreStrVec;
    const Vec highscoreStrVec;
    const Vec levelIntVec;
    const Vec scoreIntVec;
    const Vec highscoreIntVec;
    const Vec shiftVec;
    void drawNext(AbstractBlock *nb);
    void drawType(char type);
    void fillCell(int col, int row, char type);
    void outlineCell(int col, int row);
public:
    GraphicsDisplay(int level, AbstractBlock *nextblock, int width, int height);
    void clearGrid();
    void updateNext(AbstractBlock *nb) override;
    void updateLevel(int level) override;
    void update(Subject &whoNotified) override;
};
#endif

