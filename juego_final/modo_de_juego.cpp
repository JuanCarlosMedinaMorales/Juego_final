#include "modo_de_juego.h"
#include "ui_modo_de_juego.h"
#include "selecp.h"
#include "selecp2.h"
#include "instrucciones.h"

Modo_de_juego::Modo_de_juego(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modo_de_juego)
{
    ui->setupUi(this);
}

Modo_de_juego::~Modo_de_juego()
{
    delete ui;
}

void Modo_de_juego::on_pushButton_2_clicked()
{
    close();
    selecP *seleccion= new selecP(); seleccion->show();
}

void Modo_de_juego::on_pushButton_3_clicked()
{
    instrucciones *in= new instrucciones(); in->show();
}

void Modo_de_juego::on_pushButton_clicked()
{
    close();
    selecp2 *seleccion2= new selecp2(4); seleccion2->show();
}
