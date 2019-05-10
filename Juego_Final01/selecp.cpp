#include "selecp.h"
#include "ui_selecp.h"
#include <modo_de_juego.h>
selecp::selecp(int j,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selecp)
{
    ui->setupUi(this);
    seleccionJu=j;//modo de juego elegido por el usuario
    mov = new QTimer(this);//se crea el timer
    connect(mov,SIGNAL(timeout()),this,SLOT(labelm()));//se conecta el timer a la funcion que proboca el movimiento

}

selecp::~selecp()
{
    delete ui;
}

void selecp::animar(int opcion)
{
    mov->start(15);//se inicia e temporizador
}

void selecp::labelm()
{
    contador++;//para saber que imagen poner en un tiempo determinado
    if(jugador==0){//si el jugador es 1 coloca una secuencia de imagenes correspondientes al personaje seleccionado
        if(contador==1){
            ui->label->setPixmap(QPixmap(":/CCV1.png"));
        }
        else if(contador==4){
            ui->label->setPixmap(QPixmap(":/CCV2.png"));
        }
        else if(contador==8){
            ui->label->setPixmap(QPixmap(":/CCV3.png"));
        }
        else if(contador==12){
            ui->label->setPixmap(QPixmap(":/CCV4.png"));
        }
        else if(contador==16){
            ui->label->setPixmap(QPixmap(":/CCV5.png"));
        }
        else if(contador==20){
            ui->label->setPixmap(QPixmap(":/CCV6.png"));
            contador=0;
        }
    }
    if(jugador==1){
        if(contador==1){
            ui->label->setPixmap(QPixmap(":/caminar1.png"));
        }
        else if(contador==4){
            ui->label->setPixmap(QPixmap(":/caminar2.png"));
        }
        else if(contador==8){
            ui->label->setPixmap(QPixmap(":/caminar3.png"));
        }
        else if(contador==12){
            ui->label->setPixmap(QPixmap(":/caminar4.png"));
        }
        else if(contador==16){
            ui->label->setPixmap(QPixmap(":/caminar5.png"));
        }
        else if(contador==20){
            ui->label->setPixmap(QPixmap(":/caminar6.png"));
            contador=0;
        }
    }
    if(jugador==2){
        if(contador==1){
            ui->label->setPixmap(QPixmap(":/esmadC1V.png"));
        }
        else if(contador==4){
            ui->label->setPixmap(QPixmap(":/esmadC2V.png"));
        }
        else if(contador==8){
            ui->label->setPixmap(QPixmap(":/esmadC3V.png"));
        }
        else if(contador==12){
            ui->label->setPixmap(QPixmap(":/esmadC4V.png"));
        }
        else if(contador==16){
            ui->label->setPixmap(QPixmap(":/esmadC5V.png"));
        }
        else if(contador==20){
            ui->label->setPixmap(QPixmap(":/esmadC6V.png"));
            contador=0;
        }
    }


}

void selecp::on_radioButton_clicked()
{
    contador=0;//reestablece el contador en cero para poder ejecutar de una forma correcta la funcion
    jugador=0;//jugador seleccionado
    if(mov->isActive()){//rectifica que el timer esta activo, ya que si ya esta activo se produce un error
      mov->stop();
    }

    animar(seleccionJu);//se llama la funcion para iniciar el timer
}

void selecp::on_radioButton_2_clicked()
{
    contador=0;
    jugador=1;
    mov->stop();
    animar(seleccionJu);
}

void selecp::on_radioButton_3_clicked()
{
    contador=0;
    jugador=2;
    mov->stop();
    animar(seleccionJu);
}

void selecp::on_pushButton_2_clicked()
{
    modo_de_juego *menu=new modo_de_juego(); menu->show();//regresa a la pagina anterior
    close();//cierra esta ventana
}

void selecp::on_pushButton_clicked()
{
    if(jugador==9){
        mov->stop();
        ui->label->setPixmap(QPixmap(":/payaso.png"));
    }//rectifica si el usuario ya selecciono un personaje

    else{
        if(seleccionJu==0){//se abre la ventana del juego
            iniciar_juego *Game = new iniciar_juego(0,jugador,4);Game->show();
            close();
        }
        else if(seleccionJu==1){//se abre la ventana de seeccionar el segundo personaje
            selecp2 *seg_ju = new selecp2(jugador);seg_ju->show();
            close();
        }
        else{

        }
    }


}
