#ifndef INICIAR_SESION_H
#define INICIAR_SESION_H

#include <QDialog>

namespace Ui {
class iniciar_sesion;
}

class iniciar_sesion : public QDialog
{
    Q_OBJECT

public:
    explicit iniciar_sesion(QWidget *parent = nullptr);
    ~iniciar_sesion();

private:
    Ui::iniciar_sesion *ui;
};

#endif // INICIAR_SESION_H
