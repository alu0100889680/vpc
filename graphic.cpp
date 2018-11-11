#include "graphic.h"
#include "ui_graphic.h"

Graphic::Graphic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graphic)
{
    ui->setupUi(this);
    this->setWindowTitle("Histograma");

    int size = 10;
    QVector<double> x(10), y(size);

    for(int i = 0; i < 256; i++)
        x[i] = i;

    ui->plot->addGraph();
    ui->plot->graph(0)->setData(x,y);
    ui->plot->xAxis->setRange(0,255);
    ui->plot->yAxis->setRange(0,10000); // Aqui ira el numero de pixeles
}


Graphic::Graphic(QImage img, QFileInfo name, int acumu):
    ui(new Ui::Graphic),
    contador_(0.0)
{
    image_ = img;
    name_ = name;
    ui->setupUi(this);
    this->setWindowTitle("Histograma");

    // Etiqueta del tipo
    ui->etiqueta_tipo->setText("." + name.completeSuffix());      // Extensión

    img = img.convertToFormat(QImage::Format_RGB888);   // Convertir a RGB de 8 bits
    uchar *bits = img.bits();

    // Lista de todos los colores
    for (int i = 0; i < (img.width() * img.height() * 3); i++)
        lista_.push_back(bits[i]);

    // Lista de pixeles / color
    for (int i = 0; i < 256; i++){
        int cont = lista_.count(i);
        x_.push_back(i);
        color_table_.push_back(cont);
        contador_ += cont;
    }

    for (int i = 0; i < 256; i++)
        cout << i << " " <<color_table_[i] <<endl;

    acumulativo_.push_back(color_table_[0]);
    for (int i =1; i<color_table_.size(); i++){
            acumulativo_.push_back(color_table_[i]+acumulativo_[i-1]);
    }

    for(int i = 0; i < acumulativo_.size(); i++)
        cout << i << " = " << acumulativo_[i] << endl;

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
    for (int i = 0; i < 256; i++){
            double pi = color_table_[i]/contador_;
            cout << " hola soy pi y cambio: " << pi << endl;
            sumatorio3 = sumatorio3 - (pi*log(pi));
    }
    entropia = sumatorio;
    QString entropia_s = QString::number(entropia);
    ui->etiqueta_entropia->setText(entropia_s);

//    cout << "media: " << media << endl;
//    cout << "DT: " << desvt << endl;
//    cout << "Entropía: " << entropia << endl;

  //  ui->plot->addGraph();
   // ui->plot->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
    ui->plot->addGraph();
    ui->plot->graph(0)->setPen(QPen(Qt::red)); // line color red for second graph

    // make left and bottom axes always transfer their ranges to right and top axes:
    connect(ui->plot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->plot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->plot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->plot->yAxis2, SLOT(setRange(QCPRange)));

    // Añadir los valores a los graficos


    if(acumu==0){
        ui->plot->graph(0)->setData(x_, color_table_);
        ui->plot->graph(0)->rescaleAxes(true);

    }
    else if(acumu==1){
        ui->plot->graph(0)->setData(x_, acumulativo_);
        ui->plot->graph(0)->rescaleAxes();
    }
}

Graphic::~Graphic()
{
    delete ui;
}



void Graphic::on_acumulativo_clicked()
{

    Graphic grafico2(image_, name_.fileName(), 1);
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
//       cout <<"hola guapa"<< endl;
////        ui->plot->clearGraphs();
////        ui->plot->replot();


//        ui->plot->addGraph();
//        ui->plot->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
//        ui->plot->graph(0)->setData(x_,color_table_);
////        ui->plot->graph(0)->setVisible(true);


//    //    // Obtetener el max numero de un color qe se repite para ponerlo de máximo en la gráfica.
//        max_ = *max_element(color_table_.constBegin(), color_table_.constEnd());

//        ui->plot->xAxis->setRange(0,256);
//        ui->plot->yAxis->setRange(0,max_);
}
