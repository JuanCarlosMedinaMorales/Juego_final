#ifndef PARTIDAS_H
#define PARTIDAS_H

#include <QDialog>

namespace Ui {
class PARTIDAS;
}

class PARTIDAS : public QDialog
{
    Q_OBJECT

public:
    explicit PARTIDAS(QWidget *parent = nullptr);
    ~PARTIDAS();

private:
    Ui::PARTIDAS *ui;
};

#endif // PARTIDAS_H
