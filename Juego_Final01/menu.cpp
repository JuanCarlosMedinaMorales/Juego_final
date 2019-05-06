#include "menu.h"
#include "ui_menu.h"
#include "registro.h"
#include "iniciar_sesion.h"
#include "mainwindow.h"

menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_pushButton_clicked()//Abre la ventana de inisio de sesion
{
    iniciar_sesion *inicio= new iniciar_sesion(); inicio->show();
    close();
}

void menu::on_pushButton_2_clicked()//Abre la ventana de cargar la partida
{
    close();
    registro *Registro= new registro(); Registro->show();
}

void menu::on_pushButton_3_clicked()//regresa a la ventana anterior
{
 close();
 MainWindow *regreso= new MainWindow();regreso->show();

}
