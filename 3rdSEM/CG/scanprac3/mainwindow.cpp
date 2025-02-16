#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMouseEvent>
#include <iostream>
#include <QColorDialog>
using namespace std;


QImage img=QImage(500,500,QImage::Format_RGB888);
QColor color=Qt::yellow;


int vx[20];
int vy[20];
float slopes[20];
int numv;
int ind=0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::plotpixel(int x,int y)
{
    img.setPixel(x,y,color.rgb());
}


void MainWindow::dda(int x1,int y1,int x2,int y2)
{
    float dx=x2-x1;
    float dy=y2-y1;
    float steps=abs(dx);
    if(abs(dy)>abs(dx))
    {
        steps=abs(dy);
    }

    float xinc=dx/steps;
    float yinc=dy/steps;

    float x=x1;
    float y=y1;


    for(int i=0;i<steps;i++)
    {
        x=x+xinc;
        y=y+yinc;
        plotpixel(x,y);
    }
     ui->label->setPixmap(QPixmap::fromImage(img));
}
void MainWindow::mousePressEvent(QMouseEvent *e)
{
     int x=e->pos().x();
     int y=e->pos().y();
     plotpixel(x,y);
     if(x>500||y>500)
     {
        return;
     }

     if(e->button()==Qt::RightButton)
     {
        vx[ind]=vx[0];
        vy[ind]=vy[0];
        dda(vx[ind-1],vy[ind-1],vx[0],vy[0]);
        numv=ind;
     }
     else
     {
        vx[ind]=x;
        vy[ind]=y;
        if(ind>0)
        {
            dda(vx[ind-1],vy[ind-1],x,y);
        }
        ind++;
     }
     ui->label->setPixmap(QPixmap::fromImage(img));
}



void MainWindow::on_pushButton_clicked()
{
     //calc ymin
     float ymin=10000.0f;
     for(int i=0;i<numv;i++)
     {
        if(vy[i]<ymin)
            ymin=vy[i];
     }

     //calc ymax
     float ymax=0.f;
     for(int i=0;i<numv;i++)
     {
        if(vy[i]>ymax)
            ymax=vy[i];
     }

     //for calculating slopes
     for(int i=0;i<numv;i++)
     {
        float dx=vx[i+1]-vx[i];
        float dy=vy[i+1]-vy[i];

        if(dx==0)
        {
            slopes[i]=1.0f;
        }
        else
        {
            slopes[i]=dy/dx;
        }
     }

     //scan for lines

     for(int y=ymin;y<ymax;y++)
     {
        float xint[numv];
        int ae=0;

        for(int i=0;i<numv;i++)
        {
            float yminline=std::min(vy[i],vy[i+1]);
            float ymaxline=std::max(vy[i],vy[i+1]);

            if(yminline<y && y<=ymaxline)
            {
                xint[ae]=vx[i]+((1/slopes[i])*(y-vy[i]));
                ae++;
            }

        for(int i=0;i<numv;i++)
            {
                for(int j=0;j<numv-i-1;j++)
                {
                    if(xint[j]>xint[j+1])
                    {
                        float temp=xint[j];
                        xint[j]=xint[j+1];
                        xint[j+1]=temp;
                    }
                }
            }
        for(int i=0;i<ae;i+=2)
            {
                dda(xint[i],y,xint[i+1]+1,y);
            }
        }
     }
}



void MainWindow::on_pushButton_2_clicked()
{
     color=QColorDialog::getColor();

}

