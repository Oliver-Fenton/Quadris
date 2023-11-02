#ifndef COMMANDINTERPRETER_H
#define COMMANDINTERPRETER_H

#include <QObject>
#include <QKeyEvent>
#include <QTimer>


class CommandInterpreter : public QObject {
    Q_OBJECT

private:
    QTimer moveDownTimer;
    QTimer doubleRPressTimer;
    bool isFirstRKeyPress = false;

public:
    explicit CommandInterpreter(QObject *parent = nullptr);

public slots:
    void interpretKeyPress(QKeyEvent *event);
    void interpretKeyRelease(QKeyEvent *event);

signals:
    void commandReceived(const std::string &command);
};

#endif // COMMANDINTERPRETER_H
