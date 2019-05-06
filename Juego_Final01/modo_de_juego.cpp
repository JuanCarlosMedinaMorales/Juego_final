#include "modo_de_juego.h"
#include "ui_modo_de_juego.h"
#include <QMouseEvent>


modo_de_juego::modo_de_juego(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modo_de_juego)
{
    ui->setupUi(this);
    timer=new QTimer(this);//se crea un nuevo timer
    connect(timer,SIGNAL(timeout()),this,SLOT(acr()));//Se conecta el timer a la funcion
    timer->start(25);//Se inicia el timer
    ui->label->setVisible(false);//Se esconde las imagenes
    ui->label_2->setVisible(false);
}

modo_de_juego::~modo_de_juego()
{
    delete ui;

}

void modo_de_juego::mouseMoveEvent(QMouseEvent *event)
{
    //QWidget::mouseMoveEvent(event);
    posx=event->x();//se le da el valor de la posicion de el cursor
    posy=event->y();

}

void modo_de_juego::on_pushButton_clicked()//un jugador
{
    selecp *un_j=new selecp(0); un_j->show();
    close();
}

void modo_de_juego::on_pushButton_2_clicked()//Dos jugadores
{
    selecp *dos_j = new selecp(1);dos_j->show();
    close();
}

void modo_de_juego::on_pushButton_3_clicked()//Instrucciones
{
    instrucciones *teclas =new instrucciones(this);teclas->show();
}

void modo_de_juego::acr()
{
 if(cursor().pos().x()>787
         &&cursor().pos().y()>140
         &&cursor().pos().x()<927
         &&cursor().pos().y()<250){//se muestra la imagen que se encuentra en el label cuando el cursor este sobre el boton
    ui->label->setVisible(true);//Hace visible el label
 }
 else{
     ui->label->setVisible(false);
 }
 if(cursor().pos().x()>787
         &&cursor().pos().y()>250
         &&cursor().pos().x()<927
         &&cursor().pos().y()<350){
    ui->label_2->setVisible(true);
 }
 else{
     ui->label_2->setVisible(false);
 }


}
