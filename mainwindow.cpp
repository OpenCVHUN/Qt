#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gameboard.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    GameBoard *board = new GameBoard();
    ui->gameView->setScene(board);
}

MainWindow::~MainWindow()
{
    delete ui;
}
