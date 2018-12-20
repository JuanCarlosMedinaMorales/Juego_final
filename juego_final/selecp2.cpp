#include "selecp2.h"
#include "ui_selecp2.h"
#include "iniciar_juego.h"

selecp2::selecp2(int jugador1,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selecp2)
{
    ui->setupUi(this);
    jugador=jugador1;
}

selecp2::~selecp2()
{
    delete ui;
}



void selecp2::on_pushButton_clicked()
{
    close();
    iniciar_juego *juego= new iniciar_juego(jugador,jugador2); juego->show();
}

void selecp2::on_radioButton_clicked()
{
    ui->label->setPixmap(QPixmap(":/capuchoEntero.png"));
    ui->label_3->setPixmap(QPixmap(":/1. Tropel Ut - Noviembre 27 de 2014.jpg"));
    jugador2=1;
}

void selecp2::on_radioButton_3_clicked()
{
    ui->label->setPixmap(QPixmap(":/artesEntero.png"));
    ui->label_3->setPixmap(QPixmap(":/facultad de artes udea.jpg"));
    jugador2=2;

}

void selecp2::on_radioButton_5_clicked()
{
    ui->label->setPixmap(QPixmap(":/esmadEntero.png"));
    ui->label_3->setPixmap(QPixmap(":/3822176_n_vir6.jpg"));
    jugador2=3;

}
