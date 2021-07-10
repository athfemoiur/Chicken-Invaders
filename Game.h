#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "Bullet.h"
#include "Spaceship.h"
#include "Chicken.h"




class Game : public QGraphicsView
{

    Q_OBJECT
    friend class Controller;
    friend class SpaceShip;
    friend class Bullet;

public:

    Game(int , int , int ,bool , int);
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
    int gameFinishedTime;
    void resumGame();
private:

    QGraphicsScene * scene;


    QTimer *timer;
    QTimer *shipTimer;
    QTimer *chickTimer;
    QTimer *henTimer;
    QTimer *supChickTimer;
    QTimer *gftTimer;
    QTimer *eggMeatTimer;

    SpaceShip *ship;

    QGraphicsTextItem * lifeboard;
    QGraphicsTextItem * scoreboard;
    QGraphicsTextItem * resboard;
    QGraphicsTextItem * meatboard;

public slots:

    void schedule();

private:


    void keyPressEvent(QKeyEvent * event);
    void mouseMoveEvent(QMouseEvent *event);
    void lose();
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
    int time_collid ,width ,height ,chickenRow ,chikenColumn ,score ,chickenNum ,level , meat ,lostTime , life ;
    bool isCollided , isStarted , isLost , isLoaded;

};
#endif // GAME_H
