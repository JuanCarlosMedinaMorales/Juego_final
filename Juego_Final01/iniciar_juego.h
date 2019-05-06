#ifndef INICIAR_JUEGO_H
#define INICIAR_JUEGO_H

#include <QDialog>
#include <QGraphicsScene>
#include <QTimer>
#include <QFile>
#include <cuerpo.h>
#include <cuerpograf.h>
#include <QKeyEvent>
#include <QFileDialog>
#include "QList"
#include "iniciar_sesion.h"//para heredar los atributos privados
#include <QMovie>
#include "qmediaplayer.h"
#include <QFileDialog>
#include <time.h>


namespace Ui {
class iniciar_juego;
}

class iniciar_juego : public iniciar_sesion


{
    Q_OBJECT

public:
    explicit iniciar_juego(int score,int jugador1,int jugador2,QWidget *parent = 0);
    ~iniciar_juego();
private slots:
    void keyPressEvent(QKeyEvent *event);//indica la acccion queusa el personaje cuando se presiona una tecla
    void keyReleaseEvent(QKeyEvent *event);// indica cuando el usuario solto la tecla
    void on_pegar();
    void mov();
    void par();
    void pegar();
    void salto();
    void grav();
    void mov_proyectil();
    void duracion_escudo();
    void movimiento_bot();
    void poderes_J(int lanzador,int poder);//contiene todas las acciones de los poderes, los parametros de entrada son el jugador que la ejecuta y el poder que quiere utilizar
    void golpear(int peleador);//en esta funcion se realiza la accion de pegar de los dos jugadores
    void mover(char movida_player);//mueve a los personajes dependiendo de la entrada que le envien, la entrada es la tecla presionada
    void on_actiongo_triggered();
    void on_actionstop_triggered();


private:
    Ui::iniciar_juego *ui;
    QMediaPlayer *mMediaPlayer;
    int h_limit;                //longitud en X de la escena
    int v_limit;                //longitud en Y de laescena
    int diferencia_dista_bot;//distancia entre los dos personajes
    int vel=10000;//velocidad de los personajes
    bool i=0;
    int flag=1;//bandera usada para saber si el personaje esta en el aire
    int cont;
    float posi;
    int S_lanzador;
    bool nube_activa=false;//bandera para ver si esta en la escena la nube lacrimogena activa
     bool nube_activa2=false;
    bool lacrimogena=false;
    bool eliminado=false;// bandera para saber si ya fue eliminado el poder de la escena
    bool eliminado2=false;
    int podeselec;//el poder seleccionado
    int ganaste=0;//contador de el tiempo que pasa despues de la muerte de un personaje
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
    QTimer *timer_escudo;// duracion y acciones de el escudo
    QTimer *timer_jugador_auto;
    QGraphicsScene *scene;
    grafica *c;//jugador 1
    grafica *d;//jugador2
    grafica *lacr;//la granada lacrimogena de el primer jugador
    grafica *nube;//la nube generada por la granada lacrimogena de el primer jugador
    grafica *escudo_objet;// el escudo de el primer jugador
    grafica *escudo_objet2;//es escudo de el segundo jugador
    grafica *lacr2;//la granada lacrimogena de el segundo jugador
    grafica *nube2;//la nube generada por la granada lacrimogena de el segundo jugador
    float sp=0.0;
    char recuerdo='-';//mustra la tecla que uso el usuario1 para saber que accion tomar
    char recuerdo2='-';//mustra la tecla que uso el usuario2 para saber que accion tomar
    char recor_salto='-';
    cuerpo *proyectil;
    QList<grafica*> lista;

    int vida=100;
    int vida2=100;//vida de el primer jugador
    int poderJ1=0;//barra de poder del primer jugador
    int poderJ2=0;//barra de poder del segundo jugador
    int puntaje=0;
    int p1;//primer jugador
    int P2;
    int incremento=2;
    int accion_player=0;
    int tiempo_mov_bot=0;
    bool bloqueo=false;//bandera usada para bloquear las teclas cuando se necesite
    bool escudo=false;//avisa que el jugador uno lanzo el escudo
    bool escudo2=false;//avisa que el jugador dos lanzo el escudo
    bool tecla_presionada_p1=false;//indica si la tecla esta siendo presionada en ese momento
    bool tecla_presionada_p2=false;
    bool bot=false;//indica si el usuario esta jugando con un bot
    bool tiempo_de_mov=false;
};

#endif // INICIAR_JUEGO_H
