#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QImage>
#include <QVector>
#include <QColor>

#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    QImage on_actionAbrir_triggered();
    void on_actionDuplicar_triggered(QImage);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
