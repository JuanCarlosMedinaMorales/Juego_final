#ifndef CARGAR_PARTIDAS_H
#define CARGAR_PARTIDAS_H

#include <QDialog>

namespace Ui {
class cargar_partidas;
}

class cargar_partidas : public QDialog
{
    Q_OBJECT

public:
    explicit cargar_partidas(QWidget *parent = nullptr);
    ~cargar_partidas();

private:
    Ui::cargar_partidas *ui;
};

#endif // CARGAR_PARTIDAS_H
