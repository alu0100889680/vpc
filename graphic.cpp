#include "graphic.h"
#include "ui_graphic.h"

Graphic::Graphic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graphic)
{
    ui->setupUi(this);

    int size = 10;
    QVector<double> x(10), y(size);

    for(int i = 0; i < 256; i++)
        x[i] = i;

    ui->plot->addGraph();
    ui->plot->graph(0)->setData(x,y);
    ui->plot->xAxis->setRange(0,255);
    ui->plot->yAxis->setRange(0,10000); // Aqui ira el numero de pixeles
}

Graphic::Graphic(QImage img):
    ui(new Ui::Graphic)
{
    ui->setupUi(this);
    QVector<double> x(255), y;


        // ESTO NO FUNCIONA
    double val = 0;
//    for(int i = 0; i < 256; i++)
//        x[i] = val++;


    //http://doc.qt.io/qt-5/qtcharts-barchart-example.html

     uchar *bits = img.bits();

     for (int i = 0; i < img.width() * img.height(); i++)
     {
//         y.push_back(bits[i]);
         cout << bits[i] << "   ";
     }
     cout << endl;

//    ui->plot->addGraph();
//    ui->plot->graph(0)->setData(x,y);
//    ui->plot->xAxis->setRange(0,255);
//    ui->plot->yAxis->setRange(0,img.width() * img.height()); // Aqui ira el numero de pixeles
}

Graphic::~Graphic()
{
    delete ui;
}
