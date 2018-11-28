#include "bola.h"

Bola::Bola()
{
    vy=7;
}

QRectF Bola::boundingRect() const
{
    return QRectF(-10,-10,20,20);
}

void Bola::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->setBrush(Qt::darkBlue);
//    painter->drawRect(boundingRect());
    QPixmap pixmap;
    pixmap.load(":/pokebola.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void Bola::mover()
{
    setPos(x(),y()+vy);
}

void Bola::choque()
{
    vy=-vy/1.3;
}
