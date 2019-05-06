#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"menu.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSize size(578,423);//dimensiones de label que contiene el gif
    QMovie *mov=new QMovie(":/PORTADA.gif");
    mov->setScaledSize(size);//pone el gif a escala del label
    ui->label->setMovie(mov);
    mov->start();//Inicia el gif
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    menu *MyDialog = new menu(); MyDialog->show();//llama la ventana llamda menu
    delete ui->label;//Elimina el gif
    close();//Cierra la ventana
}
