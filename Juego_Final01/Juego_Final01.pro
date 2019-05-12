#-------------------------------------------------
#
# Project created by QtCreator 2019-03-21T13:20:29
#
#-------------------------------------------------

QT       += core gui widgets\
         serialport\
         multimedia

TARGET = Juego_Final01
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    menu.cpp \
    cargar_partidas.cpp \
    iniciar_juego.cpp \
    iniciar_sesion.cpp \
    instrucciones.cpp \
    juego.cpp \
    modo_de_juego.cpp \
    partidas.cpp \
    registro.cpp \
    selecp.cpp \
    selecp2.cpp \
    cuerpo.cpp \
    cuerpograf.cpp

HEADERS += \
        mainwindow.h \
    menu.h \
    cargar_partidas.h \
    iniciar_juego.h \
    iniciar_sesion.h \
    instrucciones.h \
    juego.h \
    modo_de_juego.h \
    partidas.h \
    registro.h \
    selecp.h \
    selecp2.h \
    cuerpo.h \
    cuerpograf.h

FORMS += \
        mainwindow.ui \
    menu.ui \
    cargar_partidas.ui \
    iniciar_juego.ui \
    iniciar_sesion.ui \
    instrucciones.ui \
    juego.ui \
    modo_de_juego.ui \
    partidas.ui \
    registro.ui \
    selecp.ui \
    selecp2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resourse.qrc
QMAKE_CXXFLAGS += -std=gnu++11

DISTFILES += \
    GameOver.png
