#ifndef CARGAR_PARTIDAS_H
#define CARGAR_PARTIDAS_H

#include <QDialog>
#include "QString"

namespace Ui {
class cargar_partidas;
}

class cargar_partidas : public QDialog
{
    Q_OBJECT

public:
    explicit cargar_partidas(QString ca,QWidget *parent = nullptr);
    ~cargar_partidas();

private:
    Ui::cargar_partidas *ui;
    int contador=0;
    int contador2=0;
    QString nom;
};

#endif // CARGAR_PARTIDAS_H
