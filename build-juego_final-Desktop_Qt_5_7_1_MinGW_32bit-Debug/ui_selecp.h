/********************************************************************************
** Form generated from reading UI file 'selecp.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECP_H
#define UI_SELECP_H

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

class Ui_selecP
{
public:
    QLabel *label;
    QRadioButton *radioButton;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_5;
    QLabel *label_2;
    QPushButton *pushButton;
    QLabel *label_3;

    void setupUi(QDialog *selecP)
    {
        if (selecP->objectName().isEmpty())
            selecP->setObjectName(QStringLiteral("selecP"));
        selecP->resize(273, 425);
        label = new QLabel(selecP);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 30, 151, 141));
        label->setStyleSheet(QStringLiteral(""));
        radioButton = new QRadioButton(selecP);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(30, 180, 91, 101));
        radioButton->setStyleSheet(QStringLiteral("image: url(:/oie_transparent.png);"));
        radioButton_3 = new QRadioButton(selecP);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(110, 180, 171, 101));
        radioButton_3->setStyleSheet(QStringLiteral("image: url(:/arte.png);"));
        radioButton_5 = new QRadioButton(selecP);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setGeometry(QRect(100, 300, 91, 91));
        radioButton_5->setStyleSheet(QStringLiteral("image: url(:/esmad.png);"));
        label_2 = new QLabel(selecP);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 0, 131, 31));
        pushButton = new QPushButton(selecP);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(180, 390, 80, 21));
        label_3 = new QLabel(selecP);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 10, 281, 421));
        label_3->raise();
        label->raise();
        radioButton->raise();
        radioButton_3->raise();
        radioButton_5->raise();
        label_2->raise();
        pushButton->raise();

        retranslateUi(selecP);

        QMetaObject::connectSlotsByName(selecP);
    } // setupUi

    void retranslateUi(QDialog *selecP)
    {
        selecP->setWindowTitle(QApplication::translate("selecP", "Dialog", Q_NULLPTR));
        label->setText(QString());
        radioButton->setText(QApplication::translate("selecP", "capucho", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("selecP", "artes", Q_NULLPTR));
        radioButton_5->setText(QApplication::translate("selecP", "esmad", Q_NULLPTR));
        label_2->setText(QApplication::translate("selecP", "primer jugador", Q_NULLPTR));
        pushButton->setText(QApplication::translate("selecP", "siguiente", Q_NULLPTR));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class selecP: public Ui_selecP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECP_H
