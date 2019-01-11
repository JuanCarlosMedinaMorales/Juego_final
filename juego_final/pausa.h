#ifndef PAUSA_H
#define PAUSA_H

#include <QDialog>

namespace Ui {
class Pausa;
}

class Pausa : public QDialog
{
    Q_OBJECT

public:
    explicit Pausa(QWidget *parent = nullptr);
    ~Pausa();

private:
    Ui::Pausa *ui;
};

#endif // PAUSA_H
