#ifndef INICIAR_SESION_H
#define INICIAR_SESION_H

#include <QDialog>
#include "QFile"
#include "QTextStream"
#include "QString"
#include "partidas.h"


namespace Ui {
class iniciar_sesion;
}

class iniciar_sesion : public QDialog
{
    Q_OBJECT

public:
    explicit iniciar_sesion(QWidget *parent = nullptr);
     QString get_archivo_de_guardado();
    ~iniciar_sesion();


private slots:
    void on_pushButton_clicked();//Boton para cambiar de pagina

private:
    Ui::iniciar_sesion *ui;
    bool flaguser=0;//Bandera para verificar usuario
    bool flagpass=0;//Bandera para verificar contraseña
    QString nombre_archivo_G;//archivo donde se guardan los datos y va a ser heredado
};

#endif // INICIAR_SESION_H
