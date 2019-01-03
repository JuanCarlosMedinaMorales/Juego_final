#ifndef SELECP_H
#define SELECP_H

#include <QDialog>

namespace Ui {
class selecP;
}

class selecP : public QDialog
{
    Q_OBJECT

public:

    explicit selecP(QWidget *parent = nullptr);
    ~selecP();

private slots:
    void on_pushButton_clicked();

    void on_radioButton_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_5_clicked();

    void on_label_linkHovered(const QString &link);

private:
    Ui::selecP *ui;
    int jugador=9;
};

#endif // SELECP_H
