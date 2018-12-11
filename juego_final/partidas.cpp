#include "partidas.h"
#include "ui_partidas.h"
#include "modo_de_juego.h"
#include "cargar_partidas.h"

PARTIDAS::PARTIDAS(QString C,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PARTIDAS)
{
    ui->setupUi(this);
    nombre_text=C;
}

PARTIDAS::~PARTIDAS()
{
    delete ui;
}

void PARTIDAS::on_pushButton_clicked()
{
    close();
    Modo_de_juego *modo= new Modo_de_juego(); modo->show();
}

void PARTIDAS::on_pushButton_2_clicked()
{
    close();
    cargar_partidas *cargar=new cargar_partidas(nombre_text); cargar->show();

}
