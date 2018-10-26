#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_graphic.h"
#include <QtCore/QCoreApplication>
#include <iostream>
#include "graphic.h"


using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
        ui->setupUi(this);
        this->setWindowTitle("Programa VPC");
        cout <<" hola estas en el constroctor" <<endl;
    }

MainWindow::MainWindow(QImage img, QString title):
    image_(img),
    name_(title),
    ui(new Ui::MainWindow){
        ui->setupUi(this);
        this->setWindowTitle(name_);
        this->ui->cuadroImg->setScaledContents(true);
        this->ui->cuadroImg->setPixmap(QPixmap::fromImage(image_));
        this->setWindowTitle(title);
    };
//    uo(new Ui::QCustomPlot){
//        ui->setupUi(this);
//        this->setWindowTitle(name_);
//        this->ui->cuadroImg->setScaledContents(true);
//        this->ui->cuadroImg->setPixmap(QPixmap::fromImage(image_));
//        this->setWindowTitle(title);
//    };


MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_actionAbrir_triggered(){


    QString filename = QFileDialog::getOpenFileName(this, tr("Selecciona una imagen"), "", tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)"));
    QFileInfo file = filename;
    name_ = file.fileName();


    if(QString::compare(filename, QString()) != 0){

        QVector<QRgb> vector;
        bool valid = image_.load(filename);

        if(valid) {
            ui->cuadroImg->setScaledContents(true);
            ui->cuadroImg->setPixmap(QPixmap::fromImage(image_));
            this->setWindowTitle(name_);

//            for(int i=0; i< this->height(); i++){
//                for(int j=0; j < this->g)
//            }

            //cout<<"total= "<<total;


           // image = image.convertToFormat(QImage::Format_RGB888);

           /* uchar *bits = image.bits();

            for (int i = 0; i < (image.width() * image.height() * 3); i++)
            {
                vector.push_back(bits[i]);
            }
            cout << endl;

//            vector = image.colorTable();
            cout << vector.size() << endl;
            for (int i = 0; i < vector.size(); i++){
                cout << vector.at(i) << " ";
            }
            cout << endl;*/
            // Cuando carga la imagen, crear el objeto (deberia ser global o sea que declarar en el .h), en la etiqueta de abajo de la ventana
            // "imprimir" la extension de la imagen o el tamaño


            // Nota: para coger la extensión de la foto usar QString QFileInfo::completeSuffix() const
            // En QImage hay un metodo booleano que detecta una imagen monocromo o rgb (bool QImage::allGray() const)
        }
        else{
            // Error
            cout << "errorrrrrr"  << endl;
        }
    }
}



void MainWindow::on_actionDuplicar_triggered(){

    //QWidget* W = new QWidget();
    MainWindow* W = new MainWindow(image_,name_);
    W->show();
//    W->ui->cuadroImg->setScaledContents(true);
//    W->ui->cuadroImg->setPixmap(QPixmap::fromImage(image_));
//    W->setWindowTitle(name_);
}

void MainWindow::on_actionHistograma_triggered()
{

    // Esto funciona (3)
//    Graphic grafico;
//    grafico.setModal(true);
//    grafico.exec();

   grafico = new Graphic(image_);
   grafico->show();

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

//    cout<<"HISTOGRAMA"<<endl;
//    uchar *bits = image_.bits();

//    long int histograma[256];
//    for (int i=0;i<256;i++){
//        histograma[i]=0;
//    }
//    for (int i = 0; i < (image_.width() * image_.height()); i++)
//    {
//        histograma[bits[i]]++;
//    }
//    for (int i=0; i<256; i++){
//        cout<<i<<"\t="<<histograma[i]<<endl;
//    }

//    long int total=0;
//    for (int i=0;i<256;i++){
//        total+=histograma[i];
//    }


//    qsizetype a = image_.sizeInBytes();

//    cout << image_.height() * image_.width() << endl;
//    cout << a << endl;
}
