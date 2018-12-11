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
    close();
    selecp2 *seleccion2= new selecp2(); seleccion2->show();
}

void selecP::on_radioButton_clicked()
{
    ui->label->setPixmap(QPixmap(":/capuchoEntero.png"));
    ui->label_3->setPixmap(QPixmap(":/1. Tropel Ut - Noviembre 27 de 2014.jpg"));

}

void selecP::on_radioButton_3_clicked()
{
    ui->label->setPixmap(QPixmap(":/artesEntero.png"));
    ui->label_3->setPixmap(QPixmap(":/facultad de artes udea.jpg"));
}


void selecP::on_radioButton_5_clicked()
{
    ui->label->setPixmap(QPixmap(":/esmadEntero.png"));
    ui->label_3->setPixmap(QPixmap(":/3822176_n_vir6.jpg"));

}

void selecP::on_label_linkHovered(const QString &link)
{

}
