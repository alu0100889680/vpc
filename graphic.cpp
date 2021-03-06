#include "graphic.h"
#include "ui_graphic.h"
#include <algorithm>    // std::max
//#include "mainwindow.h"


Graphic::Graphic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graphic),
    vin_(256)
{
    ui->setupUi(this);
    this->setWindowTitle("Histograma");

    int size = 10;
    QVector<double> x(10), y(size);

    for(int i = 0; i < 256; i++){
        x[i] = i;
        vin_.push_back(i);
    }
    ui->plot->addGraph();
    ui->plot->graph(0)->setData(x,y);
    ui->plot->xAxis->setRange(0,256);
    ui->plot->yAxis->setRange(0,10000); // Aqui ira el numero de pixeles
}


Graphic::Graphic(QImage img, QImage grey_img, QFileInfo name, int acumu):
    ui(new Ui::Graphic),
    contador_(0.0)
{
    image_ = img;
    name_ = name;
    grey_ = grey_img;
    ui->setupUi(this);
    this->setWindowTitle("Histograma");

    // Etiqueta del tipo
    ui->etiqueta_tipo->setText("." + name.completeSuffix());      // Extensión

    img = img.convertToFormat(QImage::Format_RGB888);   // Convertir a RGB de 8 bits
    uchar *bits = img.bits();

    // Lista de todos los colores
    for (int i = 0; i < image_.width(); i++)
        for (int j = 0; j < image_.height(); j++)
            lista_.push_back(img.pixelColor(i,j).value());

    for(int i = 0; i < 256; i++){
        vin_.push_back(i);
    }

    // Lista de pixeles / color
    for (int i = 0; i < 256; i++){
        int cont = lista_.count(i);cout<<endl<<"antes: "<<cont;
        if(i==0 && acumu>2) cont = max(0,cont - acumu);
        x_.push_back(i);cout<<endl<<"despu: "<<cont;//system("pause");
        color_table_.push_back(cont);
        contador_ += cont;
    }

    acumulativo_.push_back(color_table_[0]);
    for (int i =1; i<color_table_.size(); i++){
        acumulativo_.push_back(color_table_[i]+acumulativo_[i-1]);
    }

    double sumatorio = 0.0, sumatorio2= 0.0, sumatorio3 = 0.0, media = 0.0, desvt = 0.0, entropia = 0.0;

    // MEDIA / BRILLO
    for (int i = 0; i < 256; i++){
            sumatorio = sumatorio + color_table_[i]*i;
    }
    media = sumatorio / contador_;
    QString media_s = QString::number(media);
    ui->etiqueta_brillo->setText(media_s);


    // DT / CONTRASTE
    for (int i = 0; i < 256; i++){
            double potencia = pow(i-media, 2);
            sumatorio2 = sumatorio2 + round(potencia*color_table_[i]);
    }
    desvt = sqrt(sumatorio2/contador_);
    QString desvt_s = QString::number(desvt);
    ui->etiqueta_contraste->setText(desvt_s);

    // ENTROPIA - NO SE SI ESTA BIEN EL RESULTADO :(
    double size = image_.width()*image_.height();
    for (int i = 0; i < 256; i++){
            double pi = color_table_[i]/size;
            if(pi!=0.0)
                sumatorio3 = sumatorio3 + (pi*log2(pi));
    }
    entropia = -sumatorio3;
    QString entropia_s = QString::number(entropia);
    ui->etiqueta_entropia->setText(entropia_s);
    cout<<endl<<"entropia= "<<entropia<<endl;

    // Rango de Valores

    int min, max;
    for (int i=0; i<256;i++){
        if(color_table_[i]!=0){
            min=i;
            break;
        }
    }
    for (int i=255; i>0;i--){
        if(color_table_[i]!=0){
            max=i;
            break;
        }
    }

    QString rango = QString::number(min);
    rango.append(" - ");
    rango.append(QString::number(max));
    ui->etiqueta_rango->setText(rango);







    ui->plot->addGraph();
    ui->plot->graph(0)->setPen(QPen(Qt::red)); // line color red for second graph

    // make left and bottom axes always transfer their ranges to right and top axes:
    connect(ui->plot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->plot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->plot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->plot->yAxis2, SLOT(setRange(QCPRange)));

    // Añadir los valores a los graficos
    if(acumu==0 || acumu>2){
        ui->plot->graph(0)->setData(x_, color_table_);
        ui->plot->graph(0)->rescaleAxes(true);

    }
    else if(acumu==1){
        ui->plot->graph(0)->setData(x_, acumulativo_);
        ui->plot->graph(0)->rescaleAxes();
    }
    else if(acumu==2){
        ui->plot->graph(0)->setData(x_, ecualizado_);
        ui->plot->graph(0)->rescaleAxes();
    }
}

Graphic::~Graphic()
{
    delete ui;
}

void Graphic::on_acumulativo_clicked()
{

    Graphic grafico2(image_, grey_, name_.fileName(), 1);
    grafico2.setModal(true);
    grafico2.exec();

    /*QPushButton button;
     button.setText("My text");
     button.setToolTip("A tooltip");
     button.show();

    ui->plot->graph(0)->setVisible(true);*/

//    this->setWindowTitle("Histograma acumulativo");

//    ui->plot->graph(0)->data()->clear();
//    ui->plot->replot();

//    ui->plot->addGraph();
//    ui->plot->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph


//        cout <<"hola guapa" <<endl;

//    ui->plot->addGraph();
//    ui->plot->graph(1)->setPen(QPen(Qt::red)); // line color red for second graph

//    ui->plot->xAxis2->setVisible(true);

////    // make left and bottom axes always transfer their ranges to right and top axes:
//    connect(ui->plot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->plot->xAxis2, SLOT(setRange(QCPRange)));
//    connect(ui->plot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->plot->yAxis2, SLOT(setRange(QCPRange)));
//    // pass data points to graphs:
//    ui->plot->graph(0)->setData(x_,color_table_);
//    ui->plot->graph(1)->setData(x_, acumulativo_);

//    // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
//    ui->plot->graph(0)->rescaleAxes();
//    // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
//    ui->plot->graph(1)->rescaleAxes(true);


//    ui->plot->xAxis->setRange(0,256);
//    ui->plot->yAxis->setRange(0,acumulativo_[acumulativo_.size()-1]);

//    acumulativo_.clear();   // Para que si vuelves a pulsar el vector no aumente el tamaño a 512

}

void Graphic::on_histograma_clicked()
{
        this->setWindowTitle("Histograma");

////        ui->plot->graph(0)->data()->clear();
////        ui->plot->clearGraphs();
////        ui->plot->replot();
////        ui->plot->graph(0)->setVisible(true);


//    //    // Obtetener el max numero de un color qe se repite para ponerlo de máximo en la gráfica.
//        max_ = *max_element(color_table_.constBegin(), color_table_.constEnd());

//        ui->plot->xAxis->setRange(0,256);
//        ui->plot->yAxis->setRange(0,max_);
}

void Graphic::on_histograma_ec_clicked()
{

    QVector<double> vout;
    double K = (image_.width()*image_.height())/256;
    for(int i = 0; i < 256; i++){
        double a = floor(acumulativo_[vin_[i]]/K) -1;
        if(a<256)
            vout.push_back(a);
        else
            vout.push_back(255);
//         Vout = max { 0, round [C0(Vin) * M/SIZE] – 1 }

//        Vout = floor ( C0(Vin) * (M-1)/SIZE )
//        double a = round(acumulativo_[vin_[i]]*lista_[i]/K)-1;
//        if(a > 0)
//            vout.push_back(a);
//        else
//            vout.push_back(0);
//        if(i==0)
//            ecualizado_acum_.push_back(ecualizado_[i]);
//        else
//            ecualizado_acum_.push_back(ecualizado_[i]+ecualizado_acum_[i-1]);
    }

    QImage img_ec;
    img_ec = image_;

    for (int ii = 0; ii < img_ec.width(); ii++) {
        for (int jj = 0; jj < img_ec.height(); jj++){
            QRgb c = img_ec.pixel(ii,jj);
            double azul = qBlue(c);
            double verde = qGreen(c);
            double rojo = qRed(c);


            img_ec.setPixel(ii, jj, QColor(vout[rojo],vout[verde],vout[azul]).rgb());
        }
    }
    if(img_ec != image_)
        cout << " Son distintas" << endl;

//        MainWindow* W = new MainWindow(img_ec,name_.fileName());
//        W->ui->cuadroImg->setGeometry(50,50,img_ec.width(),img_ec.height());
//        W->show();



//        // Ecualizar por pixel - No funciona. Da valores muy grandes y el histograma no esta bien
//    QVector<double> vin, vout(256);
//    for(int i = 0; i < 256; i++)
//        vin.push_back(i);

//    for(int i = 0; i < acumulativo_.size(); i++){

//        int j = i;
//        if(j!=255){
//            while(floor(acumulativo_[j]) == floor(acumulativo_[j+1])){
//                j++;
//            }
//        }
//        for(int k = j; k >= i; k--){
////                vout[k] = floor((acumulativo_[i]/(image_.width()*image_.height()*3))*255);
////                    vout[k] = (((acumulativo_[i]*lista_[i])/K)/255);
//            vout[k] = (round(acumulativo_[vin[i]]/K)-1);
//        }
//    }
//    for(int i = 0; i <256; i++){
//        cout << "i = " << i << " Vin= " << vin[i] << " Vout= " << vout[i] << endl;
//    }






//    for(int i = 0 ; i < color_table_.size(); i++){
//        double a = floor(acumulativo_[i]*((image_.width()*image_.height())/256))-1;
////        double a = floor((256-1)*color_table_[i]);
//        ecualizado_.push_back(a);

//        cout << i << " === " << a << endl;
//    }
//    cout <<" Tamañito es: " << ecualizado_.size() << endl;


//    int total = grey_.width() * grey_.height();

//    QVector<double> p, ecualizador;
//    for(int i = 0; i < 256; i++)
//        p.push_back(color_table_[i]/total);

//    for(int i = 0; i < 256; i++)
//        ecualizador.push_back(acumulativo_[i]*256);

//    QImage img_ecualizada(image_.height(), image_.width(), QImage::Format_RGB888);
//    img_ecualizada = img_ecualizada.scaled(image_.height(), image_.width(), Qt::KeepAspectRatio);
//    for(int i = 0; i < img_ecualizada.height(); i++){
//        for(int j = 0; j < img_ecualizada.width(); j++){
//            int d = floor((256-1)*acumulativo_[matriz_[i][j]]);
//            cout << "hola_ " << d <<endl;
//            img_ecualizada.setPixel(i,j,floor((256-1)*acumulativo_[matriz_[i][j]]));
//        }
//    }

//    QPixmap tempImagePix = QPixmap::fromImage(nueva);

//    QImage myimage = tempImagePix.toImage();    // convert your QPixmap to QImage
//    int width = myimage.width();
//    int height = myimage.height();
//    int *matrix = new int [width*height];   // store 2-D data in 1-D vector

//    for(int j = 0; j < height; j++)
//    {
//      for(int i = 0; i < width; i++)
//      {
//        matrix[j*width+i] = qGray(myimage.pixel(i,j));
//      }
//    }


//    for(int i = 0; i < image_.width()+image_.height()*3; i++){
//        double color  = lista_[i];

//    }

//    cout << height*width << endl;

//    for(int i = 0; i < image_.height(); i++){
//        for(int j = 0; j < image_.width(); j++){
////            int d = floor((256-1)*acumulativo_[matrix[j*width+i]]);
////            int d = floor((256-1)*(color_table_[qAlpha(image_.pixel(i,j))]/(image_.width()*image_.height())));
////            int d = round(((acumulativo_[i]-1)/acumulativo_[255])*255);
//            cout << "hola_ " << d <<endl;
////            matrix[j*width+i] = d/*(i,j,floor((256-1)*acumulativo_[matriz_[i][j]]))*/;
////            nueva.setPixel(i,j,d);
//        }
//    }


    Graphic grafico2(img_ec,grey_, name_.fileName(), 2);
    grafico2.setModal(true);
    grafico2.exec();
}

void Graphic::on_pushButton_clicked()
{
//    QImage img_ecualizada;
//    img_ecualizada = img_ecualizada.scaled(image_.height(), image_.width(), Qt::KeepAspectRatio);
//    for(int i = 0; i < image_.height(); i++){
//        for(int j = 0; j < image_.width(); j++){
//            int d = floor((256-1)*acumulativo_[matriz_[i][j]]);
//            cout << "hola_ " << d <<endl;
//            img_ecualizada.setPixel(i,j,floor((256-1)*acumulativo_[matriz_[i][j]]));
//        }
//    }

//    x.setPixel(i,j,qRgb(color,color,color));






//    Graphic grafico2(image_, grey_, name_.fileName(), 2);
//    grafico2.setModal(true);
//    grafico2.exec();
}
