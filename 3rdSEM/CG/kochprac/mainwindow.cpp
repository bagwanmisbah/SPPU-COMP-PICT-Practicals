#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<math.h>


QImage img(500,500,QImage::Format_RGB888);
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
    img.setPixel(x,y,qRgb(0,255,0));
}

void MainWindow::dda(int x1, int y1, int x2, int y2)
{
    float dx,dy,step,xinc,yinc;
    dx = x2 - x1;
    dy = y2 - y1;
    if(abs(dy)>abs(dx)){
        step = abs(dy);
    }
    else{
        step = abs(dx);
    }

    xinc = dx/step;
    yinc = dy/step;

    float x = x1;
    float y = y1;

    for(int i=0;i<step;i++){

        x = x + xinc;
        y = y + yinc;
        plotpixel(x,y);
    }
}

void MainWindow::koch(int it,int x1,int y1,int x5,int y5)
{
    int x2,y2,x3,y3,x4,y4;
    int dx,dy;
    if(it==0)
    {
        dda(x1,y1,x5,y5);
    }
    else
    {
        dx=(x5-x1)/3;
        dy=(y5-y1)/3;

        x2=x1+dx;
        y2=y1+dy;

        x3=(int)(0.5* (x1+x5)  +  sqrt(3)*(y5-y1)/6);
        y3=(int)(0.5 *(y1+y5)  +  sqrt(3)*(x5-x1)/6);

        x4=2*dx+x1;
        y4=2*dy+y1;

        koch(it-1,x1,y1,x2,y2);
        koch(it-1,x2,y2,x3,y3);
        koch(it-1,x3,y3,x4,y4);
        koch(it-1,x4,y4,x5,y5);
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_clicked()
{
    int it= ui->textEdit->toPlainText().toFloat();
    koch(it,100,200,420,200);
}

