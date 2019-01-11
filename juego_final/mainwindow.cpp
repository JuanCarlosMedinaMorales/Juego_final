#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"menu.h"
#include <QMovie>
#include <qmediaplayer.h>
#include "QFile"


#include <QGraphicsPixmapItem>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    QMediaPlayer *musica=new QMediaPlayer();
//    musica->setMedia(QUrl("qrc:/Amon_Amarth_-_Victorious_March_[Fanvideo].mp3"));
//    musica->setVolume(50);
//    musica->play();

    QSize size(578,423);
    QMovie *mov=new QMovie(":/PORTADA.gif");
    mov->setScaledSize(size);
    ui->label->setMovie(mov);
    mov->start();




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
  Menu *MyDialog = new Menu(); MyDialog->show();
  close();
}
