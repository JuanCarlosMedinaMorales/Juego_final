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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_iniciar_juego
{
public:
    QAction *actiongo;
    QAction *actionstop;
    QAction *actionGuardar_Partida;
    QAction *actionSalir;
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QProgressBar *progressBar;
    QProgressBar *progressBar_2;
    QLCDNumber *lcdNumber;
    QLabel *label;
    QLabel *label_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QProgressBar *progressBar_3;
    QProgressBar *progressBar_4;
    QProgressBar *progressBar_5;
    QProgressBar *progressBar_6;
    QMenuBar *menubar;
    QMenu *menuOpciones;
    QMenu *menuPausar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *iniciar_juego)
    {
        if (iniciar_juego->objectName().isEmpty())
            iniciar_juego->setObjectName(QStringLiteral("iniciar_juego"));
        iniciar_juego->resize(1136, 700);
        actiongo = new QAction(iniciar_juego);
        actiongo->setObjectName(QStringLiteral("actiongo"));
        actionstop = new QAction(iniciar_juego);
        actionstop->setObjectName(QStringLiteral("actionstop"));
        actionGuardar_Partida = new QAction(iniciar_juego);
        actionGuardar_Partida->setObjectName(QStringLiteral("actionGuardar_Partida"));
        actionSalir = new QAction(iniciar_juego);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        centralwidget = new QWidget(iniciar_juego);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1111, 600));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(30, 10, 481, 23));
        progressBar->setCursor(QCursor(Qt::WaitCursor));
        progressBar->setValue(100);
        progressBar->setTextVisible(false);
        progressBar->setTextDirection(QProgressBar::BottomToTop);
        progressBar_2 = new QProgressBar(centralwidget);
        progressBar_2->setObjectName(QStringLiteral("progressBar_2"));
        progressBar_2->setGeometry(QRect(657, 10, 441, 23));
        progressBar_2->setCursor(QCursor(Qt::WaitCursor));
        progressBar_2->setValue(100);
        progressBar_2->setTextVisible(false);
        progressBar_2->setInvertedAppearance(true);
        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(520, 10, 121, 21));
        lcdNumber->setStyleSheet(QLatin1String("color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(35, 40, 3, 255), stop:0.16 rgba(136, 106, 22, 255), stop:0.225 rgba(166, 140, 41, 255), stop:0.285 rgba(204, 181, 74, 255), stop:0.345 rgba(235, 219, 102, 255), stop:0.415 rgba(245, 236, 112, 255), stop:0.52 rgba(209, 190, 76, 255), stop:0.57 rgba(187, 156, 51, 255), stop:0.635 rgba(168, 142, 42, 255), stop:0.695 rgba(202, 174, 68, 255), stop:0.75 rgba(218, 202, 86, 255), stop:0.815 rgba(208, 187, 73, 255), stop:0.88 rgba(187, 156, 51, 255), stop:0.935 rgba(137, 108, 26, 255), stop:1 rgba(35, 40, 3, 255));\n"
"border-color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(35, 40, 3, 255), stop:0.16 rgba(136, 106, 22, 255), stop:0.225 rgba(166, 140, 41, 255), stop:0.285 rgba(204, 181, 74, 255), stop:0.345 rgba(235, 219, 102, 255), stop:0.415 rgba(245, 236, 112, 255), stop:0.52 rgba(209, 190, 76, 255), stop:0.57 rgba(187, 156, 51, 255), stop:0.635 rgba(168, 142, 42, 255), stop:0.695 rgba(202, 174, 68, 255), stop:0.75 rgba(218, 202, 86, 255), stop:"
                        "0.815 rgba(208, 187, 73, 255), stop:0.88 rgba(187, 156, 51, 255), stop:0.935 rgba(137, 108, 26, 255), stop:1 rgba(35, 40, 3, 255));"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 30, 1111, 550));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(520, 160, 121, 41));
        QFont font;
        font.setFamily(QStringLiteral("Ozzy II"));
        font.setPointSize(16);
        label_2->setFont(font);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(520, 210, 121, 121));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        progressBar_3 = new QProgressBar(centralwidget);
        progressBar_3->setObjectName(QStringLiteral("progressBar_3"));
        progressBar_3->setGeometry(QRect(10, 560, 121, 23));
        progressBar_3->setStyleSheet(QLatin1String("alternate-background-color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(35, 40, 3, 255), stop:0.16 rgba(136, 106, 22, 255), stop:0.225 rgba(166, 140, 41, 255), stop:0.285 rgba(204, 181, 74, 255), stop:0.345 rgba(235, 219, 102, 255), stop:0.415 rgba(245, 236, 112, 255), stop:0.52 rgba(209, 190, 76, 255), stop:0.57 rgba(187, 156, 51, 255), stop:0.635 rgba(168, 142, 42, 255), stop:0.695 rgba(202, 174, 68, 255), stop:0.75 rgba(218, 202, 86, 255), stop:0.815 rgba(208, 187, 73, 255), stop:0.88 rgba(187, 156, 51, 255), stop:0.935 rgba(137, 108, 26, 255), stop:1 rgba(35, 40, 3, 255));\n"
"background-color: rgb(85, 0, 0);\n"
"gridline-color: rgb(0, 0, 0);\n"
"\n"
""));
        progressBar_3->setValue(0);
        progressBar_3->setTextVisible(false);
        progressBar_3->setInvertedAppearance(false);
        progressBar_4 = new QProgressBar(centralwidget);
        progressBar_4->setObjectName(QStringLiteral("progressBar_4"));
        progressBar_4->setGeometry(QRect(130, 560, 121, 23));
        progressBar_4->setStyleSheet(QLatin1String("alternate-background-color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(35, 40, 3, 255), stop:0.16 rgba(136, 106, 22, 255), stop:0.225 rgba(166, 140, 41, 255), stop:0.285 rgba(204, 181, 74, 255), stop:0.345 rgba(235, 219, 102, 255), stop:0.415 rgba(245, 236, 112, 255), stop:0.52 rgba(209, 190, 76, 255), stop:0.57 rgba(187, 156, 51, 255), stop:0.635 rgba(168, 142, 42, 255), stop:0.695 rgba(202, 174, 68, 255), stop:0.75 rgba(218, 202, 86, 255), stop:0.815 rgba(208, 187, 73, 255), stop:0.88 rgba(187, 156, 51, 255), stop:0.935 rgba(137, 108, 26, 255), stop:1 rgba(35, 40, 3, 255));\n"
"background-color: rgb(85, 0, 0);\n"
"gridline-color: rgb(0, 0, 0);\n"
"\n"
""));
        progressBar_4->setValue(0);
        progressBar_4->setTextVisible(false);
        progressBar_4->setInvertedAppearance(false);
        progressBar_5 = new QProgressBar(centralwidget);
        progressBar_5->setObjectName(QStringLiteral("progressBar_5"));
        progressBar_5->setGeometry(QRect(980, 560, 121, 23));
        progressBar_5->setStyleSheet(QLatin1String("alternate-background-color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(35, 40, 3, 255), stop:0.16 rgba(136, 106, 22, 255), stop:0.225 rgba(166, 140, 41, 255), stop:0.285 rgba(204, 181, 74, 255), stop:0.345 rgba(235, 219, 102, 255), stop:0.415 rgba(245, 236, 112, 255), stop:0.52 rgba(209, 190, 76, 255), stop:0.57 rgba(187, 156, 51, 255), stop:0.635 rgba(168, 142, 42, 255), stop:0.695 rgba(202, 174, 68, 255), stop:0.75 rgba(218, 202, 86, 255), stop:0.815 rgba(208, 187, 73, 255), stop:0.88 rgba(187, 156, 51, 255), stop:0.935 rgba(137, 108, 26, 255), stop:1 rgba(35, 40, 3, 255));\n"
"background-color: rgb(85, 0, 0);\n"
"gridline-color: rgb(0, 0, 0);\n"
"\n"
""));
        progressBar_5->setValue(0);
        progressBar_5->setTextVisible(false);
        progressBar_5->setInvertedAppearance(true);
        progressBar_6 = new QProgressBar(centralwidget);
        progressBar_6->setObjectName(QStringLiteral("progressBar_6"));
        progressBar_6->setGeometry(QRect(860, 560, 121, 23));
        progressBar_6->setStyleSheet(QLatin1String("alternate-background-color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(35, 40, 3, 255), stop:0.16 rgba(136, 106, 22, 255), stop:0.225 rgba(166, 140, 41, 255), stop:0.285 rgba(204, 181, 74, 255), stop:0.345 rgba(235, 219, 102, 255), stop:0.415 rgba(245, 236, 112, 255), stop:0.52 rgba(209, 190, 76, 255), stop:0.57 rgba(187, 156, 51, 255), stop:0.635 rgba(168, 142, 42, 255), stop:0.695 rgba(202, 174, 68, 255), stop:0.75 rgba(218, 202, 86, 255), stop:0.815 rgba(208, 187, 73, 255), stop:0.88 rgba(187, 156, 51, 255), stop:0.935 rgba(137, 108, 26, 255), stop:1 rgba(35, 40, 3, 255));\n"
"background-color: rgb(85, 0, 0);\n"
"gridline-color: rgb(0, 0, 0);\n"
"\n"
""));
        progressBar_6->setValue(0);
        progressBar_6->setTextVisible(false);
        progressBar_6->setInvertedAppearance(true);
        iniciar_juego->setCentralWidget(centralwidget);
        menubar = new QMenuBar(iniciar_juego);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1136, 20));
        menuOpciones = new QMenu(menubar);
        menuOpciones->setObjectName(QStringLiteral("menuOpciones"));
        menuPausar = new QMenu(menubar);
        menuPausar->setObjectName(QStringLiteral("menuPausar"));
        iniciar_juego->setMenuBar(menubar);
        statusbar = new QStatusBar(iniciar_juego);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        iniciar_juego->setStatusBar(statusbar);

        menubar->addAction(menuOpciones->menuAction());
        menubar->addAction(menuPausar->menuAction());
        menuOpciones->addAction(actiongo);
        menuOpciones->addAction(actionstop);
        menuPausar->addAction(actionGuardar_Partida);
        menuPausar->addAction(actionSalir);

        retranslateUi(iniciar_juego);

        QMetaObject::connectSlotsByName(iniciar_juego);
    } // setupUi

    void retranslateUi(QMainWindow *iniciar_juego)
    {
        iniciar_juego->setWindowTitle(QApplication::translate("iniciar_juego", "MainWindow", Q_NULLPTR));
        actiongo->setText(QApplication::translate("iniciar_juego", "Go", Q_NULLPTR));
        actionstop->setText(QApplication::translate("iniciar_juego", "Stop", Q_NULLPTR));
        actionGuardar_Partida->setText(QApplication::translate("iniciar_juego", "Guardar Partida", Q_NULLPTR));
        actionSalir->setText(QApplication::translate("iniciar_juego", "Salir", Q_NULLPTR));
        label->setText(QApplication::translate("iniciar_juego", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("iniciar_juego", "      pausa", Q_NULLPTR));
        pushButton->setText(QApplication::translate("iniciar_juego", "Continue", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("iniciar_juego", "Guardar", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("iniciar_juego", "Salir", Q_NULLPTR));
        menuOpciones->setTitle(QApplication::translate("iniciar_juego", "Opciones", Q_NULLPTR));
        menuPausar->setTitle(QApplication::translate("iniciar_juego", "Pausar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class iniciar_juego: public Ui_iniciar_juego {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIAR_JUEGO_H
