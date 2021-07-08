#include "Game.h"

Game::Game(int width , int height , QGraphicsView *parent): QGraphicsView(parent)
{
    setBackgroundBrush(QPixmap(":/Backgrounds/Images/gamebackground.png"));
    this->width = width;
    this->height = height;
    setMouseTracking(true);
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,width,height);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(width ,height);
    ship = new SpaceShip();
    ship->setFlag(QGraphicsItem::ItemIsFocusable);
    ship->setFocus();
    scene->addItem(ship);







}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    ship->setPos(event->x()-35 , event->y()-35);
}
