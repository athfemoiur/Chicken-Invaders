#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QPushButton>
#include "Bullet.h"
#include "Spaceship.h"
#include "Chicken.h"
class Game : public QGraphicsView
{


public:

    Game(int , int , int);

    int getWidth() const;

    int getHeight() const;

public:

    QGraphicsScene * scene;
    QTimer *timer;
    SpaceShip *ship;
    QGraphicsTextItem * lifeboard;
    QGraphicsTextItem * scoreboard;
    void increasePoint();
    void updateStats();
    int getScore() const;
    int getChickenNum() const;
    int getLevel() const;
    void addChicken();

public slots:
    void increaseTime();


private:

    void mouseMoveEvent(QMouseEvent *event);
private:
    int time;
    int width , height;
    int chickenRow;
    int chikenColumn;
    int score;
    int chickenNum;
    int level;

};
#endif // GAME_H
