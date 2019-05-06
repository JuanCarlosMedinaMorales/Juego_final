#ifndef SELECP_H
#define SELECP_H

#include <QDialog>
#include "selecp2.h"
#include "iniciar_juego.h"
#include "QTimer"

namespace Ui {
class selecp;
}

class selecp : public QDialog
{
    Q_OBJECT

public:
    explicit selecp(int seleccion_j,QWidget *parent = nullptr);
    ~selecp();
    void animar(int opcion);


private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
    void labelm();

private:
    Ui::selecp *ui;
    int jugador=9;// Jugador seleccionado
    int seleccionJu;//Modo de juego
    QTimer *mov;
    int contador=0;
};

#endif // SELECP_H
