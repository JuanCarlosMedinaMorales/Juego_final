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
    QPushButton *pushButton_2;
    QLabel *label;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QPushButton *pushButton;

    void setupUi(QDialog *selecp2)
    {
        if (selecp2->objectName().isEmpty())
            selecp2->setObjectName(QStringLiteral("selecp2"));
        selecp2->resize(578, 445);
        selecp2->setStyleSheet(QStringLiteral("border-image: url(:/universidad_de_antioquia_2_0.jpg);"));
        pushButton_2 = new QPushButton(selecp2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 370, 71, 51));
        pushButton_2->setStyleSheet(QStringLiteral("border-image: url(:/back1.png);"));
        pushButton_2->setFlat(false);
        label = new QLabel(selecp2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, 210, 171, 171));
        label->setStyleSheet(QStringLiteral("border-image: url(:/transparnt.png);"));
        radioButton = new QRadioButton(selecp2);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setEnabled(true);
        radioButton->setGeometry(QRect(30, 20, 100, 100));
        radioButton->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton->setStyleSheet(QStringLiteral("border-image: url(:/oie_transparent.png);"));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(selecp2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(30, 130, 100, 100));
        radioButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_2->setStyleSheet(QStringLiteral("border-image: url(:/arte.png);"));
        radioButton_3 = new QRadioButton(selecp2);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(30, 240, 100, 100));
        radioButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_3->setStyleSheet(QStringLiteral("border-image: url(:/esmad.png);"));
        pushButton = new QPushButton(selecp2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(450, 380, 91, 31));
        pushButton->setStyleSheet(QStringLiteral("border-image: url(:/transparnt.png);"));

        retranslateUi(selecp2);

        QMetaObject::connectSlotsByName(selecp2);
    } // setupUi

    void retranslateUi(QDialog *selecp2)
    {
        selecp2->setWindowTitle(QApplication::translate("selecp2", "Dialog", Q_NULLPTR));
        pushButton_2->setText(QString());
        label->setText(QString());
        radioButton->setText(QString());
        radioButton_2->setText(QString());
        radioButton_3->setText(QString());
        pushButton->setText(QApplication::translate("selecp2", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class selecp2: public Ui_selecp2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECP2_H
