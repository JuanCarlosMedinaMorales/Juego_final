#include "registro.h"
#include "ui_registro.h"
#include "QFile"
#include "QTextStream"
#include "menu.h"

Registro::Registro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registro)
{
    ui->setupUi(this);

}

Registro::~Registro()
{
    delete ui;
}



void Registro::on_pushButton_clicked()
{
    QFile file(ui->plainTextEdit_4->toPlainText());

        if ((!file.open((QIODevice::WriteOnly  | QIODevice::Text))
            ))
            return;

        QTextStream out(&file);
        out <<endl<< ui->plainTextEdit_3->toPlainText()<<endl;
        out << ui->plainTextEdit_4->toPlainText()<<endl;
        out << "partidas"<<ui->plainTextEdit_4->toPlainText()<<endl;

        pal=ui->label_4->text();//clave
        file.close();
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
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
                       out1 <<endl<<"---"<<endl;
                       while (contador2!=19) {
                           out1 << "---"<<endl;
                           contador2++;
                       }

              }
               contador++;



           }

         Menu *menu= new Menu(); menu->show();
        close();

}
