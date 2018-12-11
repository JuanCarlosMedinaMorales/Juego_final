#-------------------------------------------------
#
# Project created by QtCreator 2018-11-28T15:57:47
#
#-------------------------------------------------

QT       += core gui widgets multimedia

TARGET = juego_final
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
    registro.cpp \
    iniciar_sesion.cpp \
    partidas.cpp \
    modo_de_juego.cpp \
    selecp.cpp \
    selecp2.cpp \
    juego.cpp \
    iniciar_juego.cpp \
    cuerpo.cpp \
    cuerpograf.cpp \
    instrucciones.cpp \
    cargar_partidas.cpp

HEADERS += \
        mainwindow.h \
    menu.h \
    registro.h \
    iniciar_sesion.h \
    partidas.h \
    modo_de_juego.h \
    selecp.h \
    selecp2.h \
    juego.h \
    iniciar_juego.h \
    cuerpo.h \
    cuerpograf.h \
    instrucciones.h \
    cargar_partidas.h

FORMS += \
        mainwindow.ui \
    menu.ui \
    registro.ui \
    iniciar_sesion.ui \
    partidas.ui \
    modo_de_juego.ui \
    selecp.ui \
    selecp2.ui \
    juego.ui \
    iniciar_juego.ui \
    instrucciones.ui \
    cargar_partidas.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    6282614902_ded28303e1_b.jpg
QMAKE_CXXFLAGS += -std=gnu++11
