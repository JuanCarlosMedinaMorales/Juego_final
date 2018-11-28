#include "myscene.h"


Myscene::Myscene(int x, int y, int w, int h)
{
    this->setSceneRect(x,y,w,h);

    mover1=false;
    mover2=false;

    QPainter *painter=new QPainter();
    QPixmap pixmap;
    pixmap.load(":/pokebola.png");
    painter->drawPixmap(this->sceneRect(),pixmap,pixmap.rect());
    this->drawBackground(painter,this->sceneRect());

    timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(animar()));
    timer->start(33);
    timerj=new QTimer();
    connect(timerj,SIGNAL(timeout()),this,SLOT(mousePressEvent()));


    barra=new QGraphicsRectItem(-30,-10,60,20);
    this->addItem(barra);
    barra->setPos(200,300);

    barra2=new QGraphicsRectItem(-30,-10,60,20);
    this->addItem(barra2);
    barra2->setPos(200,200);

    l1=new QGraphicsLineItem(0,0,500,0);
    l2=new QGraphicsLineItem(0,0,0,400);
    l3=new QGraphicsLineItem(500,0,500,400);
    l4=new QGraphicsLineItem(0,400,500,400);
    this->addItem(l1);
    this->addItem(l2);
    this->addItem(l3);
    this->addItem(l4);

}

Myscene::~Myscene()
{
    delete l1;
    delete l2;
    delete l3;
    delete l4;
    delete barra;
    delete barra2;
    delete timer;
}

void Myscene::animar()
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

void Myscene::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A)
    {
        mover1=true;
    }
    else if(ev->key()==Qt::Key_D)
    {
        mover2=true;
    }
}

void Myscene::keyReleaseEvent(QKeyEvent *ev)
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

void Myscene::mousePressEvent(QMouseEvent *ev)
{
    timerj->start(100);
    bolas.append(new Bola());
    this->addItem(bolas.last());
    bolas.last()->setPos(ev->x(),ev->y());
}

