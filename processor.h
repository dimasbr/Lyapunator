#ifndef PROCESSOR_H
#define PROCESSOR_H
#include <vector>
#include <string>
#include <QImage>
#include <math.h>
#include <QColor>

std::vector<std::vector<double> > createLim(int width, int height, double ab, double ae,
                                         double bb, double be, std::string inp);

QImage* draw(std::vector<std::vector<double> > lims, int width, int height, std::string path,
             int stRed, int stGreen, int stBlue, int chRed, int chGreen, int chBlue);

#endif // PROCESSOR_H
