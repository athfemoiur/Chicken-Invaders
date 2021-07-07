#include "Mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->setupUi(this);
    ui->load_game_btn->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exit_btn_clicked()
{
     exit(1);
}
