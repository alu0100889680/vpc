#ifndef GRAFICO_H
#define GRAFICO_H

#include <QDialog>

namespace Ui {
class Grafico;
}

class Grafico : public QDialog
{
    Q_OBJECT

public:
    explicit Grafico(QWidget *parent = nullptr);
    ~Grafico();

private:
    Ui::Grafico *ui;
};

#endif // GRAFICO_H
