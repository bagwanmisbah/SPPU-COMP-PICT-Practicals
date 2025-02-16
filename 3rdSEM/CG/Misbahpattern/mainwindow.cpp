#include "mainwindow.h"
#include "ui_mainwindow.h"

QImage img(501,501,(QImage::Format_RGB888));
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*circle(50,50,20);
    dda(15,70,85,70);
    dda(85,70,50,10);
    dda(50,10,15,70);
    circle(50,50,40);*/

    /*circle(50,40,20);
    dda(18,15,82,15);
    dda(82,15,82,65);
    dda(82,65,18,65);
    dda(18,65,18,15);
    dda(50,15,82,40);
    dda(82,40,50,65);
    dda(50,65,18,40);
    dda(18,40,50,16);*/


    /*circle(120,120,50);
    dda(34,170,120,20);
    dda(206,170,120,20);
    dda(206,170,30,170);
    circle(120,120,100);*/

    /*circle(350,350,45);
    dda(250,300,450,300);
    dda(450,300,450,400);
    dda(450,400,250,400);
    dda(250,400,250,300);
    dda(350,300,450,350);
    dda(450,350,350,400);
    dda(350,400,250,350);
    dda(250,350,350,300);*/

    /*circle(50,50,20);
    dda(15,70,85,70);
    dda(85,70,50,10);
    dda(50,10,15,70);
    circle(50,50,40);*/

    circle(50,40,19);
    dda(18,15,82,15);
    dda(82,15,82,65);
    dda(82,65,18,65);
    dda(18,65,18,15);
    dda(50,15,82,40);
    dda(82,40,50,65);
    dda(50,65,18,40);
    dda(18,40,50,15);


    ui->label->setPixmap(QPixmap::fromImage(img));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::dda(float x1,float y1,float x2,float y2)
{
    float dx,dy,xinc,yinc,len;
    int x,y;
    dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)>=abs(dy))
    {
        len=dx;
    }
    else
    {
        len=dy;
    }
    xinc=dx/len;
    yinc=dy/len;
    x=x1;
    y=y1;
    int i=0;
    while(i<=len)
    {
        img.setPixel(x,y,qRgb(0,255,0));
        x=x+xinc;
        y=y+yinc;
        i=i+1;
    }

}
void MainWindow::circle(float p,float q,float r)
{
    float d,x,y;
    d=3-(2*r);
    x=0;y=r;
    while(x<y)
    {
        img.setPixel(x+p,y+q,qRgb(0,255,0));
        img.setPixel(y+p,x+q,qRgb(0,255,0));
        img.setPixel(-y+p,x+q,qRgb(0,255,0));
        img.setPixel(-x+p,y+q,qRgb(0,255,0));
        img.setPixel(-x+p,-y+q,qRgb(0,255,0));
        img.setPixel(-y+p,-x+q,qRgb(0,255,0));
        img.setPixel(y+p,-x+q,qRgb(0,255,0));
        img.setPixel(x+p,-y+q,qRgb(0,255,0));
        if(d<0)
        {
            d=d+(4*x)+6;
            x=x+1;
        }
        else
        {
            d=d+4*(x-y)+10;
            x=x+1;
            y=y-1;
        }
    }
}


void MainWindow::on_pushButton_clicked()
{
    float x1=ui->textEdit->toPlainText().toInt();
    float y1=ui->textEdit_2->toPlainText().toInt();
    float x2=ui->textEdit_3->toPlainText().toInt();
    float y2=ui->textEdit_4->toPlainText().toInt();
    dda(x1,y1,x2,y2);
    ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_pushButton_2_clicked()
{
    float p=ui->textEdit_5->toPlainText().toInt();
    float q=ui->textEdit_6->toPlainText().toInt();
    float r=ui->textEdit_7->toPlainText().toInt();
    circle(p,q,r);
    ui->label->setPixmap(QPixmap::fromImage(img));

}

