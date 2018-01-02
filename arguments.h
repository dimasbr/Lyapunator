#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <QWidget>
#include <string>

namespace Ui {
class Arguments;
}

class Arguments : public QWidget
{
    Q_OBJECT

public:
    explicit Arguments(QWidget *parent, double* abT, double* aeT, double* bbT, double* beT, std::string* inpT);
    ~Arguments();

private slots:
    void on_saveArgs_clicked();

private:
    Ui::Arguments *ui;
    double* ab;
    double* ae;
    double* bb;
    double* be;
    std::string* inp;
};

#endif // ARGUMENTS_H
