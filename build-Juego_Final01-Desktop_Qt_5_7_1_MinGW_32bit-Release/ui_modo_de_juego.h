/********************************************************************************
** Form generated from reading UI file 'modo_de_juego.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODO_DE_JUEGO_H
#define UI_MODO_DE_JUEGO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_modo_de_juego
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_4;

    void setupUi(QDialog *modo_de_juego)
    {
        if (modo_de_juego->objectName().isEmpty())
            modo_de_juego->setObjectName(QStringLiteral("modo_de_juego"));
        modo_de_juego->resize(578, 445);
        modo_de_juego->setStyleSheet(QStringLiteral("border-image: url(:/image.png);"));
        pushButton = new QPushButton(modo_de_juego);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(400, 0, 131, 111));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QLatin1String("border-image: url(:/iconp1.png);\n"
""));
        pushButton_2 = new QPushButton(modo_de_juego);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(400, 110, 141, 111));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QStringLiteral("border-image: url(:/iconp2.png);"));
        pushButton_3 = new QPushButton(modo_de_juego);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(400, 270, 141, 51));
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_3->setStyleSheet(QStringLiteral("border-image: url(:/5ec3a229d482e70.png);"));
        label = new QLabel(modo_de_juego);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 50, 211, 161));
        label->setStyleSheet(QStringLiteral("border-image: url(:/p2esp1.png);"));
        label_2 = new QLabel(modo_de_juego);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(150, 50, 231, 161));
        label_2->setStyleSheet(QStringLiteral("border-image: url(:/p1contro.png);"));
        pushButton_4 = new QPushButton(modo_de_juego);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(30, 370, 71, 51));
        pushButton_4->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_4->setStyleSheet(QStringLiteral("border-image: url(:/back1.png);"));

        retranslateUi(modo_de_juego);

        QMetaObject::connectSlotsByName(modo_de_juego);
    } // setupUi

    void retranslateUi(QDialog *modo_de_juego)
    {
        modo_de_juego->setWindowTitle(QApplication::translate("modo_de_juego", "Dialog", Q_NULLPTR));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        pushButton_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class modo_de_juego: public Ui_modo_de_juego {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODO_DE_JUEGO_H
