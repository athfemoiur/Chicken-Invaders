#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "Bullet.h"
#include "Spaceship.h"
#include "Chicken.h"
#include <QVector>



class Game :   public QGraphicsView
{

    Q_OBJECT
    friend class Controller;

public:

    Game(int , int , int);
    ~Game();


    int getWidth() const;
    int getHeight() const;
    int getScore() const;
    int getChickenNum() const;
    void setChickenNum(int);
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
    void shipColision();
    void setcursor();
    void setTimer();
    void checkLevel();
    void setscene();
    void setBackground();
    void addShip();
    void addLifeBoard();
    void addScoreBoard();
    void addChicken();
private:
    int gTime ,time_collid ,width ,height ,chickenRow ,chikenColumn ,score ,chickenNum ,level;
    bool isCollided;

};
#endif // GAME_H
