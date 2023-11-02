#include <QApplication>
#include <QDir>

#include "mainwindow.h"
#include "quadris.h"
#include "commandinterpreter.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CommandInterpreter cI;
    MainWindow w;
    w.show();

    QString appDir = QCoreApplication::applicationDirPath();
    QString sequenceFilePath = appDir + "/sequence.txt";

    QFile sequenceFile(sequenceFilePath);
    if (!sequenceFile.exists()) {
        if (sequenceFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&sequenceFile);
            out << "I J L O S T Z\n";
            sequenceFile.close();
        }
    }

    Quadris game(std::cin, std::cout, sequenceFilePath.toStdString(), 0);

    Grid& grid = game.getGrid();
    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j < 11; ++j) {
            const Cell& cell = grid.getCell(i, j);
            QObject::connect(&cell, &Cell::cellChanged, &w, [&w](int row, int col, char type) {
                w.updateBoardCell(row, col, type);
            });

            w.updateBoardCell(i, j, cell.getType());
        }
    }

    QObject::connect(&w, &MainWindow::keyPressed, &cI, &CommandInterpreter::interpretKeyPress);
    QObject::connect(&w, &MainWindow::keyReleased, &cI, &CommandInterpreter::interpretKeyRelease);
    QObject::connect(&cI, &CommandInterpreter::commandReceived, &game, &Quadris::executeCommand);

    QObject::connect(&game.getScore(), &Score::scoreChanged, &w, &MainWindow::updateScoreDisplay);
    QObject::connect(&game.getScore(), &Score::highScoreChanged, &w, &MainWindow::updateHighScoreDisplay);
    QObject::connect(&game, &Quadris::levelChanged, &w, &MainWindow::updateLevelDisplay);
    QObject::connect(&game, &Quadris::nextBlockChanged, &w, &MainWindow::updateNextBlockDisplay);

    emit game.getScore().highScoreChanged(game.getScore().getHighScore());

    return a.exec();
}
