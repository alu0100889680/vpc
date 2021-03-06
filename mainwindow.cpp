#include "mainwindow.h"

#include "graphic.h"
#include <QFileDialog>
#include <QImage>
#include <QVector>
#include <QColor>
#include "qcustomplot.h"
#include <iostream>
#include <QVBoxLayout>
#include <math.h>
#include <algorithm>    // std::max
#define PI 3.14159265

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
        ui->setupUi(this);
        this->setWindowTitle("Programa VPC");
    }

MainWindow::MainWindow(QImage img, QString title):
    image_(img),
    name_(title),
    ui(new Ui::MainWindow){
        ui->setupUi(this);
        this->setWindowTitle(name_.fileName());
        this->ui->cuadroImg->setScaledContents(true);
        this->ui->cuadroImg->setPixmap(QPixmap::fromImage(image_));
        this->ui->cuadroImg->setGeometry(50,50,img.width(),img.height());
        this->setWindowTitle(title);
        this->setGeometry(50,50,image_.width()+100,image_.height()+120);
        connect(this->ui->cuadroImg, SIGNAL(Mouse_Pos()), this, SLOT(Mouse_current_pos()));
    };

MainWindow::MainWindow(QImage img, QString title, int acumu):
    image_(img),
    name_(title),
    acumu_(acumu),
    ui(new Ui::MainWindow){
        ui->setupUi(this);
        this->setWindowTitle(name_.fileName());
        this->ui->cuadroImg->setScaledContents(true);
        this->ui->cuadroImg->setPixmap(QPixmap::fromImage(image_));
        this->ui->cuadroImg->setGeometry(50,50,img.width(),img.height());
        this->setWindowTitle(title);
        this->setGeometry(50,50,image_.width()+100,image_.height()+120);
        connect(this->ui->cuadroImg, SIGNAL(Mouse_Pos()), this, SLOT(Mouse_current_pos()));
    };

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_actionAbrir_triggered(){

    QString filename = QFileDialog::getOpenFileName(this, tr("Selecciona una imagen"), "", tr("Images (*.png *.jpg *.jpeg *.bmp *.gif*.tif)"));
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
           // uchar *bits = img.bits();

            for (int i = 0; i < image_.width(); i++)
                for (int j = 0; j < image_.height(); j++)
                    lista_.push_back(image_.pixelColor(i,j).value());

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
            this->setGeometry(50,50,image_.width()+100,image_.height()+120);
        }
        else{
            QMessageBox::information(this,tr("Error"),tr("Error cargando la imagen."));
        }
    }

    connect(this->ui->cuadroImg, SIGNAL(Mouse_Pos()), this, SLOT(Mouse_current_pos()));
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
//    connect(W->ui->cuadroImg, SIGNAL(Mouse_Pos()), this, SLOT(Mouse_current_pos()));
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
    cout<<"histograma";

        Graphic grafico(image_, grey_image_, name_.fileName(), acumu_);
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
    var = QInputDialog::getInt(this,"Brillo", "Inserte variación del brillo: ");
    if(var!=0){

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

}

void MainWindow::on_actionCambiar_Contraste_triggered()
{
    QImage nueva;
    nueva = image_;
    int var = 0;
    var = QInputDialog::getInt(this,"Contraste", "Inserte variación del contraste: ");
    if(var!=0){

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
}

void MainWindow::on_actionCambiar_ByC_triggered()
{
    QImage nueva;
    nueva = image_;
    int varC, varB;
    QVector<double> x_,lista_, color_table_, acumulativo_;
    double contador_ = 0.0;

    varC = QInputDialog::getInt(this,"Brillo", "Inserte variación del contraste: ");
    varB = QInputDialog::getInt(this,"Contraste", "Inserte variación del brillo: ");
    if(varC!=0 || varB !=0){

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
        double A = (desvt + varC)/ desvt;
        double B = media + varB - A * media;

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
}

void MainWindow::on_actionCorrecci_on_Gamma_triggered()
{
    QImage nueva;
    nueva = image_;
    double var = 0.0;
    var = QInputDialog::getDouble(this,"Gamma", "Inserte función Gamma: ");
    if(var!=0){
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
}

void MainWindow::on_actionTramos_triggered()
{
    int n = QInputDialog::getInt(this,"Transformación por tramos", "Número de tramos: ");

    struct Tramo{
        double x1;
        double y1;
        double x2;
        double y2;
    };

    QImage nueva;
    nueva = image_;

    Tramo tramo[n];
    Tramo tram;
    tramo[0].x1 = QInputDialog::getInt(this, "Primer Punto", "Inserte la posición x del 1º punto: ");
    tramo[0].y1 = QInputDialog::getInt(this, "Primer Punto", "Inserte la posición y del 1º punto: ");

    for (int i=0;i<n;i++){
      if(i!=0){
          tramo[i].x1 = tramo[i-1].x2;
          tramo[i].y1 = tramo[i-1].y2;
      }

      QString tramo_s("Fin del tramo ");
      tramo_s.append(QString::number(i+1));
      QString puntoX_s("Posición x del punto final del tramo ");
      puntoX_s.append(QString::number(i+1));
      QString puntoY_s("Posición y del punto final del tramo ");
      puntoY_s.append(QString::number(i+1));

      tramo[i].x2 = QInputDialog::getInt(this, tramo_s, puntoX_s);
      tramo[i].y2 = QInputDialog::getInt(this, tramo_s, puntoY_s);
    }

    QVector<int> vout(256);
    int k = 0;
    for(int i = 0; i < 256; i++){

        if(i<tramo[0].x1){
            vout[i] = i;
        }
        else if(i > tramo[n-1].x2)
            vout[i] = i;
        else{
            while(i > tramo[k].x2){
                k++;
            }

            double A = (tramo[k].y2 - tramo[k].y1)/(tramo[k].x2-tramo[k].x1);
            double B = tramo[k].y1 - (A*tramo[k].x1);
            vout[i] = (A*i + B);
        }
    }

    for(int i =0;i<nueva.width();i++){
        for(int j=0; j<nueva.height();j++){
            int color= vout[nueva.pixelColor(i,j).value()];
            nueva.setPixel(i,j,qRgb(color,color,color));
        }
    }

    MainWindow* W = new MainWindow(nueva,name_.fileName());
    W->show();
    //connect(W->ui->cuadroImg, SIGNAL(Mouse_Pos()), this, SLOT(Mouse_current_pos()));
}

void MainWindow::on_actionUmbralizar_triggered()
{
    int n = QInputDialog::getInt(this,"Umbralizar", "Número de tramos: ");
    int tramo[n][2];
    for (int i=0;i<n;i++){
        tramo[i][0] = QInputDialog::getInt(this,"X", "Valor de X: ");
        tramo[i][1] = QInputDialog::getInt(this,"Y", "Valor de Y: ");
    }
    QImage nueva;
    nueva = image_;


    for(int i =0;i<nueva.width();i++){
        for(int j=0; j<nueva.height();j++){
            int color= nueva.pixelColor(i,j).value();
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

            }else{
                QMessageBox::information(this,tr("Error"),tr("Las imágenes deben ser del mismo tamaño para poder hacerles la diferencia."));
            }
        }
        }
        else{
            cout << "Error cargando la imagen"  << endl;
        }

}

void MainWindow::on_actionUmbralizar_con_Imagen_Diferencia_triggered(){

    QString filename2 = QFileDialog::getOpenFileName(this, tr("Selecciona una imagen"), "", tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)"));
    QFileInfo file2 = filename2;
    QImage img_diferencia;


    if(QString::compare(filename2, QString()) != 0){


        bool valid = img_diferencia.load(filename2);


        if(valid) {
            if(image_.width()==img_diferencia.width() && image_.height()==img_diferencia.height()){

                int umbral = QInputDialog::getInt(this,"Umbralizar diferencia", "Introduce el umbral: ");

                if(umbral>0 && umbral<256){

                    QImage umbralizada = image_.convertToFormat(QImage::Format_RGB888);
                    for(int i =0;i<image_.width();i++){
                        for(int j=0; j<image_.height();j++){
                            if(img_diferencia.pixelColor(i,j).value() >= umbral)
                                umbralizada.setPixel(i,j,qRgb(255,0,0));
                        }
                    }

                    MainWindow* W2 = new MainWindow(umbralizada,name_.fileName());
                     W2->show();
                }


            }else{
                cout<<"Las imagenes deben ser del mismo tamaño para poder hacerles el umbralizado con la diferencia."<<endl;

            }
        }
    }
    else{
        cout << "Error cargando la imagen"  << endl;
    }
}

void MainWindow::Mouse_current_pos()
{
    QColor color = image_.pixel(this->ui->cuadroImg->x,this->ui->cuadroImg->y);
    QRgb red = color.red();
    QRgb green = color.green();
    QRgb blue = color.blue();
    this->ui->etiqueta_coordenadas->setText(QString("X = %1, Y = %2  (%3,%4,%5)").arg(this->ui->cuadroImg->x).arg(this->ui->cuadroImg->y).arg(red).arg(green).arg(blue));
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

    QVector<double> vout;
    double K = (image_.width()*image_.height())/256;

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

void MainWindow::on_actionRecortar_triggered()
{
    int x1, y1, x2, y2;

    x1 = QInputDialog::getInt(this,"Introduzca valores esquina superior izquierda", "X: ");
    y1 = QInputDialog::getInt(this,"Introduzca valores esquina superior izquierda", "Y: ");
    x2 = QInputDialog::getInt(this,"Introduzca valores esquina inferior derecha", "X: ");
    y2 = QInputDialog::getInt(this,"Introduzca valores esquina inferior derecha", "Y: ");

    QImage img_rec{x2-x1,y2-y1, QImage::Format_RGB888};

    for (int i = x1; i<x2;i++)
        for(int j=y1;j<y2;j++){
            int color = image_.pixelColor(i,j).value();
            img_rec.setPixel(i-x1,j-y1,qRgb(color,color,color));
        }

    MainWindow* W = new MainWindow(img_rec,name_.fileName());
    W->show();
}

void MainWindow::on_actionEspejo_Vertical_triggered(){

QImage nueva = image_;
int alto = image_.height()-1;

for (int y=0;y<image_.height();y++)
    for(int x=0;x<image_.width();x++){
        int color = image_.pixelColor(x,y).value();
        nueva.setPixel(x,alto-y, qRgb(color,color,color));
    }

MainWindow* W = new MainWindow(nueva,name_.fileName());
W->show();
}

void MainWindow::on_actionEspejo_Horizontal_triggered(){

QImage nueva = image_;
int ancho = image_.width()-1;

for (int y=0;y<image_.height();y++)
    for(int x=0;x<image_.width();x++){
        int color = image_.pixelColor(x,y).value();
        nueva.setPixel(ancho-x,y, qRgb(color,color,color));
    }

MainWindow* W = new MainWindow(nueva,name_.fileName());
W->show();
}

void MainWindow::on_actionTranspuesta_triggered(){

    QImage nueva{image_.height(),image_.width(), QImage::Format_RGB888};

    for (int y=0;y<image_.height();y++)
        for(int x=0;x<image_.width();x++){
            int color = image_.pixelColor(x,y).value();
            nueva.setPixel(y,x, qRgb(color,color,color));
        }

    MainWindow* W = new MainWindow(nueva, name_.fileName());
    W->show();
}

void MainWindow::on_action90_triggered(){

    QImage nueva{image_.height(),image_.width(), QImage::Format_RGB888};   
    int ancho = image_.width()-1;

    for (int y=0;y<image_.height();y++)
        for(int x=0;x<image_.width();x++){
            int color = image_.pixelColor(x,y).value();
            nueva.setPixel(y,ancho-x, qRgb(color,color,color));
        }

    MainWindow* W = new MainWindow(nueva, name_.fileName());
    W->show();
}

void MainWindow::on_action180_triggered(){

    QImage nueva{image_.width(),image_.height(), QImage::Format_RGB888};
    int ancho = image_.width()-1;
    int alto = image_.height()-1;

    for (int y=0;y<image_.height();y++)
        for(int x=0;x<image_.width();x++){
            int color = image_.pixelColor(x,y).value();
            nueva.setPixel(ancho-x,alto-y, qRgb(color,color,color));
        }

    MainWindow* W = new MainWindow(nueva, name_.fileName());
    W->show();
}

void MainWindow::on_action270_triggered(){

    QImage nueva{image_.height(),image_.width(), QImage::Format_RGB888};
    int alto = image_.height()-1;

    for (int y=0;y<image_.height();y++)
        for(int x=0;x<image_.width();x++){
            int color = image_.pixelColor(x,y).value();
            nueva.setPixel(alto-y,x, qRgb(color,color,color));
        }

    MainWindow* W = new MainWindow(nueva, name_.fileName());
    W->show();
}

void MainWindow::on_actionEscalado_IVMP_triggered(){

    QString tamano_s("Tamaño de la Imagen: ");
    tamano_s.append(QString::number(image_.width()));
    tamano_s.append(" x ");
    tamano_s.append(QString::number(image_.height()));
    tamano_s.append("\n\nIntroduzca el nuevo alto de la imagen (%): ");

    double nueva_x = QInputDialog::getDouble(this, "Nuevo alto", tamano_s)/100;

    tamano_s = "Tamaño de la Imagen: ";
    tamano_s.append(QString::number(image_.width()));
    tamano_s.append(" x ");
    tamano_s.append(QString::number(image_.height()));
    tamano_s.append("\n\nIntroduzca el nuevo ancho de la imagen (%): ");

    double nueva_y = QInputDialog::getDouble(this, "Nuevo ancho", tamano_s)/100;

    int N_x = (int) trunc(nueva_x*image_.width());
    int N_y = (int) trunc(nueva_y*image_.height());

    QImage nueva{N_x,N_y, QImage::Format_RGB888};

    for(int i=0; i<N_x-1; i++)
        for(int j=0; j<N_y-1; j++){
            int x = (int) round(i / nueva_x);
            int y = (int) round(j / nueva_y);
            int color = image_.pixelColor(x,y).value();
            nueva.setPixel(i,j, qRgb(color,color,color));
        }
    int i = N_y-1;
    for(int j=0; j<N_y-1; j++){
        int x = (int) trunc(i / nueva_x);
        int y = (int) trunc(j / nueva_y);
        int color = image_.pixelColor(x,y).value();
        nueva.setPixel(i,j, qRgb(color,color,color));
    }
    int j = N_y-1;
    for(int i=0; i<N_y; i++){
        int x = (int) trunc(i / nueva_x);
        int y = (int) trunc(j / nueva_y);
        int color = image_.pixelColor(x,y).value();
        nueva.setPixel(i,j, qRgb(color,color,color));
    }

    MainWindow* W = new MainWindow(nueva, name_.fileName());
    W->show();

}

void MainWindow::on_actionEscalado_Bilineal_triggered(){

    QString tamano_s("Tamaño de la Imagen: ");
    tamano_s.append(QString::number(image_.width()));
    tamano_s.append(" x ");
    tamano_s.append(QString::number(image_.height()));
    tamano_s.append("\n\nIntroduzca el nuevo alto de la imagen (%): ");

    double nueva_x = QInputDialog::getDouble(this, "Nuevo alto", tamano_s)/100;

    tamano_s = "Tamaño de la Imagen: ";
    tamano_s.append(QString::number(image_.width()));
    tamano_s.append(" x ");
    tamano_s.append(QString::number(image_.height()));
    tamano_s.append("\n\nIntroduzca el nuevo ancho de la imagen (%): ");

    double nueva_y = QInputDialog::getDouble(this, "Nuevo ancho", tamano_s)/100;

    int N_x = (int) trunc(nueva_x*image_.width());
    int N_y = (int) trunc(nueva_y*image_.height());

    QImage nueva{N_x,N_y, QImage::Format_RGB888};

    for(int i=0; i<N_x-2; i++)
        for(int j=0; j<N_y-2; j++){

            double x = i / nueva_x;
            double y = j / nueva_y;
            int X = (int) trunc(x);
            int Y = (int) trunc(y);

            double p = x - X;
            double q = y - Y;


            int color = image_.pixelColor(X,Y).value() + (image_.pixelColor(X+1,Y).value() - image_.pixelColor(X,Y).value())*p + (image_.pixelColor(X,Y+1).value() - image_.pixelColor(X,Y).value())*q + (image_.pixelColor(X+1,Y+1).value() + image_.pixelColor(X,Y).value() - image_.pixelColor(X,Y+1).value() - image_.pixelColor(X+1,Y).value())*p*q;
            nueva.setPixel(i,j, qRgb(color,color,color));

        }


    MainWindow* W = new MainWindow(nueva, name_.fileName());
    W->show();

}

void MainWindow::on_actionEspecificacion_triggered(){

    QString filename2 = QFileDialog::getOpenFileName(this, tr("Selecciona una imagen"), "", tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)"));
    QFileInfo file2 = filename2;
    QImage img_ref;


    if(QString::compare(filename2, QString()) != 0){


        bool valid = img_ref.load(filename2);
        if(valid) {

            //acumulativo de img referencia
            QVector<double> lista, histograma, acumulativo_ref;
            for (int i = 0; i < img_ref.width(); i++)
                for (int j = 0; j < img_ref.height(); j++)
                    lista.push_back(img_ref.pixelColor(i,j).value());

            for (int i = 0; i < 256; i++){
                int cont = lista.count(i);
                histograma.push_back(cont);
            }
            acumulativo_ref.push_back(histograma[0]);
            for (int i =1; i<histograma.size(); i++){
                acumulativo_ref.push_back(histograma[i]+acumulativo_ref[i-1]);
            }
            ///// fin acumu

            double size1 = image_.height()*image_.width();
            double size2 = img_ref.height()*img_ref.width();
            int T[256] {};


            for(int a=0; a<256; a++){
                int j = 255;
                while(j>=0 && acumulativo_[a]/size1 <= acumulativo_ref[j]/size2){
                    T[a] = j;
                    j--;
                }
            }

            for(int i = 0;i<256;i++){
                cout<<"T["<<i<<"]= "<<T[i]<<endl;
            }

            QImage nueva = image_;
            for(int i=0; i<image_.width(); i++)
                for(int j=0; j<image_.height(); j++){

                    int color = image_.pixelColor(i,j).value();

                    nueva.setPixel(i,j, qRgb(T[color],T[color],T[color]));
                }

            MainWindow* W = new MainWindow(nueva, name_.fileName());
            W->show();
        }
    }

}

void MainWindow::on_actionRotaci_n_Avanzada_triggered(){

    double angulo = (QInputDialog::getDouble(this, "Ángulo", "Introduzca el ángulo de rotación deseado: "))* PI / 180.0;

    double nueva_esquina_x[4] {};
    double nueva_esquina_y[4] {};

    //superior der
    nueva_esquina_x[1] = cos(angulo)*(image_.width()-1) - sin(angulo)*0;
    nueva_esquina_y[1] = sin(angulo)*(image_.width()-1) + cos(angulo)*0;

    //inferior izq
    nueva_esquina_x[2] = cos(angulo)*0 - sin(angulo)*(image_.height()-1);
    nueva_esquina_y[2] = sin(angulo)*0 + cos(angulo)*(image_.height()-1);

    //inferior der
    nueva_esquina_x[3] = cos(angulo)*(image_.width()-1) - sin(angulo)*(image_.height()-1);
    nueva_esquina_y[3] = sin(angulo)*(image_.width()-1) + cos(angulo)*(image_.height()-1);

    for(int i=0;i<4;i++)
        cout<<"x="<<nueva_esquina_x[i]<<"\ty="<<nueva_esquina_y[i]<<endl;

    double max_x,min_x,max_y,min_y {};
    for(int i =1;i<4;i++){
        if(nueva_esquina_x[i]>max_x)max_x=nueva_esquina_x[i];
        if(nueva_esquina_y[i]>max_y)max_y=nueva_esquina_y[i];
        if(nueva_esquina_x[i]<min_x)min_x=nueva_esquina_x[i];
        if(nueva_esquina_y[i]<min_y)min_y=nueva_esquina_y[i];
    }

    QImage nueva{(int) max_x - (int) min_x +2,(int) max_y - (int) min_y +2, QImage::Format_RGB888};

    for(int i=0; i<image_.width(); i++)
        for(int j=0; j<image_.height(); j++){


            int n_x = (cos(angulo)*i - sin(angulo)*j)- (int) min_x;
            int n_y = (sin(angulo)*i + cos(angulo)*j)- (int) min_y;

//             cout<<"x="<<n_x<<"\ty="<<n_y<<endl;
//             int oo;
//             cin>>oo;

            int color = image_.pixelColor(i,j).value();

            nueva.setPixel(n_x, n_y, qRgb(color,color,color));
        }


    MainWindow* W = new MainWindow(nueva, name_.fileName());
    W->show();

int acumu = 0;

    for(int i=0+min_x; i<nueva.width()+min_x; i++)
        for(int j=0+min_y; j<nueva.height()+min_y; j++){


            double original_x = (cos(-angulo)*i - sin(-angulo)*j);
            double original_y = (sin(-angulo)*i + cos(-angulo)*j);





            if (original_x >=0.0 && original_x<(image_.width()-1) && original_y >=0.0 && original_y<(image_.height()-1)){


//                    cout<<"x="<<original_x<<"\ty="<<original_y<<endl;
//                    cout<<"i="<<i<<"\tj="<<j<<endl;
//                     system ("pause");

                    int X = (int) trunc(original_x);
                    int Y = (int) trunc(original_y);

                    double p = original_x - X;
                    double q = original_y - Y;


                    int color = image_.pixelColor(X,Y).value() + (image_.pixelColor(X+1,Y).value() - image_.pixelColor(X,Y).value())*p + (image_.pixelColor(X,Y+1).value() - image_.pixelColor(X,Y).value())*q + (image_.pixelColor(X+1,Y+1).value() + image_.pixelColor(X,Y).value() - image_.pixelColor(X,Y+1).value() - image_.pixelColor(X+1,Y).value())*p*q;
                    nueva.setPixel(i-min_x, j-min_y, qRgb(color,color,color));

            }else{
                acumu++;
            }
        }





cout<<acumu;

    MainWindow* W2 = new MainWindow(nueva, name_.fileName(), acumu);
    W2->show();





}
