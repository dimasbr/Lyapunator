#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(QTime::currentTime().hour() + QTime::currentTime().second() +
          QTime::currentTime().minute() + QTime::currentTime().msec());
    stRed = 200;
    stGreen = 200;
    stBlue = 0;
    chRed = 0;
    chGreen = 0;
    chBlue = 200;

    ab=2;
    ae=4;
    bb=2;
    be=4;
    inp = "AB";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_choosePath_clicked()
{
    path = QFileDialog::getExistingDirectory(0, "Choose path for saving", "/home", QFileDialog::ShowDirsOnly).toStdString();
}


void MainWindow::on_randomImg_clicked()
{
    char ch;
    int r;
    int r2;

    ab = (double)(rand()%4000)/1000;
    ae = (double)(rand()%4000)/1000;
    bb = (double)(rand()%4000)/1000;
    be = (double)(rand()%4000)/1000;

    double temp;
    if (ab > ae)
    {
        temp = ab;
        ab = ae;
        ae = temp;
    }

    if (bb > be)
    {
        temp = bb;
        bb = be;
        be = temp;
    }

    r = rand()%10 + 2;
    inp = "";

    for (int i=0; i<r; i++)
    {
        r2 = rand()%2;
        if(r2 == 0) ch = 'A';
        else ch = 'B';
        inp+=ch;
    }

    width = 200;
    height = 200;

    std::vector<std::vector<double> > lims = createLim(width, height, ab, ae, bb, be, inp);
    img = draw(lims, width, height, path, stRed, stGreen, stBlue, chRed, chGreen, chBlue);

    ui->render->setPixmap(QPixmap::fromImage(*img));
    delete img;
}

void MainWindow::on_save_clicked()
{
    width = 2000;
    height = 2000;

    std::vector<std::vector<double> > lims = createLim(width, height, ab, ae, bb, be, inp);
    highImg = draw(lims, width, height, path, stRed, stGreen, stBlue, chRed, chGreen, chBlue);
    QString fileName = QString::fromStdString(path) + "/";

    //QTime time = QTime::currentTime();
    //fileName += time.toString();
    fileName = fileName + "(" + QString::number(ab) + "_" +
            QString::number(ae) + ")" + "(" + QString::number(bb) +
            "_" + QString::number(be) + ")" + "_" + QString::fromStdString(inp);
    fileName+= ".png";
    highImg->save(fileName);
    delete highImg;
}

void MainWindow::on_verticalSlider_valueChanged(int value)
{
    width = 200;
    height = 200;
    stRed = value;
    std::vector<std::vector<double> > lims = createLim(width, height, ab, ae, bb, be, inp);
    img = draw(lims, width, height, path, stRed, stGreen, stBlue, chRed, chGreen, chBlue);

    ui->render->setPixmap(QPixmap::fromImage(*img));
    delete img;
}

void MainWindow::on_verticalSlider_2_valueChanged(int value)
{
    width = 200;
    height = 200;
    stGreen = value;
    std::vector<std::vector<double> > lims = createLim(width, height, ab, ae, bb, be, inp);
    img = draw(lims, width, height, path, stRed, stGreen, stBlue, chRed, chGreen, chBlue);

    ui->render->setPixmap(QPixmap::fromImage(*img));
    delete img;
}

void MainWindow::on_verticalSlider_3_valueChanged(int value)
{
    width = 200;
    height = 200;
    stBlue = value;
    std::vector<std::vector<double> > lims = createLim(width, height, ab, ae, bb, be, inp);
    img = draw(lims, width, height, path, stRed, stGreen, stBlue, chRed, chGreen, chBlue);

    ui->render->setPixmap(QPixmap::fromImage(*img));
    delete img;
}

void MainWindow::on_verticalSlider_6_valueChanged(int value)
{
    width = 200;
    height = 200;
    chRed = value;
    std::vector<std::vector<double> > lims = createLim(width, height, ab, ae, bb, be, inp);
    img = draw(lims, width, height, path, stRed, stGreen, stBlue, chRed, chGreen, chBlue);

    ui->render->setPixmap(QPixmap::fromImage(*img));
    delete img;
}

void MainWindow::on_verticalSlider_4_valueChanged(int value)
{
    width = 200;
    height = 200;
    chGreen = value;
    std::vector<std::vector<double> > lims = createLim(width, height, ab, ae, bb, be, inp);
    img = draw(lims, width, height, path, stRed, stGreen, stBlue, chRed, chGreen, chBlue);

    ui->render->setPixmap(QPixmap::fromImage(*img));
    delete img;
}

void MainWindow::on_verticalSlider_5_valueChanged(int value)
{
    width = 200;
    height = 200;
    chBlue = value;
    std::vector<std::vector<double> > lims = createLim(width, height, ab, ae, bb, be, inp);
    img = draw(lims, width, height, path, stRed, stGreen, stBlue, chRed, chGreen, chBlue);

    ui->render->setPixmap(QPixmap::fromImage(*img));
    delete img;
}

void MainWindow::on_arguments_clicked()
{
    args = new Arguments(this, &ab, &ae, &bb, &be, &inp);
    args->show();
}

void MainWindow::on_pushButton_clicked()
{
    width = 200;
    height = 200;
    std::vector<std::vector<double> > lims = createLim(width, height, ab, ae, bb, be, inp);
    img = draw(lims, width, height, path, stRed, stGreen, stBlue, chRed, chGreen, chBlue);

    ui->render->setPixmap(QPixmap::fromImage(*img));
    delete img;
}
