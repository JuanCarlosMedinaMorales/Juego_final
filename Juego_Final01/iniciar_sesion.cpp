#include "iniciar_sesion.h"
#include "ui_iniciar_sesion.h"

iniciar_sesion::iniciar_sesion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::iniciar_sesion)
{
    ui->setupUi(this);
    ui->label->setVisible(0);//Esconde el mensaje de error.
    nombre_archivo_G=ui->lineEdit->text();

}

QString iniciar_sesion::get_archivo_de_guardado()
{
    return nombre_archivo_G;
}

iniciar_sesion::~iniciar_sesion()
{
    delete ui;
}

void iniciar_sesion::on_pushButton_clicked()
{
    QFile file(ui->lineEdit->text());
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))//se abre el .txt donde se guarda el usuario y la contraseña en modo de lectura
           return;

       QTextStream in(&file);

       while (!in.atEnd()) {//Recorre el .txt
              QString line = in.readLine();
              if(line==ui->plainTextEdit->toPlainText()){//Verifica que el usuario sea correcto
                 flaguser=1;
             }
             if(line==ui->lineEdit->text()){//Verifica que la cpontraseña sea correcta
                 flagpass=1;

             }


          }
       if(flaguser==1 && flagpass==1){//Si el usuario y la conraseña coinsiden se habre la ventana partidas
           close();
           partidas *partida= new partidas(ui->lineEdit->text()); partida->show();//Se abre la ventana y se le pasa el nombre del archivo donde se va aguardar

       }
       else{//Si no coinsiden el usuario y la contraseña, aparece el mensaje de error
           ui->label->setVisible(1);
       }
}
