#include "selecp.h"
#include "ui_selecp.h"
#include "selecp2.h"

selecP::selecP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selecP)
{
    ui->setupUi(this);
}

selecP::~selecP()
{
    delete ui;
}

void selecP::on_pushButton_clicked()
{
    if(jugador==9){

    }
    else{
        close();
        selecp2 *seleccion2= new selecp2(jugador); seleccion2->show();

    }

}

void selecP::on_radioButton_clicked()
{
    ui->label->setPixmap(QPixmap(":/capuchoEntero.png"));
    ui->label_3->setPixmap(QPixmap(":/1. Tropel Ut - Noviembre 27 de 2014.jpg"));
    jugador=0;

}

void selecP::on_radioButton_3_clicked()
{
    ui->label->setPixmap(QPixmap(":/artesEntero.png"));
    ui->label_3->setPixmap(QPixmap(":/facultad de artes udea.jpg"));
    jugador=1;
}


void selecP::on_radioButton_5_clicked()
{
    ui->label->setPixmap(QPixmap(":/esmadEntero.png"));
    ui->label_3->setPixmap(QPixmap(":/3822176_n_vir6.jpg"));
    jugador=2;

}

void selecP::on_label_linkHovered(const QString &link)
{

}
