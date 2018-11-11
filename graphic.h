#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QDialog>
#include <QImage>
#include <iostream>
#include <QString>
#include <QFileInfo>
#include <math.h>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>
#include <QLabel>


using namespace std;

namespace Ui {
class Graphic;
}

class Graphic : public QDialog
{
    Q_OBJECT

public:
    explicit Graphic(QWidget *parent = nullptr);
    Graphic(QImage img, QFileInfo name, int acumu);


    ~Graphic();

private slots:

    void on_acumulativo_clicked();
    void on_histograma_clicked();

private:
    Ui::Graphic *ui;
    QVector<double> x_,lista_, color_table_, acumulativo_;
    double contador_, max_;
    QImage image_;
    QFileInfo name_;
};

#endif // GRAPHIC_H
