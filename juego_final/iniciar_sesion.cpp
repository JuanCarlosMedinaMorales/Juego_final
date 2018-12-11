#include "iniciar_sesion.h"
#include "ui_iniciar_sesion.h"
#include "QFile"
#include "QTextStream"
#include "QString"
#include "partidas.h"

iniciar_sesion::iniciar_sesion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::iniciar_sesion)
{
    ui->setupUi(this);
    ui->label_4->setVisible(0);

}

iniciar_sesion::~iniciar_sesion()
{
    delete ui;
}

void iniciar_sesion::on_pushButton_clicked()
{
    QFile file(ui->plainTextEdit_2->toPlainText());
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           return;

       QTextStream in(&file);

       while (!in.atEnd()) {
              QString line = in.readLine();
              if(line==ui->plainTextEdit->toPlainText()){
                 flaguser=1;
             }
             if(line==ui->plainTextEdit_2->toPlainText()){
                 flagpass=1;
             }


          }
       if(flaguser==1 && flagpass==1){
           close();
           PARTIDAS *partida= new PARTIDAS(ui->plainTextEdit_2->toPlainText()); partida->show();

       }
       else{
           ui->label_4->setVisible(1);
       }
}
