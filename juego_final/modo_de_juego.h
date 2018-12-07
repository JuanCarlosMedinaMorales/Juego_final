#ifndef MODO_DE_JUEGO_H
#define MODO_DE_JUEGO_H

#include <QDialog>

namespace Ui {
class Modo_de_juego;
}

class Modo_de_juego : public QDialog
{
    Q_OBJECT

public:
    explicit Modo_de_juego(QWidget *parent = nullptr);
    ~Modo_de_juego();

private:
    Ui::Modo_de_juego *ui;
};

#endif // MODO_DE_JUEGO_H
