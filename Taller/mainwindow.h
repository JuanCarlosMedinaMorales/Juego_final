#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QFile>
#include "cuerpo.h"
#include "cuerpograf.h"
#include <QKeyEvent>
#include <QFileDialog>


namespace Ui {
class MainWindow;
}
class QMediaPlayer;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void keyPressEvent(QKeyEvent *event);
    void on_actionGo_triggered();
    void on_pegar();
    void mov();
    void par();
    void on_actionStop_triggered();
    void pegar();
    void salto();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *mMediaPlayer;
    int h_limit;                //longitud en X del mundo
    int v_limit;                //longitud en Y del mundo
    int vel;
    bool i=0;
    int cont;
    QTimer *timer_mov;
    QTimer *timer_par;
    QTimer *timer_pel;
    QTimer *timer_salt;
    QGraphicsScene *scene;
    grafica *c;
    grafica *d;
    int sp=0.0;
};

#endif // MAINWINDOW_H
