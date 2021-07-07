#include "Game.h"

Game::Game()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,900,800);
 // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
 // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,800);
    Bullet * bullet = new Bullet;
    bullet->setPos(500, 700);
    bullet->setVisible(true);
    scene->addItem(bullet);

}
