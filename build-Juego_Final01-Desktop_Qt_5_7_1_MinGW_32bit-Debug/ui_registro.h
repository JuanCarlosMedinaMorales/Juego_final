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

class Ui_registro
{
public:
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit_2;
    QPlainTextEdit *plainTextEdit_3;
    QPlainTextEdit *plainTextEdit_4;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_2;

    void setupUi(QDialog *registro)
    {
        if (registro->objectName().isEmpty())
            registro->setObjectName(QStringLiteral("registro"));
        registro->resize(578, 445);
        registro->setStyleSheet(QStringLiteral("background-image: url(:/rebellion-wallpapers-2.jpg);"));
        plainTextEdit = new QPlainTextEdit(registro);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(57, 107, 246, 27));
        QFont font;
        font.setFamily(QStringLiteral("Mongolian Baiti"));
        font.setPointSize(9);
        plainTextEdit->setFont(font);
        plainTextEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        plainTextEdit->setStyleSheet(QLatin1String("background-image: url(:/transparnt.png);\n"
"color: rgb(255, 255, 255);"));
        plainTextEdit_2 = new QPlainTextEdit(registro);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(57, 166, 246, 27));
        plainTextEdit_2->setFont(font);
        plainTextEdit_2->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        plainTextEdit_2->setStyleSheet(QLatin1String("background-image: url(:/transparnt.png);\n"
"color: rgb(255, 255, 255);"));
        plainTextEdit_3 = new QPlainTextEdit(registro);
        plainTextEdit_3->setObjectName(QStringLiteral("plainTextEdit_3"));
        plainTextEdit_3->setGeometry(QRect(57, 241, 246, 27));
        plainTextEdit_3->setFont(font);
        plainTextEdit_3->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        plainTextEdit_3->setAutoFillBackground(false);
        plainTextEdit_3->setStyleSheet(QLatin1String("background-image: url(:/transparnt.png);\n"
"color: rgb(255, 255, 255);"));
        plainTextEdit_3->setOverwriteMode(false);
        plainTextEdit_4 = new QPlainTextEdit(registro);
        plainTextEdit_4->setObjectName(QStringLiteral("plainTextEdit_4"));
        plainTextEdit_4->setGeometry(QRect(57, 300, 246, 27));
        plainTextEdit_4->setFont(font);
        plainTextEdit_4->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        plainTextEdit_4->setStyleSheet(QLatin1String("background-image: url(:/transparnt.png);\n"
"color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(registro);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(100, 350, 171, 71));
        pushButton->setStyleSheet(QLatin1String("border-image: url(:/button_reg.png);\n"
"background-image: url(:/transparnt.png);"));
        label = new QLabel(registro);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(350, 30, 191, 101));
        label->setStyleSheet(QStringLiteral("border-image: url(:/1865661-0 (1).png);"));
        label_2 = new QLabel(registro);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(310, 240, 31, 21));
        label_2->setStyleSheet(QLatin1String("border-image: url(:/warning.png);\n"
"background-image: url(:/transparnt.png);"));
        label_3 = new QLabel(registro);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(310, 300, 31, 21));
        label_3->setStyleSheet(QLatin1String("border-image: url(:/warning.png);\n"
"background-image: url(:/transparnt.png);"));
        pushButton_2 = new QPushButton(registro);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(490, 380, 71, 51));
        pushButton_2->setStyleSheet(QLatin1String("border-image: url(:/back1.png);\n"
"background-image: url(:/transparnt.png);"));

        retranslateUi(registro);

        QMetaObject::connectSlotsByName(registro);
    } // setupUi

    void retranslateUi(QDialog *registro)
    {
        registro->setWindowTitle(QApplication::translate("registro", "Dialog", Q_NULLPTR));
        plainTextEdit->setPlainText(QApplication::translate("registro", "ESCRIBA AQUI", Q_NULLPTR));
        plainTextEdit_2->setPlainText(QApplication::translate("registro", "ESCRIBA AQUI", Q_NULLPTR));
        plainTextEdit_3->setPlainText(QApplication::translate("registro", "ESCRIBA AQUI", Q_NULLPTR));
        plainTextEdit_4->setPlainText(QApplication::translate("registro", "ESCRIBA AQUI", Q_NULLPTR));
        pushButton->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class registro: public Ui_registro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRO_H
