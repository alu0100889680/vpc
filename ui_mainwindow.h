/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
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
    QAction *actionDuplicar;
    QAction *actionRango_de_valores;
    QAction *actionTama_o;
    QAction *actionHistograma_Acumulativo;
    QAction *actionCojo;
    QAction *actionHola;
    QAction *actionNUEVO;
    QAction *actionCambiar_Brillo;
    QAction *actionTransformaci_n_por_Tramos;
    QAction *actionEscala_de_grises;
    QAction *actionE;
    QAction *actionEcualizar_imagen;
    QAction *actionCambiar_Contraste;
    QAction *actionCorrecci_on_Gamma;
    QWidget *centralWidget;
    my_qlabel *cuadroImg;
    QLabel *etiqueta_coordenadas;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QMenu *menuAnalizar;
    QMenu *menuEditar;
    QMenu *menuPrueba;
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
        actionDuplicar = new QAction(MainWindow);
        actionDuplicar->setObjectName(QStringLiteral("actionDuplicar"));
        actionRango_de_valores = new QAction(MainWindow);
        actionRango_de_valores->setObjectName(QStringLiteral("actionRango_de_valores"));
        actionTama_o = new QAction(MainWindow);
        actionTama_o->setObjectName(QStringLiteral("actionTama_o"));
        actionHistograma_Acumulativo = new QAction(MainWindow);
        actionHistograma_Acumulativo->setObjectName(QStringLiteral("actionHistograma_Acumulativo"));
        actionHistograma_Acumulativo->setCheckable(false);
        actionHistograma_Acumulativo->setEnabled(true);
        actionHistograma_Acumulativo->setVisible(true);
        actionCojo = new QAction(MainWindow);
        actionCojo->setObjectName(QStringLiteral("actionCojo"));
        actionHola = new QAction(MainWindow);
        actionHola->setObjectName(QStringLiteral("actionHola"));
        actionNUEVO = new QAction(MainWindow);
        actionNUEVO->setObjectName(QStringLiteral("actionNUEVO"));
        actionCambiar_Brillo = new QAction(MainWindow);
        actionCambiar_Brillo->setObjectName(QStringLiteral("actionCambiar_Brillo"));
        actionTransformaci_n_por_Tramos = new QAction(MainWindow);
        actionTransformaci_n_por_Tramos->setObjectName(QStringLiteral("actionTransformaci_n_por_Tramos"));
        actionEscala_de_grises = new QAction(MainWindow);
        actionEscala_de_grises->setObjectName(QStringLiteral("actionEscala_de_grises"));
        actionE = new QAction(MainWindow);
        actionE->setObjectName(QStringLiteral("actionE"));
        actionEcualizar_imagen = new QAction(MainWindow);
        actionEcualizar_imagen->setObjectName(QStringLiteral("actionEcualizar_imagen"));
        actionCambiar_Contraste = new QAction(MainWindow);
        actionCambiar_Contraste->setObjectName(QStringLiteral("actionCambiar_Contraste"));
        actionCorrecci_on_Gamma = new QAction(MainWindow);
        actionCorrecci_on_Gamma->setObjectName(QStringLiteral("actionCorrecci_on_Gamma"));
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
        menuBar->setGeometry(QRect(0, 0, 407, 21));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        menuAnalizar = new QMenu(menuBar);
        menuAnalizar->setObjectName(QStringLiteral("menuAnalizar"));
        menuEditar = new QMenu(menuBar);
        menuEditar->setObjectName(QStringLiteral("menuEditar"));
        menuPrueba = new QMenu(menuBar);
        menuPrueba->setObjectName(QStringLiteral("menuPrueba"));
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
        menuBar->addAction(menuPrueba->menuAction());
        menuArchivo->addAction(actionAbrir);
        menuArchivo->addAction(actionGuardar);
        menuArchivo->addAction(actionDuplicar);
        menuAnalizar->addAction(actionHistograma);
        menuAnalizar->addAction(actionRango_de_valores);
        menuAnalizar->addAction(actionTama_o);
        menuAnalizar->addAction(actionHistograma_Acumulativo);
        menuAnalizar->addAction(actionEcualizar_imagen);
        menuEditar->addAction(actionCambiar_Brillo);
        menuEditar->addAction(actionCambiar_Contraste);
        menuEditar->addAction(actionTransformaci_n_por_Tramos);
        menuEditar->addAction(actionEscala_de_grises);
        menuEditar->addAction(actionCorrecci_on_Gamma);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionAbrir->setText(QApplication::translate("MainWindow", "Abrir", 0));
        actionGuardar->setText(QApplication::translate("MainWindow", "Guardar", 0));
        actionHistograma->setText(QApplication::translate("MainWindow", "Histograma", 0));
        actionDuplicar->setText(QApplication::translate("MainWindow", "Duplicar", 0));
        actionRango_de_valores->setText(QApplication::translate("MainWindow", "Rango de valores", 0));
        actionTama_o->setText(QApplication::translate("MainWindow", "Tama\303\261o", 0));
        actionHistograma_Acumulativo->setText(QApplication::translate("MainWindow", "Histograma Acumulado", 0));
        actionCojo->setText(QApplication::translate("MainWindow", "cojo", 0));
        actionHola->setText(QApplication::translate("MainWindow", "hola", 0));
        actionNUEVO->setText(QApplication::translate("MainWindow", "NUEVO", 0));
        actionCambiar_Brillo->setText(QApplication::translate("MainWindow", "Cambiar Brillo", 0));
        actionTransformaci_n_por_Tramos->setText(QApplication::translate("MainWindow", "Transformaci\303\263n por Tramos", 0));
        actionEscala_de_grises->setText(QApplication::translate("MainWindow", "Escala de grises", 0));
        actionE->setText(QApplication::translate("MainWindow", "Ecualizar imagen", 0));
        actionEcualizar_imagen->setText(QApplication::translate("MainWindow", "Ecualizar imagen", 0));
        actionCambiar_Contraste->setText(QApplication::translate("MainWindow", "Cambiar Contraste", 0));
        actionCorrecci_on_Gamma->setText(QApplication::translate("MainWindow", "Correcci\303\263n Gamma", 0));
        cuadroImg->setText(QString());
        etiqueta_coordenadas->setText(QApplication::translate("MainWindow", "X = 0, Y = 0", 0));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", 0));
        menuAnalizar->setTitle(QApplication::translate("MainWindow", "Analizar", 0));
        menuEditar->setTitle(QApplication::translate("MainWindow", "Editar", 0));
        menuPrueba->setTitle(QApplication::translate("MainWindow", "Prueba", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
