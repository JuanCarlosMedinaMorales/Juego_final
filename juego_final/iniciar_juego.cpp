#include "iniciar_juego.h"
#include "ui_iniciar_juego.h"
#include "qmediaplayer.h"
#include <QFileDialog>

iniciar_juego::iniciar_juego(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::iniciar_juego)
{
    ui->setupUi(this);
    mMediaPlayer = new QMediaPlayer(this);
    h_limit=1000;                  //Asigna los valores leidos el archivo
    v_limit=593;
    timer_mov = new QTimer(this);
    timer_par = new QTimer(this);
    timer_pel= new QTimer(this);
    timer_salt= new QTimer(this);
    scene=new QGraphicsScene(this);         //crea la scene
    scene->setSceneRect(0,0,h_limit,v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
    ui->graphicsView->setScene(scene);
    ui->centralwidget->adjustSize();

    scene->addRect(scene->sceneRect());
    timer_mov->stop();
    timer_pel->stop();
    timer_par->stop();
    connect(timer_mov,SIGNAL(timeout()),this,SLOT(mov()));
    connect(timer_pel,SIGNAL(timeout()),this,SLOT(pegar()));
    connect(timer_par,SIGNAL(timeout()),this,SLOT(par()));
    connect(timer_salt,SIGNAL(timeout()),this,SLOT(salto()));

     ui->graphicsView->setBackgroundBrush(QImage(":/5b734c53396e3_opt.jpg"));
     //QString nombre=QFileDialog::getOpenFileName(this,":/Images/Contra_(NES)_Music_-_Jungle_Theme.mp3");
     mMediaPlayer->setMedia(QUrl::fromLocalFile(":/Contra_(NES)_Music_-_Jungle_Theme.mp3"));
     mMediaPlayer->setVolume(100);
     mMediaPlayer->play();

    c=new grafica();
    d=new grafica();
    lacr=new grafica();
    lacr->setPixmap(QPixmap(":/oie_wjRyGB5Cadu8.png"));
    d->setPixmap(QPixmap(":/CCV1.png"));
    if(flag==0){
        timer_salt->stop();
        timer_salt->start();
        timer_pel->stop();
        c->get_carro()->CalcularPosicion();
       // c->get_carro()->set_py(c->get_carro()->get_py()+vel);
        on_actionstop_triggered();

        if(c->get_carro()->GetVy()==0){
            flag=1;
        }
    }

    c->get_carro()->set_valores(0,-450,450,450);
    c->posicion(v_limit);
    scene->addItem(c);
    setFocus();
    d->get_carro()->set_valores(600,-450,450,450);
    d->posicion(v_limit);
    scene->addItem(d);
    //scene->setFocusItem(d);
    vel=3;
    i=0;


}

iniciar_juego::~iniciar_juego()
{
    delete ui;
}

void iniciar_juego::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_C)on_actiongo_triggered();
    if(event->key()==Qt::Key_P)on_actionstop_triggered();
    if(event->key()==Qt::Key_F4) close();
    if(event->key()==Qt::Key_Z){
       //on_actionStop_triggered();
        on_pegar();
        event->accept();
        c->pelea();
        d-> setPixmap(QPixmap(":/saltar2.png"));;
        if(c->collidesWithItem(d)==true)
        {
            ui->progressBar_2->setValue(vida-20);
            vida-=20;
            d->get_carro()->SetVy(1000);
            d->get_carro()->SetVx(5000);
            ui->lcdNumber->display(puntaje+50);
            puntaje+=50;
        }


    }

    if(event->key()== Qt::Key_D && c->get_carro()->get_px()<950)
    {
        timer_pel->stop();
        timer_salt->stop();
        c->get_carro()->set_px(c->get_carro()->get_px()+vel);
        on_actionstop_triggered();
        event->accept();
        c->mov(0);
        recuerdo='D';
    }
    if(event->key()== Qt::Key_6 && c->get_carro()->get_px()<950)
    {
        timer_pel->stop();
        timer_salt->stop();
        d->get_carro()->set_px(d->get_carro()->get_px()+vel);
        on_actionstop_triggered();
        event->accept();
        d->mov(1);
        recuerdo='6';
    }
   if(event->key()== Qt::Key_A&& c->get_carro()->get_px()>0 && flag==1)
    {
       timer_pel->stop();
       timer_salt->stop();
        c->get_carro()->set_px(c->get_carro()->get_px()-vel) ;
        on_actionstop_triggered();
        event->accept();
        c->mov(0);
        recuerdo='A';
    }
    if(event->key()== Qt::Key_W && c->get_carro()->get_py()<200 )
    {

            posi=c->get_carro()->get_py();
            flag=0;
            timer_pel->stop();
            on_actionstop_triggered();
            timer_salt->stop();
            event->accept();
            timer_salt->start(50);


        recuerdo='W';

    }
    if(event->key()== Qt::Key_8 && c->get_carro()->get_py()<200 )
    {

            posi=d->get_carro()->get_py();
            flag=0;
            timer_pel->stop();
            on_actionstop_triggered();
            timer_salt->stop();
            event->accept();
            d->get_carro()->SetVy(d->get_carro()->GetVy()+1000);


        recuerdo='W';

    }
   if(event->key()== Qt::Key_S && c->get_carro()->get_py()>0 && flag==1)
    {
       timer_pel->stop();
       timer_salt->stop();
        c->get_carro()->set_py(c->get_carro()->get_py()-vel);
        on_actionstop_triggered();
        event->accept();
        c->mov(0);
        recuerdo='S';
    }
   if(event->key()== Qt::Key_M)
    {
       timer_pel->stop();
       timer_salt->stop();
       on_actionstop_triggered();
        timer_par->start();
        event->accept();
        c->mov(0);
    }
   if (event->key()==Qt::Key_4 ){
       timer_pel->stop();
       timer_salt->stop();
        d->get_carro()->set_px(d->get_carro()->get_px()-vel) ;
        //d->get_carro()->SetVx(-50);
        on_actionstop_triggered();
        event->accept();
        d->mov(1);
   }
   if (event->key()==Qt::Key_O ){
       timer_pel->stop();
       // d->get_carro()->set_px(d->get_carro()->get_px()-vel) ;
        //d->get_carro()->SetVx(-50);
        on_actionstop_triggered();
        event->accept();
        //d->mov();
        d->get_carro()->SetVy(d->get_carro()->GetVy()+200);
        d->get_carro()->SetVx(d->get_carro()->GetVx()+10);
   }
   if (event->key()==Qt::Key_V ){
       float x=30;
       float y=30;
       float g=-3;
       lista.append(new grafica());
       lista.last()->setPixmap(QPixmap(":/oie_wjRyGB5Cadu8.png"));
       lista.last()->get_carro()->SetVx(x);
       lista.last()->get_carro()->SetVy(y);
       scene->addItem(lista.last());
       //lista.last()->get_carro()->set_valores(c->get_carro()->get_px(),c->get_carro()->get_py(),450,450);
        lista.last()->get_carro()->set_px(c->get_carro()->get_px());
        lista.last()->get_carro()->set_py(c->get_carro()->get_py());
//        for(int i=0;i<5;i++){

//            lista.append(lacr);
//            lista.last()->get_carro()->SetVx(x);
//            lista.last()->get_carro()->SetVy(y);


//             g=g*-1;
//            x=x*g;
//            y=y*2;
//            scene->addItem(lista.last());
//            lista.last()->setPos(c->get_carro()->get_px(),c->get_carro()->get_py());

//        }
   }



c->mov(0);
//timer_pel->stop();
//c->pelea();
//timer_salt->start();
c->posicion(v_limit);
d->posicion(v_limit);

}

void iniciar_juego::on_pegar()
{
    timer_pel->start(50);
}

void iniciar_juego::mov()
{
    if(c->get_carro()->GetVy()>sp){
        c->salto(2);
        sp=c->get_carro()->GetVy();
    }
    else{
        c->mov(0);
        cont=0;
    }
    if(d->get_carro()->GetVy()>sp){
        d->salto(2);
        sp=d->get_carro()->GetVy();
    }
    else{
        d->mov(1);
        cont=0;
    }
}

void iniciar_juego::par()
{
    if (i==0){
    c->get_carro()->set_px(100);
    c->get_carro()->set_py(300);
    i=1;
    }
    if (c->get_carro()->get_py()>0) c->par(v_limit);
}

void iniciar_juego::pegar()
{
    timer_mov->stop();
    timer_par->stop();
    c->pelea();
    cont=1;
    d->posicion(v_limit);
}

void iniciar_juego::salto()
{
    if(c->get_carro()->get_py()<=-200){
        if(flag==0){
           flag=1;
            c->get_carro()->SetVy(c->get_carro()->GetVy()+1000);


        }
        else {
            flag=2;
            timer_salt->stop();
        }


    }
    else{
        flag=0;

    }
    if(flag ==0 || flag==1){
        if(c->get_carro()->get_py()==posi ){
           c->get_carro()->SetVy(c->get_carro()->GetVy()+1000);

        }
        if(c->get_carro()->GetVy()>0){
            c->salto(1);


        }
        else if(c->get_carro()->GetVy()<=0){
            c->salto(2);
            flag=1;
        }
//        c->posicion(v_limit);
//        d->posicion(v_limit);
        if(c->get_carro()->get_px()>=950){
            flag=1;

            timer_salt->stop();
        }



    }
    else if(flag==2){
        timer_salt->stop();
        flag=1;
    }
    c->posicion(v_limit);
    d->posicion(v_limit);
}



void iniciar_juego::on_actiongo_triggered()
{
    timer_mov->start(50);
}

void iniciar_juego::on_actionstop_triggered()
{
    timer_mov->stop();
    timer_par->stop();
    i=0;
}


void iniciar_juego::on_progressBar_valueChanged(int value)
{

}
