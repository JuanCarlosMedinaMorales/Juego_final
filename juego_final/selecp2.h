#ifndef SELECP2_H
#define SELECP2_H

#include <QDialog>

namespace Ui {
class selecp2;
}

class selecp2 : public QDialog
{
    Q_OBJECT

public:
    explicit selecp2(QWidget *parent = nullptr);
    ~selecp2();

private:
    Ui::selecp2 *ui;
};

#endif // SELECP2_H
