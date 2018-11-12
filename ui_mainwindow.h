/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <my_qlabel.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbrir;
    QAction *actionGuardar;
    QAction *actionHistograma;
    QAction *actionHistograma_Acumulado;
    QAction *actionDuplicar;
    QAction *actionRango_de_valores;
    QAction *actionTama_o;
    QAction *actionCambiar_Brillo;
    QWidget *centralWidget;
    my_qlabel *cuadroImg;
    QLabel *etiqueta_coordenadas;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QMenu *menuAnalizar;
    QMenu *menuEditar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(407, 446);
        actionAbrir = new QAction(MainWindow);
        actionAbrir->setObjectName(QStringLiteral("actionAbrir"));
        actionGuardar = new QAction(MainWindow);
        actionGuardar->setObjectName(QStringLiteral("actionGuardar"));
        actionHistograma = new QAction(MainWindow);
        actionHistograma->setObjectName(QStringLiteral("actionHistograma"));
        actionHistograma_Acumulado = new QAction(MainWindow);
        actionHistograma_Acumulado->setObjectName(QStringLiteral("actionHistograma_Acumulado"));
        actionDuplicar = new QAction(MainWindow);
        actionDuplicar->setObjectName(QStringLiteral("actionDuplicar"));
        actionRango_de_valores = new QAction(MainWindow);
        actionRango_de_valores->setObjectName(QStringLiteral("actionRango_de_valores"));
        actionTama_o = new QAction(MainWindow);
        actionTama_o->setObjectName(QStringLiteral("actionTama_o"));
        actionCambiar_Brillo = new QAction(MainWindow);
        actionCambiar_Brillo->setObjectName(QStringLiteral("actionCambiar_Brillo"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        cuadroImg = new my_qlabel(centralWidget);
        cuadroImg->setObjectName(QStringLiteral("cuadroImg"));
        cuadroImg->setEnabled(true);
        cuadroImg->setGeometry(QRect(10, 50, 361, 321));
        cuadroImg->setMinimumSize(QSize(0, 0));
        cuadroImg->setSizeIncrement(QSize(0, 0));
        cuadroImg->setMouseTracking(true);
        cuadroImg->setFocusPolicy(Qt::ClickFocus);
        cuadroImg->setAutoFillBackground(false);
        cuadroImg->setStyleSheet(QStringLiteral(""));
        cuadroImg->setFrameShape(QFrame::Box);
        cuadroImg->setMidLineWidth(0);
        cuadroImg->setMargin(0);
        etiqueta_coordenadas = new QLabel(centralWidget);
        etiqueta_coordenadas->setObjectName(QStringLiteral("etiqueta_coordenadas"));
        etiqueta_coordenadas->setGeometry(QRect(10, 0, 131, 41));
        etiqueta_coordenadas->setFrameShape(QFrame::Box);
        etiqueta_coordenadas->setFrameShadow(QFrame::Raised);
        etiqueta_coordenadas->setMidLineWidth(0);
        etiqueta_coordenadas->setTextFormat(Qt::AutoText);
        etiqueta_coordenadas->setAlignment(Qt::AlignCenter);
        etiqueta_coordenadas->setMargin(0);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 407, 26));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        menuAnalizar = new QMenu(menuBar);
        menuAnalizar->setObjectName(QStringLiteral("menuAnalizar"));
        MainWindow->setMenuBar(menuBar);
        menuEditar = new QMenu(menuBar);
        menuEditar->setObjectName(QStringLiteral("menuEditar"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuBar->addAction(menuAnalizar->menuAction());
        menuBar->addAction(menuEditar->menuAction());
        menuArchivo->addAction(actionAbrir);
        menuArchivo->addAction(actionGuardar);
        menuArchivo->addAction(actionDuplicar);
        menuAnalizar->addAction(actionHistograma);
        menuAnalizar->addAction(actionHistograma_Acumulado);
        menuAnalizar->addAction(actionRango_de_valores);
        menuAnalizar->addAction(actionTama_o);
        menuEditar->addAction(actionCambiar_Brillo);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAbrir->setText(QApplication::translate("MainWindow", "Abrir", nullptr));
        actionGuardar->setText(QApplication::translate("MainWindow", "Guardar", nullptr));
        actionHistograma->setText(QApplication::translate("MainWindow", "Histograma", nullptr));
        actionHistograma_Acumulado->setText(QApplication::translate("MainWindow", "Histograma Acumulado", nullptr));
        actionDuplicar->setText(QApplication::translate("MainWindow", "Duplicar", nullptr));
        actionRango_de_valores->setText(QApplication::translate("MainWindow", "Rango de valores", nullptr));
        actionTama_o->setText(QApplication::translate("MainWindow", "Tama\303\261o", nullptr));
        actionCambiar_Brillo->setText(QApplication::translate("MainWindow", "Cambiar Brillo", nullptr));
        cuadroImg->setText(QString());
        etiqueta_coordenadas->setText(QApplication::translate("MainWindow", "X = 0, Y = 0", nullptr));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", nullptr));
        menuAnalizar->setTitle(QApplication::translate("MainWindow", "Analizar", nullptr));
        menuEditar->setTitle(QApplication::translate("MainWindow", "Editar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
