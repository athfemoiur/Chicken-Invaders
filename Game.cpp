#include "Game.h"
#include "QThread"
Game::Game(int width , int height , QGraphicsView *parent): QGraphicsView(parent)
{
    setBackgroundBrush(QPixmap(":/Backgrounds/Images/gamebackground.png"));
    this->width = width;
    this->height = height;
    chickenRow = 4;
    chikenColumn = 5;
    chickenNum = chickenRow * chikenColumn;
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
    int startY = 35;
    for (int i = 1;i <= chickenNum; i++) {
        Chicken * chk = new Chicken(width, height, i, chickenRow, chikenColumn);
        chk->setPos(startX, startY);
        scene->addItem(chk);
        startX += 200;
        if(i % chikenColumn ==0){
            startY += 100;
            startX = 600;
    }
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

