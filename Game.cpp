   #include "Game.h"
#include <QThread>
#include "QDebug"
#include "QMediaPlayer"
#include "Hen.h"

extern Game *game;

Game::Game(int w , int h , int lev) : gTime(0), width(w),height(h), chickenRow(4), score(0) ,level(lev) ,isCollided(false)
{
    isStarted = false;
    isLevFinished = false;
    setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    setcursor();
    setTimer();
    setMouseTracking(true);
    setFocus();
    setBackground();
    setscene();
//    auto musicPlayer = new QMediaPlayer;
//    musicPlayer->setMedia(QUrl("qrc:/Sounds/Sounds/02-01. Main Theme.mp3"));
//    musicPlayer->setVolume(50);
//    musicPlayer->play();
    checkLevel();
    resboard->hide();

}

Game::~Game()
{
    // destructor must not delete ptr

//    delete scene;
//    delete ship;
//    delete scoreboard;
//    delete lifeboard;
//    delete timer;

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

void Game::setChickenNum(int num)
{
    chickenNum = num;
}


void Game::mouseMoveEvent(QMouseEvent *event)
{
    ship->collision();
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
    addResBoard();
    scene->addItem(ship);
    scene->addItem(lifeboard);
    scene->addItem(scoreboard);
    scene->addItem(resboard);
}

void Game::setBackground()
{
    setBackgroundBrush(QPixmap(":/Backgrounds/Images/LevelOneBack.png"));
}

void Game::setNextLevel()
{
    isStarted =false;
    ship->setPos(600 ,600);
    isLevFinished= false;
    gTime= 0;
    ++level;
    checkLevel();
    setscene();

}

void Game::schedule()
{
    gTime++;
    if(gTime == 4){
        isStarted = true;
        if(level<2){
            resboard->hide();
            addChicken();
        }
        else if (level>=2 && level <4){
             resboard->hide();

        }
    }
    if(time_collid + 1 == gTime){
        ship->setPixmap(QPixmap(":/Icons/Images/ship.png"));
        isCollided = false;
    }
    if(isLevFinished){
        setNextLevel();
        resboard->show();
    }
}

void Game::resetLevel()
{
    isStarted = false;
    ship->setPos(600 ,600);
    gTime= 0;
    level=0;
    checkLevel();
    setscene();
}

void Game::checkLevel()
{
    if(level == 0) {
        chikenColumn = 5;
    }
    else if (level ==1) {
        chikenColumn = 9;
    }
    chickenNum = chickenRow * chikenColumn;
}

void Game::updateStats()
{
      lifeboard->setPlainText( QString::number((ship->getLife())));
      scoreboard->setPlainText(QString::number(score));
}

void Game::increasePoint(int p)
{
    score += p;
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
    lifeboard->setPlainText( QString::number((ship->getLife())));
    lifeboard->setDefaultTextColor(Qt::white);
    lifeboard->setFont(QFont("Bw Stretch Medium",30));
    lifeboard->setPos(90,970);
}

void Game::addScoreBoard()
{
    scoreboard = new QGraphicsTextItem;
    scoreboard->setPlainText(QString::number(score));
    scoreboard->setDefaultTextColor(Qt::white);
    scoreboard->setFont(QFont("Bw Stretch Medium",36));
    scoreboard->setPos(130,5);
}

void Game::addResBoard()
{
    resboard = new QGraphicsTextItem;
    resboard->setPlainText(QString("You Won Level : ") + QString::number(level)+QString("!"));
    resboard->setDefaultTextColor(Qt::white);
    resboard->setFont(QFont("Bw Stretch Medium",72));
    resboard->setPos(width/2-300,height/2-60);
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
