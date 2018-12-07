#include "selecp.h"
#include "ui_selecp.h"

selecP::selecP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selecP)
{
    ui->setupUi(this);
}

selecP::~selecP()
{
    delete ui;
}
