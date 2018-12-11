#include "cargar_partidas.h"
#include "ui_cargar_partidas.h"

cargar_partidas::cargar_partidas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cargar_partidas)
{
    ui->setupUi(this);
}

cargar_partidas::~cargar_partidas()
{
    delete ui;
}
