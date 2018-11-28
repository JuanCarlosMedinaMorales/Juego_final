#ifndef CUERPOGRAF_H
#define CUERPOGRAF_H

#include <QPainter>
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "cuerpo.h"

class grafica:public QObject,
              public QGraphicsPixmapItem

{
    Q_OBJECT
private:


    Cuerpo *car;
    float escala=1;
    bool flag=1;
    int cont=1;
    int contador=0;
    int contador2=0;
public:
    grafica(QGraphicsItem* carr = 0);
    void mov();
    void par(float v_limit);
    void pelea();
    void salto(int vec);
    Cuerpo* get_carro();
    void posicion(float v_lim);
    ~grafica();
    float get_escala();
    float get_contador();
};
#endif // CUERPOGRAF_H
