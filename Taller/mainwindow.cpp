#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmediaplayer.h"
#include <QFileDialog>
#include <QList>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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
    ui->centralWidget->adjustSize();


    scene->addRect(scene->sceneRect());
    timer_mov->stop();
    timer_pel->stop();
    timer_par->stop();
    connect(timer_mov,SIGNAL(timeout()),this,SLOT(mov()));
    connect(timer_pel,SIGNAL(timeout()),this,SLOT(pegar()));
    connect(timer_par,SIGNAL(timeout()),this,SLOT(par()));
    connect(timer_salt,SIGNAL(timeout()),this,SLOT(salto()));
     ui->graphicsView->setBackgroundBrush(QImage(":/Images/5b734c53396e3_opt.jpg"));
     //QString nombre=QFileDialog::getOpenFileName(this,":/Images/Contra_(NES)_Music_-_Jungle_Theme.mp3");
     mMediaPlayer->setMedia(QUrl::fromLocalFile("Contra_(NES)_Music_-_Jungle_Theme.mp3"));
     mMediaPlayer->setVolume(100);
     mMediaPlayer->play();

    grafica *cuerpo1;
    c=new grafica();
    QList<grafica*> l;
    l.append(c);
    l.last()->setPixmap(QPixmap(":/Images/caminar1.png"));


    d=new grafica();
    l.append(d);
    l.last()->setPixmap(QPixmap(":/Images/pegar5.png"));

    if(flag==0){
        timer_salt->stop();
        timer_salt->start();
        timer_pel->stop();
        c->get_carro()->CalcularPosicion();
       // c->get_carro()->set_py(c->get_carro()->get_py()+vel);
        on_actionStop_triggered();

        if(c->get_carro()->GetVy()==0){
            flag=1;
        }
    }

    c->get_carro()->set_valores(0,-450,450,450);
    c->posicion(v_limit);
    scene->addItem(c);
    scene->setFocusItem(c);
    d->get_carro()->set_valores(600,-450,450,450);
    d->posicion(v_limit);
    scene->addItem(d);
    scene->setFocusItem(d);
    vel=3;
    i=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionGo_triggered()
{
    timer_mov->start(50);
}

void MainWindow::on_pegar()
{
    timer_pel->start(50);
}

void MainWindow::mov()
{
    if(c->get_carro()->GetVy()>sp){
        c->salto(2);
        sp=c->get_carro()->GetVy();
    }
    else{
        c->mov();
        cont=0;
    }
    if(d->get_carro()->GetVy()>sp){
        d->salto(2);
        sp=d->get_carro()->GetVy();
    }
    else{
        d->mov();
        cont=0;
    }

}
void MainWindow::par()
{

if (i==0){
c->get_carro()->set_px(100);
c->get_carro()->set_py(300);
i=1;
}
if (c->get_carro()->get_py()>0) c->par(v_limit);
}


void MainWindow::on_actionStop_triggered()
{
    timer_mov->stop();
    timer_par->stop();
    i=0;
}

void MainWindow::pegar()
{
    timer_mov->stop();
    timer_par->stop();
    c->pelea();
    cont=1;
//    if(c->get_contador()==5){
//        timer_pel->stop();
    //    }
}

void MainWindow::salto()
{
    if(flag ==0){
        //c->salto(1);
        if(c->get_carro()->get_py()==posi ){
           c->get_carro()->SetVy(c->get_carro()->GetVy()+1000);

        }

        if(c->get_carro()->GetVy()>0){
            c->salto(1);

        }
        else if(c->get_carro()->GetVy()<=0){
            c->salto(2);
        }
        c->posicion(v_limit);
        d->posicion(v_limit);
        if(c->get_carro()->get_px()>=950){
            flag=1;

            timer_salt->stop();
        }



    }
    else{
        timer_salt->stop();
    }

    //c->get_carro()->SetVx();
}

void MainWindow::keyPressEvent(QKeyEvent *event){       //Funciones de teclas
    if(event->key()==Qt::Key_C)on_actionGo_triggered();
    if(event->key()==Qt::Key_P)on_actionStop_triggered();
    if(event->key()==Qt::Key_F4) close();
    if(event->key()==Qt::Key_Z){
       //on_actionStop_triggered();
        on_pegar();
        event->accept();
        c->pelea();
        d-> setPixmap(QPixmap(":/Images/saltar2.png"));;

            if(c->collidesWithItem(d)==true)
            {
                ui->progressBar->setValue(vida-20);
                vida-=20;
            }

    }

    if(event->key()== Qt::Key_D && c->get_carro()->get_px()<950)
    {
        timer_pel->stop();
        timer_salt->stop();
        c->get_carro()->set_px(c->get_carro()->get_px()+vel);
        d->get_carro()->set_px(d->get_carro()->get_px()-vel);
        on_actionStop_triggered();
        event->accept();
        c->mov();
        d->mov();
        recuerdo='D';
    }
   if(event->key()== Qt::Key_A&& c->get_carro()->get_px()>0 && flag==1)
    {
       timer_pel->stop();
       timer_salt->stop();
        c->get_carro()->set_px(c->get_carro()->get_px()-vel) ;
        d->get_carro()->set_px(d->get_carro()->get_px()+vel);
        on_actionStop_triggered();
        event->accept();
        c->mov();
        d->mov();
        recuerdo='A';
    }
    if(event->key()== Qt::Key_W && c->get_carro()->get_py()<200 )
    {

            posi=c->get_carro()->get_py();
            flag=0;
            timer_pel->stop();
           // c->get_carro()->set_py(c->get_carro()->get_py()+vel);
            on_actionStop_triggered();
            timer_salt->stop();
            event->accept();
            timer_salt->start(90);


        recuerdo='W';

        //c->mov();
    }
   if(event->key()== Qt::Key_S && c->get_carro()->get_py()>0 && flag==1)
    {
       timer_pel->stop();
       timer_salt->stop();
        c->get_carro()->set_py(c->get_carro()->get_py()-vel);
        on_actionStop_triggered();
        event->accept();
        c->mov();
        recuerdo='S';
    }
   if(event->key()== Qt::Key_M)
    {
       timer_pel->stop();
       timer_salt->stop();
       on_actionStop_triggered();
        timer_par->start();
        event->accept();
        c->mov();
    }
   if (event->key()==Qt::Key_4 ){
       timer_pel->stop();
       timer_salt->stop();
        d->get_carro()->set_px(d->get_carro()->get_px()-vel) ;
        //d->get_carro()->SetVx(-50);
        on_actionStop_triggered();
        event->accept();
        d->mov();
   }
   if (event->key()==Qt::Key_O ){
       timer_pel->stop();
       // d->get_carro()->set_px(d->get_carro()->get_px()-vel) ;
        //d->get_carro()->SetVx(-50);
        on_actionStop_triggered();
        event->accept();
        //d->mov();
        d->get_carro()->SetVy(d->get_carro()->GetVy()+200);
        d->get_carro()->SetVx(d->get_carro()->GetVx()+10);
   }



c->mov();
//timer_pel->stop();
//c->pelea();
//timer_salt->start();
c->posicion(v_limit);
d->posicion(v_limit);

    }
