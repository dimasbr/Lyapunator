#include "processor.h"


std::vector<std::vector<double> > createLim(int width, int height, double ab, double ae,
                                         double bb, double be, std::string inp)
{
    std::vector<std::vector<double> > res(width, std::vector<double>(height, 0));
    bool check;

    for(int a=1; a<width; a++)
    {
        for(int b=1; b<height; b++)
        {
            double x = (double)a /((double)width/(ae-ab)) + (double)ab;
            double y = (double)b /((double)height/(be-bb)) + (double)bb;

            //std::cout<<x<<"    "<<y<<std::endl;

            double xn =0.5;
            double limit =0;
            double rn;
            check = false;
            int index;

            for (int i=0; i<100; i++)
            {
                //std::cout<<(i+ (a-1)*width*1000+ (b-1)*1000) /(width*height*1000/100)<<std::endl;
                index = i%inp.length();

                if(inp[index] == 'A') rn = x;
                else rn = y;
                xn = rn*xn*(1-xn);
                //std::cout<<xn<<"  "<<rn<<std::endl;
                if (xn==0.5) xn = 0.49999;
                limit+= log(fabs(rn * (1-2*xn) ));


            }

            if(limit<-1000)
            {
                limit = -50;
                check=true;
            }
            if(limit>1000)
            {
                limit = 50;
                check=true;
            }

            if (!check) limit=limit/(double)50;

            res.at(a-1).at(b-1) = limit;
        }
    }
    return res;
}

QImage* draw(std::vector<std::vector<double> > lims, int width, int height, std::string path,
             int stRed, int stGreen, int stBlue, int chRed, int chGreen, int chBlue)
{
    int red=0;
    int green=0;
    int blue=0;
    QColor color;

    QImage* res = new QImage(width, height, QImage::Format_RGB16);

    for(int a=1; a<width; a++)
    {
        for(int b=1; b<height; b++)
        {

//            red = (int)(( fabs(lims.at(a).at(b)) * 200)) %255;           //works!
//            green = (int)(( fabs(lims.at(a).at(b)) * 200)) %255;
//            blue = (255 - ( (int)(fabs(lims.at(a).at(b)) * 150))%255);

            if (lims.at(a).at(b) > 0)
            {
                red = (int)(( (lims.at(a).at(b)) * chRed)) %255;
                green = (int)(( (lims.at(a).at(b)) * chGreen)) %255;
                blue = (int)(( (lims.at(a).at(b)) * chBlue)) %255;
            }

            else
            {
                red = (int)(( fabs(lims.at(a).at(b)) * stRed)) %255;
                green = (int)(( fabs(lims.at(a).at(b)) * stGreen)) %255;
                blue = (int)(( fabs(lims.at(a).at(b)) * stBlue)) %255;
            }

            color.setRed(red);
            color.setBlue(blue);
            color.setGreen(green);
            //std::cout<<lims.at(a).at(b)<<std::endl;
            //std::cout<<red<<"    "<<green<<"    "<<blue<<std::endl;
            res->setPixel(a, b, color.rgb());
        }
    }
    //res->save("RESULT.png");
    return res;
}


