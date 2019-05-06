#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QFile>
#include <QMovie>
#include <qmediaplayer.h>
#include <QGraphicsPixmapItem>

namespace Ui {
class MainWindow;
}
class QMediaPlayer;//Se usa para reproducir los gifs y audio
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();//Funcion para comportamiento del boton.

private:
    Ui::MainWindow *ui;
    QMediaPlayer *mMediaPlayer;//Puntero para poder usar el multimedia
    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
