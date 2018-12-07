#include "juego.h"
#include "ui_juego.h"

juego::juego(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::juego)
{
    ui->setupUi(this);
}

juego::~juego()
{
    delete ui;
}
