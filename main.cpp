#include "mainwindow.h"

#include <QApplication>
#include <Game.h>
Game *game;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWindow window;
    window.show();
    return a.exec();
}
