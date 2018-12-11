#include "selecp2.h"
#include "ui_selecp2.h"
#include "iniciar_juego.h"

selecp2::selecp2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selecp2)
{
    ui->setupUi(this);
}

selecp2::~selecp2()
{
    delete ui;
}



void selecp2::on_pushButton_clicked()
{
    close();
    iniciar_juego *juego= new iniciar_juego(); juego->show();
}
