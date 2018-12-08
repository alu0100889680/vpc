#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "ui_mainwindow.h"
#include "ui_graphic.h"
#include <QtCore/QCoreApplication>
#include <iostream>
#include "graphic.h"
#include <QString>
#include "my_qlabel.h"
#include <QMainWindow>
#include <pthread.h>
#include <thread>
#include <QInputDialog>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

//class QVBoxLayout;
class QCustomPlot;
class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = nullptr);
    MainWindow( QImage img, QString title);
    ~MainWindow();
    Ui::MainWindow *ui;

private slots:

    void on_actionAbrir_triggered();
    void on_actionGuardar_triggered();
    void on_actionDuplicar_triggered();
    void on_actionHistograma_triggered();

    void on_actionRango_de_valores_triggered();
    void on_actionTama_o_triggered();
    void on_actionCambiar_Brillo_triggered();
    void on_actionTramos_triggered();
    void on_actionCambiar_Contraste_triggered();
    void on_actionCorrecci_on_Gamma_triggered();
    void on_actionDiferencia_triggered();
    void on_actionUmbralizar_con_Imagen_Diferencia_triggered();
    void on_actionRecortar_triggered();
    void on_actionCambiar_ByC_triggered();
    void on_actionUmbralizar_triggered();
    void on_actionEspejo_Vertical_triggered();
    void on_actionEspejo_Horizontal_triggered();
    void on_actionTranspuesta_triggered();
    void on_action90_triggered();
    void on_action180_triggered();
    void on_action270_triggered();
    void on_actionEscalado_IVMP_triggered();
    void on_actionEscalado_Bilineal_triggered();


    void Mouse_current_pos();

    void uno();
    void dos();


    void on_actionEscala_de_grises_triggered();
    void on_actionEcualizar_imagen_triggered();

private:

    QImage image_, grey_image_;
    QFileInfo name_;
    QVector<QVector<QColor> > vector_;
    QVector<double> acumulativo_, histograma_, lista_; //monocolor -> red = blue = green
    Graphic *grafico;
    QVBoxLayout *mLayout;
    QCustomPlot *mPlot;

};

#endif // MAINWINDOW_H
