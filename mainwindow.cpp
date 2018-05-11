#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gameboard.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_board = new GameBoard();
    ui->gameView->setScene(m_board);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    m_board->startGame();
}

void MainWindow::on_pushButton_2_clicked()
{
    m_board->endGame();
}
