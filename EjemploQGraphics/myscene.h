#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QKeyEvent>
#include <QTimer>
#include "bola.h"

class Myscene: public QGraphicsScene
{

public:
    Myscene(int x, int y, int w, int h);
    ~Myscene();

public slots:
    void animar();

private:
    QGraphicsRectItem* barra;
    QGraphicsRectItem* barra2;
    QGraphicsLineItem* l1;
    QGraphicsLineItem* l2;
    QGraphicsLineItem* l3;
    QGraphicsLineItem* l4;
    bool mover1;
    bool mover2;
    QList<Bola*> bolas;

    QTimer *timer;
    QTimer *timerj;
    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
};

#endif // MYSCENE_H
