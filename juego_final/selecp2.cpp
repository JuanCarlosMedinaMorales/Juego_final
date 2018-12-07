#include "selecp2.h"
#include "ui_selecp2.h"

selecp2::selecp2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selecp2)
{
    ui->setupUi(this);
}

selecp2::~selecp2()
{
    delete ui;
}
