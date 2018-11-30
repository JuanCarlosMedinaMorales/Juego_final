#-------------------------------------------------
#
# Project created by QtCreator 2018-05-06T19:34:36
#
#-------------------------------------------------

QT       += core gui multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Taller
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cuerpo.cpp \
    cuerpograf.cpp

HEADERS  += mainwindow.h \
    cuerpo.h \
    cuerpograf.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc

DISTFILES += \
    Contra_(NES)_Music_-_Jungle_Theme.mp3
QMAKE_CXXFLAGS += -std=gnu++11
