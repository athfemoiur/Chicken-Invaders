#include "Game.h"

Game::Game()
{

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1289,720);
 // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
 // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1289,720);


    ship = new SpaceShip();
    ship->setFlag(QGraphicsItem::ItemIsFocusable);
    ship->setFocus();
    scene->addItem(ship);

}
