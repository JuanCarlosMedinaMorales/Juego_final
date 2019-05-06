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
public:
    grafica(QGraphicsItem* PJ = 0);
    void mov(int seleccion,char direccion);//realiza el movimiento a la derecha y a la izquierda, recibiendo como parametros de entrada la direccon a la que se dirige el personaje y el personaje dseleccionado
    void par(float v_limit);//actualiza la posicion
    void pelea();//muestra las posicionesde pelea de los personajes en el mometo indicado
    void salto(int vec,char direccion,int seleccion,int P);//muestra la animacion de el salto, con datos de entrada de vec=cambio de imagen en el maximo, seleccion=el personaje usado por el usuario, p=usuario.
    cuerpo *get_personaje();// posicion del personaje en tiempo real
    void posicion(float v_lim);//calcular la posicion en escala del graphics views
    void porro(float vlim);//calcular la posicion del porro
    ~grafica();
    float get_escala();
    float get_contador();

private:
    cuerpo *persona;
    float escala=1;
    bool flag=1;
    int cont=1,contador=0,contador2=0,seleccion=0;//cont=el tiempo que transcurre en el timer,contador=se selecciona la imagen en la que va de la susecion de el movimiento correspondiente a el primerjugador,contador2=lo ismo de la anterior pero este corresponde al segundo jugador,seleccion=el persnaje seleccionado
    QString c=":/caminar1.png";//posicion po defecto de el personaje
    QList<QString>n;//lista de movimientos de el capucho
    QList<QString>cap;//lista de movimientos de el personaje de artes
    QList<QString>esmad;//lista de movimientos de el personaje correspondiente al smad
    QList<QList<QString>>f;//lista que contiene las listas de los movimientos de los personajes

};


#endif // CUERPOGRAF_H
