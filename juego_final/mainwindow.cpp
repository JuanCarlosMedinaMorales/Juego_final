#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"menu.h"
#include <QGraphicsPixmapItem>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    h_limit=661;                  //Asigna los valores leidos el archivo
    v_limit=361;
    scene=new QGraphicsScene(this);
    scene->setSceneRect(0,0,h_limit,v_limit);
    ui->graphicsView->setScene(scene);
    ui->centralWidget->adjustSize();
    ui->graphicsView->setBackgroundBrush(QImage(":/6282614902_ded28303e1_b.jpg"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
  Menu *MyDialog = new Menu(); MyDialog->show();
  close();
}
