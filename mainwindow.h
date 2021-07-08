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
public:
    QPushButton *LoadGame , *Exit , *StartNewGame , *Credits ;
    int wbtn , hbtn;
};

#endif // MAINWINDOW_H
