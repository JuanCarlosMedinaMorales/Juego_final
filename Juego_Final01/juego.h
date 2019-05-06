#ifndef JUEGO_H
#define JUEGO_H

#include <QDialog>

namespace Ui {
class juego;
}

class juego : public QDialog
{
    Q_OBJECT

public:
    explicit juego(QWidget *parent = nullptr);
    ~juego();

private:
    Ui::juego *ui;
};

#endif // JUEGO_H
