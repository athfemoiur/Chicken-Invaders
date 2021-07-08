#include "Game.h"
#include "QThread"
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
    int startX = 600;
    for (int i = 0;i < 5; i++) {
        Chicken * chk = new Chicken(width, height);
        chk->setPos(startX, 35);
        scene->addItem(chk);
        startX += 200;
    }

}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    ship->setPos(event->x()-35 , event->y()-35);
}

int Game::getHeight() const
{
    return height;
}

int Game::getWidth() const
{
    return width;
}

