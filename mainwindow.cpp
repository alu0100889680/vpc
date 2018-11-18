#include "mainwindow.h"
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

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
        ui->setupUi(this);
        this->setWindowTitle("Programa VPC");
        cout <<" hola estas en el constroctor" <<endl;

       connect(ui->cuadroImg, SIGNAL(sendMousePosition(QPoint&)), this, SLOT(showMousePosition(Qpoint&)));
    }

MainWindow::MainWindow(QImage img, QString title):
    image_(img),
    name_(title),
    ui(new Ui::MainWindow){
        ui->setupUi(this);
        this->setWindowTitle(name_.fileName());
        this->ui->cuadroImg->setScaledContents(true);
        this->ui->cuadroImg->setPixmap(QPixmap::fromImage(image_));
        this->setWindowTitle(title);
        connect(ui->cuadroImg, SIGNAL(sendMousePosition(QPoint&)), this, SLOT(showMousePosition(Qpoint&)));

    };


MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_actionAbrir_triggered(){

    QString filename = QFileDialog::getOpenFileName(this, tr("Selecciona una imagen"), "", tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)"));
    QFileInfo file = filename;
    name_ = filename;

    if(QString::compare(filename, QString()) != 0){

        QVector<QRgb> vector;
        bool valid = image_.load(filename);
//        bool valid = image_.load(name_.fileName());

        if(valid) {
//            ui->cuadroImg->setScaledContents(true);       // Con esta se ajusta la imagen al tamaño del widget
            if((image_.width() > 2560)&&(image_.height() > 1800))
                    image_ = image_.scaled(image_.width()/2,image_.height()/2);
            else
                ui->cuadroImg->setGeometry(50,50,image_.width(),image_.height());


            cout << "Hola:  " << image_.width()*image_.height() << endl;

            if(!image_.allGray()){
                grey_image_ = image_;
                for (int ii = 0; ii < image_.width(); ii++) {
                    for (int jj = 0; jj < image_.height(); jj++) {
                        int gray = qGray(image_.pixel(ii, jj));
                        grey_image_.setPixel(ii, jj, QColor(gray, gray, gray).rgb());
                    }
                }
            }
            else
                grey_image_ = image_;

            ui->cuadroImg->setPixmap(QPixmap::fromImage(image_));
            ui->cuadroImg->setGeometry(50,50,image_.width(),image_.height());

            this->setWindowTitle(name_.fileName());
        }
        else{
            cout << "Error cargando la imagen"  << endl;
        }
    }

    connect(ui->cuadroImg, SIGNAL(Mouse_Pos()), this, SLOT(Mouse_current_pos()));
}


void MainWindow::on_actionDuplicar_triggered(){

    MainWindow* W = new MainWindow(image_,name_.fileName());
    W->ui->cuadroImg->setGeometry(50,50,image_.width(),image_.height());
    W->show();
}

void MainWindow::on_actionHistograma_triggered()
{
//<<<<<<< HEAD

    // Esto funciona (3)
//    Graphic grafico;
//    grafico.setModal(true);
//    grafico.exec();

 //  grafico = new Graphic(image_);
  // grafico->show();

    //    //HISTOGRAMA//

    // generate some data:
//    QVector<double> x(101), y(101); // initialize with entries 0..100
//    for (int i=0; i<101; ++i)
//    {
//      x[i] = i/50.0 - 1; // x goes from -1 to 1
//      y[i] = x[i]*x[i]; // let's plot a quadratic function
//    }
    // create graph and assign data to it:
//    grafico->addGraph();
//    grafico->graph(0)->setData(x, y);
//    // give the axes some labels:
//    grafico->xAxis->setLabel("x");
//    grafico->yAxis->setLabel("y");
//    // set axes ranges, so we see all data:
//    grafico->xAxis->setRange(-1, 1);
//    grafico->yAxis->setRange(0, 1);
//    grafico->replot();

 /*   cout<<"HISTOGRAMA"<<endl;
    uchar *bits = image_.bits();

    long int histograma[256];
    for (int i=0;i<256;i++){
        histograma[i]=0;
    }
    for (int i = 0; i < (image_.width() * image_.height()); i++)
    {
        histograma[bits[i]]++;
    }
    for (int i=0; i<256; i++){
        cout<<i<<"\t="<<histograma[i]<<endl;
    }

    long int total=0;
    for (int i=0;i<256;i++){
        total+=histograma[i];
    }

    long int brillo=0;
    for (int i=0;i<256;i++){
        brillo+=histograma[i]*i;
    }
    brillo = brillo /(image_.height() * image_.width());

    //qsizetype a = image_.sizeInBytes();

    cout << image_.height() * image_.width() << endl;
    cout << "Brillo = "<<brillo<<endl;


    //cout << a << endl;

//    QCPBars *myBars = new QCPBars(mPlot->xAxis, mPlot->yAxis);
//    // now we can modify properties of myBars:
//    myBars->setName("Bars Series 1");
//    QVector<double> keyData;
//    QVector<double> valueData;
//    keyData << 1 << 2 << 3;
//    valueData << 1 << 2 << 3;
//    myBars->setData(keyData, valueData);
//    mPlot->rescaleAxes();
//    mPlot->replot();
//=======
    */
    Graphic grafico(image_, grey_image_, name_.fileName(), 0);
    grafico.setModal(true);
    grafico.exec();



//>>>>>>> 72e6f673c7bccc85f843a9815c7b415ef6a1c36a
}
void MainWindow::uno(){

    Graphic grafico(image_, grey_image_, name_.fileName(), 0);
    grafico.setModal(true);
    grafico.exec();

}
void MainWindow::dos(){

    Graphic grafico(image_, grey_image_, name_.fileName(), 1);
    grafico.setModal(true);
    grafico.exec();

}
void MainWindow::on_actionHistograma_Acumulado_triggered()
{
    Graphic grafico(image_, grey_image_, name_.fileName(), 1);
    grafico.setModal(true);
    grafico.exec();
}

void MainWindow::on_actionRango_de_valores_triggered()
{
    cout<<"rango de valores"<<endl;

     uchar *bits = image_.bits();
    long int histograma[256];
    for (int i=0;i<256;i++){
        histograma[i]=0;
    }
    for (int i = 0; i < (image_.width() * image_.height()); i++)
    {
        histograma[bits[i]]++;
    }
    int min, max;
    for (int i=0; i<256;i++){
        if(histograma[i]!=0){
            min=i;
            break;
        }
    }
    for (int i=255; i>0;i--){
        if(histograma[i]!=0){
            max=i;
            break;
        }
    }
   // +min+"max= "+max
    QString rango("min= ");
     rango.append(QString::number(min));
    rango.append("\nmax= ");
    rango.append(QString::number(max));

    QMessageBox::information(this,"Rango de Valores",rango);
}

void MainWindow::on_actionTama_o_triggered()
{
    QString rango(QString::number(image_.width()));
    rango.append(" x ");
    rango.append(QString::number(image_.height()));

    QMessageBox::information(this,"Tamaño de la imagen",rango);
}

void MainWindow::on_actionCambiar_Brillo_triggered()
{
    QImage nueva;
    nueva = image_;
    int var = 0;
    cin >> var;
//        cout<<nueva.pixelColor(25,25).value();
//               nueva.setPixel(25,25,qRgb(150,150,150));
    for(int i =0;i<nueva.width();i++)
       for(int j=0; j<nueva.height();j++){
           int color= nueva.pixelColor(i,j).value() + var;
           if (color>255) color = 255;
           if (color<0) color = 0;
            nueva.setPixel(i,j,qRgb(color,color,color));
       }

    MainWindow* W = new MainWindow(nueva,name_.fileName());
    W->show();

}

void MainWindow::on_actionTramos_triggered()
{
    cout<<"Numero de tramos: ";
    int n;
    cin>>n;
    int tramo[n][2];
    for (int i=0;i<n;i++){
        cout<<endl<<i+1<<"º X: ";
        cin>>tramo[i][0];
        cout<<endl<<"Y: ";
        cin>>tramo[i][1];
    }
    QImage nueva;
    nueva = image_;


    for(int i =0;i<nueva.width();i++){
        for(int j=0; j<nueva.height();j++){
            int color= nueva.pixelColor(i,j).value() + 10;
            for(int k=0; k<n;k++){
                if (color<tramo[k][0]){
                    color = tramo[k][1];
                    break;
                }
            }
            nueva.setPixel(i,j,qRgb(color,color,color));
        }
    }

 MainWindow* W = new MainWindow(nueva,name_.fileName());
  W->show();
}

void MainWindow::Mouse_current_pos()
{
    ui->etiqueta_coordenadas->setText(QString("X = %1, Y = %2").arg(ui->cuadroImg->x).arg(ui->cuadroImg->y));
}

void MainWindow::on_actionEscala_de_grises_triggered()
{

    if(!image_.allGray()){
        grey_image_ = image_;
        for (int ii = 0; ii < image_.width(); ii++) {
            for (int jj = 0; jj < image_.height(); jj++) {
                QRgb pix = image_.pixel(ii,jj);
                double red = qRed(pix);
                double green = qGreen(pix);
                double blue = qBlue(pix);
                int gray = (0.222*red)+(0.707*green)+(0.071*blue);
                grey_image_.setPixel(ii,jj,QColor(gray,gray,gray).rgb());
            }
        }
    }
    else
        grey_image_ = image_;

    MainWindow* W = new MainWindow(grey_image_,name_.fileName());

    if((grey_image_.width() > 2560)&&(grey_image_.height() > 1800))
            grey_image_ = grey_image_.scaled(grey_image_.width()/2,grey_image_.height()/2);
    else
        W->ui->cuadroImg->setGeometry(50,50,grey_image_.width(),grey_image_.height());

    W->show();

}

void MainWindow::on_actionEcualizar_imagen_triggered()
{


////        cout<<nueva.pixelColor(25,25).value();
////               nueva.setPixel(25,25,qRgb(150,150,150));
//    for(int i =0;i<nueva.width();i++)
//       for(int j=0; j<nueva.height();j++){
//           int color= nueva.pixelColor(i,j).value() + 10;
//           if (color>255) color = 255;
//           if (color<0) color = 0;
//            nueva.setPixel(i,j,qRgb(color,color,color));
//       }
}
