#include "partidas.h"
#include "ui_partidas.h"
#include"cargar_partidas.h"
#include"modo_de_juego.h"

partidas::partidas(QString C,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::partidas)
{
    ui->setupUi(this);
    nombre_text=C;
}

partidas::~partidas()
{
    delete ui;
}

void partidas::on_pushButton_clicked()
{
    close();
    modo_de_juego *modo= new modo_de_juego(); modo->show();//se abre el menu del juego
}

void partidas::on_pushButton_2_clicked()
{
    close();
    cargar_partidas *carga= new cargar_partidas(nombre_text);carga->show();//se abre el menu de las partidas guardadas, se le enviaa el nombre de el archivo guardado
}
