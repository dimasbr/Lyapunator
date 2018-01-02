#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdlib.h>
#include <QTime>
#include <processor.h>
#include <QFileDialog>
#include <arguments.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_choosePath_clicked();

    void on_randomImg_clicked();

    void on_save_clicked();

    void on_verticalSlider_valueChanged(int value);

    void on_verticalSlider_2_valueChanged(int value);

    void on_verticalSlider_3_valueChanged(int value);

    void on_verticalSlider_6_valueChanged(int value);

    void on_verticalSlider_4_valueChanged(int value);

    void on_verticalSlider_5_valueChanged(int value);

    void on_arguments_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QImage* img;
    QImage* highImg;
    std::string path;
    int width;
    int height;
    double ab;
    double ae;
    double bb;
    double be;

    int stRed;
    int stGreen;
    int stBlue;
    int chRed;
    int chGreen;
    int chBlue;

    std::string inp;

    Arguments* args;
};

#endif // MAINWINDOW_H
