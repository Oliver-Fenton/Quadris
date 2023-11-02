#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <iostream>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QKeyEvent>
#include <algorithm>
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFocusPolicy(Qt::StrongFocus);
    this->setFocus();

    // Set the number of rows and columns for the QTableWidget
    ui->gameBoard->setRowCount(18);
    ui->gameBoard->setColumnCount(11);
    ui->nextBlockTable->setRowCount(2);
    ui->nextBlockTable->setColumnCount(11);

    // Set the headers to stretch mode so that columns and rows resize automatically
    ui->gameBoard->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->gameBoard->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->nextBlockTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->nextBlockTable->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->nextBlockTable->setStyleSheet("background-color: transparent;"
                               "gridline-color: transparent;");
    // Set nextBlockTable cell sizes to be the same
    for (int row = 0; row < ui->nextBlockTable->rowCount(); ++row) {
        for (int col = 0; col < ui->nextBlockTable->columnCount(); ++col) {
            setTableCellColour(ui->nextBlockTable, row, col, Qt::transparent);
        }
    }


    ui->gameBoard->setSelectionMode(QAbstractItemView::NoSelection);
    ui->gameBoard->setFocusPolicy(Qt::NoFocus);
    ui->nextBlockTable->setSelectionMode(QAbstractItemView::NoSelection);
    ui->nextBlockTable->setFocusPolicy(Qt::NoFocus);
}

MainWindow::~MainWindow() {
    delete ui;
}

QColor MainWindow::blockTypeToColor(char type) {
    switch (type) {
    case 'I': return Qt::cyan;
    case 'J': return Qt::blue;
    case 'L': return QColorConstants::Svg::orange;
    case 'O': return Qt::yellow;
    case 'S': return Qt::green;
    case 'Z': return Qt::red;
    case 'T': return Qt::magenta;
    case '-': return Qt::gray;
    case '?': return Qt::lightGray;
    default:  return Qt::white;  // Default color for empty cells
    }
}

void MainWindow::setTableCellColour(QTableWidget *table, int row, int col, const QColor &color) {
    QTableWidgetItem *item = new QTableWidgetItem();
    item->setBackground(QBrush(color));
    table->setItem(row, col, item);
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    emit keyPressed(event);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {
    emit keyReleased(event);
}

void MainWindow::updateBoardCell(int row, int col, char type) {
    QColor colour = blockTypeToColor(type);
    setTableCellColour(ui->gameBoard, row, col, colour);
}

void MainWindow::updateScoreDisplay(int newScore) {
    QString scoreVal = QString("%1").arg(newScore);
    ui->ScoreValue->setText(scoreVal);
}

void MainWindow::updateHighScoreDisplay(int newHighScore) {
    QString highScoreVal = QString("%1").arg(newHighScore);
    ui->HiScoreValue->setText(highScoreVal);
}

void MainWindow::updateLevelDisplay(int newLevel) {
    QString levelVal = QString("%1").arg(newLevel);
    ui->LevelValue->setText(levelVal);
}

void MainWindow::updateNextBlockDisplay(std::shared_ptr<AbstractBlock> newBlock) {
    if (!newBlock) return;

    char blockType = newBlock->getType();
    QColor colour = blockTypeToColor(blockType);

    // clear previous block display
    for (int row = 0; row < ui->nextBlockTable->rowCount(); ++row) {
        for (int col = 0; col < ui->nextBlockTable->columnCount(); ++col) {
            setTableCellColour(ui->nextBlockTable, row, col, Qt::transparent);
        }
    }

    std::vector<std::pair<int,int>> coords = newBlock->getCoords(newBlock->getOrientation());
    for (int i = 0; i < 4; i++) {
        setTableCellColour(ui->nextBlockTable, coords[i].first - ((blockType == 'I') ? 2 : 3), coords[i].second, colour);
    }
}
