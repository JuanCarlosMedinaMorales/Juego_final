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
    explicit selecp2(int jugador1,QWidget *parent = nullptr);
    ~selecp2();

private slots:
    void on_pushButton_clicked();

    void on_radioButton_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_5_clicked();

private:
    Ui::selecp2 *ui;
    int jugador2=0;
    int jugador=0;
};

#endif // SELECP2_H
