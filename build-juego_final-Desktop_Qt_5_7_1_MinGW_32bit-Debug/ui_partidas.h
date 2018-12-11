/********************************************************************************
** Form generated from reading UI file 'partidas.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARTIDAS_H
#define UI_PARTIDAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PARTIDAS
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *PARTIDAS)
    {
        if (PARTIDAS->objectName().isEmpty())
            PARTIDAS->setObjectName(QStringLiteral("PARTIDAS"));
        PARTIDAS->resize(578, 366);
        pushButton = new QPushButton(PARTIDAS);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(210, 40, 151, 41));
        QFont font;
        font.setFamily(QStringLiteral("Broken Detroit"));
        font.setPointSize(12);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(PARTIDAS);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 110, 151, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Broken Detroit"));
        font1.setPointSize(14);
        pushButton_2->setFont(font1);

        retranslateUi(PARTIDAS);

        QMetaObject::connectSlotsByName(PARTIDAS);
    } // setupUi

    void retranslateUi(QDialog *PARTIDAS)
    {
        PARTIDAS->setWindowTitle(QApplication::translate("PARTIDAS", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("PARTIDAS", "NUEVA PARTIDA", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("PARTIDAS", "CARGAR", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PARTIDAS: public Ui_PARTIDAS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARTIDAS_H
