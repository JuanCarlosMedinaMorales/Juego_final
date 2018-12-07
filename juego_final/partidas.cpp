#include "partidas.h"
#include "ui_partidas.h"

PARTIDAS::PARTIDAS(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PARTIDAS)
{
    ui->setupUi(this);
}

PARTIDAS::~PARTIDAS()
{
    delete ui;
}
