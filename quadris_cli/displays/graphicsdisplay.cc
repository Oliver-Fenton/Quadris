#include <iostream>
#include <sstream>
#include <vector>

#include "graphicsdisplay.h"
#include "../blocks/abstractblock.h"
#include "window.h"
#include "../observer.h"
#include "../subject.h"
#include "../score.h"
#include "../cell.h"

using namespace std;

GraphicsDisplay::GraphicsDisplay(int level, AbstractBlock *nextblock, int width, int height):
Observer{level, nextblock},
windowWidth{width},
windowHeight{height},
xw{width, height},
nextStrVec{(width / 13) * 2, (height / 28) * 5},
levelStrVec{(width / 13) * 6, (height / 28) * 5},
scoreStrVec{(width / 13) * 8, (height / 28) * 5},
highscoreStrVec{(width / 13) * 10, (height / 28) * 5},
levelIntVec{((width / 13) * 6) + 12, (height / 28) * 7},
scoreIntVec{((width / 13) * 8) + 12, (height / 28) * 7},
highscoreIntVec{(width / 13) * 11, (height / 28) * 7},
shiftVec{1, 9}{
    xw.fillRectangle(0, 0, windowWidth, windowHeight, Xwindow::White);
    xw.drawBigString((gridWidth / 2) * (windowWidth / 13), (windowHeight / 28) * 3, "Quadris", Xwindow::Blue);
    xw.drawString(nextStrVec.x, nextStrVec.y, "next");
    xw.drawString(levelStrVec.x, levelStrVec.y, "level");
    xw.drawString(scoreStrVec.x, scoreStrVec.y, "score");
    xw.drawString(highscoreStrVec.x, highscoreStrVec.y, "highscore");
    stringstream ss;
    ss << theLevel;
    drawType(nextBlock->getType());
    xw.drawString(levelIntVec.x, levelIntVec.y, ss.str());
    xw.drawString(scoreIntVec.x, scoreIntVec.y, "0");
    xw.drawString(highscoreIntVec.x, highscoreIntVec.y, "0");
    for (int row = 0; row < gridHeight; ++row){
        xw.fillRectangle(shiftVec.x * (windowWidth / 13), (row + shiftVec.y) *(windowWidth / 13), (windowWidth / 13) * 11, 1);
    }
    xw.fillRectangle(shiftVec.x * (windowWidth / 13), (shiftVec.y + gridHeight) *(windowWidth / 13), (windowWidth / 13) * 11, 1);
    for (int col = 0; col < gridWidth; ++col){
        xw.fillRectangle((col + shiftVec.x) * (windowWidth / 13), shiftVec.y * (windowHeight / 28), 1, (windowHeight / 28) * 18);
    }
    xw.fillRectangle((shiftVec.x + gridWidth) * (windowWidth / 13), shiftVec.y * (windowHeight / 28), 1, (windowHeight / 28) * 18);
}
    
    
void GraphicsDisplay::drawType(char type){
    xw.fillRectangle((windowWidth / 13), (windowHeight / 28) * 6, (windowWidth / 13) * 4, (windowHeight / 28) * 2, Xwindow::White);
    for (int row = 6; row < 8; ++row){
        for (int col = 1; col < 5; ++col){
            xw.outlineRectangle(col * (windowWidth / 13), row * (windowHeight / 28), (windowWidth / 13), (windowHeight / 28), Xwindow::White);
        }
    }
    if (type == 'I'){
        xw.fillRectangle((windowWidth / 13), (windowHeight / 28) * 7, (windowWidth / 13) * 4, (windowHeight / 28), Xwindow::Blue);
        xw.outlineRectangle((windowWidth / 13), (windowHeight / 28) * 7, (windowWidth / 13), (windowHeight / 28));
        xw.outlineRectangle((windowWidth / 13) * 2, (windowHeight / 28) * 7, (windowWidth / 13), (windowHeight / 28));
        xw.outlineRectangle((windowWidth / 13) * 3, (windowHeight / 28) * 7, (windowWidth / 13), (windowHeight / 28));
        xw.outlineRectangle((windowWidth / 13) * 4, (windowHeight / 28) * 7, (windowWidth / 13), (windowHeight / 28));
    }
    else if (type == 'J'){
        xw.fillRectangle((windowWidth / 13), (windowHeight / 28) * 7, (windowWidth / 13) * 3, (windowHeight / 28), Xwindow::Orange);
        xw.fillRectangle((windowWidth / 13), (windowHeight / 28) * 6,(windowWidth / 13), (windowHeight / 28), Xwindow::Orange);
        xw.outlineRectangle((windowWidth / 13), (windowHeight / 28) * 6,(windowWidth / 13), (windowHeight / 28));
        xw.outlineRectangle((windowWidth / 13), (windowHeight / 28) * 7, (windowWidth / 13), (windowHeight / 28));
        xw.outlineRectangle((windowWidth / 13) * 2, (windowHeight / 28) * 7, (windowWidth / 13), (windowHeight / 28));
        xw.outlineRectangle((windowWidth / 13) * 3, (windowHeight / 28) * 7, (windowWidth / 13), (windowHeight / 28));
    }
    else if (type == 'L'){
        xw.fillRectangle((windowWidth / 13), (windowHeight / 28) * 7, (windowWidth / 13) * 3, (windowHeight / 28), Xwindow::Red);
        xw.fillRectangle((windowWidth / 13) * 3, (windowHeight / 28) * 6,(windowWidth / 13), (windowHeight / 28), Xwindow::Red);
        xw.outlineRectangle((windowWidth / 13) * 3, (windowHeight / 28) * 6,(windowWidth / 13), (windowHeight / 28));
        xw.outlineRectangle((windowWidth / 13), (windowHeight / 28) * 7, (windowWidth / 13), (windowHeight / 28));
        xw.outlineRectangle((windowWidth / 13) * 2, (windowHeight / 28) * 7, (windowWidth / 13), (windowHeight / 28));
        xw.outlineRectangle((windowWidth / 13) * 3, (windowHeight / 28) * 7, (windowWidth / 13), (windowHeight / 28));
    }
    else if (type == 'O'){
        xw.fillRectangle((windowWidth / 13), (windowHeight / 28) * 6, (windowWidth / 13) * 2, (windowHeight / 28) * 2, Xwindow::Yellow);
        xw.outlineRectangle((windowWidth / 13), (windowHeight / 28) * 6,(windowWidth / 13), (windowHeight / 28));
        xw.outlineRectangle((windowWidth / 13), (windowHeight / 28) * 7, (windowWidth / 13), (windowHeight / 28));
        xw.outlineRectangle((windowWidth / 13) * 2, (windowHeight / 28) * 6,(windowWidth / 13), (windowHeight / 28));
        xw.outlineRectangle((windowWidth / 13) * 2, (windowHeight / 28) * 7, (windowWidth / 13), (windowHeight / 28));
    }
    else if (type == 'S'){
        xw.fillRectangle((windowWidth / 13) * 2, (windowHeight / 28) * 6, (windowWidth / 13) * 2, (windowHeight / 28), Xwindow::Cyan);
        xw.fillRectangle((windowWidth / 13), (windowHeight / 28) * 7, (windowWidth / 13) * 2, (windowHeight / 28), Xwindow::Cyan);
        xw.outlineRectangle((windowWidth / 13) * 2, (windowHeight / 28) * 6,(windowWidth / 13), (windowHeight / 28));
        xw.outlineRectangle((windowWidth / 13) * 3, (windowHeight / 28) * 6,(windowWidth / 13), (windowHeight / 28));
        xw.outlineRectangle((windowWidth / 13), (windowHeight / 28) * 7, (windowWidth / 13), (windowHeight / 28));
        xw.outlineRectangle((windowWidth / 13) * 2, (windowHeight / 28) * 7, (windowWidth / 13), (windowHeight / 28));
    }
    else if (type == 'Z'){
        xw.fillRectangle((windowWidth / 13), (windowHeight / 28) * 6, (windowWidth / 13) * 2, (windowHeight / 28), Xwindow::Green);
        xw.fillRectangle((windowWidth / 13) * 2, (windowHeight / 28) * 7, (windowWidth / 13) * 2, (windowHeight / 28), Xwindow::Green);
        xw.outlineRectangle((windowWidth / 13), (windowHeight / 28) * 6,(windowWidth / 13), (windowHeight / 28));
        xw.outlineRectangle((windowWidth / 13) * 2, (windowHeight / 28) * 6,(windowWidth / 13), (windowHeight / 28));
        xw.outlineRectangle((windowWidth / 13) * 2, (windowHeight / 28) * 7, (windowWidth / 13), (windowHeight / 28));
        xw.outlineRectangle((windowWidth / 13) * 3, (windowHeight / 28) * 7, (windowWidth / 13), (windowHeight / 28));
    }
    else if (type == 'T'){
        xw.fillRectangle((windowWidth / 13), (windowHeight / 28) * 6, (windowWidth / 13) * 3, (windowHeight / 28), Xwindow::Magenta);
        xw.fillRectangle((windowWidth / 13) * 2, (windowHeight / 28) * 7, (windowWidth / 13), (windowHeight / 28), Xwindow::Magenta);
        xw.outlineRectangle((windowWidth / 13), (windowHeight / 28) * 6, (windowWidth / 13), (windowHeight / 28));
        xw.outlineRectangle((windowWidth / 13) * 2, (windowHeight / 28) * 6,(windowWidth / 13), (windowHeight / 28));
        xw.outlineRectangle((windowWidth / 13) * 3, (windowHeight / 28) * 6, (windowWidth / 13), (windowHeight / 28));
        xw.outlineRectangle((windowWidth / 13) * 2, (windowHeight / 28) * 7, (windowWidth / 13), (windowHeight / 28));
    }
}

    
void GraphicsDisplay::drawNext(AbstractBlock *nb){
    if (nb){
        drawType(nb->getType());
    }
}
    
    
void GraphicsDisplay::fillCell(int col, int row, char type){
    if (type == 'I'){
        xw.fillRectangle((col + shiftVec.x) * (windowWidth / 13), (row + shiftVec.y) * (windowHeight / 28), (windowWidth / 13), (windowHeight / 28), Xwindow::Blue);
    }
    else if (type == 'J'){
        xw.fillRectangle((col + shiftVec.x) * (windowWidth / 13), (row + shiftVec.y) * (windowHeight / 28), (windowWidth / 13), (windowHeight / 28), Xwindow::Orange);
    }
    else if (type == 'L'){
        xw.fillRectangle((col + shiftVec.x) * (windowWidth / 13), (row + shiftVec.y) * (windowHeight / 28), (windowWidth / 13), (windowHeight / 28), Xwindow::Red);
    }
    else if (type == 'O'){
        xw.fillRectangle((col + shiftVec.x) * (windowWidth / 13), (row + shiftVec.y) * (windowHeight / 28), (windowWidth / 13), (windowHeight / 28), Xwindow::Yellow);
    }
    else if (type == 'S'){
        xw.fillRectangle((col + shiftVec.x) * (windowWidth / 13), (row + shiftVec.y) * (windowHeight / 28), (windowWidth / 13), (windowHeight / 28), Xwindow::Cyan);
    }
    else if (type == 'Z'){
        xw.fillRectangle((col + shiftVec.x) * (windowWidth / 13), (row + shiftVec.y) * (windowHeight / 28), (windowWidth / 13), (windowHeight / 28), Xwindow::Green);
    }
    else if (type == 'T'){
        xw.fillRectangle((col + shiftVec.x) * (windowWidth / 13), (row + shiftVec.y) * (windowHeight / 28), (windowWidth / 13), (windowHeight / 28), Xwindow::Magenta);
    }
    else if (type == '-'){
        xw.fillRectangle((col + shiftVec.x) * (windowWidth / 13), (row + shiftVec.y) * (windowHeight / 28), (windowWidth / 13), (windowHeight / 28), Xwindow::Brown);
    }
    else{
        xw.fillRectangle((col + shiftVec.x) * (windowWidth / 13), (row + shiftVec.y) * (windowHeight / 28), (windowWidth / 13), (windowHeight / 28), Xwindow::White);
    }
}
    

void GraphicsDisplay::outlineCell(int col, int row){
    xw.outlineRectangle((col + shiftVec.x) * (windowWidth / 13), (row + shiftVec.y) * (windowHeight / 28), (windowWidth / 13), (windowHeight / 28));
}
    
    
void GraphicsDisplay::clearGrid(){
    xw.fillRectangle(shiftVec.x * (windowWidth / 13), shiftVec.y * (windowHeight / 28), gridWidth * (windowWidth / 13), gridHeight * (windowHeight / 28), Xwindow::White);
    for (int row = 0; row < gridHeight; ++row){
        xw.fillRectangle(shiftVec.x * (windowWidth / 13), (row + shiftVec.y) *(windowWidth / 13), (windowWidth / 13) * 11, 1);
    }
    xw.fillRectangle(shiftVec.x * (windowWidth / 13), (shiftVec.y + gridHeight) *(windowWidth / 13), (windowWidth / 13) * 11, 1);
    for (int col = 0; col < gridWidth; ++col){
        xw.fillRectangle((col + shiftVec.x) * (windowWidth / 13), shiftVec.y * (windowHeight / 28), 1, (windowHeight / 28) * 18);
    }
    xw.fillRectangle((shiftVec.x + gridWidth) * (windowWidth / 13), shiftVec.y * (windowHeight / 28), 1, (windowHeight / 28) * 18);
}
    

    
void GraphicsDisplay::updateNext(AbstractBlock *nb){
    nextBlock = nb;
    if (nb){
        drawNext(nextBlock);
    }
}
    
    
void GraphicsDisplay::updateLevel(int level){
    theLevel = level;
    stringstream ss;
    ss << theLevel;
    xw.fillRectangle(levelIntVec.x - (windowWidth / 13), levelIntVec.y - (windowHeight / 28), (windowWidth / 13) * 2, (windowHeight / 28) * 2, Xwindow::White);
    xw.drawString(levelIntVec.x, levelIntVec.y, ss.str());
}
    

void GraphicsDisplay::update(Subject &whoNotified) {
    if (dynamic_cast<Cell *>(&whoNotified)){
        Cell *cp = dynamic_cast<Cell *>(&whoNotified);
        fillCell(cp->getCol(), cp->getRow(), cp->getType());
        outlineCell(cp->getCol(), cp->getRow());
    }
    else if (dynamic_cast<Score *>(&whoNotified)){
        Score *sp = dynamic_cast<Score *>(&whoNotified);
        theScore = sp->getScore();
        stringstream scoress;
        scoress << theScore;
        if (theHighScore != sp->getHighScore()){
            theHighScore = sp->getHighScore();
            stringstream highscoress;
            highscoress << theHighScore;
            xw.fillRectangle(scoreIntVec.x - (windowWidth / 13), scoreIntVec.y - (windowHeight / 28), (windowWidth / 13) * 5, (windowHeight / 28) * 2, Xwindow::White);
            xw.drawString(scoreIntVec.x, scoreIntVec.y, scoress.str());
            xw.drawString(highscoreIntVec.x, highscoreIntVec.y, highscoress.str());
        }
        else{
            xw.fillRectangle(scoreIntVec.x - (windowWidth / 13), scoreIntVec.y - (windowHeight / 28), (windowWidth / 13) * 2, (windowHeight / 28) * 2, Xwindow::White);
            xw.drawString(scoreIntVec.x, scoreIntVec.y, scoress.str());
        }
    }
}

