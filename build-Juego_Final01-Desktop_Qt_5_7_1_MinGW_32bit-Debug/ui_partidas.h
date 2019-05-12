/********************************************************************************
** Form generated from reading UI file 'partidas.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARTIDAS_H
#define UI_PARTIDAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_partidas
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *partidas)
    {
        if (partidas->objectName().isEmpty())
            partidas->setObjectName(QStringLiteral("partidas"));
        partidas->resize(578, 445);
        partidas->setStyleSheet(QStringLiteral("border-image: url(:/Riot-Wallpaper-Gallery.jpg);"));
        pushButton = new QPushButton(partidas);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 70, 161, 81));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QLatin1String("border-image: url(:/f956bbddf912427 (1).png);\n"
"image: url(:/transparnt.png);\n"
"background-image: url(:/transparnt.png);\n"
""));
        pushButton_2 = new QPushButton(partidas);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(400, 73, 161, 81));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QLatin1String("image: url(:/3ba683339f59abc.png);\n"
"border-image: url(:/transparnt.png);\n"
"background-image: url(:/transparnt.png);"));

        retranslateUi(partidas);

        QMetaObject::connectSlotsByName(partidas);
    } // setupUi

    void retranslateUi(QDialog *partidas)
    {
        partidas->setWindowTitle(QApplication::translate("partidas", "Dialog", Q_NULLPTR));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class partidas: public Ui_partidas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARTIDAS_H
