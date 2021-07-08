#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "Bullet.h"
#include "Spaceship.h"
#include "Chicken.h"
class Game :   public QGraphicsView
{

    Q_OBJECT

public:

    Game(int , int , int);

    virtual ~Game();

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
    int time_collid;
    int width , height;
    int chickenRow;
    int chikenColumn;
    int score;
    int chickenNum;
    int level;
    bool isCollided;

};
#endif // GAME_H
