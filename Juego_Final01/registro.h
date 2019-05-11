#ifndef REGISTRO_H
#define REGISTRO_H

#include <QDialog>
#include <iniciar_sesion.h>
#include "QFile"
#include "QTextStream"
#include "menu.h"
#include<string.h>
using namespace std;
namespace Ui {
class registro;
}

class registro : public QDialog
{
    Q_OBJECT

public:
    explicit registro(QWidget *parent = nullptr);
    int persona=1;
    registro *nombre;
    ~registro();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::registro *ui;
    string pal;
    int contador=0;
    int contador2=0;

};

#endif // REGISTRO_H
