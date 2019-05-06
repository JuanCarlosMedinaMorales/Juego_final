#include "iniciar_juego.h"
#include "ui_iniciar_juego.h"

iniciar_juego::iniciar_juego(int score,int jugador1,int jugador2,QWidget *parent) :
    iniciar_sesion(parent),
    ui(new Ui::iniciar_juego)
{
    ui->setupUi(this);
    mMediaPlayer = new QMediaPlayer(this);//se inicialza el puntero media player para poder ejecutar tanto los gifs como la musica
    h_limit=1000;                  //el tamañode la escena en x
    v_limit=593;                   //el tamañode la escena en y
    timer_mov = new QTimer(this);   //se inicializan los timers
    timer_par = new QTimer(this);
    timer_pel= new QTimer(this);
    timer_salt= new QTimer(this);
    timer_grav= new QTimer(this);
    timer_proy=new QTimer(this);
    timer_escudo=new QTimer(this);
    timer_jugador_auto=new QTimer(this);
    srand(time(NULL));              //se usa srand para que no se repita ningun numero aleatorio
    puntaje=score;//se atribuye el puntaje de el nivel anterior
    scene=new QGraphicsScene(this);         //crea la scene
    scene->setSceneRect(0,0,h_limit,v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
    ui->graphicsView->setScene(scene);      // se le otorga la escena a el graphics view
    ui->label->setVisible(false);           //se esconde las imagenes que no se nesecitan por el momento
    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->label_2->setPixmap(QPixmap(":/tanketa.png"));
    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);
    ui->label_5->setVisible(false);
    ui->label_6->setVisible(false);
    ui->label_7->setVisible(false);
    ui->pushButton_5->setVisible(false);
    ui->pushButton_6->setVisible(false);
    if(P2!=6){
      ui->label_2->setVisible(false);
    }
    scene->addRect(scene->sceneRect());//se crean las dimensiones de la scena
    timer_mov->stop();//detiene los tiimers antes de iniciarlos
    timer_pel->stop();
    timer_par->stop();
    timer_proy->stop();
    connect(timer_mov,SIGNAL(timeout()),this,SLOT(mov()));//se conectan los timers a las respectivas funciones
    connect(timer_pel,SIGNAL(timeout()),this,SLOT(pegar()));
    connect(timer_par,SIGNAL(timeout()),this,SLOT(par()));
    connect(timer_salt,SIGNAL(timeout()),this,SLOT(salto()));
    connect(timer_grav,SIGNAL(timeout()),this,SLOT(grav()));
    connect(timer_proy,SIGNAL(timeout()),this,SLOT(mov_proyectil()));
    connect(timer_escudo,SIGNAL(timeout()),this,SLOT(duracion_escudo()));
    connect(timer_jugador_auto,SIGNAL(timeout()),this,SLOT(movimiento_bot()));
     p1=jugador1;//se asigna los jugadores elegidos a unas variables
     P2=jugador2;
    c=new grafica();//se crea el jugador1
    d=new grafica();//se crea el jugadr2
    lacr=new grafica();//se crea la granada lacrimogena
    nube=new grafica();//se crea la nube de la granada lacrimogena
    lacr2=new grafica();//se crea la granada lacrimogena de el segundo jugador
    escudo_objet=new grafica();//se crea el escudo de el primer jugador
    escudo_objet2=new grafica();// se crea el escudo de el segundo jugador
    nube2=new grafica();//se crea la nube de la granada lacrimogena de el segundo jugador
    lacr->setPixmap(QPixmap(":/oie_wjRyGB5Cadu8.png"));// se le asigna a la granada lacrimogena la imagen
        if(jugador1==0){
            c->setPixmap(QPixmap(":/CCD1.png")); // se asigna la imagen que el jugador 1 selecciono
        }
        if(jugador1==1){
            c->setPixmap(QPixmap(":/caminar1.png"));
        }
        if(jugador1==2){
            c->setPixmap(QPixmap(":/esmadEntero.png"));
        }

        if(jugador2==0||jugador2==4){// se asigna la imagen que el segundo jugador selecciono o del bot dependiendo de el nivel en que se encuentre
            d->setPixmap(QPixmap(":/CCV1.png"));
            if(jugador2==4){
                vida=100;
                ui->progressBar_2->setValue(vida);
            }
        }
        if(jugador2==1||jugador2==5){
            d->setPixmap(QPixmap(":/caminar1V.png"));
            if(jugador2==5){
                vida=100;
                ui->progressBar_2->setValue(vida);
            }
        }
        if(jugador2==2||jugador2==6){
            d->setPixmap(QPixmap(":/esmadC1V.png"));
            if(jugador2==6){
                vida=100;
                ui->progressBar_2->setValue(vida);
            }
        }
        if(jugador2>2){//verifica que se este jugando con la maquina
            bot=true;
        }

    if(flag==0){
        timer_salt->stop();
        if(timer_salt->isActive()){}//verifica que el timer este detenido
        else{
          timer_salt->start();
        }

        timer_pel->stop();
        timer_jugador_auto->stop();
        c->get_personaje()->CalcularPosicion();//actualiza la posicion de el jugador
        on_actionstop_triggered();//pausa tosdos los timers

        if(c->get_personaje()->GetVy()==0){
            flag=1;// se activa la bandera para poder dejar de actuar la gravedad sobre el objeto
        }
    }
    c->get_personaje()->set_valores(0,-450,450,450);//se le da los valores por defecto de el personaje
    c->posicion(v_limit);//se actualiza la posicion de el personaje de el jugador 1
    scene->addItem(c);//se añade el persoaje a la escena
    d->get_personaje()->set_valores(600,-450,450,450);//se actualiza la posicion de el personaje de el jugador 2
    d->posicion(v_limit);//se actualiza la posicion de el personaje de el jugador 2
    scene->addItem(d);//se añade el persoaje de el jugador 2 a la escena
    if(timer_salt->isActive()){}// si el timer de la gravedad esta desactivado, se lo activa
    else{
      timer_salt->start(25);//se inicia el timer
    }

    if(bot==true){//rectifica si el se esta jugando con la maquina y se inicia el timer el cual mueve el personaje automatico
      timer_jugador_auto->start(50);
      tiempo_de_mov=false;
    }

    scene->setFocusItem(d);// se coloca el focus en un personaje
    vel=3;
    i=0;

}

iniciar_juego::~iniciar_juego()// se eliminan todos los punteros
{
    delete ui;
    delete c;
    delete lacr;
    delete d;
    delete nube;
    delete escudo_objet;
    delete escudo_objet2;
    delete timer_escudo;
    delete  timer_grav;
    delete timer_jugador_auto;
    delete timer_mov;
    delete timer_par;
    delete timer_pel;
    delete timer_proy;
    delete timer_salt;
    delete mMediaPlayer;
    delete lacr2;
    delete nube2;
}

void iniciar_juego::keyPressEvent(QKeyEvent *event)
{
    if(vida2<=0){//si la vida de el primer personaje es menor a cero el programa coloca la imagen de el personaje muerto y bloque todas las teclas
        if(p1==0){//rectifica el personaje seleccionado por el usuario
            c-> setPixmap(QPixmap(":/capucho morir 3.png"));
        }
        else if(p1==1){
            c-> setPixmap(QPixmap(":/artes morir 3s.png"));
        }
        else if(p1==2){
            c-> setPixmap(QPixmap(":/esmadM3.png"));
        }
        bloqueo=true;//bloquea las acciones de las teclas
        timer_grav->stop();//detiene todos los timers para asegurar que ya no se mueve nada
        timer_salt->stop();
        timer_proy->stop();
        ui->label_7->setVisible(true);
        ui->pushButton_5->setVisible(true);
        ui->pushButton_6->setVisible(true);
//        QSize size(1114,597);//establece una escala al gif
//        QMovie *mov=new QMovie(":/41.gif");//se le da la direccion de donde esta el gif
//        mov->setSpeed(100000);// se le da la velocidad a ala que se reproduce el gif
//        mov->setScaledSize(size);//pone el gif a un tamaño escala
//        ui->label->setMovie(mov);//reproduce el gif dentro de un label
//        mov->start();//inicia la reproduccion de el gif
    }
    if(vida<=0){////si la vida de el segundo personaje o del bot es menor a cero el programa coloca la imagen de el personaje muerto y bloque todas las teclas
        if(P2==0||P2==4){
            d-> setPixmap(QPixmap(":/capucho morir 3.png"));
        }
        else if(P2==1||P2==5){
            d-> setPixmap(QPixmap(":/artes morir 3s.png"));
        }
        else if(P2==2||P2==6){
            d-> setPixmap(QPixmap(":/esmadM3.png"));
        }
        if(P2>2&&P2!=6){
            if(ganaste==200){//si ya han pasado 200 milisegundos despues de la muerte de el jugador se inicia el siguiente nivel
                P2++;// se configura otro personaje para el otro nivel
                close();//se cierra la ventana
                iniciar_juego *juego= new iniciar_juego(puntaje,p1,P2); juego->show();//se abre el siguiente nivel
            }
            else{
                ganaste++;//contabiliza el tiempo transcurrido
            }

        }
        else if(P2<=2||P2==6){//se decide quien es el ganador de la pelea en estilo de 2 jugadores y se pone la imagen de game over
            ui->label_7->setVisible(false);
            ui->pushButton_5->setVisible(false);
            ui->pushButton_6->setVisible(false);
        }
         bloqueo=true;
         timer_grav->stop();
         timer_proy->stop();
    }
    if(event->key()==Qt::Key_Y&&bloqueo==false)on_actiongo_triggered();//inicia todos los timers para crear una falsa ilusion de movimiento
    if(event->key()==Qt::Key_P&&bloqueo==false){//al presionar la tecla p se activa la bandera de bloqueo y pausa el juego
        on_actionstop_triggered();
        bloqueo=true;
        ui->label_2->setVisible(true);//hace visible todo lo referente al menu de pausa
        ui->pushButton->setVisible(true);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_3->setVisible(true);
    }
    if(event->key()==Qt::Key_F4&&bloqueo==false) close();//al presionarF4 se cierra el programa
    if(event->key()==Qt::Key_C&&bloqueo==false){//se activan las acciones de golpe de el primer jugador si el bloqueo esta desactivado
        event->accept();//acepta el evento
        golpear(1);//llama a la funcion donde se realiza la accion de golpear
    }
    if(event->key()==Qt::Key_K&&bloqueo==false){//se activan las acciones de golpe de el segundo jugador si el bloqueo esta desactivado
        event->accept();
        golpear(2);
    }
    if((event->key()== Qt::Key_D && c->get_personaje()->get_px()<950&&bloqueo==false)||(tecla_presionada_p1==true&&recuerdo=='D'&&bloqueo==false&& c->get_personaje()->get_px()<950))
    {//llama a la funcion que mueve al personaje de el primer jugador a la derecha hasta el limite de el mapa
        mover('D');//funcion donde se mueve el personaje
        event->accept();
    }
    if((event->key()== Qt::Key_6 && d->get_personaje()->get_px()<950&&bloqueo==false&&bot==false)||(tecla_presionada_p2==true&&recuerdo2=='6'&&bot==false&& d->get_personaje()->get_px()<950))
    {//llama a la funcion que mueve al personaje de el segundo jugador a la derecha hasta el limite de el mapa
        mover('6');
        event->accept();

    }
   if((event->key()== Qt::Key_A&& c->get_personaje()->get_px()>0 && flag==1&&bloqueo==false)||(tecla_presionada_p1==true&&recuerdo=='A'&& c->get_personaje()->get_px()>0&&bloqueo==false))
    {//llama a la funcion que mueve al personaje de el primer jugador a la izquierda hasta el limite de el mapa
       mover('A');
        event->accept();
    }
    if(event->key()== Qt::Key_W && c->get_personaje()->get_py()<200&&bloqueo==false )
    {//llama a la funcion que hace saltar a los personajes con la entrada para que solo mueva el primer jugador
            mover('W');
            event->accept();
    }
    if(event->key()== Qt::Key_8 && d->get_personaje()->get_py()<200&&bloqueo==false&&bot==false )
    {//llama a la funcion que hace saltar a los personajes con la entrada para que solo mueva el segundo jugador
            mover('8');
            event->accept();
    }
   if(event->key()== Qt::Key_S && c->get_personaje()->get_py()>0 && flag==1&&bloqueo==false)
    {//llama a la funcion donde se decide poner el escudo siempre y cuando la barra de poder este mayor al 50%
        poderes_J(1,1);
        event->accept();
    }
   if ((event->key()==Qt::Key_4&& d->get_personaje()->get_px()>0 && flag==1&&bloqueo==false&&bot==false)||(tecla_presionada_p2==true&& d->get_personaje()->get_px()>0&&recuerdo2=='4'&&bloqueo==true) ){
       //llama a la funcion que mueve al personaje de el segundo jugador a la izquierda hasta el limite de el mapa
       mover('4');
        event->accept();
   }
   if (event->key()==Qt::Key_5&&bloqueo==false ){
       //llama a la funcion donde se decide poner el escudo siempre y cuando la barra de poder este mayor al 50%
       poderes_J(2,1);
       event->accept();
   }
   if (event->key()==Qt::Key_V&&bloqueo==false ){
       //llama a la funcion donde se usa un condicional que decide usar el poder del personaje si la barra de poder esta al maximo
        poderes_J(1,2);
        event->accept();
   }

   if (event->key()==Qt::Key_L&&bloqueo==false ){
       //llama a la funcion donde se usa un condicional que decide usar el poder del personaje si la barra de poder esta al maximo
       poderes_J(2,2);
       event->accept();
//       S_lanzador=2;
//       eliminado=false;
//      float x=400;
//      float y=800;
//      float px=d->get_carro()->get_px();
//      float py=d->get_carro()->get_py();
//      if(recuerdo=='6'){
//          lacr->get_carro()->SetVx(x);
//          lacr->get_carro()->SetVy(y);
//      }
//      if(recuerdo=='4'){
//          lacr->get_carro()->SetVx(x*-1);
//          lacr->get_carro()->SetVy(y*-1);
//      }

//      lacr->get_carro()->set_px(px);
//      lacr->get_carro()->set_py(py*-1);
//      nube->get_carro()->SetVx(0);
//      nube->get_carro()->SetVy(0);
//      nube->get_carro()->set_valores(500,100,100,100);
//      if(poder1_2>=100){
//          if(P2==0){
//              lacr->setPixmap(QPixmap(":/molotov C.png"));
//              nube->setPixmap(QPixmap(":/fuego.png"));
//              timer_grav->start(25);
//              if(lacr->get_carro()->get_py()<200){
//                  u=1;
//              }
//              timer_proy->start(50);

//          }
//          if(P2==1){
//              S_lanzador=2;
//              lacr->setPixmap(QPixmap(":/hongo A.png"));
//              nube->setPixmap(QPixmap(":/porro.png"));
//              timer_grav->start(25);

//              if(nube_activa==true){
//                  nube->porro(v_limit);
//              }
//              timer_proy->start(50);


//          }
//          if(P2==2){
//              lacr->setPixmap(QPixmap(":/oie_wjRyGB5Cadu8.png"));
//              nube->setPixmap(QPixmap(":/nube gas.png"));
//              timer_grav->start(25);
//              if(lacr->get_carro()->get_py()<200){
//                  u=1;
//              }

//              timer_proy->start(50);
//          }
//          poder1_2=0;
//          poder2_2=0;
//          ui->progressBar_4->setValue(poder2_2);
//          ui->progressBar_3->setValue(poder1_2);

//      }
//      if(poder2_2==100&&poder1_2<100){
//          if(P2==0){
//              escudo_objet2->setPixmap(QPixmap(":/escudo C.png"));
//          }
//          if(P2==1){
//              escudo_objet2->setPixmap(QPixmap(":/escudo A.png"));
//          }
//          if(P2==2){
//              escudo_objet2->setPixmap(QPixmap(":/escudo E.png"));
//          }
//          escudo_objet2->get_carro()->set_px(lacr->get_carro()->get_px());
//          escudo_objet2->get_carro()->set_py(lacr->get_carro()->get_py()-5);
//          scene->addItem(escudo_objet2);
//          escudo2=true;
//          escudo_objet2->posicion(v_limit);
//          timer_escudo->start(50);
//          conta_escudo2=0;
//          poder1_1=0;
//          poder2_1=0;
//          poder1_2=0;
//          poder2_2=0;
//          ui->progressBar_3->setValue(poder1_1);
//          ui->progressBar_6->setValue(poder1_2);
//          ui->progressBar_4->setValue(poder2_1);
//          ui->progressBar_5->setValue(poder2_2);
//      }

   }


//timer_pel->stop();
//c->pelea();
//timer_salt->start();

c->posicion(v_limit);
d->posicion(v_limit);
lacr->posicion(v_limit);
lacr2->posicion(v_limit);
escudo_objet->posicion(v_limit);
escudo_objet2->posicion(v_limit);//mirar si sigue cayendo al ejecutar
nube->porro(v_limit);
nube2->porro(v_limit);
//lacr->posicion(v_limit);
//porro->posicion(v_limit);
//if(tie==10){
//    scene->removeItem(nube);
//    tie=0;

//}
//tie++;

}

void iniciar_juego::keyReleaseEvent(QKeyEvent *event)
{

}

void iniciar_juego::on_pegar()
{

}

void iniciar_juego::mov()
{

}

void iniciar_juego::par()
{

}

void iniciar_juego::pegar()
{

}

void iniciar_juego::salto()
{

}

void iniciar_juego::grav()
{

}

void iniciar_juego::mov_proyectil()
{

}

void iniciar_juego::duracion_escudo()
{

}

void iniciar_juego::movimiento_bot()
{

}

void iniciar_juego::poderes_J(int lanzador,int poder)
{
    float x=400;//velocidades de los objetos lanzados en x
    float y=800;//velocidades de los objetos lanzados en y
    float px1=c->get_personaje()->get_px();//se pone la posicion actual de el cuerpo
    float py1=c->get_personaje()->get_py();
    float px2=d->get_personaje()->get_px();//se pone la posicion actual de el cuerpo
    float py2=d->get_personaje()->get_py();
    if(lanzador==1){// verifica quien es el que llama a la funcion
        if(poder==1&&poderJ1>=50){//se coloca la imagen al escudo dependiendo de el personaje si la barra de poder esta por escima de 50%
            if(p1==0){
                escudo_objet->setPixmap(QPixmap(":/escudo C.png"));
            }
            if(p1==1){
                escudo_objet->setPixmap(QPixmap(":/escudo A.png"));
            }
            if(p1==2){
                escudo_objet->setPixmap(QPixmap(":/escudo E.png"));
            }
            escudo_objet->get_personaje()->set_px(px1);//se coloca el escudo en la posicion de el personaje
            escudo_objet->get_personaje()->set_py(py1-5);
            scene->addItem(escudo_objet);//se añade a la escena el personaje
            escudo=true;//se le dice al programa que el escudo esta activo
            escudo_objet->posicion(v_limit);//actualiza la posicion
            timer_escudo->start(50);//corre una funcion donde se determina la duracion de el escudo
            conta_escudo=0;//reinicia el tiempo transcurrido dentro del timer escudo
            poderJ1=0;//hace que la barra de poder se vacie
            ui->progressBar_3->setValue(poderJ1);
        }
        if(poder==2&&poderJ1>=100){//activa el poder si la barra esta al maximo
            if(recuerdo=='D'){//le da la velocidad a los objetos lanzables
                lacr->get_personaje()->SetVx(x);
                lacr->get_personaje()->SetVy(y);
            }
           if(recuerdo=='A'){
               lacr->get_personaje()->SetVx(x*-1);
               lacr->get_personaje()->SetVy(y*-1);
           }

           lacr->get_personaje()->set_px(px1);
           lacr->get_personaje()->set_py(py1*-1);
           nube->get_personaje()->SetVx(0);
           nube->get_personaje()->SetVy(0);
           nube->get_personaje()->set_valores(500,100,100,100);
            if(p1==0){
                lacr->setPixmap(QPixmap(":/molotov C.png"));
                nube->setPixmap(QPixmap(":/fuego.png"));
                timer_grav->start(25);
                timer_proy->start(50);

            }
            if(p1==1){
                lacr->setPixmap(QPixmap(":/hongo A.png"));
                nube->setPixmap(QPixmap(":/porro.png"));
                timer_grav->start(25);

                if(nube_activa==true){
                    nube->porro(v_limit);
                }
                timer_proy->start(50);


            }
            if(p1==2){
                lacr->setPixmap(QPixmap(":/oie_wjRyGB5Cadu8.png"));
                nube->setPixmap(QPixmap(":/nube gas.png"));
                timer_grav->start(25);
                if(lacr->get_personaje()->get_py()<200){
                    u=1;
                }

                timer_proy->start(50);


            }
            poderJ1=0;
            ui->progressBar_3->setValue(poderJ1);//reinicia la barra de poder

        }
    }
    if(lanzador==2){// verifica quien es el que llama a la funcion
        if(poder==1&&poderJ2>=50){//se coloca la imagen al escudo dependiendo de el personaje si la barra de poder esta por escima de 50%
            if(P2==0){
                escudo_objet2->setPixmap(QPixmap(":/escudo C.png"));
            }
            if(P2==1){
                escudo_objet2->setPixmap(QPixmap(":/escudo A.png"));
            }
            if(P2==2){
                escudo_objet2->setPixmap(QPixmap(":/escudo E.png"));
            }
            escudo_objet2->get_personaje()->set_px(px2);//se coloca el escudo en la posicion de el personaje
            escudo_objet2->get_personaje()->set_py(py2-5);
            scene->addItem(escudo_objet2);//se añade a la escena el personaje
            escudo2=true;//se le dice al programa que el escudo esta activo
            escudo_objet2->posicion(v_limit);//actualiza la posicion
            timer_escudo->start(50);//corre una funcion donde se determina la duracion de el escudo
            conta_escudo2=0;//reinicia el tiempo transcurrido dentro del timer escudo
            poderJ2=0;//hace que la barra de poder se vacie
            ui->progressBar_3->setValue(poderJ2);
        }
        if(poder==2&&poderJ2>=100){//activa el poder si la barra esta al maximo
            if(recuerdo2=='D'){//le da la velocidad a los objetos lanzables
                lacr2->get_personaje()->SetVx(x);
                lacr2->get_personaje()->SetVy(y);
            }
           if(recuerdo2=='A'){
               lacr2->get_personaje()->SetVx(x*-1);
               lacr2->get_personaje()->SetVy(y*-1);
           }

           lacr2->get_personaje()->set_px(px2);
           lacr2->get_personaje()->set_py(py2*-1);
           nube2->get_personaje()->SetVx(0);
           nube2->get_personaje()->SetVy(0);
           nube2->get_personaje()->set_valores(500,100,100,100);
            if(P2==0){
                lacr2->setPixmap(QPixmap(":/molotov C.png"));
                nube2->setPixmap(QPixmap(":/fuego.png"));
                timer_grav->start(25);
                timer_proy->start(50);

            }
            if(P2==1){
                lacr2->setPixmap(QPixmap(":/hongo A.png"));
                nube2->setPixmap(QPixmap(":/porro.png"));
                timer_grav->start(25);

                if(nube_activa2==true){
                    nube2->porro(v_limit);
                }
                timer_proy->start(50);


            }
            if(P2==2){
                lacr2->setPixmap(QPixmap(":/oie_wjRyGB5Cadu8.png"));
                nube2->setPixmap(QPixmap(":/nube gas.png"));
                timer_grav->start(25);
                if(lacr2->get_personaje()->get_py()<200){
                    u=1;
                }

                timer_proy->start(50);


            }
            poderJ2=0;
            ui->progressBar_3->setValue(poderJ2);//reinicia la barra de poder

        }
    }
/////////////////////////////////////////////////////////////////estoy aqui
/// seguir con lo de arriba
}

void iniciar_juego::golpear(int peleador)
{

}

void iniciar_juego::mover(char movida_player)
{

}

void iniciar_juego::on_actiongo_triggered()
{

}

void iniciar_juego::on_actionstop_triggered()
{

}
