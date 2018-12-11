#ifndef REGISTRO_H
#define REGISTRO_H

#include <QDialog>
#include <iniciar_sesion.h>

namespace Ui {
class Registro;
}

class Registro : public QDialog
{
    Q_OBJECT

public:
    explicit Registro(QWidget *parent = nullptr);
    int persona=1;
    Registro *nombre;
    ~Registro();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Registro *ui;
    QString pal;
    int contador=0;
    int contador2=0;

};

#endif // REGISTRO_H
