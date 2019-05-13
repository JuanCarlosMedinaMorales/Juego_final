/********************************************************************************
** Form generated from reading UI file 'cargar_partidas.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARGAR_PARTIDAS_H
#define UI_CARGAR_PARTIDAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_cargar_partidas
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *cargar_partidas)
    {
        if (cargar_partidas->objectName().isEmpty())
            cargar_partidas->setObjectName(QStringLiteral("cargar_partidas"));
        cargar_partidas->resize(578, 445);
        pushButton = new QPushButton(cargar_partidas);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(220, 80, 151, 51));
        pushButton_2 = new QPushButton(cargar_partidas);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 150, 151, 51));
        pushButton_3 = new QPushButton(cargar_partidas);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(220, 220, 151, 51));

        retranslateUi(cargar_partidas);

        QMetaObject::connectSlotsByName(cargar_partidas);
    } // setupUi

    void retranslateUi(QDialog *cargar_partidas)
    {
        cargar_partidas->setWindowTitle(QApplication::translate("cargar_partidas", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("cargar_partidas", "no es", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("cargar_partidas", "--", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("cargar_partidas", "--", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class cargar_partidas: public Ui_cargar_partidas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARGAR_PARTIDAS_H
