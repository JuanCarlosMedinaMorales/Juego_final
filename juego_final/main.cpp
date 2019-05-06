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
    QSplashScreen *splash= new QSplashScreen;
    splash->setPixmap(QPixmap(":/calav.png"));
    splash->show();
    MainWindow w;
    QTimer::singleShot(2500,splash,SLOT(close()));
    QTimer::singleShot(2500,&w,SLOT(show()));
   // w.show();

    return a.exec();
}
