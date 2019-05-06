#include "registro.h"
#include "ui_registro.h"

registro::registro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registro)
{
    ui->setupUi(this);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->label->setVisible(false);
}

registro::~registro()
{
    delete ui;
}
void registro::on_pushButton_clicked()
{
    if(ui->plainTextEdit_3->toPlainText()==ui->plainTextEdit_4->toPlainText()){//Verifica la que la contraseña sea bien escrita.
        QFile file(ui->plainTextEdit_3->toPlainText());//crea un archivo de nombre "la clave del usuario"donde se guardan todos los datos

            if ((!file.open((QIODevice::WriteOnly  | QIODevice::Text))//abre el archivo sitado en modo escritura
                ))
                return;

            QTextStream out(&file);
            out <<endl<< ui->plainTextEdit->toPlainText()<<endl;//guarda el nombre del usuario
            out << ui->plainTextEdit_3->toPlainText()<<endl;//guarda la contraseña del usuario
            out << "partidas"<<ui->plainTextEdit_3->toPlainText()<<endl;//le pone nombre al archivo


            file.close();
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))//abre el archivo txt. en modo lectura
                return;

            QTextStream in(&file);

            while (!in.atEnd()) {
                   QString line = in.readLine();
                   if(contador==3){
                       QFile file1(line);

                           if ((!file1.open((QIODevice::WriteOnly  | QIODevice::Text))
                               ))
                               return;

                           QTextStream out1(&file1);
                           out1 <<endl<<"---"<<endl;//ingresa los valores por defecto que tiene el archivo de guardado
                           while (contador2!=19) {
                               out1 << "---"<<endl;
                               contador2++;
                           }

                  }
                   contador++;



               }

             menu *Menu= new menu(); Menu->show();//cierra la ventana de registro y abre la ventana de menu
            close();
    }
    else{
        ui->label->setVisible(true);
        ui->label_2->setVisible(true);
        ui->label_3->setVisible(true);
    }

}

void registro::on_pushButton_2_clicked()
{
    menu *Menu= new menu(); Menu->show();//cierra la ventana de registro y abre la ventana de menu
   close();
}
