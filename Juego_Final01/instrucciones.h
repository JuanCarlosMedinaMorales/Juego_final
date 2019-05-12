#ifndef INSTRUCCIONES_H
#define INSTRUCCIONES_H

#include <QDialog>


namespace Ui {
class instrucciones;
}

class instrucciones : public QDialog
{
    Q_OBJECT

public:
    explicit instrucciones(QString c,QWidget *parent = nullptr);
    ~instrucciones();

private slots:
    void on_pushButton_clicked();

private:
    Ui::instrucciones *ui;
    QString text;
};

#endif // INSTRUCCIONES_H
