/********************************************************************************
** Form generated from reading UI file 'iniciar_juego.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INICIAR_JUEGO_H
#define UI_INICIAR_JUEGO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_iniciar_juego
{
public:
    QGraphicsView *graphicsView;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLCDNumber *lcdNumber;
    QProgressBar *progressBar;
    QProgressBar *progressBar_2;
    QProgressBar *progressBar_3;
    QProgressBar *progressBar_4;
    QPushButton *pushButton_4;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QDialog *iniciar_juego)
    {
        if (iniciar_juego->objectName().isEmpty())
            iniciar_juego->setObjectName(QStringLiteral("iniciar_juego"));
        iniciar_juego->resize(1136, 700);
        graphicsView = new QGraphicsView(iniciar_juego);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1136, 700));
        graphicsView->setStyleSheet(QStringLiteral("border-image: url(:/5b734c53396e3_opt.jpg);"));
        label = new QLabel(iniciar_juego);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(460, 150, 221, 51));
        label->setStyleSheet(QStringLiteral("border-image: url(:/oie_Cgi6vpj3EWZU.jpg);"));
        label_2 = new QLabel(iniciar_juego);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(880, 380, 241, 211));
        pushButton = new QPushButton(iniciar_juego);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(500, 210, 121, 41));
        pushButton->setLayoutDirection(Qt::RightToLeft);
        pushButton_2 = new QPushButton(iniciar_juego);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(500, 250, 121, 41));
        pushButton_3 = new QPushButton(iniciar_juego);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(500, 290, 121, 41));
        lcdNumber = new QLCDNumber(iniciar_juego);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(520, 10, 91, 31));
        progressBar = new QProgressBar(iniciar_juego);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(0, 10, 511, 31));
        progressBar->setCursor(QCursor(Qt::WaitCursor));
        progressBar->setValue(100);
        progressBar->setTextVisible(false);
        progressBar->setOrientation(Qt::Vertical);
        progressBar->setInvertedAppearance(false);
        progressBar_2 = new QProgressBar(iniciar_juego);
        progressBar_2->setObjectName(QStringLiteral("progressBar_2"));
        progressBar_2->setGeometry(QRect(620, 10, 511, 31));
        progressBar_2->setCursor(QCursor(Qt::WaitCursor));
        progressBar_2->setLayoutDirection(Qt::RightToLeft);
        progressBar_2->setValue(100);
        progressBar_2->setTextVisible(false);
        progressBar_2->setOrientation(Qt::Horizontal);
        progressBar_3 = new QProgressBar(iniciar_juego);
        progressBar_3->setObjectName(QStringLiteral("progressBar_3"));
        progressBar_3->setGeometry(QRect(10, 80, 21, 611));
        progressBar_3->setValue(0);
        progressBar_3->setOrientation(Qt::Vertical);
        progressBar_4 = new QProgressBar(iniciar_juego);
        progressBar_4->setObjectName(QStringLiteral("progressBar_4"));
        progressBar_4->setGeometry(QRect(1110, 80, 21, 621));
        progressBar_4->setValue(0);
        progressBar_4->setOrientation(Qt::Vertical);
        pushButton_4 = new QPushButton(iniciar_juego);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 50, 80, 21));
        label_3 = new QLabel(iniciar_juego);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 510, 41, 41));
        label_3->setStyleSheet(QStringLiteral("border-image: url(:/escudopo.png);"));
        label_4 = new QLabel(iniciar_juego);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(1100, 550, 41, 41));
        label_4->setStyleSheet(QStringLiteral("border-image: url(:/escudopo.png);"));
        label_5 = new QLabel(iniciar_juego);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 220, 41, 51));
        label_5->setStyleSheet(QStringLiteral("border-image: url(:/oie_MULiyVysWllZ.png);"));
        label_6 = new QLabel(iniciar_juego);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(1100, 220, 41, 51));
        label_6->setStyleSheet(QStringLiteral("border-image: url(:/oie_MULiyVysWllZ.png);"));
        label_7 = new QLabel(iniciar_juego);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(0, 0, 1136, 700));
        label_7->setStyleSheet(QStringLiteral("border-image: url(:/GameOver.png);"));
        pushButton_5 = new QPushButton(iniciar_juego);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(350, 450, 111, 51));
        pushButton_6 = new QPushButton(iniciar_juego);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(630, 450, 111, 51));

        retranslateUi(iniciar_juego);

        QMetaObject::connectSlotsByName(iniciar_juego);
    } // setupUi

    void retranslateUi(QDialog *iniciar_juego)
    {
        iniciar_juego->setWindowTitle(QApplication::translate("iniciar_juego", "Dialog", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QString());
        pushButton->setText(QApplication::translate("iniciar_juego", "Continue", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("iniciar_juego", "Guardar", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("iniciar_juego", "Salir", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("iniciar_juego", "Conectar", Q_NULLPTR));
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
        pushButton_5->setText(QApplication::translate("iniciar_juego", "Regresar a menu", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("iniciar_juego", "Salir", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class iniciar_juego: public Ui_iniciar_juego {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIAR_JUEGO_H
