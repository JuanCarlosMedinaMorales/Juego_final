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

class Ui_selecp
{
public:
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QDialog *selecp)
    {
        if (selecp->objectName().isEmpty())
            selecp->setObjectName(QStringLiteral("selecp"));
        selecp->resize(578, 445);
        selecp->setStyleSheet(QStringLiteral("border-image: url(:/universidad_de_antioquia_2_0.jpg);"));
        radioButton = new QRadioButton(selecp);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(30, 30, 100, 100));
        radioButton->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton->setStyleSheet(QStringLiteral("border-image: url(:/oie_transparent.png);"));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(selecp);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(30, 140, 100, 100));
        radioButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_2->setStyleSheet(QStringLiteral("border-image: url(:/arte.png);"));
        radioButton_3 = new QRadioButton(selecp);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(30, 250, 100, 100));
        radioButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_3->setStyleSheet(QStringLiteral("border-image: url(:/esmad.png);"));
        pushButton = new QPushButton(selecp);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(450, 390, 91, 31));
        pushButton->setStyleSheet(QStringLiteral("border-image: url(:/transparnt.png);"));
        pushButton_2 = new QPushButton(selecp);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 380, 71, 51));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QStringLiteral("border-image: url(:/back1.png);"));
        pushButton_2->setFlat(false);
        label = new QLabel(selecp);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, 220, 171, 171));
        label->setStyleSheet(QStringLiteral("border-image: url(:/transparnt.png);"));

        retranslateUi(selecp);

        QMetaObject::connectSlotsByName(selecp);
    } // setupUi

    void retranslateUi(QDialog *selecp)
    {
        selecp->setWindowTitle(QApplication::translate("selecp", "Dialog", Q_NULLPTR));
        radioButton->setText(QString());
        radioButton_2->setText(QString());
        radioButton_3->setText(QString());
        pushButton->setText(QApplication::translate("selecp", "PushButton", Q_NULLPTR));
        pushButton_2->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class selecp: public Ui_selecp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECP_H
