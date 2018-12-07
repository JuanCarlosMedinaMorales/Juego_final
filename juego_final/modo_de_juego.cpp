#include "modo_de_juego.h"
#include "ui_modo_de_juego.h"

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
