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
    Game(int , int , QGraphicsView *parent = nullptr);
    int getWidth() const;

    int getHeight() const;

private:

    QGraphicsScene * scene;
    SpaceShip *ship;
private:

    void mouseMoveEvent(QMouseEvent *event);
private:
    int width , height;
};

#endif // GAME_H
