#ifndef INICIAR_JUEGO_H
#define INICIAR_JUEGO_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QFile>
#include "cuerpo.h"
#include "cuerpograf.h"
#include <QKeyEvent>
#include <QFileDialog>
#include "QList"


namespace Ui {
class iniciar_juego;
}
class QMediaPlayer;
class iniciar_juego : public QMainWindow
{
    Q_OBJECT

public:
    explicit iniciar_juego(QWidget *parent = 0);
    ~iniciar_juego();

private slots:
    void keyPressEvent(QKeyEvent *event);
    void on_pegar();
    void mov();
    void par();
    void pegar();
    void salto();

    void on_actiongo_triggered();

    void on_actionstop_triggered();

    void on_progressBar_valueChanged(int value);

private:
    Ui::iniciar_juego *ui;
    QMediaPlayer *mMediaPlayer;
    int h_limit;                //longitud en X del mundo
    int v_limit;                //longitud en Y del mundo
    int vel;
    bool i=0;
    int flag=1;
    int cont;
    float posi;
    QTimer *timer_mov;
    QTimer *timer_par;
    QTimer *timer_pel;
    QTimer *timer_salt;
    QGraphicsScene *scene;
    grafica *c;
    grafica *d;
    grafica *lacr;
    int sp=0.0;
    char recuerdo='-';
    char recuerdo2='-';
    char recor_salto='-';
    Cuerpo *proyectil;
    QList<grafica*> lista;

    int vida=100;
    int puntaje=0;
};

#endif // INICIAR_JUEGO_H
