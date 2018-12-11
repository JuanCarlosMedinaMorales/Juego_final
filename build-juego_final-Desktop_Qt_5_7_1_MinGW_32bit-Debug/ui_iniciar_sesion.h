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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_iniciar_sesion
{
public:
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit_2;
    QPushButton *pushButton;
    QLabel *label_4;
    QCheckBox *checkBox;

    void setupUi(QDialog *iniciar_sesion)
    {
        if (iniciar_sesion->objectName().isEmpty())
            iniciar_sesion->setObjectName(QStringLiteral("iniciar_sesion"));
        iniciar_sesion->resize(935, 698);
        iniciar_sesion->setStyleSheet(QStringLiteral("background-image: url(:/inicioSesion.png);"));
        plainTextEdit = new QPlainTextEdit(iniciar_sesion);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(100, 390, 251, 41));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(12);
        plainTextEdit->setFont(font);
        plainTextEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        plainTextEdit_2 = new QPlainTextEdit(iniciar_sesion);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(100, 480, 251, 41));
        plainTextEdit_2->setFont(font);
        plainTextEdit_2->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        plainTextEdit_2->setStyleSheet(QStringLiteral("selection-color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(35, 40, 3, 255), stop:0.16 rgba(136, 106, 22, 255), stop:0.225 rgba(166, 140, 41, 255), stop:0.285 rgba(204, 181, 74, 255), stop:0.345 rgba(235, 219, 102, 255), stop:0.415 rgba(245, 236, 112, 255), stop:0.52 rgba(209, 190, 76, 255), stop:0.57 rgba(187, 156, 51, 255), stop:0.635 rgba(168, 142, 42, 255), stop:0.695 rgba(202, 174, 68, 255), stop:0.75 rgba(218, 202, 86, 255), stop:0.815 rgba(208, 187, 73, 255), stop:0.88 rgba(187, 156, 51, 255), stop:0.935 rgba(137, 108, 26, 255), stop:1 rgba(35, 40, 3, 255));"));
        pushButton = new QPushButton(iniciar_sesion);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(100, 640, 131, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Broken Detroit"));
        font1.setPointSize(16);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QLatin1String("alternate-background-color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(35, 40, 3, 255), stop:0.16 rgba(136, 106, 22, 255), stop:0.225 rgba(166, 140, 41, 255), stop:0.285 rgba(204, 181, 74, 255), stop:0.345 rgba(235, 219, 102, 255), stop:0.415 rgba(245, 236, 112, 255), stop:0.52 rgba(209, 190, 76, 255), stop:0.57 rgba(187, 156, 51, 255), stop:0.635 rgba(168, 142, 42, 255), stop:0.695 rgba(202, 174, 68, 255), stop:0.75 rgba(218, 202, 86, 255), stop:0.815 rgba(208, 187, 73, 255), stop:0.88 rgba(187, 156, 51, 255), stop:0.935 rgba(137, 108, 26, 255), stop:1 rgba(35, 40, 3, 255));\n"
"image: url(:/inicioSesionConectar.png);\n"
"gridline-color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(35, 40, 3, 255), stop:0.16 rgba(136, 106, 22, 255), stop:0.225 rgba(166, 140, 41, 255), stop:0.285 rgba(204, 181, 74, 255), stop:0.345 rgba(235, 219, 102, 255), stop:0.415 rgba(245, 236, 112, 255), stop:0.52 rgba(209, 190, 76, 255), stop:0.57 rgba(187, 156, 51, 255), stop:0.635 rgba(168, 142, 42, 255), stop:0.69"
                        "5 rgba(202, 174, 68, 255), stop:0.75 rgba(218, 202, 86, 255), stop:0.815 rgba(208, 187, 73, 255), stop:0.88 rgba(187, 156, 51, 255), stop:0.935 rgba(137, 108, 26, 255), stop:1 rgba(35, 40, 3, 255));"));
        label_4 = new QLabel(iniciar_sesion);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setEnabled(true);
        label_4->setGeometry(QRect(380, 420, 241, 61));
        label_4->setStyleSheet(QLatin1String("color: rgb(85, 0, 0);\n"
"background-image: url(:/5b734c53396e3_opt.jpg);\n"
""));
        checkBox = new QCheckBox(iniciar_sesion);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(120, 560, 31, 31));

        retranslateUi(iniciar_sesion);

        QMetaObject::connectSlotsByName(iniciar_sesion);
    } // setupUi

    void retranslateUi(QDialog *iniciar_sesion)
    {
        iniciar_sesion->setWindowTitle(QApplication::translate("iniciar_sesion", "Dialog", Q_NULLPTR));
        pushButton->setText(QString());
        label_4->setText(QApplication::translate("iniciar_sesion", "EL USUARIO Y/O LA CLAVE SON INCORRECTOS", Q_NULLPTR));
        checkBox->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class iniciar_sesion: public Ui_iniciar_sesion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIAR_SESION_H
