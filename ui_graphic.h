/********************************************************************************
** Form generated from reading UI file 'graphic.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHIC_H
#define UI_GRAPHIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_Graphic
{
public:
    QCustomPlot *plot;
    QLabel *label;
    QLabel *etiqueta_tipo;
    QLabel *label_2;
    QLabel *etiqueta_brillo;
    QLabel *label_3;
    QLabel *etiqueta_contraste;
    QLabel *label_4;
    QLabel *etiqueta_entropia;
    QPushButton *acumulativo;
    QLabel *label_5;
    QLabel *etiqueta_rango;

    void setupUi(QDialog *Graphic)
    {
        if (Graphic->objectName().isEmpty())
            Graphic->setObjectName(QStringLiteral("Graphic"));
        Graphic->resize(722, 540);
        plot = new QCustomPlot(Graphic);
        plot->setObjectName(QStringLiteral("plot"));
        plot->setEnabled(true);
        plot->setGeometry(QRect(30, 30, 451, 391));
        plot->setMouseTracking(false);
        label = new QLabel(Graphic);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 440, 101, 16));
        etiqueta_tipo = new QLabel(Graphic);
        etiqueta_tipo->setObjectName(QStringLiteral("etiqueta_tipo"));
        etiqueta_tipo->setGeometry(QRect(150, 440, 281, 16));
        label_2 = new QLabel(Graphic);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 460, 81, 16));
        etiqueta_brillo = new QLabel(Graphic);
        etiqueta_brillo->setObjectName(QStringLiteral("etiqueta_brillo"));
        etiqueta_brillo->setGeometry(QRect(150, 460, 121, 16));
        label_3 = new QLabel(Graphic);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 480, 91, 16));
        etiqueta_contraste = new QLabel(Graphic);
        etiqueta_contraste->setObjectName(QStringLiteral("etiqueta_contraste"));
        etiqueta_contraste->setGeometry(QRect(150, 480, 151, 16));
        label_4 = new QLabel(Graphic);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 500, 61, 20));
        etiqueta_entropia = new QLabel(Graphic);
        etiqueta_entropia->setObjectName(QStringLiteral("etiqueta_entropia"));
        etiqueta_entropia->setGeometry(QRect(150, 500, 141, 16));
        acumulativo = new QPushButton(Graphic);
        acumulativo->setObjectName(QStringLiteral("acumulativo"));
        acumulativo->setGeometry(QRect(510, 40, 161, 28));
        label_5 = new QLabel(Graphic);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(340, 500, 91, 16));
        etiqueta_rango = new QLabel(Graphic);
        etiqueta_rango->setObjectName(QStringLiteral("etiqueta_rango"));
        etiqueta_rango->setGeometry(QRect(450, 500, 91, 16));

        retranslateUi(Graphic);

        QMetaObject::connectSlotsByName(Graphic);
    } // setupUi

    void retranslateUi(QDialog *Graphic)
    {
        Graphic->setWindowTitle(QApplication::translate("Graphic", "Dialog", nullptr));
        label->setText(QApplication::translate("Graphic", "Tipo de archivo: ", nullptr));
        etiqueta_tipo->setText(QString());
        label_2->setText(QApplication::translate("Graphic", "Media/ Brillo:", nullptr));
        etiqueta_brillo->setText(QString());
        label_3->setText(QApplication::translate("Graphic", "DT / Contraste:", nullptr));
        etiqueta_contraste->setText(QString());
        label_4->setText(QApplication::translate("Graphic", "Entrop\303\255a: ", nullptr));
        etiqueta_entropia->setText(QString());
        acumulativo->setText(QApplication::translate("Graphic", "Histograma acumulado", nullptr));
        label_5->setText(QApplication::translate("Graphic", "Rango de Valores:", nullptr));
        etiqueta_rango->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Graphic: public Ui_Graphic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHIC_H
