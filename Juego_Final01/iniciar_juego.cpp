#include "iniciar_juego.h"
#include "ui_iniciar_juego.h"
#include "modo_de_juego.h"


iniciar_juego::iniciar_juego(int score,int jugador1,int jugador2,QWidget *parent) :
    iniciar_sesion(parent),
    ui(new Ui::iniciar_juego)
{
    ui->setupUi(this);
    mMediaPlayer = new QMediaPlayer(this);//se inicialza el puntero media player para poder ejecutar tanto los gifs como la musica
    h_limit=1000;                  //el tamañode la escena en x
    v_limit=593;                   //el tamañode la escena en y
    timer_mov = new QTimer(this);   //se inicializan los timers
    gravedad=new QTimer(this);
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
    connect(gravedad,SIGNAL(timeout()),this,SLOT(gravedadt()));
    connect(timer_mov,SIGNAL(timeout()),this,SLOT(mov()));//se conectan los timers a las respectivas funciones
    connect(timer_pel,SIGNAL(timeout()),this,SLOT(pegar()));//
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
          //timer_salt->start();
        }

        timer_pel->stop();
        timer_jugador_auto->stop();
        c->get_personaje()->CalcularPosicion();//actualiza la posicion de el jugador
        on_actionstop_triggered();//pausa tosdos los timers

        if(c->get_personaje()->GetVy()==0){
            flag=1;// se activa la bandera para poder dejar de actuar la gravedad sobre el objeto
        }
    }
    //scene->setFocusItem(scene->addEllipse(1,1,2,1));
    c->get_personaje()->set_valores(0,-250,450,450);//se le da los valores por defecto de el personaje
    c->posicion(v_limit);//se actualiza la posicion de el personaje de el jugador 1
    scene->addItem(c);//se añade el persoaje a la escena
    d->get_personaje()->set_valores(600,-250,450,450);//se actualiza la posicion de el personaje de el jugador 2
    d->posicion(v_limit);//se actualiza la posicion de el personaje de el jugador 2
    scene->addItem(d);//se añade el persoaje de el jugador 2 a la escena
    if(timer_salt->isActive()){}// si el timer de la gravedad esta desactivado, se lo activa
    else{
     // timer_salt->start(25);//se inicia el timer
    }

    if(bot==true){//rectifica si el se esta jugando con la maquina y se inicia el timer el cual mueve el personaje automatico
      timer_jugador_auto->start(50);
      tiempo_de_mov=false;
    }

    scene->setFocusItem(d);// se coloca el focus en un personaje
    vel=3;
    i=0;
    gravedad->start(50);

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
            ui->graphicsView->showMaximized();
        }
        else if(p1==1){
            c-> setPixmap(QPixmap(":/artes morir 3s.png"));
        }
        else if(p1==2){
            c-> setPixmap(QPixmap(":/esmadM3.png"));
        }
        bloqueo=true;//bloquea las acciones de las teclas
        timer_grav->stop();//detiene todos los timers para asegurar que ya no se mueve nada
       // timer_salt->stop();
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
        if(c->get_personaje()->get_px()>950){
            c->get_personaje()->set_px(950);
        }

        event->accept();
    }
    if((event->key()== Qt::Key_6 && d->get_personaje()->get_px()<950&&bloqueo==false&&bot==false)||(tecla_presionada_p2==true&&recuerdo2=='6'&&bot==false&& d->get_personaje()->get_px()<950))
    {//llama a la funcion que mueve al personaje de el segundo jugador a la derecha hasta el limite de el mapa
        mover('6');
        if(d->get_personaje()->get_px()>950){
            d->get_personaje()->set_px(950);
        }
        event->accept();

    }
   if((event->key()== Qt::Key_A&& c->get_personaje()->get_px()>0 && bloqueo==false)||(tecla_presionada_p1==true&&recuerdo=='A'&& c->get_personaje()->get_px()>0&&bloqueo==false))
    {//llama a la funcion que mueve al personaje de el primer jugador a la izquierda hasta el limite de el mapa
       if(c->get_personaje()->get_px()<0){
           c->get_personaje()->set_px(0);
       }
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
   if ((event->key()==Qt::Key_4&& d->get_personaje()->get_px()>0 && bloqueo==false&&bot==false)||(tecla_presionada_p2==true&& d->get_personaje()->get_px()>0&&recuerdo2=='4'&&bloqueo==true) ){
       //llama a la funcion que mueve al personaje de el segundo jugador a la izquierda hasta el limite de el mapa
       if(d->get_personaje()->get_px()<0){
           d->get_personaje()->set_px(0);
       }
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
   }

}

void iniciar_juego::keyReleaseEvent(QKeyEvent *event)//indica cuando el usuario suelta una tecla en la ejecicion de el programa
{
    if (event->key()==Qt::Key_A){
        tecla_presionada_p1=false;
    }
    if (event->key()==Qt::Key_D){
        tecla_presionada_p1=false;
    }
    if (event->key()==Qt::Key_4){
        tecla_presionada_p2=false;
    }
    if (event->key()==Qt::Key_6){
        tecla_presionada_p2=false;
    }
    if(event->key()==Qt::Key_W){
        tecla_presionada_p1=false;
    }
    if(event->key()==Qt::Key_8){
        tecla_presionada_p2=false;
    }
    if(event->key()==Qt::Key_C){
        tecla_golpe1=false;
    }
    if(event->key()==Qt::Key_K){
        tecla_golpe2=false;
    }

}

void iniciar_juego::on_pegar()
{
    if(timer_pel->isActive()){ }//si el timer de pelea esta desactivado lo activa o sino no
    else{
       timer_pel->start(25);//activa el timer que contiene la funcion donde el personaje golpea
    }

}

void iniciar_juego::mov()
{
    if(c->get_personaje()->GetVy()>sp){//si la velocidad en y es mayor  a cero significa que el prsonaje esta saltando y entonces cambia la imagen a saltando
        c->salto(2,recuerdo,p1,1);//se llama la funcion donde se cambia la imagen y se le pasa como datos de entrada la imagen, la direccion del personaje, el personaje elegido y el jugador que esta llamando a la funcion
        sp=c->get_personaje()->GetVy();//se actualiza la posicion maxima para poder seguir cambiar la imagen
    }
    else{
        c->mov(p1,recuerdo);
        cont=0;
        sp=0.0;//se reinicia el contador de la altura de el personaje
    }
    if(d->get_personaje()->GetVy()>sp2){
        d->salto(2,recuerdo,p1,2);
        sp2=d->get_personaje()->GetVy();
    }
    else{
        d->mov(P2,recuerdo2);//cambia la imagen del personaje para que paresca que esta cayendo
        cont=0;
        sp2=0.0;
    }
}

void iniciar_juego::par()
{
    if (i==0){
    c->get_personaje()->set_px(100);
    c->get_personaje()->set_py(300);
    i=1;
    }
    if (c->get_personaje()->get_py()>0) c->par(v_limit);
}

void iniciar_juego::pegar()
{
    timer_mov->stop();
    timer_par->stop();
    c->pelea();//muestra la animacion de golpe de el personaje de artes
    cont=1;
    d->posicion(v_limit);
}

void iniciar_juego::salto()
{

    if(recor_salto=='W'){
        if(c->get_personaje()->get_py()==-200){// si la altura es menor a la maxima de el salto le da velocidad en x e y al personaje
            if(flag==0){
               flag=1;
               if(recuerdo=='D'){//el jugador salta a la derecha
//                  c->get_personaje()->SetVy(c->get_personaje()->GetVy()+1000);
//                  c->get_personaje()->SetVx(c->get_personaje()->GetVx()+200);
               }
               else{//el jugador salta a la izquierda
//                  c->get_personaje()->SetVy(c->get_personaje()->GetVy()+1000);
//                  c->get_personaje()->SetVx(c->get_personaje()->GetVx()-200);
               }
            }
            else {
                flag=2;
               // timer_salt->stop();//detiene el timer
            }
        }
        else{
            flag=0;

        }
        if(flag ==0 || flag==1){
           if(c->get_personaje()->get_py()==posi ){
               c->get_personaje()->SetVy(c->get_personaje()->GetVy()+1000);
               if(recuerdo=='D'){
                   c->get_personaje()->SetVx(c->get_personaje()->GetVx()+200);
               }
               else{
                   c->get_personaje()->SetVx(c->get_personaje()->GetVx()-200);
               }

            }
            if(c->get_personaje()->GetVy()>0){
                c->salto(1,recuerdo,p1,1);//establece la imagen de salto


            }
            else if(c->get_personaje()->GetVy()<=0){
                c->salto(2,recuerdo,p1,1);
                flag=1;
            }
            if(c->get_personaje()->get_px()>=950){
                flag=0;

               // timer_salt->stop();
            }



        }
        else if(flag==2){
            //timer_salt->stop();
            flag=0;
        }
    }
    if(recor_salto=='8'){
        if(d->get_personaje()->get_py()<=-200){
            if(flag==0){
               flag=1;
               if(recuerdo2=='6'){
                  d->get_personaje()->SetVy(d->get_personaje()->GetVy()+1000);
                  d->get_personaje()->SetVx(d->get_personaje()->GetVx()+200);
               }
               else{
                  d->get_personaje()->SetVy(d->get_personaje()->GetVy()+1000);
                  d->get_personaje()->SetVx(d->get_personaje()->GetVx()-200);
               }
            }
            else {
                flag=2;
                //timer_salt->stop();
            }


        }
    }
        else{
            flag=0;

        }
        if(flag ==0 || flag==1){
//            if(d->get_carro()->get_py()==posi ){
//               d->get_carro()->SetVy(d->get_carro()->GetVy()+1000);
//               if(recuerdo=='D'){
//                   d->get_carro()->SetVx(d->get_carro()->GetVx()+200);
//               }
//               else{
//                   d->get_carro()->SetVx(d->get_carro()->GetVx()-200);
//               }

//            }
            if(d->get_personaje()->GetVy()>0){
               d->salto(1,recuerdo,p1,2);
            }
            else if(d->get_personaje()->GetVy()<=0){
                d->salto(2,recuerdo2,P2,2);
                flag=1;
            }
            if(d->get_personaje()->get_px()>=950){
                flag=1;
               // timer_salt->stop();
            }
        }
        else if(flag==2){
            //timer_salt->stop();
            flag=1;
        }
    c->posicion(v_limit);
    d->posicion(v_limit);

}

void iniciar_juego::grav()
{

    if(u==0){//rectifica si la granada esta en la escena y si no esta la añaden
      scene->addItem(lacr);
       u++;
    }
    if(u2==0){
      scene->addItem(lacr2);
       u++;
    }
    lacr->posicion(v_limit);//actualizalas posiciones de las granadas o proyectiles
    lacr2->posicion(v_limit);
    if(lacr->get_personaje()->get_py()<200&&u==1){//si llega a cierta posicion el proyectil setransforma en otra cosa
        if(p1!=1){//rectifica que el personaje sea distinto a el de artes
            nube->get_personaje()->set_px(lacr->get_personaje()->get_px());//se le da la posicion de donde termino el proyetil a la nube
            nube->get_personaje()->set_py(200);
            scene->addItem(nube);//se añade a la escena la nube
            nube_activa=true;//rectifica si la nube ya esta en el escenario
            //nube->posicion(v_limit);//actualiza la posicion de nube
            //scene->removeItem(lacr);//quita de la escena a el proyectil
            u=20;//reinicia el contador de acciones
            timer_grav->stop();
        }
        else{//si es el personaje de artes reaccina de distinta manera
            nube->get_personaje()->SetVx(10);//se le da valores a x e y
            nube->get_personaje()->SetVy(10);
            lacr->get_personaje()->set_py(200);// se le da una nuva posicion a el proyectil
            lacr->get_personaje()->SetVy(lacr->get_personaje()->GetVy()*-1);//cambia el sentido de la velocidad de el proyactil
            if(lacr->get_personaje()->GetVy()<0){//disminulle la velocidad de el proyectil
              lacr->get_personaje()->SetVy(lacr->get_personaje()->GetVy()-incremento);
              lacr->get_personaje()->SetVx(lacr->get_personaje()->GetVx()+-incremento);
            }
            else if(lacr->get_personaje()->GetVy()==0){}
            else{
                lacr->get_personaje()->SetVy(lacr->get_personaje()->GetVy()+incremento);
                lacr->get_personaje()->SetVx(lacr->get_personaje()->GetVx()+incremento);
            }
        }
    }
    if(lacr->get_personaje()->get_px()>950||lacr->get_personaje()->get_px()<0){//cambia la velocidad con respecto a x cuando el proyectil llega al limite de la escena
        lacr->get_personaje()->SetVx(lacr->get_personaje()->GetVx()*-1);
    }
    if(lacr2->get_personaje()->get_py()<200&&u2==1){//si llega a cierta posicion el proyectil setransforma en otra cosa
        if(P2!=1||P2!=4){//rectifica que el personaje sea distinto a el de artes
            nube2->get_personaje()->set_px(lacr2->get_personaje()->get_px());//se le da la posicion de donde termino el proyetil a la nube
            nube2->get_personaje()->set_py(200);
            scene->addItem(nube2);//se añade a la escena la nube
            nube_activa2=true;//rectifica si la nube ya esta en el escenario
            //nube2->posicion(v_limit);//actualiza la posicion de nube
            scene->removeItem(lacr2);//quita de la escena a el proyectil
            timer_grav->stop();
            u2=20;//reinicia el contador de acciones
        }
        else{//si es el personaje de artes reaccina de distinta manera
            nube2->get_personaje()->SetVx(10);//se le da valores a x e y
            nube2->get_personaje()->SetVy(10);
            lacr2->get_personaje()->set_py(200);// se le da una nuva posicion a el proyectil
            lacr2->get_personaje()->SetVy(lacr2->get_personaje()->GetVy()*-1);//cambia el sentido de la velocidad de el proyactil
            if(lacr2->get_personaje()->GetVy()<0){//disminulle la velocidad de el proyectil
              lacr2->get_personaje()->SetVy(lacr2->get_personaje()->GetVy()+incremento);
            }
            else if(lacr2->get_personaje()->GetVy()==0){}
            else{
                lacr2->get_personaje()->SetVy(lacr2->get_personaje()->GetVy()-incremento);
            }
        }
    }
    if(lacr2->get_personaje()->get_px()>950||lacr2->get_personaje()->get_px()<0){//cambia la velocidad con respecto a x cuando el proyectil llega al limite de la escena
        lacr2->get_personaje()->SetVx(lacr2->get_personaje()->GetVx()*-1);
    }
    if(p1==1||P2==1||P2==4){
        if(S_lanzador==1){
            if(lacr->collidesWithItem(d)){//accion de cuando el hongo coliciona con el otro personaje
                u=20;
                if(eliminado==false){//si el proyectil no ha sido eliminado entra al condicional
                    scene->removeItem(lacr);//elimina el proyectil
                    scene->addItem(nube);//coloca la nube en la escena
                    eliminado=true;//indica que el proyectil ya fue eliminado
                    nube_activa=true;//indica que la nube esta activa
                    ui->graphicsView->setBackgroundBrush(QImage(":/droga orgins.jpg"));//cambia el fondo como efecto de el poder
                }
                nube->porro(v_limit);//actualiza la posicion de el porro formando el movimiento circular
            }
            else if(nube_activa==true&&eliminado==true){
                nube->porro(v_limit);
            }
        }
        if((S_lanzador==2&&P2==1)||(S_lanzador==2&&P2==4)){
            if(lacr2->collidesWithItem(c)){
                if(eliminado2==false){
                    scene->removeItem(lacr2);
                    scene->addItem(nube2);
                    eliminado2=true;
                    u=20;
                    nube_activa2=true;
                    ui->graphicsView->setBackgroundBrush(QImage(":/droga orgins.jpg"));
                }
                nube2->porro(v_limit);
            }
            else if((nube_activa==true&&eliminado==true)||(nube_activa==true&&eliminado2==true)){
                nube2->porro(v_limit);
            }
        }
    }
}

void iniciar_juego::mov_proyectil()//comportamiento de el personaje cuando colisiona con la nube o proyectil
{
    if(nube_activa==true){//si la nube esta activa empieza a contabilozar el tiempo transcurrido
        conta_proyectil++;
    }
    if(nube_activa2==true){
        conta_proyectil2++;
    }
    if(S_lanzador==1){
        if(p1==0){
            if(nube->collidesWithItem(d)==true&&nube_activa==true){//disminuye la vida cuando el personaje choca con el fuego
                ui->progressBar_2->setValue(vida-5);
                vida-=5;
            }
        }
        if(p1==1){
            if(nube->collidesWithItem(d)==true&&nube_activa==true){//disminuye la vida cuando el porro golpea a el personaje
                ui->progressBar_2->setValue(vida-3);
                vida-=3;
                if(c->get_personaje()->get_px()<=d->get_personaje()->get_px()){//hace retroceder al jugador despues de el impacto
                    d->get_personaje()->SetVy(1000);
                    d->get_personaje()->SetVx(5000);
                }
                if(c->get_personaje()->get_px()>d->get_personaje()->get_px()){
                    d->get_personaje()->SetVy(1000);
                    d->get_personaje()->SetVx(-5000);
                }
                if(timer_salt->isActive()){}
                else{
                 // timer_salt->start(25);
                }
            }
        }
        if(p1==2){
            if(nube->collidesWithItem(d)==true&&nube_activa==true){//coloca una bandera diciendo que colisiono con la nube de gas lacrimogeno
               lacrimogena=true;
            }
            else{
                lacrimogena=false;
            }

        }
    }
    if(S_lanzador==2){

        if(P2==0){
            if(nube2->collidesWithItem(c)==true&&nube_activa2==true){
                ui->progressBar->setValue(vida2-5);
                vida2-=5;
            }
        }
        if(P2==1){
            nube->porro(v_limit);
            if(nube2->collidesWithItem(c)==true&&nube_activa2==true){
                ui->progressBar->setValue(vida2-20);
                vida2-=20;
                if(c->get_personaje()->get_px()<=d->get_personaje()->get_px()){
                    c->get_personaje()->SetVy(1000);
                    c->get_personaje()->SetVx(5000);
                }
                if(c->get_personaje()->get_px()>d->get_personaje()->get_px()){
                    c->get_personaje()->SetVy(1000);
                    c->get_personaje()->SetVx(-5000);
                }
                if(timer_salt->isActive()){}
                else{
                  // timer_salt->start(25);
                }
            }
        }
        if(P2==2){
            if(nube2->collidesWithItem(c)==true&&nube_activa2==true){
               lacrimogena=true;
            }
            else{
                lacrimogena=false;
            }
        }
    }

    if(conta_proyectil==200){
        if(nube_activa==true){
           scene->removeItem(nube);//elimina la nube
        }

        conta_proyectil=0;//reinicia el temporizador
        nube_activa=false;//indica que la nube fue eliminada
        eliminado=false;//indica que ya se puede lanzar otro proyectil
        ui->graphicsView->setBackgroundBrush(QImage(":/5b734c53396e3_opt.jpg"));//regresa el fondo a la normalidad
        u=20;
        timer_grav->stop();
        timer_proy->stop();
    }
    if(conta_proyectil2==200){
        if(nube_activa2==true){
           scene->removeItem(nube2);//elimina la nube
        }
        //scene->removeItem(nube2);
        conta_proyectil2=0;
        eliminado2=false;
        nube_activa2=false;
        ui->graphicsView->setBackgroundBrush(QImage(":/5b734c53396e3_opt.jpg"));
        u=20;
        timer_grav->stop();
        timer_proy->stop();
    }

}

void iniciar_juego::duracion_escudo()//mide la duracion de el escudo en la escena
{
    if(S_lanzador==1){//es el jugadorseleccionado
       conta_escudo++;//contabiliza eltiempo transcurrido en el timer
    }
    if(S_lanzador==2){
       conta_escudo2++;
    }
    if(conta_escudo==200){
        scene->removeItem(escudo_objet);//quita el escudo de la escena
        conta_escudo=0;//reinicia el contador
        escudo=false;//indica que el escudo ya fue sacado de escena

    }
    if(conta_escudo2==200){
        scene->removeItem(escudo_objet2);
        conta_escudo2=0;
        escudo2=false;

    }
}

void iniciar_juego::movimiento_bot()
{
    if(tiempo_de_mov==false&&bloqueo==false){
        diferencia_dista_bot=c->get_personaje()->get_px()-d->get_personaje()->get_px();//la distancia que existe entre el bot y el jugador, para poder decidir los movimientos que va a realizar
        accion_player=1+rand()%5;//decide una accion aleatoria de el el bot
        if(accion_player==3){//si el bot no esta saltando se mueve a la izquiera o a la derecha dependiendode la distancia entre el bot y el jugador

        }
        else if(diferencia_dista_bot<0){//el bot se mueve a la izquierda
            accion_player=1;
        }
        else if(diferencia_dista_bot>0){//el bot se mueve a la derecha
            accion_player=2;
        }
        if(c->collidesWithItem(d)||(diferencia_dista_bot>-10&&diferencia_dista_bot<10)){//si el bot se encuentra cerca de el jugador lo golpea
            accion_player=5;
        }
        podeselec=1+rand()%2;//elige un poder aleatorio para lanzar
        if(poderJ2>=50&&podeselec==1){//el bot lanza el escudo
          accion_player=6;
        }
        if(poderJ2>=100&&podeselec==2){//el bot laza un proyactil
            accion_player=7;
        }

        tiempo_de_mov=true;//indica que el bot sta en movimiento
    }
    else{
        if(bloqueo==false){
            tiempo_mov_bot++;//contabiliza el tiempo transcurrido en el timer de movimiento de personaje
            if(accion_player==1){
                if(d->get_personaje()->get_px()<0){//indica el limte donde el personaje puede moverse si este se pasa lo regresa automaticamente
                    d->get_personaje()->set_px(0);
                }
                mover('4');//llama a la funcion donde se genera el movimiento
            }
            else if(accion_player==2){
                mover('6');
                if(d->get_personaje()->get_px()>950){
                    d->get_personaje()->set_px(950);
                }
            }
            else if(accion_player==3){
                mover('8');
                tiempo_de_mov=false;
                tiempo_mov_bot=0;
            }
            else if(accion_player==4){
                mover('5');
            }
            else if(accion_player==5){
                golpear(2);
                tiempo_de_mov=false;
                tiempo_mov_bot=0;
            }
            if(tiempo_mov_bot==10){
                tiempo_de_mov=false;
                tiempo_mov_bot=0;
            }
            if(accion_player==6){
                poderes_J(2,1);
                tiempo_de_mov=false;
                tiempo_mov_bot=0;
            }
            if(accion_player==7){
                poderes_J(2,2);
                tiempo_de_mov=false;
                tiempo_mov_bot=0;
            }
        }

    }
    d->posicion(v_limit);
}

void iniciar_juego::gravedadt()
{
    ui->lcdNumber->display(lacr->get_personaje()->GetVy());
    c->posicion(v_limit);//actualizaa las posiciones de todos los objetos en el escenario
    d->posicion(v_limit);
    lacr->posicion(v_limit);
    lacr2->posicion(v_limit);
    escudo_objet->posicion(v_limit);
    escudo_objet2->posicion(v_limit);//mirar si sigue cayendo al ejecutar
    if(p1==1){
       nube->porro(v_limit);
    }
    else{
        nube->get_personaje()->SetVx(0);
        nube->get_personaje()->SetVy(0);
        nube->get_personaje()->setax(0);
        nube->get_personaje()->setay(0);
        nube->posicion(v_limit);
    }
    if(P2==1){
      nube2->porro(v_limit);
    }
    else{
        nube2->get_personaje()->SetVx(0);
        nube2->get_personaje()->SetVy(0);
        nube2->get_personaje()->setax(0);
        nube2->get_personaje()->setay(0);
        nube2->posicion(v_limit);
    }
    if(c->get_personaje()->get_px()<0){
        c->get_personaje()->set_px(0);
    }
    if(d->get_personaje()->get_px()<0){
        d->get_personaje()->set_px(0);
    }
    if(d->get_personaje()->get_px()>950){
        d->get_personaje()->set_px(950);
    }
    if(c->get_personaje()->get_px()>950){
        c->get_personaje()->set_px(950);
    }
    if(lacr->get_personaje()->get_px()<0){
        lacr->get_personaje()->set_px(0);
    }
    if(lacr->get_personaje()->get_py()<200){
        lacr->get_personaje()->set_py(200);
    }
    if(nube->get_personaje()->get_py()<-200){
        nube->get_personaje()->set_py(-200);
    }
    if(lacr->get_personaje()->get_px()>950){
        lacr->get_personaje()->set_px(950);
    }

    if(lacr2->get_personaje()->get_px()<0){
        lacr2->get_personaje()->set_px(0);
    }
    if(lacr2->get_personaje()->get_py()<-200){
        lacr2->get_personaje()->set_py(-200);
    }
    if(nube2->get_personaje()->get_py()<-200){
        nube2->get_personaje()->set_py(-200);
    }
    if(lacr2->get_personaje()->get_px()>950){
        lacr2->get_personaje()->set_px(950);
    }
    if(nube2->get_personaje()->get_py()<=-200){
        nube2->get_personaje()->SetVy(nube2->get_personaje()->GetVy()*-1);
    }
    if(nube->get_personaje()->get_py()<=-200){
        nube->get_personaje()->SetVy(nube->get_personaje()->GetVy()*-1);
    }
    if(c->get_personaje()->get_py()>-200){
        c->get_personaje()->set_py(c->get_personaje()->get_py()-10);
    }
    if(d->get_personaje()->get_py()>-200){
        d->get_personaje()->set_py(d->get_personaje()->get_py()-10);
    }
}

void iniciar_juego::poderes_J(int lanzador,int poder)
{
    float x=400;//velocidades de los objetos lanzados en x
    float y=1500;//velocidades de los objetos lanzados en y
    float px1=c->get_personaje()->get_px();//se pone la posicion actual de el cuerpo
    float py1=c->get_personaje()->get_py();
    float px2=d->get_personaje()->get_px();//se pone la posicion actual de el cuerpo
    float py2=d->get_personaje()->get_py();
    if(lanzador==1){// verifica quien es el que llama a la funcion
        S_lanzador=1;
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
            if(escudo==false){
               scene->addItem(escudo_objet);//se añade a la escena el personaje
               escudo=true;//se le dice al programa que el escudo esta activo
               if(timer_escudo->isActive()){}//si el timer esta encendido no lo vuelve a encender
               else{
                   timer_escudo->start(50);//corre una funcion donde se determina la duracion de el escudo
               }
            }

            //escudo_objet->posicion(v_limit);//actualiza la posicion
            conta_escudo=0;//reinicia el tiempo transcurrido dentro del timer escudo
            poderJ1=0;//hace que la barra de poder se vacie
            ui->progressBar_3->setValue(poderJ1);
        }
        if(poder==2&&poderJ1>=100){//activa el poder si la barra esta al maximo
            if(recuerdo=='D'){//le da la velocidad a los objetos lanzables para que se dirigan a la derecha o a la izquierda
                lacr->get_personaje()->SetVx(x);
                lacr->get_personaje()->SetVy(y);
            }
           if(recuerdo=='A'){
               lacr->get_personaje()->SetVx(x*-1);
               lacr->get_personaje()->SetVy(y*-1);
           }
           u=0;
           lacr->get_personaje()->set_px(px1);//le da la posicion de a el proyectil de el personae que lo lanzo
           lacr->get_personaje()->set_py(py1*-1);
           nube->get_personaje()->SetVx(0);//le quita la velocidad de a la reaccion
           nube->get_personaje()->SetVy(0);
           nube->get_personaje()->set_valores(500,100,100,100);
            if(p1==0){//se le da la imagen y se activa el movimiento de el proyectil
                lacr->setPixmap(QPixmap(":/molotov C.png"));
                nube->setPixmap(QPixmap(":/fuego.png"));
                if(timer_grav->isActive()){}
                else{
                   timer_grav->start(25);
                }
                if(timer_proy->isActive()){}
                else{
                   timer_proy->start(50);
                }
            }
            if(p1==1){
                lacr->setPixmap(QPixmap(":/hongo A.png"));
                nube->setPixmap(QPixmap(":/porro.png"));
                if(timer_grav->isActive()){}
                else{
                   timer_grav->start(25);
                }
                if(nube_activa==true){
                    nube->porro(v_limit);
                }
                if(timer_proy->isActive()){}
                else{
                   timer_proy->start(50);
                }

            }
            if(p1==2){
                lacr->setPixmap(QPixmap(":/oie_wjRyGB5Cadu8.png"));
                nube->setPixmap(QPixmap(":/nube gas.png"));                
                if(lacr->get_personaje()->get_py()<200){
                    u=1;
                }
                if(timer_grav->isActive()){}
                else{
                   timer_grav->start(25);
                }
                if(timer_proy->isActive()){}
                else{
                   timer_proy->start(50);
                }

            }
            poderJ1=0;
            ui->progressBar_3->setValue(poderJ1);//reinicia la barra de poder

        }
    }
    if(lanzador==2){// verifica quien es el que llama a la funcion
        S_lanzador=2;
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
            if(timer_escudo->isActive()){}
            else{
                timer_escudo->start(50);
            }
            conta_escudo2=0;//reinicia el tiempo transcurrido dentro del timer escudo
            poderJ2=0;//hace que la barra de poder se vacie
            ui->progressBar_4->setValue(poderJ2);
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
            u2=0;
           lacr2->get_personaje()->set_px(px2);
           lacr2->get_personaje()->set_py(py2*-1);
           nube2->get_personaje()->SetVx(0);
           nube2->get_personaje()->SetVy(0);
           nube2->get_personaje()->set_valores(500,100,100,100);
            if(P2==0){
                lacr2->setPixmap(QPixmap(":/molotov C.png"));
                nube2->setPixmap(QPixmap(":/fuego.png"));
                if(timer_grav->isActive()){}
                else{
                   timer_grav->start(25);
                }
                if(timer_proy->isActive()){}
                else{
                   timer_proy->start(50);
                }

            }
            if(P2==1){
                lacr2->setPixmap(QPixmap(":/hongo A.png"));
                nube2->setPixmap(QPixmap(":/porro.png"));
                if(nube_activa2==true){
                    nube2->porro(v_limit);
                }
                if(timer_grav->isActive()){}
                else{
                   timer_grav->start(25);
                }
                if(timer_proy->isActive()){}
                else{
                   timer_proy->start(50);
                }
            }
            if(P2==2){
                lacr2->setPixmap(QPixmap(":/oie_wjRyGB5Cadu8.png"));
                nube2->setPixmap(QPixmap(":/nube gas.png"));
                if(lacr2->get_personaje()->get_py()<200){
                    u=1;
                }
                if(timer_grav->isActive()){}
                else{
                   timer_grav->start(25);
                }
                if(timer_proy->isActive()){}
                else{
                   timer_proy->start(50);
                }


            }
            poderJ2=0;
            ui->progressBar_4->setValue(poderJ2);//reinicia la barra de poder

        }
    }
}

void iniciar_juego::golpear(int peleador)
{
    if(peleador==1){
        if((p1==0&&recuerdo=='D')||(p1==0&&recuerdo=='-')){//pone la imagen de golpear en la direccion en la que esta el personaje
            c->setPixmap(QPixmap(":/capucho golpe2.png"));
        }
        else if(p1==0&&recuerdo=='A'){
             c->setPixmap(QPixmap(":/capucho golpe.png"));

        }
        else if((p1==1&&recuerdo=='D')||(p1==1&&recuerdo=='-')){
            c->setPixmap(QPixmap(":/pegar7.png"));
        }
        else if(p1==1&&recuerdo=='A'){
            c->setPixmap(QPixmap(":/pegarV.png"));
        }
        else if((p1==2&&recuerdo=='D')||(p1==0&&recuerdo=='-')){
            c->setPixmap(QPixmap(":/esmadG.png"));
        }
        else if(p1==2&&recuerdo=='A'){
            c->setPixmap(QPixmap(":/esmadGV.png"));
        }


        if(c->collidesWithItem(d)==true)//realiza la reaccion al presionar la tecla de golpear y a la vez este colisionando conel otro personaje
        {
            if(P2==0||P2==4){//coloca la imagen de el jugador contrario de erido al ser golpeado por e otro personaje
                d-> setPixmap(QPixmap(":/capucho golpeadoV.png"));
            }
            else if(P2==1||P2==5){
                d-> setPixmap(QPixmap(":/artes golpeadoV.png"));
            }
            else if(P2==2||P2==6){
                d-> setPixmap(QPixmap(":/esmad golpeado.png"));
            }
            if(P2==4){//disminuye la vida dependiendo de el nivel en que se encuentre
              vida-=1;
            }
            else if(P2==5){
              vida-=0.5;
            }
            else if(P2==6){
              vida-=0.1;
            }
            else{//es el porcentaje de vida que le baja en el modo de juego de 2 jugadores
              vida-=5;
            }
            ui->progressBar_2->setValue(vida);//coloca la vida en el medidor que esta en la escena
            if(poderJ1!=100){//al golpear al otro personaje la barra de poder aumenta en 10% y loindica en la escena
                poderJ1+=10;
                ui->progressBar_3->setValue(poderJ1);
            }
            if(c->get_personaje()->get_px()<=d->get_personaje()->get_px()){// al golpear al otro personaje causa un retroceso al rival
                d->get_personaje()->SetVy(500);
                d->get_personaje()->SetVx(200);
            }
            if(c->get_personaje()->get_px()>d->get_personaje()->get_px()){
                d->get_personaje()->SetVy(500);
                d->get_personaje()->SetVx(-200);
            }

            //ui->lcdNumber->display(puntaje+50);//aumenta el puntaje de el jugador
            puntaje+=50;
            if(timer_salt->isActive()){}//si el timer de gravedad esta desactivado se activa
            else{
             // timer_salt->start(25);
            }
        }
    }
    else if(peleador==2){//los mismos comentarios del anterior condicional pero esta vez se aplica para el segundo jugador y el bot
        if((P2==0||P2==4)&&recuerdo2=='6'){
            d->setPixmap(QPixmap(":/capucho golpe2.png"));
        }
        else if((P2==0||P2==4)&&recuerdo2=='4'){
            d->setPixmap(QPixmap(":/capucho golpe.png"));
        }
        else if((P2==1||P2==5)&&recuerdo2=='6'){
            d->setPixmap(QPixmap(":/pegar7.png"));
        }
        else if((P2==1||P2==5)&&recuerdo2=='4'){
            d->setPixmap(QPixmap(":/pegarV.png"));
        }
        else if((P2==2||P2==6)&&recuerdo2=='6'){
            d->setPixmap(QPixmap(":/esmadG.png"));
        }
        else if((P2==2||P2==6)&&recuerdo2=='4'){
            d->setPixmap(QPixmap(":/esmadGV.png"));
        }

        if(d->collidesWithItem(c)==true)
        {
            if(p1==0){
                c-> setPixmap(QPixmap(":/capucho golpeadoV.png"));
            }
            else if(p1==1){
                c-> setPixmap(QPixmap(":/artes golpeadoV.png"));
            }
            else if(p1==2){
                c-> setPixmap(QPixmap(":/esmad golpeado.png"));
            }

            ui->progressBar->setValue(vida2-5);
            vida2-=5;
            if(poderJ2<=100){
                poderJ2+=10;
                ui->progressBar_4->setValue(poderJ2);
            }
            if(c->get_personaje()->get_px()>=d->get_personaje()->get_px()){
                c->get_personaje()->SetVy(500);
                c->get_personaje()->SetVx(200);
            }
            if(c->get_personaje()->get_px()<d->get_personaje()->get_px()){
                c->get_personaje()->SetVy(500);
                c->get_personaje()->SetVx(-200);
            }

            //ui->lcdNumber->display(puntaje-50);
            puntaje-=50;
            if(timer_salt->isActive()){}
            else{
                //timer_salt->start(25);
            }
                    }
        if(d->collidesWithItem(escudo_objet)==true && escudo==true){
            if(c->get_personaje()->get_px()>=d->get_personaje()->get_px()){
                c->get_personaje()->SetVy(1000);
                c->get_personaje()->SetVx(5000);
            }
            if(c->get_personaje()->get_px()<d->get_personaje()->get_px()){
                c->get_personaje()->SetVy(1000);
                c->get_personaje()->SetVx(-5000);
            }
        }
    }
}

void iniciar_juego::mover(char movida_player)
{
    if(movida_player=='A'){//mueve el objeto a la derecha
        tecla_presionada_p1=true;//indica que se esta presionando una tecla
        timer_pel->stop();
        if(c->collidesWithItem(escudo_objet2)==true&&escudo2==true){//accion al chocar con el escudo al intentar realizar el movimiento
             c->get_personaje()->SetVx(0);
        }
        if(c->collidesWithItem(nube)==true&&lacrimogena==true){//la accion de el personaje al interactuar con la nube de gas
            c->get_personaje()->SetVx(0);
            c->get_personaje()->setax(0);
            c->get_personaje()->set_px(c->get_personaje()->get_px()-3);//mueve el personaje a la izquierda
//             c->get_personaje()->set_px(c->get_personaje()->get_px()-vel);
//             c->get_personaje()->SetVx(c->get_personaje()->GetVx()-(vel/2));
        }
        else{
          c->get_personaje()->set_px(c->get_personaje()->get_px()-15);//mueve el personaje a la izquierda
          c->get_personaje()->SetVx(0);
          c->get_personaje()->setax(0);
        }
         on_actionstop_triggered();
         recuerdo='A';
         c->mov(p1,recuerdo);
    }
    else if(movida_player=='D'){//reaccion del personaje al precionar la tecla,por lo general moverse a la derecha
        tecla_presionada_p1=true;
        timer_pel->stop();
        if(c->collidesWithItem(escudo_objet2)==true&&escudo2==true){
             c->get_personaje()->SetVx(0);
        }
        else if(c->collidesWithItem(nube)==true&&lacrimogena==true){
             c->get_personaje()->SetVx(0);
             c->get_personaje()->setax(0);
             c->get_personaje()->set_px(c->get_personaje()->get_px()+3);
        }
        else{
          c->get_personaje()->set_px(c->get_personaje()->get_px()+15);
          c->get_personaje()->SetVx(0);
          c->get_personaje()->setax(0);
          //c->get_personaje()->SetVx(100);
          //c->get_personaje()->SetVx(c->get_personaje()->GetVx()+vel);
        }
        on_actionstop_triggered();
        recuerdo='D';
        c->mov(p1,recuerdo);
    }
    else if(movida_player=='W'){//realiza la accion de salto
        posi=c->get_personaje()->get_py();//coloca el valor iniicial en y
        recor_salto='W';
        if(recuerdo=='D'){//el jugador salta a la derecha
            if(c->get_personaje()->get_py()==-200){
                c->get_personaje()->SetVy(c->get_personaje()->GetVy()+1500);
                c->get_personaje()->SetVx(c->get_personaje()->GetVx()+200);
            }
                          }
        else{//el jugador salta a la izquierda
            if(c->get_personaje()->get_py()==-200){
                c->get_personaje()->SetVy(c->get_personaje()->GetVy()+1500);
                c->get_personaje()->SetVx(c->get_personaje()->GetVx()-200);
            }

        }
        c->salto(1,recuerdo,p1,1);//establece la imagen de salto
//        if(timer_salt->isActive()){}
//        else{
//          timer_salt->start(60);//llama a la funcion que le permite saltar al personaje
//        }

    }
    else if(movida_player=='4'){
        tecla_presionada_p2=true;//indica que se esta presionando una tecla, en este caso se esta presionando la tecla de salto
        timer_pel->stop();
        if(d->collidesWithItem(escudo_objet)==true&&escudo==true){
             d->get_personaje()->SetVx(0);
        }
        else if(d->collidesWithItem(nube)==true&&lacrimogena==true){
            d->get_personaje()->SetVx(1);
            d->get_personaje()->setax(0);
            d->get_personaje()->set_px(d->get_personaje()->get_px()-3);
        }
        else{
            d->get_personaje()->set_px(d->get_personaje()->get_px()-15);
            d->get_personaje()->SetVx(0);
            d->get_personaje()->setax(0);
            //d->get_personaje()->SetVx(100);
          //d->get_personaje()->SetVx(d->get_personaje()->GetVx()-50);
        }
         on_actionstop_triggered();
         recuerdo2='4';
         if(P2>3){
             if(P2==4){
                 seleccion_de_seleccion_de_personaje=0;//indica el personaje correspondiente a el bot para poder selecconar
             }
             if(P2==5){
                 seleccion_de_seleccion_de_personaje=1;
             }
             if(P2==6){
                 seleccion_de_seleccion_de_personaje=2;
             }
         }
         else if(P2<3){
             seleccion_de_seleccion_de_personaje=P2;
         }


         d->mov(seleccion_de_seleccion_de_personaje,recuerdo2);

    }
    else if(movida_player=='8'){//realiza la accion de salto de el personaje
        tecla_presionada_p2=true;
            posi=d->get_personaje()->get_py();
            flag=0;
            timer_pel->stop();
            on_actionstop_triggered();
           // timer_salt->stop();
            recor_salto='8';
            if(recuerdo2=='6'){//el jugador salta a la derecha
                if(d->get_personaje()->get_py()==-200){
                    d->get_personaje()->SetVy(d->get_personaje()->GetVy()+1000);
                    d->get_personaje()->SetVx(d->get_personaje()->GetVx()+700);
                }

            }
            else{//el jugador salta a la izquierda
                if(d->get_personaje()->get_py()==-200){
                    d->get_personaje()->SetVy(d->get_personaje()->GetVy()+1000);
                    d->get_personaje()->SetVx(d->get_personaje()->GetVx()-700);
                }
            }
           d->salto(2,recuerdo2,P2,2);
//            if(timer_salt->isActive()){}
//            else{
//              timer_salt->start(25);
//            }

    }
    else if(movida_player=='6'){//realiza la accion de mover el personaje a la izquierda
        tecla_presionada_p2=true;
        timer_pel->stop();
        //timer_salt->stop();
        if(d->collidesWithItem(escudo_objet)==true&&escudo==true){
             d->get_personaje()->SetVx(0);
        }
        if(d->collidesWithItem(nube)==true&&lacrimogena==true){
//             d->get_personaje()->SetVx(1);
//             d->get_personaje()->setax(0);
            d->get_personaje()->set_px(d->get_personaje()->get_px()+3);
        }
        else{
          d->get_personaje()->set_px(d->get_personaje()->get_px()+15);
          c->get_personaje()->SetVx(0);
          c->get_personaje()->setax(0);
          //d->get_personaje()->SetVx(100);
          //d->get_personaje()->SetVx(d->get_personaje()->GetVx()+vel);
        }

        on_actionstop_triggered();
         recuerdo2='6';
         if(P2==4){
             seleccion_de_seleccion_de_personaje=0;
         }
         if(P2==5){
             seleccion_de_seleccion_de_personaje=1;
         }
         if(P2==6){
             seleccion_de_seleccion_de_personaje=2;
         }
        d->mov(seleccion_de_seleccion_de_personaje,recuerdo2);//coloca la imagen de el personaje
    }

}

void iniciar_juego::on_actiongo_triggered()
{
    if(timer_mov->isActive()){}//genera una falsa ilucion de movimiento activando la funcion de cambio de imagen
    else{
      timer_mov->start(25);
    }
}

void iniciar_juego::on_actionstop_triggered()//detiene los timers de movimiento
{
    timer_mov->stop();
    timer_par->stop();
    i=0;
}

void iniciar_juego::on_pushButton_5_clicked()
{
    close();//se cierra la ventana
    modo_de_juego *menu = new modo_de_juego();menu->show();//abre el menu
}

void iniciar_juego::on_pushButton_6_clicked()
{
    close();//cierra la ventana
}

void iniciar_juego::on_pushButton_clicked()//quita la pausa para poder seguir jugando
{
    bloqueo=false;
    ui->label->setVisible(false);
    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(false);
}

void iniciar_juego::on_pushButton_3_clicked()
{
    close();
}
