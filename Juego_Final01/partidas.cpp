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
    modo_de_juego *modo= new modo_de_juego(nombre_text); modo->show();//se abre el menu del juego
}

void partidas::on_pushButton_2_clicked()
{
    int vida1,vida2,perso1,perso2,poderper1,poderper2,puntajeCargar;
    QFile file(nombre_text);
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
              if(contador2==0){
                  vida1=line.toInt();
                  cout<<vida1<<endl;
              }
              if(contador2==1){
                  vida2=line.toInt();
                  cout<<vida2<<endl;
              }
              if(contador2==2){
                  perso1=line.toInt();
                  cout<<perso1<<endl;
              }
              if(contador2==3){
                  perso2=line.toInt();
                  cout<<perso2<<endl;
              }
              if(contador2==4){
                  poderper1=line.toInt();
                  cout<<poderper1<<endl;
              }
              if(contador2==5){
                  poderper2=line.toInt();
                  cout<<poderper2<<endl;
              }
              if(contador2==6){
                  puntajeCargar=line.toInt();
                  cout<<puntajeCargar<<endl;
              }
              else{
                  contador2++;
              }

          }
           iniciar_juego *juego= new iniciar_juego(vida1,vida2,poderper1,poderper2,nombre_text,puntajeCargar,perso1,perso2); juego->show();//se abre el menu del juego
           close();

//    QFile file(nombre_text);
//       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))//se abre el .txt donde se guarda el usuario y la contraseña en modo de lectura
//           return;

//       QTextStream in(&file);
//       while (!in.atEnd()) {
//           cout<<0<<endl;
//           lineaC = in.readLine();
//           partidaC+=lineaC+"\n";
//           auxC++;
//           if(auxC==3){
//               cout<<1<<endl;
//               QFile file1(lineaC);

//                   if ((!file1.open((QIODevice::ReadOnly  | QIODevice::Text))
//                       ))
//                       return;
//                   QTextStream entradaC(&file1);
//                   while (!entradaC.atEnd()) {
//                       lineaC=in.readLine();
//                       cout<<2<<endl;
//                       aux2C++;
//                       if(aux2C==1){
//                           cout<<3<<endl;
//                           vida1=lineaC.split("\n")[0].toInt();
//                           cout<<vida1<<endl;
//                       }
//                   }
//                   file1.close();
//           }

//       }
//       file.close();

}
