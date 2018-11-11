#ifndef MY_QLABEL_H
#define MY_QLABEL_H

#include <QObject>
#include <QWidget>
#include <QMouseEvent>
#include <QDebug>
#include <QLabel>

class my_qlabel : public QLabel
{
    Q_OBJECT
public:
    explicit my_qlabel(QWidget *parent = nullptr);

    void mouseMoveEvent(QMouseEvent *ev);
    int x, y;

signals:
    void Mouse_Pressed();
    void Mouse_Pos();
    void Mouse_Left();
};

#endif // MY_QLABEL_H
