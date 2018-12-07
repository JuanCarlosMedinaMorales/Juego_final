#ifndef INICIAR_JUEGO_H
#define INICIAR_JUEGO_H

#include <QMainWindow>

namespace Ui {
class iniciar_juego;
}

class iniciar_juego : public QMainWindow
{
    Q_OBJECT

public:
    explicit iniciar_juego(QWidget *parent = nullptr);
    ~iniciar_juego();

private:
    Ui::iniciar_juego *ui;
};

#endif // INICIAR_JUEGO_H
