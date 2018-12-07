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

private:
    Ui::selecP *ui;
};

#endif // SELECP_H
