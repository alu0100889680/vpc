#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/QCoreApplication>
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
        ui->setupUi(this);
        this->setWindowTitle("Programa VPC");
    }

MainWindow::~MainWindow(){
    delete ui;
}

QImage MainWindow::on_actionAbrir_triggered(){

    QString filename = QFileDialog::getOpenFileName(this, tr("Selecciona una imagen"), "", tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)"));
    QFileInfo file("/tmp/archive.tar.gz");
    QString name = file.fileName();

     QImage image;

    if(QString::compare(filename, QString()) != 0){


        QVector<QRgb> vector;
        bool valid = image.load(filename);

        if(valid) {
            ui->cuadroImg->setScaledContents(true);
            ui->cuadroImg->setPixmap(QPixmap::fromImage(image));
            this->setWindowTitle(name);



            //HISTOGRAMA//

            cout<<"HISTOGRAMA"<<endl;
            uchar *bits = image.bits();

            long int histograma[256];
            for (int i=0;i<256;i++){
                histograma[i]=0;
            }
            for (int i = 0; i < (image.width() * image.height()); i++)
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
            cout<<"total= "<<total;


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
    int a;
    cin>>a;
    on_actionDuplicar_triggered(image);
    return image;
}



void MainWindow::on_actionDuplicar_triggered(QImage image){

    cout<<"dupli";

    ui->cuadroImg->setScaledContents(true);
    ui->cuadroImg->setPixmap(QPixmap::fromImage(image));
    this->setWindowTitle("dupli");

}
