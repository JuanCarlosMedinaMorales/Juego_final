#ifndef MODO_DE_JUEGO_H
#define MODO_DE_JUEGO_H

#include <QDialog>
#include <QPoint>
#include "selecp.h"
#include "selecp2.h"
#include "instrucciones.h"
#include <QTimer>
#include <QWidget>

namespace Ui {
class modo_de_juego;
}

class modo_de_juego : public QDialog
{
    Q_OBJECT

public:
    explicit modo_de_juego(QWidget *parent = nullptr);
    ~modo_de_juego();
    void mouseMoveEvent(QMouseEvent *event);

private slots:
    void on_pushButton_clicked();//boton de un jugador

    void on_pushButton_2_clicked();//Boton de dos jugadores

    void on_pushButton_3_clicked();//boton de instrucciones
    void acr();
private:
    Ui::modo_de_juego *ui;
    int posx;//posicion de el cursor en x
    int posy;//posicion de el cursor en y
    QTimer *timer;//rectifica la posicion del cursor y muestra las imagenes
};

#endif // MODO_DE_JUEGO_H
