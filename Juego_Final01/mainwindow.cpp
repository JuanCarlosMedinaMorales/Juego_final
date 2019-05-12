#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"menu.h"
#include <qmediaplayer.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
        QMediaPlayer *musica=new QMediaPlayer();//se crea un puntero para poder reproducir la musica o video
        musica->setMedia(QUrl("qrc:/Blaze_Out_-_Red_Silence.mp3"));//se le pasa el url de la cancion
        musica->setVolume(100);//se le da el volumen a la musica
        musica->play();//se reproduce la musica seleccionada
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
