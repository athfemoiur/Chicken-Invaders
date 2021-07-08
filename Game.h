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
    ~Game();

    int getWidth() const;
    int getHeight() const;
    int getScore() const;
    int getChickenNum() const;
    int getLevel() const;
    void increasePoint();
    void updateStats();

private:

    QGraphicsScene * scene;
    QTimer *timer;
    SpaceShip *ship;
    QGraphicsTextItem * lifeboard;
    QGraphicsTextItem * scoreboard;


public slots:

    void schedule();

private:

    void mouseMoveEvent(QMouseEvent *event);
    void addChicken();
    void shipColision();
    void setcursor();
    void setTimer();
    void checkLevel();
    void setscene();
    void setBackground();
    void addShip();
    void addLifeBoard();
    void addScoreBoard();
private:
    int gTime ,time_collid ,width ,height ,chickenRow ,chikenColumn ,score ,chickenNum ,level;
    bool isCollided;

};
#endif // GAME_H
