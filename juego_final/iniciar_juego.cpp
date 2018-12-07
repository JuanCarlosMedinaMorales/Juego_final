#include "iniciar_juego.h"
#include "ui_iniciar_juego.h"

iniciar_juego::iniciar_juego(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::iniciar_juego)
{
    ui->setupUi(this);
}

iniciar_juego::~iniciar_juego()
{
    delete ui;
}
