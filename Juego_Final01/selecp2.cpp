#include "selecp2.h"
#include "ui_selecp2.h"
#include "iniciar_juego.h"
#include "modo_de_juego.h"

selecp2::selecp2(int un_jugador,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selecp2)
{
    p1=un_jugador;
    ui->setupUi(this);
    mov = new QTimer(this);//se crea el timer
    connect(mov,SIGNAL(timeout()),this,SLOT(labelm()));//se conecta el timer a la funcion que proboca el movimiento

}

selecp2::~selecp2()
{
    delete ui;
}

void selecp2::animar(int opcion)
{
     mov->start(15);//se inicia e temporizador
}

void selecp2::on_pushButton_2_clicked()
{
    modo_de_juego *menu=new modo_de_juego(); menu->show();//regresa a la pagina anterior
    close();//cierra esta ventana
}

void selecp2::on_pushButton_clicked()
{
    if(jugadordos==9){}//rectifica si el usuario ya selecciono un personaje
    else{
        iniciar_juego *Game = new iniciar_juego(0,p1,jugadordos);Game->show();
        close();
    }
}

void selecp2::on_radioButton_clicked()
{
    contador=0;//reestablece el contador en cero para poder ejecutar de una forma correcta la funcion
    jugadordos=1;//jugador seleccionado
    if(mov->isActive()){//rectifica que el timer esta activo, ya que si ya esta activo se produce un error
      mov->stop();
    }

    animar(jugadordos);//se llama la funcion para iniciar el timer
}

void selecp2::on_radioButton_2_clicked()
{
    contador=0;
    jugadordos=2;
    mov->stop();
    animar(jugadordos);
}

void selecp2::on_radioButton_3_clicked()
{
    contador=0;
    jugadordos=3;
    mov->stop();
    animar(jugadordos);
}

void selecp2::labelm()
{
    contador++;//para saber que imagen poner en un tiempo determinado
    if(jugadordos==1){//si el jugador es 1 coloca una secuencia de imagenes correspondientes al personaje seleccionado
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
    if(jugadordos==2){
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
    if(jugadordos==3){
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
