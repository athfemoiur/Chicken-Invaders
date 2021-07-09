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
    void increasePoint(int);
    void updateStats();
    int gTime;
    bool isLevFinished;

private:

    QGraphicsScene * scene;
    QTimer *timer;
    SpaceShip *ship;
    QGraphicsTextItem * lifeboard;
    QGraphicsTextItem * scoreboard;
    QGraphicsTextItem * resboard;

public slots:

    void schedule();

private:



    void mouseMoveEvent(QMouseEvent *event);
    void shipColision();
    void checkLevel();
    void setcursor();
    void setTimer();    
    void setscene();
    void setBackground();
    void setNextLevel();
    void addShip();
    void addLifeBoard();
    void addScoreBoard();
    void addResBoard();
    void addChicken();

private:
    int time_collid ,width ,height ,chickenRow ,chikenColumn ,score ,chickenNum ,level;
    bool isCollided;

};
#endif // GAME_H
