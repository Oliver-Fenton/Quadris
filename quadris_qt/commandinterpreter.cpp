#include "commandinterpreter.h"


CommandInterpreter::CommandInterpreter(QObject *parent) : QObject{parent}, isFirstRKeyPress{false} {
    connect(&moveDownTimer, &QTimer::timeout, [this](){
        emit commandReceived("Down");
    });
}

void CommandInterpreter::interpretKeyPress(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_Left:
            emit commandReceived("Left");
            break;

        case Qt::Key_Right:
            emit commandReceived("Right");
            break;

        case Qt::Key_Down:
            emit commandReceived("Down");
            if (!moveDownTimer.isActive()) {
                moveDownTimer.start(200);
            }
            break;

        case Qt::Key_Space:
            emit commandReceived("Drop");
            break;

        case Qt::Key_C:
            emit commandReceived("ClockWise");
            break;

        case Qt::Key_X:
            emit commandReceived("CounterClockWise");
            break;

        case Qt::Key_Plus:
        case Qt::Key_Equal:
            emit commandReceived("LevelUp");
            break;

        case Qt::Key_Minus:
            emit commandReceived("LevelDown");
            break;

        case Qt::Key_R:
            if (isFirstRKeyPress) {
                doubleRPressTimer.stop();
                isFirstRKeyPress = false;
                emit commandReceived("Restart");
            } else {
                isFirstRKeyPress = true;
                doubleRPressTimer.start(300);
            }
            break;

        case Qt::Key_H:
            emit commandReceived("Hint");
            break;
    }
}

void CommandInterpreter::interpretKeyRelease(QKeyEvent *event) {
    if (event->key() == Qt::Key_Down) {
        moveDownTimer.stop();
    }
}
