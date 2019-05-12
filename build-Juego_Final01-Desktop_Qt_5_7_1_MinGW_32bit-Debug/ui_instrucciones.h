/********************************************************************************
** Form generated from reading UI file 'instrucciones.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTRUCCIONES_H
#define UI_INSTRUCCIONES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_instrucciones
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *instrucciones)
    {
        if (instrucciones->objectName().isEmpty())
            instrucciones->setObjectName(QStringLiteral("instrucciones"));
        instrucciones->resize(655, 496);
        instrucciones->setStyleSheet(QStringLiteral("border-image: url(:/controles.png);"));
        pushButton = new QPushButton(instrucciones);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 430, 61, 41));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QLatin1String("border-image: url(:/back1.png);\n"
"background-color: rgb(0, 0, 0);"));

        retranslateUi(instrucciones);

        QMetaObject::connectSlotsByName(instrucciones);
    } // setupUi

    void retranslateUi(QDialog *instrucciones)
    {
        instrucciones->setWindowTitle(QApplication::translate("instrucciones", "Dialog", Q_NULLPTR));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class instrucciones: public Ui_instrucciones {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRUCCIONES_H
