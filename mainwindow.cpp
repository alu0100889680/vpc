#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_graphic.h"
#include <QtCore/QCoreApplication>
#include <iostream>
#include "graphic.h"
#include <QString>
#include "my_qlabel.h"
#include <QMainWindow>

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
            if((image_.width() > 2560)||(image_.height() > 2560))
                    image_ = image_.scaled(image_.width()/2,image_.height()/2);
            else
                ui->cuadroImg->setGeometry(50,50,image_.width(),image_.height());

            ui->cuadroImg->setPixmap(QPixmap::fromImage(image_));
            this->setWindowTitle(name_.fileName());
            cout << "Hola:  " << image_.depth() << endl;
        }
        else{
            cout << "Error cargando la imagen"  << endl;
        }
    }

    connect(ui->cuadroImg, SIGNAL(Mouse_Pos()), this, SLOT(Mouse_current_pos()));
}


void MainWindow::on_actionDuplicar_triggered(){

    //QWidget* W = new QWidget();
    MainWindow* W = new MainWindow(image_,name_.fileName());
    W->show();
}

void MainWindow::on_actionHistograma_triggered()
{
    Graphic grafico(image_, name_.fileName());
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

void MainWindow::Mouse_current_pos()
{
    ui->etiqueta_coordenadas->setText(QString("X = %1, Y = %2").arg(ui->cuadroImg->x).arg(ui->cuadroImg->y));
}

