#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include "Game.h"
class mainWindow : public QMainWindow
{
public:
    mainWindow();

private slots:
    void exitP();
    void showGame();
private:
    QPushButton *LoadGame , *Exit , *StartNewGame , *Credits ;
    QVBoxLayout *mainLayout;
    int wbtn , hbtn;
    Game *game;
};

#endif // MAINWINDOW_H
