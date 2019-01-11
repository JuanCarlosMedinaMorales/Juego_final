#include "pausa.h"
#include "ui_pausa.h"

Pausa::Pausa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pausa)
{
    ui->setupUi(this);
}

Pausa::~Pausa()
{
    delete ui;
}
