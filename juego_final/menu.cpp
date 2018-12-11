#include "menu.h"
#include "ui_menu.h"
#include "registro.h"
#include "iniciar_sesion.h"

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
      ui->setupUi(this);

//    if(cursor().pos().x()>=360 && cursor().pos().x()<=501&&cursor().pos().y()>=60&&cursor().pos().y()<=111){
//        ui->label->setPixmap(QPixmap(":/FB_IMG_1542470393887.jpg"));
//    }
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_clicked()
{
    iniciar_sesion *inicio= new iniciar_sesion(); inicio->show();
    close();
}

void Menu::on_pushButton_2_clicked()
{
    close();
    Registro *registro= new Registro(); registro->show();
}
