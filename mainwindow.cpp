#include "mainwindow.h"

mainWindow::mainWindow()
{
    wbtn = 700;
    hbtn = 80;
    setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    showMaximized();
    StartNewGame = new QPushButton( "Start New Game" , this);
    LoadGame = new QPushButton("Load Game" , this);
    Exit = new QPushButton("Exit" , this);
    Credits = new QPushButton("Credits" , this);
    this->layout()->addWidget(StartNewGame);
    this->layout()->addWidget(LoadGame);
    this->layout()->addWidget(Credits);
    this->layout()->addWidget(Exit);
    StartNewGame->setGeometry(x() , y()*2-30 , wbtn , hbtn);
    LoadGame->setGeometry(x() , y()*2+90 , wbtn , hbtn);
    Credits->setGeometry(x() , y()*2+210 , wbtn , hbtn);
    Exit->setGeometry(50 , y()*2+350 , 170  ,hbtn);
    Exit->setIcon(QIcon( QPixmap(":/Icons/Images/cross.png")));
    Exit->setIconSize(QSize(35 , 35));
    setStyleSheet("QMainWindow{background-image:url(:/Backgrounds/Images/mainBackground.png);}QPushButton{background-color: rgba(92, 185, 95, 180);border-radius:40;font: 63 28pt \"Bw Stretch Medium\";border:2px solid rgba(92, 185, 95);}QPushButton:hover{background-color: rgba(92, 185, 95, 220);color:rgb(117, 234, 118);}QPushButton:pressed{background-color: rgba(92, 185, 95, 245);}");
    connect(Exit ,&QPushButton::clicked , this , &mainWindow::exitP );
    connect(StartNewGame , &QPushButton::clicked , this , &mainWindow::showGame);
}

void mainWindow::exitP()
{
    exit(1);
}

void mainWindow::showGame()
{
    game = new Game();
    game->show();
}
