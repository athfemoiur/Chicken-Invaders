#include "Game.h"
#include <QThread>
#include "QDebug"
#include "QMediaPlayer"
#include "Hen.h"
#include "Egg.h"
#include "QException"
#include "Gift.h"
#include "Superchicken.h"
#include "mainwindow.h"
extern Game *game;

Game::Game(int w , int h , int lev  , bool isl , int l, int s) :
    gTime(0), width(w),height(h), score(s) ,level(lev) , meat(0) ,
    lostTime(0), life(l), isCollided(false) , isLost(false),isLoaded(isl)
{

    eggMeatTimer = new QTimer;
    shipTimer = new QTimer;
    chickTimer = new QTimer;
    henTimer = new QTimer;
    supChickTimer = new QTimer;
    gftTimer = new QTimer;


    isStarted = false;
    isLevFinished = false;
    setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    setcursor();
    setTimer();
    setMouseTracking(true);
    setFocus();
    setBackground();
    setscene();
    checkLevel();
    setSound();

//    auto musicPlayer = new QMediaPlayer;
//    musicPlayer->setMedia(QUrl("qrc:/Sounds/Sounds/02-01. Main Theme.mp3"));
//    musicPlayer->play();



    resboard->hide();

    timer->start(1000);
    shipTimer->start(40);
    chickTimer->start(150);
    henTimer->start(150);
    supChickTimer->start(150);
    eggMeatTimer->start(40);
    gftTimer->start(40);

}

Game::~Game()
{

    delete scene;
    delete ship;
    delete scoreboard;
    delete lifeboard;
    delete timer;
    delete shipTimer;
    delete chickTimer;
    delete henTimer;
    delete supChickTimer;
    delete gftTimer;
    delete eggMeatTimer;
    delete scoreboard;
    delete meatboard;
    delete bulletBar;
    delete ship;
    delete scene;
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
    if (!isCollided && isStarted)
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
    setProgressBar();
    addShip();
    addScoreBoard();
    addLifeBoard();
    addResBoard();
    addMeatBoard();
    scene->addItem(ship);
    scene->addItem(lifeboard);
    scene->addItem(scoreboard);
    scene->addItem(resboard);
    scene->addWidget(bulletBar);
    if(level>=2){
        scene->addItem(meatboard);
    }
}

void Game::setBackground()
{
    if(level <2){
    setBackgroundBrush(QPixmap(":/Backgrounds/Images/LevelOneBack.png"));
    }else{
        setBackgroundBrush(QPixmap(":/Backgrounds/Images/LevelTwoeBack.png"));
    }
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
    setBackground();

}

void Game::setProgressBar()
{
    bulletBar = new QProgressBar();
    bulletBar->setGeometry(230,10 , 350 , 50);
    bulletBar->setStyleSheet("background-color:rgba(0,0,0,0);color:rgba(0,0,0,0);");
    bulletBar->setMaximum(15);
    bulletBar->setMinimum(0);
}
void Game::setSound(){
    bulletEffect= new QMediaPlayer;
    bulletEffect->setMedia(QUrl("qrc:/Sounds/Sounds/heat-vision.mp3"));
    effect = new QMediaPlayer;
    playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/Sounds/Sounds/03-02. Mission 1.mp3"));
    playlist->addMedia(QUrl("qrc:/Sounds/Sounds/03-03. Mission 2.mp3"));
    playlist->addMedia(QUrl("qrc:/Sounds/Sounds/03-04. Mission 3.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();
}
void Game::schedule()
{
    ship->subBcounter();
    if(!ship->getIsHeated())
        bulletBar->setValue(ship->getBcounter());
    if(isStarted && ship->getIsHeated() && ship->getHeatTime() +4 ==gTime){
        ship->setIsHeated(false);
        bulletBar->setValue(0);
    }
    if(lostTime +3 == gTime && isLost){
        mainWindow *w = new mainWindow(0);
        w->show();
        game->close();
    }
    if(level == 6 && gameFinishedTime + 2 == gTime){
        mainWindow *w = new mainWindow(0);
        w->show();
        game->close();
    }
    gTime++;
    bulletEffect->stop();
    for (int i = 0; i < Egg::eggs.size(); i++) {
        if(Egg::eggs[i]->isHited && Egg::eggs[i]->hitTime + 1 == gTime){
            delete Egg::eggs[i];
            Egg::eggs.removeAt(i);
        }
    }
    if(gTime == 15 && level>3 ){
        Gift *gift = new Gift(gftTimer);
        gift->setPos( rand() % width,0);
        scene->addItem(gift);
    }
    if(gTime == 4){
        isStarted = true;
        if(level<2){
            resboard->hide();
            addChicken();
        }
        else if (level > 1 && level <4){
             Egg::eggs.clear();
             Hen::hens.clear();
             resboard->hide();
             addChickenAndHen();
        }
        else if(level ==4){
            Egg::eggs.clear();
            Hen::hens.clear();
            resboard->hide();
            addSuperChickenAndHen();
        }else if(level == 5){
            Egg::eggs.clear();
            Hen::hens.clear();
            resboard->hide();
            addSuperChicken();
        }
    }
    if(gTime % 5 == 0 && (level ==2 || level ==3)){
        int tempRand = rand() % 4;
        for (int i = 0; i < 6; i++) {
            if (tempRand < Hen::hens.size() - 1){
                Hen::hens[tempRand]->dropEgg();
            }
            tempRand++;
        }
    }
    if(gTime % 6 == 0 && level > 3){
        int tempRand = rand() % 4;
        for (int i = 0; i < 4; i++) {
            if (tempRand < Hen::hens.size() - 1){
                Hen::hens[tempRand]->dropEgg();
            }
            tempRand++;
        }
    }
    if(time_collid + 3 == gTime && isCollided){
        ship->setPixmap(QPixmap(":/Icons/Images/ship.png"));
        isCollided = false;
    }
    if(isLevFinished){
        setNextLevel();
        resboard->show();
    }
}

void Game::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space && game->isStarted && !ship->getIsHeated() )
     {
          bulletEffect->play();
         ship->shoot();
         ship->setBcounter();
         bulletBar->setValue(ship->getBcounter());
         if(ship->getBcounter()== 15){
             ship->setIsHeated(true);
             ship->setHeatTime(gTime);
             ship->resetBcounter();
         }
    }

    if (event->key() == Qt::Key_Escape) {
        timer->stop();
        shipTimer->stop();
        chickTimer->stop();
        henTimer->stop();
        supChickTimer->stop();
        eggMeatTimer->stop();
        gftTimer->stop();
        isStarted = false;
        music->stop();
        mainWindow *w = new mainWindow(1);
        w->show();
    }
}


void Game::lose()
{
    isLost = true;
    lostTime = gTime;
    setscene();
    music->stop();
    ship->hide();
}
void Game::checkLevel()
{   if(level < 2){
        chickenRow = 4;
    }
    else if(level >1){
         chickenRow = 3;
    }
    if(level == 0) {
        chikenColumn = 5;
    }
    else if (level ==1) {
        chikenColumn = 9;
    }
    else if(level == 2){
        chikenColumn = 8;
    }
    else if(level == 3){
        chikenColumn = 10;
    }
    else if(level == 4){
        chikenColumn = 6;
    }else if(level == 5){
         chikenColumn = 9;    
    }
    else if(level == 6){
         gameFinishedTime = gTime;
    }
    chickenNum = chickenRow * chikenColumn;
}

void Game::increaseMeat()
{
    if(meat==50){
        game->increasePoint(50);
        resetMeat();
    }else{
        meat++;
    }
}

void Game::resetMeat()
{
    meat =0;
}

void Game::updateStats()
{
      lifeboard->setPlainText( QString::number((ship->getLife())));
      scoreboard->setPlainText(QString::number(score));
      if(level>=2){
        meatboard->setPlainText(QString::number(meat));
      }
}

void Game::increasePoint(int p)
{
    score += p;
}

void Game::addShip()
{
    if(level == 0){
        ship = new SpaceShip(shipTimer);
    }
    else if(isLoaded){
        int tl = life;
        ship = new SpaceShip(shipTimer , tl);
        isLoaded = false;
    }else if(level >0 && !isLoaded){
        int tl = ship->getLife();
        ship = new SpaceShip(shipTimer , tl);
    }
    ship->setFlag(QGraphicsItem::ItemIsFocusable);
    ship->setFocus();
}

void Game::addLifeBoard()
{
    lifeboard = new QGraphicsTextItem;
    lifeboard->setPlainText( QString::number((ship->getLife())));
    lifeboard->setDefaultTextColor(Qt::white);
    lifeboard->setFont(QFont("Bw Stretch Medium",30));
    if(level<2){
        lifeboard->setPos(90,970);
    }else{
        lifeboard->setPos(70,970);
    }
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
    if(level == 6){
        resboard->setPlainText(QString("You Won Game !!"));
        resboard->setPos(width/2-280,height/2-60);
        return;
    }
    resboard = new QGraphicsTextItem;
    if(isLost){
        resboard->setPlainText(QString("You Lost :)) !!"));
        resboard->setPos(width/2-140,height/2-60);
    }else{
        resboard->setPlainText(QString("You Won Level : ") + QString::number(level)+QString("!"));
        resboard->setPos(width/2-280,height/2-60);
    }
    resboard->setDefaultTextColor(Qt::white);
    resboard->setFont(QFont("Bw Stretch Medium",72));
}

void Game::addMeatBoard()
{
    meatboard = new QGraphicsTextItem;
    meatboard->setPlainText(QString::number(meat));
    meatboard->setDefaultTextColor(Qt::white);
    meatboard->setFont(QFont("Bw Stretch Medium",30));
    meatboard->setPos(160,970);
}

void Game::addChicken()
{
    int startX =width/2-100*chikenColumn+40;
    int startY = 0;
    for (int i = 1;i <= chickenNum; i++) {
        Chicken *chk = new Chicken(width, height, i, chickenRow, chikenColumn, chickTimer);
        chk->setPos(startX, startY);
        scene->addItem(chk);
        startX += 200;
        if(i % chikenColumn ==0){
            startY += 100;
            startX = width/2-100*chikenColumn +40;
        }
    }
}

void Game::addChickenAndHen()
{

    int startX =width/2-100*chikenColumn+250;
    int startY = 0;
    if(level == 2){
        for(int i=1; i<=chickenNum; i++){

            if(i%2 == 0){
               Chicken *chk = new Chicken(width, height, i, chickenRow, chikenColumn, chickTimer);
               chk->setPos(startX, startY);
               scene->addItem(chk);
               startX += 160;
           }
           else{
               Hen *hen = new Hen(width, height, i, chickenRow, chikenColumn, henTimer, eggMeatTimer);
               Hen::hens.append(hen);
               hen->setPos(startX, startY);
               scene->addItem(hen);
               startX += 160;
           }

           if(i % chikenColumn ==0){
               startY += 100;
               startX = width/2-100*chikenColumn +250;
          }
      }
    }else if (level == 3) {
        for(int i=1; i<=chickenNum; i++){

            if(i%4 == 1 || i%4 ==2){
               Chicken *chk = new Chicken(width, height, i, chickenRow, chikenColumn, chickTimer);
               chk->setPos(startX, startY);
               scene->addItem(chk);
               startX += 160;
           }
           else{
               Hen *hen = new Hen(width, height, i, chickenRow, chikenColumn, henTimer, eggMeatTimer);
               Hen::hens.append(hen);
               hen->setPos(startX, startY);
               scene->addItem(hen);
               startX += 160;
           }
           if(i % chikenColumn ==0){
               startY += 100;
               startX = width/2-100*chikenColumn +250;
          }
      }
    }
}

void Game::addSuperChickenAndHen()
{
    int startX =width/2-100*chikenColumn+250;
    int startY = 0;
        for(int i=1; i<=chickenNum; i++){

            if(i%2 == 0){
               SuperChicken *chk = new SuperChicken(width, height, i, chickenRow, chikenColumn, supChickTimer, eggMeatTimer);
               chk->setPos(startX, startY);
               Hen::hens.append(chk);
               scene->addItem(chk);
               startX += 160;
           }
           else{
               Hen *hen = new Hen(width, height, i, chickenRow, chikenColumn, henTimer, eggMeatTimer);
               Hen::hens.append(hen);
               hen->setPos(startX, startY);
               scene->addItem(hen);
               startX += 160;
           }

           if(i % chikenColumn ==0){
               startY += 100;
               startX = width/2-100*chikenColumn +250;
          }

        }
}

void Game::addSuperChicken()
{
    int startX =width/2-100*chikenColumn+200;
    int startY = 0;
    for (int i = 1;i <= chickenNum; i++) {
        SuperChicken *chk = new SuperChicken(width, height, i, chickenRow, chikenColumn, supChickTimer, eggMeatTimer);
        chk->setPos(startX, startY);
        Hen::hens.append(chk);
        scene->addItem(chk);
        startX += 160;
        if(i % chikenColumn ==0){
            startY += 100;
            startX = width/2-100*chikenColumn +200;
        }
    }
}

void Game::resumGame()
{
    timer->start(1000);
    shipTimer->start(40);
    chickTimer->start(150);
    henTimer->start(150);
    supChickTimer->start(150);
    gftTimer->start(40);
    eggMeatTimer->start(40);
    isStarted = true;
    music->play();
}
