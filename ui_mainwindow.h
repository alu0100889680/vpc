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
    QAction *actionDuplicar;
    QAction *actionRango_de_valores;
    QAction *actionTama_o;
    QAction *actionHistograma_Acumulativo;
    QAction *actionCojo;
    QAction *actionHola;
    QAction *actionNUEVO;
    QAction *actionCambiar_Brillo;
    QAction *actionTramos;
    QAction *actionEscala_de_grises;
    QAction *actionE;
    QAction *actionEcualizar_imagen;
    QAction *actionCambiar_Contraste;
    QAction *actionCorrecci_on_Gamma;
    QAction *actionDiferencia;
    QAction *actionRecortar;
    QAction *actionCambiar_ByC;
    QAction *actionUmbralizar;
    QAction *actionUmbralizar_con_Imagen_Diferencia;
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
        actionTramos = new QAction(MainWindow);
        actionTramos->setObjectName(QStringLiteral("actionTramos"));
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
        actionDiferencia = new QAction(MainWindow);
        actionDiferencia->setObjectName(QStringLiteral("actionDiferencia"));
        actionRecortar = new QAction(MainWindow);
        actionRecortar->setObjectName(QStringLiteral("actionRecortar"));
        actionCambiar_ByC = new QAction(MainWindow);
        actionCambiar_ByC->setObjectName(QStringLiteral("actionCambiar_ByC"));
        actionUmbralizar = new QAction(MainWindow);
        actionUmbralizar->setObjectName(QStringLiteral("actionUmbralizar"));
        actionUmbralizar_con_Imagen_Diferencia = new QAction(MainWindow);
        actionUmbralizar_con_Imagen_Diferencia->setObjectName(QStringLiteral("actionUmbralizar_con_Imagen_Diferencia"));
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
        etiqueta_coordenadas->setGeometry(QRect(10, 0, 361, 41));
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
        menuAnalizar->addAction(actionRango_de_valores);
        menuAnalizar->addAction(actionTama_o);
        menuAnalizar->addAction(actionHistograma_Acumulativo);
        menuAnalizar->addAction(actionEcualizar_imagen);
        menuEditar->addAction(actionCambiar_Brillo);
        menuEditar->addAction(actionCambiar_Contraste);
        menuEditar->addAction(actionCambiar_ByC);
        menuEditar->addAction(actionTramos);
        menuEditar->addAction(actionUmbralizar);
        menuEditar->addAction(actionEscala_de_grises);
        menuEditar->addAction(actionCorrecci_on_Gamma);
        menuEditar->addAction(actionDiferencia);
        menuEditar->addAction(actionUmbralizar_con_Imagen_Diferencia);
        menuEditar->addAction(actionRecortar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAbrir->setText(QApplication::translate("MainWindow", "Abrir", nullptr));
        actionGuardar->setText(QApplication::translate("MainWindow", "Guardar", nullptr));
        actionHistograma->setText(QApplication::translate("MainWindow", "Histograma", nullptr));
        actionDuplicar->setText(QApplication::translate("MainWindow", "Duplicar", nullptr));
        actionRango_de_valores->setText(QApplication::translate("MainWindow", "Rango de valores", nullptr));
        actionTama_o->setText(QApplication::translate("MainWindow", "Tama\303\261o", nullptr));
        actionHistograma_Acumulativo->setText(QApplication::translate("MainWindow", "Histograma Acumulado", nullptr));
        actionCojo->setText(QApplication::translate("MainWindow", "cojo", nullptr));
        actionHola->setText(QApplication::translate("MainWindow", "hola", nullptr));
        actionNUEVO->setText(QApplication::translate("MainWindow", "NUEVO", nullptr));
        actionCambiar_Brillo->setText(QApplication::translate("MainWindow", "Cambiar Brillo", nullptr));
        actionTramos->setText(QApplication::translate("MainWindow", "Transformaci\303\263n por Tramos", nullptr));
        actionEscala_de_grises->setText(QApplication::translate("MainWindow", "Escala de grises", nullptr));
        actionE->setText(QApplication::translate("MainWindow", "Ecualizar imagen", nullptr));
        actionEcualizar_imagen->setText(QApplication::translate("MainWindow", "Ecualizar imagen", nullptr));
        actionCambiar_Contraste->setText(QApplication::translate("MainWindow", "Cambiar Contraste", nullptr));
        actionCorrecci_on_Gamma->setText(QApplication::translate("MainWindow", "Correcci\303\263n Gamma", nullptr));
        actionDiferencia->setText(QApplication::translate("MainWindow", "Diferencia de Im\303\241genes", nullptr));
        actionRecortar->setText(QApplication::translate("MainWindow", "Recortar", nullptr));
        actionCambiar_ByC->setText(QApplication::translate("MainWindow", "Cambiar Brillo y Contraste", nullptr));
        actionUmbralizar->setText(QApplication::translate("MainWindow", "Umbralizar", nullptr));
        actionUmbralizar_con_Imagen_Diferencia->setText(QApplication::translate("MainWindow", "Umbralizar con Imagen Diferencia", nullptr));
        cuadroImg->setText(QString());
        etiqueta_coordenadas->setText(QApplication::translate("MainWindow", "X = 0, Y = 0   (R,G,B)", nullptr));
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
