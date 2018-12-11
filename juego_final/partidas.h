#ifndef PARTIDAS_H
#define PARTIDAS_H

#include <QDialog>
#include <QString>

namespace Ui {
class PARTIDAS;
}

class PARTIDAS : public QDialog
{
    Q_OBJECT

public:
    explicit PARTIDAS(QString C,QWidget *parent = nullptr);
    ~PARTIDAS();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::PARTIDAS *ui;
    QString nombre_text;
};

#endif // PARTIDAS_H
