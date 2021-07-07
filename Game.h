#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Bullet.h"
#include "Spaceship.h"
class Game : public QGraphicsView
{
public:
    Game();
    QGraphicsScene * scene;
    SpaceShip *ship;

};

#endif // GAME_H
