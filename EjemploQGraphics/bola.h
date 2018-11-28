#ifndef BOLA_H
#define BOLA_H
#include <QGraphicsItem>
#include <QPainter>


class Bola: public QGraphicsItem
{
public:
    Bola();
    QRectF boundingRect() const;
    void paint(QPainter *painter,
    const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mover();
    void choque();

    int vy;
};

#endif // BOLA_H
