#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include<QResource>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QResource::registerResource("myresource.rcc");
    //Q_INIT_RESOURCE(resource);
    QSplashScreen *splash= new QSplashScreen;//coloca la imagen al iniciar el programa
    splash->setPixmap(QPixmap(":/fantasmosn.png"));
    splash->show();
    MainWindow w;
    QTimer::singleShot(2500,splash,SLOT(close()));
    QTimer::singleShot(2500,&w,SLOT(show()));
   // w.show();

    return a.exec();
}
