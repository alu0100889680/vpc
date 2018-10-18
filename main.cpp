#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{

//    cout << "hola"  << endl;
//    qDebug() << "Hello World";
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}
