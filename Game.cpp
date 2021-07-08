#include "Game.h"
#include <QThread>
#include "QDebug"

Game::Game(int width , int height , int lev)
{
    QCursor cursor(Qt::BlankCursor);
    setCursor(cursor);
    isCollided = false;
    timer = new QTimer;
    time = 0;
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(increaseTime()));
    timer->start(1000);



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

Game::~Game()
{
    delete ship;
}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    QList<QGraphicsItem *> colliding_items = ship->collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Chicken)){
                ship->decreaseLife();
                time_collid = time;
                isCollided = true;
                ship->setPixmap(QPixmap(":/Icons/Images/explosion_PNG15391.png"));
                updateStats();
                delete colliding_items[i];
            // return (all code below refers to a non existint bullet)
                if(ship->getLife()==0){
                    close();
                }
                return;
        }
    }
    if (!isCollided)
        ship->setPos(event->x()-35 , event->y()-35);
}

int Game::getLevel() const
{
    return level;
}

void Game::increaseTime()
{
    time++;
    if(time == 4){
        addChicken();
    }
    if(time_collid + 2 == time){
        ship->setPixmap(QPixmap(":/Icons/Images/ship.png"));
        isCollided = false;
    }
}

void Game::addChicken()
{
    int startX =width/2-100*chikenColumn+40;
    int startY = 5;
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

