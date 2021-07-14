#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPushButton>
#include "Game.h"
#include "QtSql"

class mainWindow : public QMainWindow
{

public:
    mainWindow(int state);
    ~mainWindow();
private:
    void playSound();
    void stopSound();

private slots:
    QSqlDatabase db;
    void exitP();
    void showGame();
    void resGame();
    void goBackMainPanel();
    void loadGame();
    void saveGame();
    void openCredits();
public:
    QPushButton *LoadGame , *Exit , *StartNewGame , *Credits ;
    int wbtn , hbtn;
    QMessageBox *msg;
    QMediaPlayer *music;
    QMediaPlaylist *playlist;
};

#endif // MAINWINDOW_H
