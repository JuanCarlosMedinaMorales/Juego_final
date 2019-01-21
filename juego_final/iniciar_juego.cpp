#include "iniciar_juego.h"
#include "ui_iniciar_juego.h"
#include <QMovie>
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
    timer_proy=new QTimer(this);
    timer_escudo=new QTimer(this);

    scene=new QGraphicsScene(this);         //crea la scene
    scene->setSceneRect(0,0,h_limit,v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
    ui->graphicsView->setScene(scene);
    ui->centralwidget->adjustSize();
    ui->label_2->setVisible(false);
    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(false);

    scene->addRect(scene->sceneRect());
    timer_mov->stop();
    timer_pel->stop();
    timer_par->stop();
    timer_proy->stop();
    connect(timer_mov,SIGNAL(timeout()),this,SLOT(mov()));
    connect(timer_pel,SIGNAL(timeout()),this,SLOT(pegar()));
    connect(timer_par,SIGNAL(timeout()),this,SLOT(par()));
    connect(timer_salt,SIGNAL(timeout()),this,SLOT(salto()));
    connect(timer_grav,SIGNAL(timeout()),this,SLOT(grav()));
    connect(timer_proy,SIGNAL(timeout()),this,SLOT(mov_proyectil()));
    connect(timer_escudo,SIGNAL(timeout()),this,SLOT(duracion_escudo()));
     ui->graphicsView->setBackgroundBrush(QImage(":/5b734c53396e3_opt.jpg"));

//     mMediaPlayer->setMedia(QUrl::fromLocalFile(":/Amon_Amarth_-_Victorious_March_[Fanvideo].mp3"));
//     mMediaPlayer->setVolume(100);
//     mMediaPlayer->play();

     p1=jugador1;
     P2=jugador2;
    c=new grafica();
    d=new grafica();
    lacr=new grafica();
    nube=new grafica();
    escudo_objet=new grafica();
    escudo_objet->setPixmap(QPixmap(":/porro.png"));
    escudo_objet2=new grafica();
    scene->addEllipse(0,0,1,1);
    lacr->setPixmap(QPixmap(":/oie_wjRyGB5Cadu8.png"));
    if(jugador1!=4){
        if(jugador1==0){
            c->setPixmap(QPixmap(":/CCD1.png"));
        }
        if(jugador1==1){
            c->setPixmap(QPixmap(":/caminar1.png"));
        }
        if(jugador1==2){
            c->setPixmap(QPixmap(":/esmadEntero.png"));
        }
        if(jugador2==0){
            d->setPixmap(QPixmap(":/CCV1.png"));
        }
        if(jugador2==1){
            d->setPixmap(QPixmap(":/caminar1V.png"));
        }
        if(jugador2==2){
            d->setPixmap(QPixmap(":/esmadC1V.png"));
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
/////////////////// PORRO
//    porro->get_carro()->set_valores(500,500,100,100);
//    porro->get_carro()->SetVx(porro->get_carro()->GetVx()+1000);
//    porro->get_carro()->SetVy(porro->get_carro()->GetVy()+1000);
//    porro->posicion(v_limit);
//    scene->addItem(porro);
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
    if(vida2<=0){
        if(p1==0){
            c-> setPixmap(QPixmap(":/capucho morir 3.png"));
        }
        else if(p1==1){
            c-> setPixmap(QPixmap(":/artes morir 3s.png"));
        }
        else if(p1==2){
            c-> setPixmap(QPixmap(":/esmadM3.png"));
        }
        QSize size(1114,597);
        QMovie *mov=new QMovie(":/41.gif");
        mov->setSpeed(200);
        mov->setScaledSize(size);
        ui->label->setMovie(mov);
        mov->start();

         bloqueo=true;
    }
    if(vida<=0){
        if(P2==0){
            d-> setPixmap(QPixmap(":/capucho morir 3.png"));
        }
        else if(P2==1){
            d-> setPixmap(QPixmap(":/artes morir 3s.png"));
        }
        else if(P2==2){
            d-> setPixmap(QPixmap(":/esmadM3.png"));
        }
        QSize size(1114,597);
        QMovie *mov=new QMovie(":/41.gif");
        mov->setSpeed(300);
        mov->setScaledSize(size);
        ui->label->setMovie(mov);
        mov->start();
         bloqueo=true;
         timer_salt->stop();
         timer_grav->stop();
         timer_proy->stop();
    }
    if(event->key()==Qt::Key_C&&bloqueo==false)on_actiongo_triggered();
    if(event->key()==Qt::Key_P&&bloqueo==false){
        on_actionstop_triggered();
        bloqueo=true;
        ui->label_2->setVisible(true);
        ui->pushButton->setVisible(true);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_3->setVisible(true);
    }
    if(event->key()==Qt::Key_F4&&bloqueo==false) close();
    if(event->key()==Qt::Key_Z&&bloqueo==false){
        event->accept();
        if(p1==0&&recuerdo=='D'){
            c->setPixmap(QPixmap(":/capucho golpe2.png"));
        }
        else if(p1==0&&recuerdo=='A'){
            c->setPixmap(QPixmap(":/capucho golpe.png"));
        }
        else if(p1==1&&recuerdo=='D'){
            c->setPixmap(QPixmap(":/pegar7.png"));
        }
        else if(p1==1&&recuerdo=='A'){
            c->setPixmap(QPixmap(":/pegarV.png"));
        }
        else if(p1==2&&recuerdo=='D'){
            c->setPixmap(QPixmap(":/esmadG.png"));
        }
        else if(p1==2&&recuerdo=='A'){
            c->setPixmap(QPixmap(":/esmadGV.png"));
        }


        if(c->collidesWithItem(d)==true)
        {
            if(P2==0){
                d-> setPixmap(QPixmap(":/capucho golpeadoV.png"));
            }
            else if(P2==1){
                d-> setPixmap(QPixmap(":/artes golpeadoV.png"));
            }
            else if(P2==2){
                d-> setPixmap(QPixmap(":/esmad golpeado.png"));
            }

            ui->progressBar_2->setValue(vida-5);
            vida-=5;
            if(poder1_1!=100){
                if(poder1_1!=100){
                  poder1_1+=50;
                }
                ui->progressBar_3->setValue(poder1_1);
            }
            if(poder1_1==100){
                  poder2_1+=50;
                ui->progressBar_4->setValue(poder2_1);
            }
            if(c->get_carro()->get_px()<=d->get_carro()->get_px()){
                d->get_carro()->SetVy(1000);
                d->get_carro()->SetVx(5000);
            }
            if(c->get_carro()->get_px()>d->get_carro()->get_px()){
                d->get_carro()->SetVy(1000);
                d->get_carro()->SetVx(-5000);
            }

            ui->lcdNumber->display(puntaje+50);
            puntaje+=50;
            timer_salt->start(25);
        }


    }
    if(event->key()==Qt::Key_U&&bloqueo==false){
       //on_actionStop_triggered();
        //on_pegar();
        event->accept();

        if(P2==0&&recuerdo2=='6'){
            d->setPixmap(QPixmap(":/capucho golpe2.png"));
        }
        else if(P2==0&&recuerdo2=='4'){
            d->setPixmap(QPixmap(":/capucho golpe.png"));
        }
        else if(P2==1&&recuerdo2=='6'){
            d->setPixmap(QPixmap(":/pegar7.png"));
        }
        else if(P2==1&&recuerdo2=='4'){
            d->setPixmap(QPixmap(":/pegarV.png"));
        }
        else if(P2==2&&recuerdo2=='6'){
            d->setPixmap(QPixmap(":/esmadG.png"));
        }
        else if(P2==2&&recuerdo2=='4'){
            d->setPixmap(QPixmap(":/esmadGV.png"));
        }

        //c->pelea();
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
            if(poder1_2!=100){
                if(poder1_2<100){
                  poder1_2+=20;
                }
                ui->progressBar_5->setValue(poder1_2);
            }
            if(poder1_2==100){
                if(poder2_2<100){
                  poder2_2+=20;
                }
                ui->progressBar_6->setValue(poder2_2);
            }
            if(c->get_carro()->get_px()>=d->get_carro()->get_px()){
                c->get_carro()->SetVy(1000);
                c->get_carro()->SetVx(5000);
            }
            if(c->get_carro()->get_px()<d->get_carro()->get_px()){
                c->get_carro()->SetVy(1000);
                c->get_carro()->SetVx(-5000);
            }

            ui->lcdNumber->display(puntaje-50);
            puntaje-=50;
            timer_salt->start(25);
        }
        if(d->collidesWithItem(escudo_objet)==true && escudo==true){
            if(c->get_carro()->get_px()>=d->get_carro()->get_px()){
                c->get_carro()->SetVy(1000);
                c->get_carro()->SetVx(5000);
            }
            if(c->get_carro()->get_px()<d->get_carro()->get_px()){
                c->get_carro()->SetVy(1000);
                c->get_carro()->SetVx(-5000);
            }
        }


    }


    if(event->key()== Qt::Key_D && c->get_carro()->get_px()<950&&bloqueo==false)
    {
        timer_pel->stop();
        //timer_salt->stop();
        if(c->collidesWithItem(escudo_objet2)==true&&escudo2==true){
             c->get_carro()->SetVx(c->get_carro()->GetVx()/2);
             c->get_carro()->set_px(c->get_carro()->get_px()+vel-vel);
        }
        else if(c->collidesWithItem(nube)==true&&lacrimogena==true){
             c->get_carro()->set_px(c->get_carro()->get_px()+vel);
        }
        else{
          c->get_carro()->set_px(c->get_carro()->get_px()+vel+10);
        }

        on_actionstop_triggered();
        event->accept();
        recuerdo='D';
        c->mov(p1,recuerdo);

    }
    if(event->key()== Qt::Key_6 && c->get_carro()->get_px()<950&&bloqueo==false)
    {
        timer_pel->stop();
        //timer_salt->stop();
        if(d->collidesWithItem(escudo_objet)==true&&escudo==true){
             d->get_carro()->SetVx(d->get_carro()->GetVx()/2);
             d->get_carro()->set_px(d->get_carro()->get_px()+vel-vel);
        }
        if(d->collidesWithItem(nube)==true&&lacrimogena==true){
             d->get_carro()->SetVx(d->get_carro()->GetVx()/2);
             d->get_carro()->set_px(d->get_carro()->get_px()+vel);
        }
        else{
          d->get_carro()->set_px(d->get_carro()->get_px()+vel+10);
        }

        on_actionstop_triggered();
        event->accept();
         recuerdo2='6';
        d->mov(P2,recuerdo2);

    }
   if(event->key()== Qt::Key_A&& c->get_carro()->get_px()>0 && flag==1&&bloqueo==false)
    {
       timer_pel->stop();
       //timer_salt->stop();
       if(c->collidesWithItem(escudo_objet2)==true&&escudo2==true){
            c->get_carro()->SetVx(c->get_carro()->GetVx()/2);
            c->get_carro()->set_px(c->get_carro()->get_px()+vel-vel);
       }
       if(c->collidesWithItem(nube)==true&&lacrimogena==true){
            c->get_carro()->set_px(c->get_carro()->get_px()-vel);
       }
       else{
         c->get_carro()->set_px(c->get_carro()->get_px()-vel-10);
       }
        on_actionstop_triggered();
        event->accept();
        recuerdo='A';
        c->mov(p1,recuerdo);

    }
    if(event->key()== Qt::Key_W && c->get_carro()->get_py()<200&&bloqueo==false )
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
    if(event->key()== Qt::Key_8 && c->get_carro()->get_py()<200&&bloqueo==false )
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
   if(event->key()== Qt::Key_S && c->get_carro()->get_py()>0 && flag==1&&bloqueo==false)
    {
       timer_pel->stop();
       timer_salt->stop();
        c->get_carro()->set_py(c->get_carro()->get_py()-vel);
        on_actionstop_triggered();
        event->accept();
    }

   if (event->key()==Qt::Key_4&&bloqueo==false ){
       timer_pel->stop();
       //timer_salt->stop();

       if(d->collidesWithItem(escudo_objet)==true&&escudo==true){
            d->get_carro()->SetVx(d->get_carro()->GetVx()/2);
            d->get_carro()->set_px(d->get_carro()->get_px()+vel-vel);
       }
       if(d->collidesWithItem(nube)==true&&lacrimogena==true){
           d->get_carro()->SetVx(d->get_carro()->GetVx()/2);
            d->get_carro()->set_px(d->get_carro()->get_px()-vel);
       }
       else{
         d->get_carro()->set_px(d->get_carro()->get_px()-vel-10);
       }


        on_actionstop_triggered();
        event->accept();
        recuerdo2='4';
        d->mov(P2,recuerdo2);
   }
   if (event->key()==Qt::Key_O&&bloqueo==false ){
       timer_pel->stop();
       // d->get_carro()->set_px(d->get_carro()->get_px()-vel) ;
        //d->get_carro()->SetVx(-50);
        on_actionstop_triggered();
        event->accept();
        //d->mov();
        d->get_carro()->SetVy(d->get_carro()->GetVy()+200);
        d->get_carro()->SetVx(d->get_carro()->GetVx()+10);
   }
   if (event->key()==Qt::Key_V&&bloqueo==false ){
        S_lanzador=1;
        eliminado=false;
       float x=400;
       float y=800;
       float px=c->get_carro()->get_px();
       float py=c->get_carro()->get_py();
       if(recuerdo=='D'){
           lacr->get_carro()->SetVx(x);
           lacr->get_carro()->SetVy(y);
       }
       if(recuerdo=='A'){
           lacr->get_carro()->SetVx(x*-1);
           lacr->get_carro()->SetVy(y*-1);
       }

       lacr->get_carro()->set_px(px);
       lacr->get_carro()->set_py(py*-1);
       nube->get_carro()->SetVx(0);
       nube->get_carro()->SetVy(0);
       nube->get_carro()->set_valores(500,100,100,100);
       if(poder2_1>=100){
           if(p1==0){
               lacr->setPixmap(QPixmap(":/molotov C.png"));
               nube->setPixmap(QPixmap(":/fuego.png"));
               timer_grav->start(25);
               if(lacr->get_carro()->get_py()<200){
                   u=1;
               }
               timer_proy->start(50);

           }
           if(p1==1){
               S_lanzador=1;
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
               if(lacr->get_carro()->get_py()<200){
                   u=1;
               }

               timer_proy->start(50);


           }
           poder2_1=0;
           poder1_1=0;
           ui->progressBar_4->setValue(poder2_1);
           ui->progressBar_3->setValue(poder1_1);

       }
       if(poder1_1==100&&poder2_1<100){
           if(p1==0){
               escudo_objet->setPixmap(QPixmap(":/escudo C.png"));
           }
           if(p1==1){
               escudo_objet->setPixmap(QPixmap(":/escudo A.png"));
           }
           if(p1==2){
               escudo_objet->setPixmap(QPixmap(":/escudo E.png"));
           }
           escudo_objet->get_carro()->set_px(lacr->get_carro()->get_px());
           escudo_objet->get_carro()->set_py(lacr->get_carro()->get_py()-5);
           scene->addItem(escudo_objet);
           escudo=true;
           escudo_objet->posicion(v_limit);
           timer_escudo->start(50);
           conta_escudo=0;
           poder1_1=0;
           poder2_1=0;
           poder1_2=0;
           poder2_2=0;
           ui->progressBar_3->setValue(poder1_1);
           ui->progressBar_6->setValue(poder1_2);
           ui->progressBar_4->setValue(poder2_1);
           ui->progressBar_5->setValue(poder2_2);
       }



   }

   if (event->key()==Qt::Key_L&&bloqueo==false ){
       S_lanzador=2;
       eliminado=false;
      float x=400;
      float y=800;
      float px=d->get_carro()->get_px();
      float py=d->get_carro()->get_py();
      if(recuerdo=='6'){
          lacr->get_carro()->SetVx(x);
          lacr->get_carro()->SetVy(y);
      }
      if(recuerdo=='4'){
          lacr->get_carro()->SetVx(x*-1);
          lacr->get_carro()->SetVy(y*-1);
      }

      lacr->get_carro()->set_px(px);
      lacr->get_carro()->set_py(py*-1);
      nube->get_carro()->SetVx(0);
      nube->get_carro()->SetVy(0);
      nube->get_carro()->set_valores(500,100,100,100);
      if(poder1_2>=100){
          if(P2==0){
              lacr->setPixmap(QPixmap(":/molotov C.png"));
              nube->setPixmap(QPixmap(":/fuego.png"));
              timer_grav->start(25);
              if(lacr->get_carro()->get_py()<200){
                  u=1;
              }
              timer_proy->start(50);

          }
          if(P2==1){
              S_lanzador=1;
              lacr->setPixmap(QPixmap(":/hongo A.png"));
              nube->setPixmap(QPixmap(":/porro.png"));
              timer_grav->start(25);

              if(nube_activa==true){
                  nube->porro(v_limit);
              }
              timer_proy->start(50);


          }
          if(P2==2){
              lacr->setPixmap(QPixmap(":/oie_wjRyGB5Cadu8.png"));
              nube->setPixmap(QPixmap(":/nube gas.png"));
              timer_grav->start(25);
              if(lacr->get_carro()->get_py()<200){
                  u=1;
              }

              timer_proy->start(50);


          }
          poder1_2=0;
          poder2_2=0;
          ui->progressBar_4->setValue(poder2_2);
          ui->progressBar_3->setValue(poder1_2);

      }
      if(poder2_2==100&&poder1_2<100){
          if(P2==0){
              escudo_objet2->setPixmap(QPixmap(":/escudo C.png"));
          }
          if(P2==1){
              escudo_objet2->setPixmap(QPixmap(":/escudo A.png"));
          }
          if(P2==2){
              escudo_objet2->setPixmap(QPixmap(":/escudo E.png"));
          }
          escudo_objet2->get_carro()->set_px(lacr->get_carro()->get_px());
          escudo_objet2->get_carro()->set_py(lacr->get_carro()->get_py()-5);
          scene->addItem(escudo_objet2);
          escudo2=true;
          escudo_objet2->posicion(v_limit);
          timer_escudo->start(50);
          conta_escudo2=0;
          poder1_1=0;
          poder2_1=0;
          poder1_2=0;
          poder2_2=0;
          ui->progressBar_3->setValue(poder1_1);
          ui->progressBar_6->setValue(poder1_2);
          ui->progressBar_4->setValue(poder2_1);
          ui->progressBar_5->setValue(poder2_2);
      }

   }


//timer_pel->stop();
//c->pelea();
//timer_salt->start();

c->posicion(v_limit);
d->posicion(v_limit);
//lacr->posicion(v_limit);
//porro->posicion(v_limit);
//if(tie==10){
//    scene->removeItem(nube);
//    tie=0;

//}
//tie++;

}

void iniciar_juego::on_pegar()
{
    timer_pel->start(25);
}

void iniciar_juego::mov()
{
    if(c->get_carro()->GetVy()>sp){
        c->salto(2,recuerdo,p1,1);
        sp=c->get_carro()->GetVy();
    }
    else{
        c->mov(p1,recuerdo);
        cont=0;
    }
    if(d->get_carro()->GetVy()>sp){
        d->salto(2,recuerdo,p1,2);
        sp=d->get_carro()->GetVy();
    }
    else{
        d->mov(P2,recuerdo2);
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
                c->salto(1,recuerdo,p1,1);


            }
            else if(c->get_carro()->GetVy()<=0){
                c->salto(2,recuerdo,p1,1);
                flag=1;
            }
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
               d->salto(1,recuerdo,p1,2);


            }
            else if(d->get_carro()->GetVy()<=0){
                d->salto(2,recuerdo2,P2,2);
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
////////////////////////////////////////PORRO
//    if(porro->get_carro()->get_px()>700||porro->get_carro()->get_px()<500){
//        porro->get_carro()->SetVx(porro->get_carro()->GetVx()*-1);

//    }
//    if(porro->get_carro()->get_py()<0||porro->get_carro()->get_py()>200){
//        porro->get_carro()->SetVy(porro->get_carro()->GetVy()*-1);

//    }
    c->posicion(v_limit);
    d->posicion(v_limit);
//    porro->posicion(v_limit);


}

void iniciar_juego::grav()
{
 lacr->posicion(v_limit);
 if(lacr->get_carro()->get_py()>200&&u==0){
   scene->addItem(lacr);
    u++;
 }

 if(lacr->get_carro()->get_py()<200&&u==1){
     if(p1!=1&&S_lanzador==1){
         nube->get_carro()->set_px(lacr->get_carro()->get_px());
         nube->get_carro()->set_py(lacr->get_carro()->get_py());
         scene->addItem(nube);
         nube_activa=true;
         nube->posicion(v_limit);
         scene->removeItem(lacr);
         u=0;


     }
     if(P2!=1&&S_lanzador==2){
         nube->get_carro()->set_px(lacr->get_carro()->get_px());
         nube->get_carro()->set_py(lacr->get_carro()->get_py());
         scene->addItem(nube);
         nube_activa=true;
         nube->posicion(v_limit);
         scene->removeItem(lacr);
         u=0;


     }

     else{
         //nube->get_carro()->set_valores(500,500,100,100);
         nube->get_carro()->SetVx(10);
         nube->get_carro()->SetVy(10);
         lacr->get_carro()->set_py(200);
         lacr->get_carro()->SetVy(lacr->get_carro()->GetVy()*-1);
         lacr->get_carro()->SetVy(lacr->get_carro()->GetVy()+incremento);
         incremento=incremento*2;





         //nube->posicion(v_limit);

     }
 }
 if(lacr->get_carro()->get_px()>900||lacr->get_carro()->get_px()<10){
     lacr->get_carro()->SetVx(lacr->get_carro()->GetVx()*-1);
 }
 if(p1==1||P2==1){
     if(S_lanzador==1){
         if(lacr->collidesWithItem(d)){
             u=1;
             if(eliminado==false){
                 scene->removeItem(lacr);
                 scene->addItem(nube);
                 eliminado=true;
                 nube_activa=true;
                 ui->graphicsView->setBackgroundBrush(QImage(":/droga orgins.jpg"));


             }


             nube->porro(v_limit);



         }
         else if(nube_activa==true&&eliminado==true){
             nube->porro(v_limit);
         }
     }
     if(S_lanzador==2){
         if(lacr->collidesWithItem(c)){
             if(eliminado==false){
                 scene->removeItem(lacr);
                 scene->addItem(nube);
                 eliminado=true;
                 u=0;
                 nube_activa2=true;
                 ui->graphicsView->setBackgroundBrush(QImage(":/droga orgins.jpg"));
             }


             nube->porro(v_limit);



         }
         else if(nube_activa==true&&eliminado==true){
             nube->porro(v_limit);
         }
     }
 }

}

void iniciar_juego::mov_proyectil()
{
    if(nube_activa==true){
        conta_proyectil++;
    }
    if(nube_activa2==true){
        conta_proyectil2++;
    }


    if(S_lanzador==1){

        if(p1==0){
            if(nube->collidesWithItem(d)==true&&nube_activa==true){
                ui->progressBar_2->setValue(vida-20);
                vida-=20;
            }
        }
        if(p1==1){
            //nube->porro(v_limit);
            if(nube->collidesWithItem(d)==true&&nube_activa==true){
                ui->progressBar_2->setValue(vida-20);
                vida-=20;
                if(c->get_carro()->get_px()<=d->get_carro()->get_px()){
                    d->get_carro()->SetVy(1000);
                    d->get_carro()->SetVx(5000);
                }
                if(c->get_carro()->get_px()>d->get_carro()->get_px()){
                    d->get_carro()->SetVy(1000);
                    d->get_carro()->SetVx(-5000);
                }
                timer_salt->start(25);
            }
        }
        if(p1==2){
            if(nube->collidesWithItem(d)==true&&nube_activa==true){
               lacrimogena=true;
            }
            else{
                lacrimogena=false;
            }

        }
    }
    if(S_lanzador==2){

        if(p1==0){
            if(nube->collidesWithItem(c)==true&&nube_activa==true){
                ui->progressBar->setValue(vida2-20);
                vida2-=20;
            }
        }
        if(p1==1){
            nube->porro(v_limit);
            if(nube->collidesWithItem(c)==true&&nube_activa==true){
                ui->progressBar->setValue(vida2-20);
                vida2-=20;
                if(c->get_carro()->get_px()<=d->get_carro()->get_px()){
                    c->get_carro()->SetVy(1000);
                    c->get_carro()->SetVx(5000);
                }
                if(c->get_carro()->get_px()>d->get_carro()->get_px()){
                    c->get_carro()->SetVy(1000);
                    c->get_carro()->SetVx(-5000);
                }
                timer_salt->start(25);
            }
        }
        if(p1==2){
            if(nube->collidesWithItem(c)==true&&nube_activa==true){
               lacrimogena=true;
            }

        }
    }

    if(conta_proyectil==200){
        scene->removeItem(nube);
        scene->removeItem(lacr);
        conta_proyectil=0;
        nube_activa=false;
        ui->graphicsView->setBackgroundBrush(QImage(":/5b734c53396e3_opt.jpg"));
        u=0;
        //lacrimogena=false;
    }
    if(conta_proyectil2==200){
        scene->removeItem(nube);
        scene->removeItem(lacr);
        conta_proyectil=0;
        nube_activa=false;
        ui->graphicsView->setBackgroundBrush(QImage(":/5b734c53396e3_opt.jpg"));
        u=0;
        //lacrimogena=false;
    }

}

void iniciar_juego::duracion_escudo()
{
    if(S_lanzador==1){
       conta_escudo++;
    }
    if(S_lanzador==2){
       conta_escudo2++;
    }
    if(conta_escudo==200){
        if(S_lanzador==1){
          scene->removeItem(escudo_objet);
        }


        conta_escudo=0;
        escudo=false;

    }
    if(conta_escudo2==200){

        if(S_lanzador==2){
            scene->removeItem(escudo_objet2);
        }

        conta_escudo2=0;
        escudo2=false;

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

void iniciar_juego::on_pushButton_clicked()
{
    bloqueo=false;
    ui->label_2->setVisible(false);
    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(false);
}
