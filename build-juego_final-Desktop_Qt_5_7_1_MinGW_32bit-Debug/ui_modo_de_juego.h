/********************************************************************************
** Form generated from reading UI file 'modo_de_juego.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODO_DE_JUEGO_H
#define UI_MODO_DE_JUEGO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Modo_de_juego
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Modo_de_juego)
    {
        if (Modo_de_juego->objectName().isEmpty())
            Modo_de_juego->setObjectName(QStringLiteral("Modo_de_juego"));
        Modo_de_juego->resize(522, 374);
        pushButton = new QPushButton(Modo_de_juego);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(170, 40, 171, 41));
        pushButton_2 = new QPushButton(Modo_de_juego);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(170, 100, 171, 41));
        pushButton_3 = new QPushButton(Modo_de_juego);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(170, 160, 171, 51));
        pushButton_3->setStyleSheet(QStringLiteral("image: url(:/instrucciones.jpg);"));
        pushButton_3->setIconSize(QSize(171, 51));

        retranslateUi(Modo_de_juego);

        QMetaObject::connectSlotsByName(Modo_de_juego);
    } // setupUi

    void retranslateUi(QDialog *Modo_de_juego)
    {
        Modo_de_juego->setWindowTitle(QApplication::translate("Modo_de_juego", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Modo_de_juego", "1  JUGADOR", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Modo_de_juego", "2 JUGADORES", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Modo_de_juego", "INSTRUCCIONES", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Modo_de_juego: public Ui_Modo_de_juego {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODO_DE_JUEGO_H
