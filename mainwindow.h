#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include "Game.h"
#include "QtSql"

class mainWindow : public QMainWindow
{

public:
    mainWindow(int state);

private slots:
    QSqlDatabase db;
    void exitP();
    void showGame();
    void resGame();
    void goBackMainPanel();
    void loadGame();
    void saveGame();
public:
    QPushButton *LoadGame , *Exit , *StartNewGame , *Credits ;
    int wbtn , hbtn;
};

#endif // MAINWINDOW_H
