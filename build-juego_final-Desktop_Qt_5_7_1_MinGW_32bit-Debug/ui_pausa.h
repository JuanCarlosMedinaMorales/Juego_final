/********************************************************************************
** Form generated from reading UI file 'pausa.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAUSA_H
#define UI_PAUSA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pausa
{
public:
    QLabel *label;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Pausa)
    {
        if (Pausa->objectName().isEmpty())
            Pausa->setObjectName(QStringLiteral("Pausa"));
        Pausa->resize(272, 205);
        label = new QLabel(Pausa);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 10, 121, 41));
        QFont font;
        font.setFamily(QStringLiteral("Ozzy II"));
        font.setPointSize(16);
        label->setFont(font);
        widget = new QWidget(Pausa);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(70, 60, 121, 121));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);


        retranslateUi(Pausa);

        QMetaObject::connectSlotsByName(Pausa);
    } // setupUi

    void retranslateUi(QDialog *Pausa)
    {
        Pausa->setWindowTitle(QApplication::translate("Pausa", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Pausa", "pausa", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Pausa", "Continue", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Pausa", "Guardar", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Pausa", "Salir", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Pausa: public Ui_Pausa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAUSA_H
