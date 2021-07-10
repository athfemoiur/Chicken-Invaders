#include "mainwindow.h"
#include <QApplication>
#include <Game.h>

Game *game;

int main(int argc, char *argv[])
{
    srand(time(nullptr));
    QApplication a(argc, argv);
    mainWindow window(0);
    window.show();
    return a.exec();
}
