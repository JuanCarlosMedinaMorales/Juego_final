#ifndef PARTIDAS_H
#define PARTIDAS_H

#include <QDialog>
#include <QString>

namespace Ui {
class partidas;
}

class partidas : public QDialog
{
    Q_OBJECT

public:
    explicit partidas(QString C,QWidget *parent = nullptr);
    ~partidas();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::partidas *ui;
    QString nombre_text;//nombre del archivo de texto donde se guarda la informacion

};

#endif // PARTIDAS_H