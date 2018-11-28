#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene=new QGraphicsScene(0,0,500,400);
    ui->graphicsView->setScene(scene);


    mover1=false;
    mover2=false;

    ui->graphicsView->setBackgroundBrush(QImage(":/Pueblo"));

    timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(animar()));
    timer->start(20);

    barra=new QGraphicsRectItem(-30,-10,60,20);
    scene->addItem(barra);
    barra->setPos(200,300);

    barra2=new QGraphicsRectItem(-30,-10,60,20);
    scene->addItem(barra2);
    barra2->setPos(200,200);

    l1=new QGraphicsLineItem(0,0,500,0);
    l2=new QGraphicsLineItem(0,0,0,400);
    l3=new QGraphicsLineItem(500,0,500,400);
    l4=new QGraphicsLineItem(0,400,500,400);
    scene->addItem(l1);
    scene->addItem(l2);
    scene->addItem(l3);
    scene->addItem(l4);
}

MainWindow::~MainWindow()
{
    delete scene;
    delete ui;
}


void MainWindow::animar()
{
    if(mover1)
    {
        barra->setPos(barra->x()-2,barra->y());
    }
    if(mover2)
    {
        barra2->setPos(barra2->x()-2,barra2->y());
    }

    if(barra->collidesWithItem(l2) || barra->collidesWithItem(l3))
    {
        mover1=false;
        flag=false;
    }

    for(int i=0; i<bolas.length();i++)
    {
        bolas.at(i)->mover();
        if(!bolas.at(i)->collidingItems().empty())
        {
            bolas.at(i)->choque();
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A && flag==true)
    {
        mover1=true;
    }
    else if(ev->key()==Qt::Key_D)
    {
        mover2=true;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A)
    {
        mover1=false;
    }
    else if(ev->key()==Qt::Key_D)
    {
        mover2=false;
    }
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    bolas.append(new Bola());
    scene->addItem(bolas.last());
    bolas.last()->setPos(ev->x(),ev->y());
}


