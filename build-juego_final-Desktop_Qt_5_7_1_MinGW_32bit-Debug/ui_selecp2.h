/********************************************************************************
** Form generated from reading UI file 'selecp2.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECP2_H
#define UI_SELECP2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_selecp2
{
public:
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_3;
    QLabel *label;
    QLabel *label_2;
    QRadioButton *radioButton;
    QPushButton *pushButton;

    void setupUi(QDialog *selecp2)
    {
        if (selecp2->objectName().isEmpty())
            selecp2->setObjectName(QStringLiteral("selecp2"));
        selecp2->resize(306, 440);
        radioButton_5 = new QRadioButton(selecp2);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setGeometry(QRect(120, 310, 91, 91));
        radioButton_5->setStyleSheet(QStringLiteral("image: url(:/esmadEntero.png);"));
        radioButton_3 = new QRadioButton(selecp2);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(160, 190, 91, 91));
        radioButton_3->setStyleSheet(QStringLiteral("image: url(:/artesEntero.png);"));
        label = new QLabel(selecp2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 50, 131, 141));
        label_2 = new QLabel(selecp2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 10, 131, 31));
        radioButton = new QRadioButton(selecp2);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(50, 190, 91, 101));
        radioButton->setStyleSheet(QStringLiteral("image: url(:/capuchoEntero.png);"));
        pushButton = new QPushButton(selecp2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(200, 400, 80, 21));

        retranslateUi(selecp2);

        QMetaObject::connectSlotsByName(selecp2);
    } // setupUi

    void retranslateUi(QDialog *selecp2)
    {
        selecp2->setWindowTitle(QApplication::translate("selecp2", "Dialog", Q_NULLPTR));
        radioButton_5->setText(QApplication::translate("selecp2", "esmad", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("selecp2", "artes", Q_NULLPTR));
        label->setText(QApplication::translate("selecp2", "TextLabe", Q_NULLPTR));
        label_2->setText(QApplication::translate("selecp2", "segundo jugador", Q_NULLPTR));
        radioButton->setText(QApplication::translate("selecp2", "capucho", Q_NULLPTR));
        pushButton->setText(QApplication::translate("selecp2", "siguiente", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class selecp2: public Ui_selecp2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECP2_H
