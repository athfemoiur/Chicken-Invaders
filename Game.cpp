#include "Game.h"
#include <QThread>

Game::Game(int width , int height , int lev, QGraphicsView *parent): QGraphicsView(parent)
{
    level = lev;
    //setStyleSheet()
    score=0;
    setBackgroundBrush(QPixmap(":/Backgrounds/Images/gamebackground.png"));
    this->width = width;
    this->height = height;
    chickenRow = 4;
    if(level == 0)
        chikenColumn = 5;
    else
        chikenColumn = 9;
    chickenNum = chickenRow * chikenColumn;
    setMouseTracking(true);
    setFocus();
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
    int startX =width/2-100*chikenColumn+40;
    int startY = 35;
    for (int i = 1;i <= chickenNum; i++) {
        Chicken *chk = new Chicken(width, height, i, chickenRow, chikenColumn );
        chk->setPos(startX, startY);
        scene->addItem(chk);
        startX += 200;
        if(i % chikenColumn ==0){
            startY += 100;
            startX = width/2-100*chikenColumn +40;
        }
     }
    lifeboard = new QGraphicsTextItem;
    lifeboard->setPlainText(QString("LIFE: ") + QString::number((ship->getLife())));
    lifeboard->setDefaultTextColor(Qt::red);
    lifeboard->setFont(QFont("times",16));
    lifeboard->setPos(0,680);
    scene->addItem(lifeboard);
    scoreboard = new QGraphicsTextItem;
    scoreboard->setPlainText(QString("SCORE: ") + QString::number(score));
    scoreboard->setDefaultTextColor(Qt::blue);
    scoreboard->setFont(QFont("times",16));
    scoreboard->setPos(1150,680);
    scene->addItem(scoreboard);
}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    ship->setPos(event->x()-35 , event->y()-35);
}

int Game::getLevel() const
{
    return level;
}

int Game::getChickenNum() const
{
    return chickenNum;
}

int Game::getHeight() const
{
    return height;
}
void Game::updateStats(){
      lifeboard->setPlainText(QString("LIFE: ") + QString::number((ship->getLife())));
      scoreboard->setPlainText(QString("SCORE: ") + QString::number(score));
}

int Game::getScore() const
{
    return score;
}
void Game::increasePoint()
{

    score+=5;

}

int Game::getWidth() const
{
    return width;
}

