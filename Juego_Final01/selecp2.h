#ifndef SELECP2_H
#define SELECP2_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class selecp2;
}

class selecp2 : public QDialog
{
    Q_OBJECT

public:
    explicit selecp2(int primer_jugador,QWidget *parent = nullptr);//el constructor nesecita el numero de jugadr seleccionado por el jugador uno para iniciar el juego
    ~selecp2();
     void animar(int opcion);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();
    void labelm();

private:
    Ui::selecp2 *ui;
    int jugadordos=9;// Jugador seleccionado
    QTimer *mov;//timer para generar el movimiento
    int contador=0;
    int p1=0;//personaje seleccionado por jugador1
};

#endif // SELECP2_H
