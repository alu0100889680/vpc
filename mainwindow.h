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


namespace Ui {
class MainWindow;
}

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

private:

    QImage image_;
    QString name_;
    QVector<QVector<QColor> > vector_; //monocolor -> red = blue = green
    // Añadir atributo bool monocromo o no
    Ui::MainWindow *ui;
    Graphic *grafico;
};

#endif // MAINWINDOW_H
