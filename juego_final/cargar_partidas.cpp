#include "cargar_partidas.h"
#include "ui_cargar_partidas.h"
#include "QFile"
#include "QTextStream"
#include "QString"
#include "partidas.h"

cargar_partidas::cargar_partidas(QString ca,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cargar_partidas)
{
    ui->setupUi(this);
    cla=ca;
    QFile file(ca);
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           return;

       QTextStream in1(&file);

       while (!in1.atEnd()) {
              QString line = in1.readLine();
              if(contador==3){
                  nom=line;


             }
              contador++;



          }
       file.close();
       QFile file1(nom);
          if (!file1.open(QIODevice::ReadOnly | QIODevice::Text))
              return;

          QTextStream in(&file1);

          while (!in.atEnd()) {
              QString line = in.readLine();
              if(contador2==1){
                  ui->lcdNumber->display(line);
                  contador2++;
              }
              else if(contador2==2){
                  ui->lcdNumber_2->display(line);
                  contador2++;
              }
              else if(contador2==3){
                  ui->label_31->setText(line);
                  contador2++;
              }
              else if(contador2==4){
                  ui->lcdNumber_3->display(line);
                  contador2++;
              }
              else if(contador2==5){
                  ui->lcdNumber_4->display(line);
                  contador2++;
              }
              else if(contador2==6){
                  ui->lcdNumber_5->display(line);
                  contador2++;
              }
              else if(contador2==7){
                  ui->label_32->setText(line);
                  contador2++;
              }
              else if(contador2==8){
                  ui->lcdNumber_6->display(line);
                  contador2++;
              }
              else if(contador2==9){
                  ui->lcdNumber_8->display(line);
                  contador2++;
              }
              else if(contador2==10){
                  ui->lcdNumber_7->display(line);
                  contador2++;
              }
              else if(contador2==11){
                  ui->label_33->setText(line);
                  contador2++;
              }
              else if(contador2==12){
                  ui->lcdNumber_15->display(line);
                  contador2++;
              }
              else if(contador2==13){
                  ui->lcdNumber_10->display(line);
                  contador2++;
              }
              else if(contador2==14){
                  ui->lcdNumber_9->display(line);
                  contador2++;
              }
              else if(contador2==15){
                  ui->label_34->setText(line);
                  contador2++;
              }
              else if(contador2==16){
                  ui->lcdNumber_14->display(line);
                  contador2++;
              }
              else if(contador2==17){
                  ui->lcdNumber_12->display(line);
                  contador2++;
              }
              else if(contador2==18){
                  ui->lcdNumber_11->display(line);
                  contador2++;
              }
              else if(contador2==19){
                  ui->label_35->setText(line);
                  contador2++;
              }
              else if(contador2==20){
                  ui->lcdNumber_13->display(line);
                  contador2++;
              }
              else{
                  contador2++;
              }

          }
}

cargar_partidas::~cargar_partidas()
{
    delete ui;
}

void cargar_partidas::on_pushButton_2_clicked()
{
    close();
    PARTIDAS *regreso= new PARTIDAS(cla); regreso->show();
}
