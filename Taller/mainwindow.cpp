#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

    c=new grafica();

    c->get_carro()->set_valores(0,0,450,450);
    c->posicion(v_limit);
    scene->addItem(c);
    scene->setFocusItem(c);
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
    if(c->get_carro()->GetVy()>0){
        c->salto(1);

    }
    else if(c->get_carro()->GetVy()<=0){
        c->salto(2);
    }
    c->get_carro()->SetVy(500);
    c->get_carro()->SetVx(200);
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

    }

    if(event->key()== Qt::Key_D && c->get_carro()->get_px()<1200-(c->get_carro()->get_w()*c->get_escala()))
    {
        timer_pel->stop();
        timer_salt->stop();
        c->get_carro()->set_px(c->get_carro()->get_px()+vel);
        on_actionStop_triggered();
        event->accept();
        c->mov();
    }
   if(event->key()== Qt::Key_A&& c->get_carro()->get_px()>0)
    {
       timer_pel->stop();
       timer_salt->stop();
        c->get_carro()->set_px(c->get_carro()->get_px()-vel) ;
        on_actionStop_triggered();
        event->accept();
        c->mov();
    }
    if(event->key()== Qt::Key_W && c->get_carro()->get_py()<200)
    {
        timer_pel->stop();
       // c->get_carro()->set_py(c->get_carro()->get_py()+vel);
        //on_actionStop_triggered();
        timer_salt->start();
        event->accept();
        //c->mov();
    }
   if(event->key()== Qt::Key_S && c->get_carro()->get_py()>0)
    {
       timer_pel->stop();
       timer_salt->stop();
        c->get_carro()->set_py(c->get_carro()->get_py()-vel);
        on_actionStop_triggered();
        event->accept();
        c->mov();
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


//c->mov();
//timer_pel->stop();
//c->pelea();
//timer_salt->start();
c->posicion(v_limit);
    }
