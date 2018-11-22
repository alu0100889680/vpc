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

            QImage img = image_.convertToFormat(QImage::Format_RGB888);   // Convertir a RGB de 8 bits
            uchar *bits = img.bits();

            for (int i = 0; i < (image_.width() * image_.height() * 3); i++)
                lista_.push_back(bits[i]);

            for (int i = 0; i < 256; i++){
                int cont = lista_.count(i);
                histograma_.push_back(cont);
            }
            acumulativo_.push_back(histograma_[0]);
            for (int i =1; i<histograma_.size(); i++){
                acumulativo_.push_back(histograma_[i]+acumulativo_[i-1]);
            }

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

void MainWindow::on_actionGuardar_triggered(){
    //QString QFileDialog::getSaveFileName(QWidget * parent = 0, const QString & caption = QString(), const QString & dir = QString(), const QString & filter = QString(), QString * selectedFilter = 0, Options options = 0);

//    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
//                               "~/untitled.png",
//                               tr("Images (*.png *.xpm *.jpg)"));
    QString imagePath = QFileDialog::getSaveFileName( this, tr("Save File"),
                                                      "",tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" ));


    image_.save(imagePath);
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
     cout<<"Inserte variación del brillo: ";
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

void MainWindow::on_actionCambiar_Contraste_triggered()
{
    QImage nueva;
    nueva = image_;
    int var = 0;
    cout<<"Inserte variación del contraste: ";
    cin >> var;
//        cout<<nueva.pixelColor(25,25).value();
//               nueva.setPixel(25,25,qRgb(150,150,150));
QVector<double> x_,lista_, color_table_, acumulativo_;
double contador_ = 0.0;


        nueva = nueva.convertToFormat(QImage::Format_RGB888);   // Convertir a RGB de 8 bits
        uchar *bits = nueva.bits();

        // Lista de todos los colores
        for (int i = 0; i < (nueva.width() * nueva.height() * 3); i++)
            lista_.push_back(bits[i]);


        // Lista de pixeles / color
        for (int i = 0; i < 256; i++){
            int cont = lista_.count(i);
            x_.push_back(i);
            color_table_.push_back(cont);
            contador_ += cont;
        }

        acumulativo_.push_back(color_table_[0]);
        for (int i =1; i<color_table_.size(); i++){
            acumulativo_.push_back(color_table_[i]+acumulativo_[i-1]);
        }

        double sumatorio = 0.0, sumatorio2= 0.0,  media = 0.0, desvt = 0.0;

        // MEDIA / BRILLO
        for (int i = 0; i < 256; i++){
                sumatorio = sumatorio + color_table_[i]*i;
        }
        media = sumatorio / contador_;

        // DT / CONTRASTE
        for (int i = 0; i < 256; i++){
                double potencia = pow(i-media, 2);
                sumatorio2 = sumatorio2 + round(potencia*color_table_[i]);
        }
        desvt = sqrt(sumatorio2/contador_);

cout<<media<<" "<<desvt<<endl;
double A = (desvt + var)/ desvt;
double B = media - A * media;

cout<<A<<" "<<B<<endl;

    for(int i =0;i<nueva.width();i++)
       for(int j=0; j<nueva.height();j++){
           int color= A * nueva.pixelColor(i,j).value() + B;
           if (color>255) color = 255;
           if (color<0) color = 0;
           nueva.setPixel(i,j,qRgb(color,color,color));
       }

    MainWindow* W = new MainWindow(nueva,name_.fileName());
    W->show();

}

void MainWindow::on_actionCorrecci_on_Gamma_triggered()
{
    QImage nueva;
    nueva = image_;
    double var = 0.0;
     cout<<"Inserte función Gamma: ";
    cin >> var;

    for(int i =0;i<nueva.width();i++)
       for(int j=0; j<nueva.height();j++){
           double A= nueva.pixelColor(i,j).value();
           A = A/255;
           double B = pow(A,var);//cout<<"A= "<<A<<endl<<"B= "<<B<<endl;
           int color = round(B*255);
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

void MainWindow::on_actionDiferencia_triggered()
{

    QString filename2 = QFileDialog::getOpenFileName(this, tr("Selecciona una imagen"), "", tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)"));
    QFileInfo file2 = filename2;
    QImage image2;


    if(QString::compare(filename2, QString()) != 0){


        bool valid = image2.load(filename2);


        if(valid) {
            if(image_.width()==image2.width() && image_.height()==image2.height()){


                QImage diferencia = image_;
                for(int i =0;i<image_.width();i++){
                    for(int j=0; j<image_.height();j++){
                        int color= abs(image_.pixelColor(i,j).value() - image2.pixelColor(i,j).value());

                        diferencia.setPixel(i,j,qRgb(color,color,color));
                    }
                }

                MainWindow* W = new MainWindow(diferencia,name_.fileName());
                 W->show();

                cout<<"¿Desea umbralizar la imagen original con la diferencia resultado? En caso afirmativo introduzca el umbral. Pulse 0 para salir: ";
                int umbral;
                cin>>umbral;
                if(umbral>0 &&umbral<256){

                    QImage umbralizada = image_;
                    for(int i =0;i<image_.width();i++){
                        for(int j=0; j<image_.height();j++){
                            if(diferencia.pixelColor(i,j).value() >= umbral)
                                umbralizada.setPixel(i,j,qRgb(255,0,0));
                        }
                    }

                    MainWindow* W2 = new MainWindow(umbralizada,name_.fileName());
                     W2->show();
                }



            }else{
                cout<<"Las imagenes deben ser del mismo tamaño para poder hacerles la diferencia."<<endl;
            }
        }
        }
        else{
            cout << "Error cargando la imagen"  << endl;
        }

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
    double max = 0;
    QVector<double> vout;
    double K = (image_.width()*image_.height()*3)/256;

    QImage img_ec;
    img_ec = image_;

    /////parte gabriel

       //double KK = 256 / (image_.width()*image_.height()*3 );
    for(int i = 0; i < 256; i++){
        double a = round(acumulativo_[i]/K) -1;
        //double a = round(acumulativo_[i] * KK )-1;

        cout<<"acum: "<<acumulativo_[i]<<"\ta :"<<a<<endl;
        if(a<0)
            vout.push_back(0);
        else
            vout.push_back(a);
    }
    //int pp;cin>>pp;

    for (int i = 0; i<image_.width();i++)
        for(int j=0;j<image_.height();j++){
            int color = vout[image_.pixelColor(i,j).value()];
            img_ec.setPixel(i,j,qRgb(color,color,color));
        }

    /////////////////////////////parte aranza inicio
//    for(int i = 0; i < 256; i++){
//        cout << "vout: " << vout[i] << endl;
//        cout << "lista: " << lista_[i] << endl;
//        cout << "histograma: " << histograma_[i] << endl;
//    }

//    for (int ii = 0; ii < img_ec.width(); ii++) {
//        for (int jj = 0; jj < img_ec.height(); jj++){
//            QRgb c = img_ec.pixel(ii,jj);
//            double azul = qBlue(c);
//            double verde = qGreen(c);
//            double rojo = qRed(c);
//           // cout << " " << rojo << " " << verde << " " << azul << endl;
//           // cout << vout[azul];
//            img_ec.setPixel(ii, jj, QColor(vout[rojo],vout[verde],vout[azul]).rgb());
//        }
//    }
//    if(img_ec != image_)
//        cout << " Son distintas" << endl;

//    for (int ii = 0; ii < img_ec.width(); ii++) {
//        for (int jj = 0; jj < img_ec.height(); jj++){
//            QRgb c = img_ec.pixel(ii,jj);
//            double azul = qBlue(c);
//            double verde = qGreen(c);
//            double rojo = qRed(c);
////            cout << " " << rojo << " " << verde << " " << azul << endl;
//         }
//    }


//    image_ = img_ec;
    //////////////////////////////parte aranza fin

    MainWindow* W = new MainWindow(img_ec,name_.fileName());
    W->show();



//    Graphic grafico2(img_ec,grey_image_, name_.fileName(), 2);
//    grafico2.setModal(true);
//    grafico2.exec();
}
