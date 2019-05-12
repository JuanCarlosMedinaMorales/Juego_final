#include "instrucciones.h"
#include "ui_instrucciones.h"
#include "modo_de_juego.h"

instrucciones::instrucciones(QString c,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::instrucciones)
{
    ui->setupUi(this);
    text=c;
}

instrucciones::~instrucciones()
{
    delete ui;
}

void instrucciones::on_pushButton_clicked()
{
    close();

}
