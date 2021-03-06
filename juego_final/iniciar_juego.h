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
#include "iniciar_sesion.h"//para heredar los atributos privados


namespace Ui {
class iniciar_juego;
}
class QMediaPlayer;
class iniciar_juego : public QMainWindow//heredo los atributos privados
{
    Q_OBJECT

public:
    explicit iniciar_juego(int jugador1,int jugador2,QWidget *parent = 0);
    ~iniciar_juego();

private slots:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void on_pegar();
    void mov();
    void par();
    void pegar();
    void salto();
    void grav();
    void mov_proyectil();
    void duracion_escudo();
    void movimiento_bot();
    void poderes_bot();
    void golpear(int peleador);
    void mover(char movida_player);
    void on_actiongo_triggered();

    void on_actionstop_triggered();

    void on_progressBar_valueChanged(int value);

    void on_pushButton_clicked();

private:
    Ui::iniciar_juego *ui;
    QMediaPlayer *mMediaPlayer;
    int h_limit;                //longitud en X del mundo
    int v_limit;                //longitud en Y del mundo
    int diferencia_dista_bot;
    int vel=10000;
    bool i=0;
    int flag=1;
    int cont;
    float posi;
    int S_lanzador;
    bool nube_activa=false;
     bool nube_activa2=false;
    bool lacrimogena=false;
    bool eliminado=false;
    bool eliminado2=false;
    int podeselec;
    int ganaste=0;
    int u=0;
    int tie=0;
    int Rgolpe=0;
    int conta_proyectil=0;
    int conta_proyectil2=0;
    int conta_escudo=0;
    int conta_escudo2=0;
    int seleccion_de_seleccion_de_personaje=0;
    int tiempordesalto=0;

    QTimer *timer_mov;
    QTimer *timer_par;
    QTimer *timer_pel;
    QTimer *timer_salt;
    QTimer *timer_grav;
    QTimer *timer_proy;
    QTimer *timer_escudo;
    QTimer *timer_jugador_auto;
    QGraphicsScene *scene;
    grafica *c;
    grafica *d;
    grafica *lacr;
    grafica *nube;
    grafica *escudo_objet;
    grafica *escudo_objet2;
    grafica *lacr2;
    grafica *nube2;
    float sp=0.0;
    char recuerdo='-';
    char recuerdo2='-';
    char recor_salto='-';
    Cuerpo *proyectil;
    QList<grafica*> lista;

    int vida=100;
    int vida2=100;
    int poder1_1=0;
    int poder2_1=0;
    int poder1_2=0;
    int poder2_2=0;
    int puntaje=0;
    int p1;
    int P2;
    int incremento=2;
    int accion_player=0;
    int tiempo_mov_bot=0;
    bool bloqueo=false;
    bool escudo=false;
    bool escudo2=false;
    bool tecla_presionada_p1=false;
    bool tecla_presionada_p2=false;
    bool bot=false;
    bool tiempo_de_mov=false;

};

#endif // INICIAR_JUEGO_H
