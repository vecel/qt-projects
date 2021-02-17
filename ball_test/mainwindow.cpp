#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::moveButton(){
    int x = 1, y = 1;
    while(true){
        ui->button1->setGeometry(x, y, 80, 25);
        x++;
        y++;
    }
}

void MainWindow::on_button1_clicked()
{
    //ui->button1->setGeometry(200, 200, 85, 25);
    this->moveButton();
}
