#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include "Game.h"

class mainWindow : public QMainWindow
{

public:
    mainWindow(int state);

private slots:
    void exitP();
    void showGame();
    void resGame();
    void goBackMainPanel();
public:
    QPushButton *LoadGame , *Exit , *StartNewGame , *Credits ;
    int wbtn , hbtn ,st;
};

#endif // MAINWINDOW_H
