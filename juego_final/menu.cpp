#include "menu.h"
#include "ui_menu.h"
#include "registro.h"

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_clicked()
{
    close();
    Registro *registro= new Registro(); registro->show();
}
