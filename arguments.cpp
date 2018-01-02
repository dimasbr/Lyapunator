#include "arguments.h"
#include "ui_arguments.h"

Arguments::Arguments(QWidget *parent, double* abT, double* aeT, double* bbT, double* beT, std::string* inpT) :
    QWidget(parent),
    ui(new Ui::Arguments)
{
    ui->setupUi(this);
    setAutoFillBackground(true);

    ui->ab->setText(QString::number(*abT));
    ui->ae->setText(QString::number(*aeT));
    ui->bb->setText(QString::number(*bbT));
    ui->be->setText(QString::number(*beT));
    ui->str->setText(QString::fromStdString(*inpT));

    ab = abT;
    ae = aeT;
    bb = bbT;
    be = beT;
    inp = inpT;
}

Arguments::~Arguments()
{
    delete ui;
}

void Arguments::on_saveArgs_clicked()
{
    *ab = ui->ab->text().toDouble();
    *ae = ui->ae->text().toDouble();
    *bb = ui->bb->text().toDouble();
    *be = ui->be->text().toDouble();
    *inp = ui->str->text().toStdString();

    this->close();
}
