/********************************************************************************
** Form generated from reading UI file 'iniciar_sesion.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INICIAR_SESION_H
#define UI_INICIAR_SESION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_iniciar_sesion
{
public:
    QCheckBox *checkBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton;
    QLabel *label_2;

    void setupUi(QDialog *iniciar_sesion)
    {
        if (iniciar_sesion->objectName().isEmpty())
            iniciar_sesion->setObjectName(QStringLiteral("iniciar_sesion"));
        iniciar_sesion->resize(655, 496);
        iniciar_sesion->setStyleSheet(QStringLiteral(""));
        checkBox = new QCheckBox(iniciar_sesion);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(80, 410, 16, 16));
        checkBox->setStyleSheet(QStringLiteral("border-image: url(:/transparnt.png);"));
        label = new QLabel(iniciar_sesion);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(330, 310, 151, 31));
        label->setStyleSheet(QLatin1String("border-image: url(:/transparnt.png);\n"
"color: rgb(0, 0, 0);"));
        lineEdit = new QLineEdit(iniciar_sesion);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(70, 350, 171, 21));
        lineEdit->setStyleSheet(QStringLiteral("border-image: url(:/transparnt.png);"));
        plainTextEdit = new QPlainTextEdit(iniciar_sesion);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(70, 290, 161, 31));
        plainTextEdit->setStyleSheet(QStringLiteral("border-image: url(:/transparnt.png);"));
        pushButton = new QPushButton(iniciar_sesion);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 470, 91, 21));
        pushButton->setStyleSheet(QStringLiteral("border-image: url(:/transparnt.png);"));
        label_2 = new QLabel(iniciar_sesion);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 655, 496));
        label_2->setStyleSheet(QStringLiteral("border-image: url(:/inicioSesion.png);"));
        label_2->raise();
        checkBox->raise();
        label->raise();
        lineEdit->raise();
        plainTextEdit->raise();
        pushButton->raise();

        retranslateUi(iniciar_sesion);

        QMetaObject::connectSlotsByName(iniciar_sesion);
    } // setupUi

    void retranslateUi(QDialog *iniciar_sesion)
    {
        iniciar_sesion->setWindowTitle(QApplication::translate("iniciar_sesion", "Dialog", Q_NULLPTR));
        checkBox->setText(QString());
        label->setText(QApplication::translate("iniciar_sesion", "Error en contrase\303\261a \303\263 usuario", Q_NULLPTR));
        pushButton->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class iniciar_sesion: public Ui_iniciar_sesion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIAR_SESION_H
