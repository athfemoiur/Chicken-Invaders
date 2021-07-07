#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Bullet.h"

class Game : public QGraphicsView
{
public:
    Game();
    QGraphicsScene * scene;
};

#endif // GAME_H
