#include "mainwindow.h"

#include "QSqlQuery"
extern Game *game;

mainWindow::mainWindow(int state)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/cpp/Chicken-Invaders/data.db");
    db.open();

    // hardCode for design
    wbtn = 700;
    hbtn = 80;
    setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    showMaximized();

    if(state ==0){
        StartNewGame = new QPushButton( "Start New Game" , this);
        LoadGame = new QPushButton("Load Game" , this);
        Credits = new QPushButton("Credits" , this);
        this->layout()->addWidget(Credits);
        Credits->setGeometry(x() , y()*2+210 , wbtn , hbtn);
        connect(StartNewGame , &QPushButton::clicked , this , &mainWindow::showGame);
        connect(LoadGame , &QPushButton::clicked , this , &mainWindow::loadGame);
    }
    else{
        StartNewGame = new QPushButton( "Resume Game" , this);
        LoadGame = new QPushButton("Go back to mainPanel" , this);
        connect(StartNewGame , &QPushButton::clicked , this , &mainWindow::resGame);
        connect(LoadGame , &QPushButton::clicked , this , &mainWindow::goBackMainPanel);
        Credits = new QPushButton("Save and Quit" , this);
        this->layout()->addWidget(Credits);
        Credits->setGeometry(x() , y()*2+210 , wbtn , hbtn);
        connect(Credits , &QPushButton::clicked , this , &mainWindow::saveGame);
    }
     Exit = new QPushButton("Exit" , this);
     LoadGame->setGeometry(x() , y()*2+90 , wbtn , hbtn);
     StartNewGame->setGeometry(x() , y()*2-30 , wbtn , hbtn);
     this->layout()->addWidget(StartNewGame);
     this->layout()->addWidget(LoadGame);
    this->layout()->addWidget(Exit);
    StartNewGame->setFocusPolicy(Qt::FocusPolicy::NoFocus);



    Exit->setGeometry(50 , y()*2+350 , 170  ,hbtn);
    Exit->setIcon(QIcon( QPixmap(":/Icons/Images/cross.png")));
    Exit->setIconSize(QSize(35 , 35));
    setStyleSheet("QMainWindow{background-image:url(:/Backgrounds/Images/mainbackround.png);}QPushButton{background-color: rgba(92, 185, 95, 180);border-radius:40;font: 63 28pt \"Bw Stretch Medium\";border:2px solid rgb(92, 185, 95);}QPushButton:hover{background-color: rgba(92, 185, 95, 220);color:rgb(117, 234, 118);}QPushButton:pressed{background-color: rgba(92, 185, 95, 245);}");
    connect(Exit ,&QPushButton::clicked , this , &mainWindow::exitP );


}

void mainWindow::exitP()
{
    exit(1);
}

void mainWindow::showGame()
{
    game = new Game(width() , height() , 0 ,false , 0);
    game->show();
    this->hide();
}

void mainWindow::resGame()
{
    this->hide();
    game->resumGame();
}

void mainWindow::goBackMainPanel()
{
    mainWindow *w = new mainWindow(0);
    w->show();
    this->close();
    game->close();
}

void mainWindow::loadGame()
{
    QSqlQuery query;
    query.exec("SELECT level FROM saved_data");
    query.last();
    int level = query.value(0).toInt();
    int life = 3;
    game = new Game(width() , height() , level , true , life);
    game->show();
    this->hide();
}

void mainWindow::saveGame()
{
    QSqlQuery query;
    QString queryString = QString("INSERT INTO saved_data(level) VALUES(%1)").arg(QString::number(game->getLevel()));
    query.exec(queryString);
    exit(0);
}
