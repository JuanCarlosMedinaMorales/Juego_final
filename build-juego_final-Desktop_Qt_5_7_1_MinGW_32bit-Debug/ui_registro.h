/********************************************************************************
** Form generated from reading UI file 'registro.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRO_H
#define UI_REGISTRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Registro
{
public:
    QLabel *label;
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_3;
    QPlainTextEdit *plainTextEdit_2;
    QLabel *label_4;
    QLabel *label_5;
    QPlainTextEdit *plainTextEdit_3;
    QPlainTextEdit *plainTextEdit_4;
    QPushButton *pushButton;

    void setupUi(QDialog *Registro)
    {
        if (Registro->objectName().isEmpty())
            Registro->setObjectName(QStringLiteral("Registro"));
        Registro->resize(704, 429);
        label = new QLabel(Registro);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(290, 0, 141, 61));
        QFont font;
        font.setFamily(QStringLiteral("Broken Detroit"));
        font.setPointSize(20);
        label->setFont(font);
        label_2 = new QLabel(Registro);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 70, 101, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Broken Detroit"));
        font1.setPointSize(14);
        label_2->setFont(font1);
        plainTextEdit = new QPlainTextEdit(Registro);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(20, 110, 241, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Ozzy II"));
        font2.setPointSize(10);
        plainTextEdit->setFont(font2);
        plainTextEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        label_3 = new QLabel(Registro);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 150, 101, 31));
        label_3->setFont(font1);
        plainTextEdit_2 = new QPlainTextEdit(Registro);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(20, 190, 241, 31));
        label_4 = new QLabel(Registro);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(320, 70, 101, 31));
        label_4->setFont(font1);
        label_5 = new QLabel(Registro);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(320, 150, 101, 31));
        label_5->setFont(font1);
        plainTextEdit_3 = new QPlainTextEdit(Registro);
        plainTextEdit_3->setObjectName(QStringLiteral("plainTextEdit_3"));
        plainTextEdit_3->setGeometry(QRect(320, 110, 241, 31));
        plainTextEdit_3->setFont(font2);
        plainTextEdit_3->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        plainTextEdit_4 = new QPlainTextEdit(Registro);
        plainTextEdit_4->setObjectName(QStringLiteral("plainTextEdit_4"));
        plainTextEdit_4->setGeometry(QRect(320, 190, 241, 31));
        plainTextEdit_4->setFont(font2);
        plainTextEdit_4->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        pushButton = new QPushButton(Registro);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(190, 270, 161, 61));
        QFont font3;
        font3.setFamily(QStringLiteral("Broken Detroit"));
        font3.setPointSize(16);
        font3.setItalic(false);
        pushButton->setFont(font3);
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));

        retranslateUi(Registro);

        QMetaObject::connectSlotsByName(Registro);
    } // setupUi

    void retranslateUi(QDialog *Registro)
    {
        Registro->setWindowTitle(QApplication::translate("Registro", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Registro", "REGISTRO", Q_NULLPTR));
        label_2->setText(QApplication::translate("Registro", "NOMBRES", Q_NULLPTR));
        label_3->setText(QApplication::translate("Registro", "<html><head/><body><p>APELLIDOS</p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("Registro", "<html><head/><body><p>USUARIO</p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("Registro", "CLAVE", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Registro", "INGRESAR", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Registro: public Ui_Registro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRO_H
