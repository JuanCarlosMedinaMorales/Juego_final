#include "iniciar_juego.h"
#include "ui_iniciar_juego.h"
#include "qmediaplayer.h"
#include <QFileDialog>

iniciar_juego::iniciar_juego(int jugador1,int jugador2,QWidget *parent) :
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
    timer_grav= new QTimer(this);
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
    connect(timer_grav,SIGNAL(timeout()),this,SLOT(grav()));
     ui->graphicsView->setBackgroundBrush(QImage(":/5b734c53396e3_opt.jpg"));

     mMediaPlayer->setMedia(QUrl::fromLocalFile(":/Amon_Amarth_-_Victorious_March_[Fanvideo].mp3"));
     mMediaPlayer->setVolume(100);
     mMediaPlayer->play();

    c=new grafica();
    d=new grafica();
    lacr=new grafica();
    nube=new grafica();
    scene->addEllipse(0,0,1,1);
    lacr->setPixmap(QPixmap(":/oie_wjRyGB5Cadu8.png"));
    if(jugador1!=4){
        if(jugador1==1){
            c->setPixmap(QPixmap(":/CCD1.png"));
        }
        if(jugador1==2){
            c->setPixmap(QPixmap(":/caminar1.png"));
        }
        if(jugador1==3){
            c->setPixmap(QPixmap(":/esmadEntero.png"));
        }
        if(jugador2==1){
            d->setPixmap(QPixmap(":/CCV1.png"));
        }
        if(jugador2==2){
            d->setPixmap(QPixmap(":/caminar1V.png"));
        }
        if(jugador2==3){
            d->setPixmap(QPixmap(":/esmadEntero.png"));
        }
    }
    else{
        d->setPixmap(QPixmap(":/porro.png"));
    }
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
    scene->setFocusItem(scene->addEllipse(1,1,2,1));
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
        recuerdo='D';
        c->mov(0,recuerdo);

    }
    if(event->key()== Qt::Key_6 && c->get_carro()->get_px()<950)
    {
        timer_pel->stop();
        timer_salt->stop();
        d->get_carro()->set_px(d->get_carro()->get_px()+vel);
        on_actionstop_triggered();
        event->accept();
         recuerdo2='6';
        d->mov(1,recuerdo2);

    }
   if(event->key()== Qt::Key_A&& c->get_carro()->get_px()>0 && flag==1)
    {
       timer_pel->stop();
       timer_salt->stop();
        c->get_carro()->set_px(c->get_carro()->get_px()-vel) ;
        on_actionstop_triggered();
        event->accept();
        recuerdo='A';
        c->mov(0,recuerdo);

    }
    if(event->key()== Qt::Key_W && c->get_carro()->get_py()<200 )
    {

            posi=c->get_carro()->get_py();
            flag=0;
            timer_pel->stop();
            on_actionstop_triggered();
            timer_salt->stop();
            event->accept();
            recor_salto='W';
            timer_salt->start(25);

    }
    if(event->key()== Qt::Key_8 && c->get_carro()->get_py()<200 )
    {

            posi=d->get_carro()->get_py();
            flag=0;
            timer_pel->stop();
            on_actionstop_triggered();
            timer_salt->stop();
            event->accept();
            recor_salto='8';
            timer_salt->start(25);


    }
   if(event->key()== Qt::Key_S && c->get_carro()->get_py()>0 && flag==1)
    {
       timer_pel->stop();
       timer_salt->stop();
        c->get_carro()->set_py(c->get_carro()->get_py()-vel);
        on_actionstop_triggered();
        event->accept();
    }

   if (event->key()==Qt::Key_4 ){
       timer_pel->stop();
       timer_salt->stop();
        d->get_carro()->set_px(d->get_carro()->get_px()-vel) ;
        //d->get_carro()->SetVx(-50);
        on_actionstop_triggered();
        event->accept();
        recuerdo2='4';
        d->mov(1,recuerdo2);
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
       float x=500;
       float y=1000;
       float px=c->get_carro()->get_px();
       float py=c->get_carro()->get_py();
       lacr->setPixmap(QPixmap(":/oie_wjRyGB5Cadu8.png"));
       lacr->get_carro()->SetVx(x);
       lacr->get_carro()->SetVy(y);
       lacr->get_carro()->set_px(px);
       lacr->get_carro()->set_py(py*-1);
       nube->setPixmap(QPixmap(":/nube gas.png"));
       nube->get_carro()->SetVx(0);
       nube->get_carro()->SetVy(0);
       timer_grav->start(25);
       if(lacr->get_carro()->get_py()<200){
           u=1;
       }

   }

   if (event->key()==Qt::Key_X ){
       float x=500;
       float y=1000;
       float px=d->get_carro()->get_px();
       float py=d->get_carro()->get_py();
       lacr->setPixmap(QPixmap(":/porro.png"));
       lacr->get_carro()->SetVx(x);
       lacr->get_carro()->SetVy(y);
       lacr->get_carro()->set_px(px);
       lacr->get_carro()->set_py(py*-1);
       nube->setPixmap(QPixmap(":/nube gas.png"));
       nube->get_carro()->SetVx(0);
       nube->get_carro()->SetVy(0);
       timer_grav->start(25);
       if(lacr->get_carro()->get_py()<200){
           u=1;
       }

   }


//timer_pel->stop();
//c->pelea();
//timer_salt->start();

c->posicion(v_limit);
d->posicion(v_limit);
lacr->posicion(v_limit);
if(tie==10){
    scene->removeItem(nube);
    tie=0;

}
tie++;

}

void iniciar_juego::on_pegar()
{
    timer_pel->start(25);
}

void iniciar_juego::mov()
{
    if(c->get_carro()->GetVy()>sp){
        c->salto(2);
        sp=c->get_carro()->GetVy();
    }
    else{
        c->mov(0,recuerdo);
        cont=0;
    }
    if(d->get_carro()->GetVy()>sp){
        d->salto(2);
        sp=d->get_carro()->GetVy();
    }
    else{
        d->mov(1,recuerdo2);
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
    if(recor_salto=='W'){
        if(c->get_carro()->get_py()<=-200){
            if(flag==0){
               flag=1;
               if(recuerdo=='D'){
                  c->get_carro()->SetVy(c->get_carro()->GetVy()+1000);
                  c->get_carro()->SetVx(c->get_carro()->GetVx()+200);
               }
               else{
                  c->get_carro()->SetVy(c->get_carro()->GetVy()+1000);
                  c->get_carro()->SetVx(c->get_carro()->GetVx()-200);
               }



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
               if(recuerdo=='D'){
                   c->get_carro()->SetVx(c->get_carro()->GetVx()+200);
               }
               else{
                   c->get_carro()->SetVx(c->get_carro()->GetVx()-200);
               }

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
    }
    if(recor_salto=='8'){
        if(d->get_carro()->get_py()<=-200){
            if(flag==0){
               flag=1;
               if(recuerdo2=='6'){
                  d->get_carro()->SetVy(d->get_carro()->GetVy()+1000);
                  d->get_carro()->SetVx(d->get_carro()->GetVx()+200);
               }
               else{
                  d->get_carro()->SetVy(d->get_carro()->GetVy()+1000);
                  d->get_carro()->SetVx(d->get_carro()->GetVx()-200);
               }



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
            if(d->get_carro()->get_py()==posi ){
               d->get_carro()->SetVy(d->get_carro()->GetVy()+1000);
               if(recuerdo=='D'){
                   d->get_carro()->SetVx(d->get_carro()->GetVx()+200);
               }
               else{
                   d->get_carro()->SetVx(d->get_carro()->GetVx()-200);
               }

            }
            if(d->get_carro()->GetVy()>0){
               // d->setPixmap(QPixmap(""))


            }
            else if(d->get_carro()->GetVy()<=0){
                d->salto(2);
                flag=1;
            }
    //        c->posicion(v_limit);
    //        d->posicion(v_limit);
            if(d->get_carro()->get_px()>=950){
                flag=1;

                timer_salt->stop();
            }



        }
        else if(flag==2){
            timer_salt->stop();
            flag=1;
        }
    }

    c->posicion(v_limit);
    d->posicion(v_limit);

}

void iniciar_juego::grav()
{
 lacr->posicion(v_limit);
 if(lacr->get_carro()->get_py()>200&&u==1){
   scene->addItem(lacr);

 }

 if(lacr->get_carro()->get_py()<200&&u==1){
     nube->get_carro()->set_px(lacr->get_carro()->get_px());
     nube->get_carro()->set_py(lacr->get_carro()->get_py());
     scene->addItem(nube);
     nube->posicion(v_limit);
     scene->removeItem(lacr);
     u++;

 }

}



void iniciar_juego::on_actiongo_triggered()
{
    timer_mov->start(25);
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
