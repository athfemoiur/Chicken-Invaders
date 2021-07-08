#include "Game.h"
#include <QThread>
#include "QDebug"

Game::Game(int w , int h , int lev) : gTime(0), width(w),height(h), chickenRow(4), score(0) ,level(lev) ,isCollided(false)
{
    setcursor();
    setTimer();
    setMouseTracking(true);
    setFocus();
    setBackground();
    setscene();
    checkLevel();
    chickenNum = chickenRow * chikenColumn;
}

Game::~Game()
{
    delete ship;
}


int Game::getLevel() const
{
    return level;
}

int Game::getWidth() const
{
    return width;
}

int Game::getHeight() const
{
    return height;
}

int Game::getScore() const
{
    return score;
}

int Game::getChickenNum() const
{
    return chickenNum;
}


void Game::mouseMoveEvent(QMouseEvent *event)
{
    shipColision();
    if (!isCollided)
        ship->setPos(event->x()-35 , event->y()-35);
}

void Game::setcursor()
{
    QCursor cursor(Qt::BlankCursor);
    setCursor(cursor);
}

void Game::setTimer()
{
    timer = new QTimer;
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(schedule()));
    timer->start(1000);

}

void Game::setscene()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,width,height);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(width ,height);
    addShip();
    addScoreBoard();
    addLifeBoard();
    scene->addItem(ship);
    scene->addItem(lifeboard);
    scene->addItem(scoreboard);
}

void Game::setBackground()
{
    setBackgroundBrush(QPixmap(":/Backgrounds/Images/LevelOneBack.png"));
}

void Game::schedule()
{
    gTime++;
    if(gTime == 4){
        addChicken();
    }
    if(time_collid + 2 == gTime){
        ship->setPixmap(QPixmap(":/Icons/Images/ship.png"));
        isCollided = false;
    }
}

void Game::shipColision()
{
    QList<QGraphicsItem *> colliding_items = ship->collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Chicken)){
                ship->decreaseLife();
                time_collid = gTime;
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
}

void Game::checkLevel()
{
    if(level == 0) {
        chikenColumn = 5;
    }
    else {
        chikenColumn = 9;
    }
}

void Game::updateStats(){
      lifeboard->setPlainText(QString("LIFE: ") + QString::number((ship->getLife())));
      scoreboard->setPlainText(QString("SCORE: ") + QString::number(score));
}

void Game::increasePoint()
{

    score+=5;

}


void Game::addShip()
{
    ship = new SpaceShip();
    ship->setFlag(QGraphicsItem::ItemIsFocusable);
    ship->setFocus();
}

void Game::addLifeBoard()
{
    lifeboard = new QGraphicsTextItem;
    lifeboard->setPlainText(QString("LIFE: ") + QString::number((ship->getLife())));
    lifeboard->setDefaultTextColor(Qt::red);
    lifeboard->setFont(QFont("times",16));
    lifeboard->setPos(0,680);
}

void Game::addScoreBoard()
{
    scoreboard = new QGraphicsTextItem;
    scoreboard->setPlainText(QString("SCORE: ") + QString::number(score));
    scoreboard->setDefaultTextColor(Qt::blue);
    scoreboard->setFont(QFont("times",16));
    scoreboard->setPos(1150,680);
}

void Game::addChicken()
{
    int startX =width/2-100*chikenColumn+40;
    int startY = 0;
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


