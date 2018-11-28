#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QKeyEvent>
#include <QTimer>
#include "bola.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void aviso(int);

public slots:
    void animar();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QGraphicsRectItem* barra;
    QGraphicsRectItem* barra2;
    QGraphicsLineItem* l1;
    QGraphicsLineItem* l2;
    QGraphicsLineItem* l3;
    QGraphicsLineItem* l4;
    bool flag=true;
    bool mover1;
    bool mover2;
    QList<Bola*> bolas;

    QTimer *timer;

    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);
    void mousePressEvent(QMouseEvent *ev);


};

#endif // MAINWINDOW_H
