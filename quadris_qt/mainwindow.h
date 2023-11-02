#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QColor>
#include <QTableWidget>

#include "grid.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    double aspectRatio = 9.0 / 16.0;
    Ui::MainWindow *ui;
    Grid *gameGrid;

    QColor blockTypeToColor(char type);
    void setTableCellColour(QTableWidget *table, int row, int col, const QColor &color);

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void updateBoardCell(int row, int col, char type);

public slots:
    void updateScoreDisplay(int newScore);
    void updateHighScoreDisplay(int newHighScore);
    void updateLevelDisplay(int newLevel);
    void updateNextBlockDisplay(std::shared_ptr<AbstractBlock> newBlock);

signals:
    void keyPressed(QKeyEvent *event);
    void keyReleased(QKeyEvent *event);
};

#endif // MAINWINDOW_H
