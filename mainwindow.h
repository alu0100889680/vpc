#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graphic.h"
#include <QFileDialog>
#include <QImage>
#include <QVector>
#include <QColor>
#include "qcustomplot.h"
#include <iostream>
#include <QVBoxLayout>



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

private slots:

    void on_actionAbrir_triggered();
    void on_actionDuplicar_triggered();
    void on_actionHistograma_triggered();
    void on_actionHistograma_Acumulado_triggered();
    void on_actionRango_de_valores_triggered();
    void on_actionTama_o_triggered();
    void on_actionCambiar_Brillo_triggered();
    void on_actionTramos_triggered();


    void Mouse_current_pos();

    void uno();
    void dos();

private:

    QImage image_;
    QFileInfo name_;
    QVector<QVector<QColor> > vector_; //monocolor -> red = blue = green
    // Añadir atributo bool monocromo o no
    Ui::MainWindow *ui;
    Graphic *grafico;
    QVBoxLayout *mLayout;
    QCustomPlot *mPlot;

};

#endif // MAINWINDOW_H
