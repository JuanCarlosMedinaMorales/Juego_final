#include "modo_de_juego.h"
#include "ui_modo_de_juego.h"
#include "selecp.h"
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
