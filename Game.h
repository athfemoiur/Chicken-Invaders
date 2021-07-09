#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "Bullet.h"
#include "Spaceship.h"
#include "Chicken.h"
#include <Controller.h>




class Game : public QGraphicsView
{

    Q_OBJECT
    friend class Controller;
    friend class SpaceShip;
    friend class Bullet;

public:

    Game(int , int , int);
    ~Game();


    int getWidth() const;
    int getHeight() const;
    int getScore() const;
    int getChickenNum() const;
    void setChickenNum(int);
    int getLevel() const;
    void increasePoint(int);
    void updateStats();
    int gTime;
    bool isLevFinished;
    Controller *cnt;
    int gameFinishedTime;

private:

    QGraphicsScene * scene;
    QTimer *timer;
    SpaceShip *ship;
    QGraphicsTextItem * lifeboard;
    QGraphicsTextItem * scoreboard;
    QGraphicsTextItem * resboard;
    QGraphicsTextItem * meatboard;

public slots:

    void schedule();

private:



    void mouseMoveEvent(QMouseEvent *event);
    void resetLevel();
    void checkLevel();
    void increaseMeat();
    void resetMeat();
    void setcursor();
    void setTimer();    
    void setscene();
    void setBackground();
    void setNextLevel();
    void addShip();
    void addLifeBoard();
    void addScoreBoard();
    void addResBoard();
    void addMeatBoard();
    void addChicken();
    void addChickenAndHen();
    void addSuperChickenAndHen();
    void addSuperChicken();
private:
    int time_collid ,width ,height ,chickenRow ,chikenColumn ,score ,chickenNum ,level , meat;
    bool isCollided , isStarted;

};
#endif // GAME_H
