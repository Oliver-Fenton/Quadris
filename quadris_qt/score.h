#ifndef SCORE_H
#define SCORE_H

#include <QObject>


class Score : public QObject {
    Q_OBJECT

private:
    int theScore;
    int theHighScore;

public:
    Score();
    ~Score();
    int getScore() const;
    int getHighScore() const;
    void increaseScore(int amount);
    void setHighScore(int highScore);
    void reset();

signals:
    void scoreChanged(int newScore);
    void highScoreChanged(int newHighScore);
};

#endif // SCORE_H
