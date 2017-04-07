#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer=new QTimer(this);

    if(timer==NULL)
    {

}
            else {
            connect(timer,SIGNAL(timeout()),this,SLOT(changetime()));
            timer->start(250);

}
            connect(this,SIGNAL(get_time(int)),this,SLOT(on_dial_actionTriggered(int)));
            connect(this,SIGNAL(get_time(int)),ui->lcdNumber,SLOT(display(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_dial_actionTriggered(int action)
{
    ui->dial->setValue(action);
}


void MainWindow:: changetime()
    {
             i=++i%60;
    emit get_time(i);
}

