#include "mainwindow.h"
#include "ui_mainwindow.h"


int xmin=125;
int ymin=100;
int xmax=350;
int ymax=250;

const int INSIDE=0;
const int TOP=8;
const int LEFT=1;
const int BOTTOM=4;
const int RIGHT=2;



QImage img=QImage(500,500,QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    drawwindow();
    ui->label->setPixmap(QPixmap::fromImage(img));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::drawwindow()
{
    dda(xmin,ymin,xmin,ymax);
    dda(xmin,ymin,xmax,ymin);
    dda(xmax,ymin,xmax,ymax);
    dda(xmin,ymax,xmax,ymax);
}

void MainWindow::clearcanvas()
{
    img.fill(qRgb(0,0,0));
    drawwindow();
     ui->label->setPixmap(QPixmap::fromImage(img));

}


void MainWindow::plotpixel(int x,int y)
{
    img.setPixel(x,y,qRgb(0,255,0));
}
void MainWindow::dda(float x1,float y1,float x2,float y2)
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


int MainWindow::compute(int x,int y)
{
    int code=INSIDE;

    if(x<xmin)
    {
        code |=LEFT;
    }
    if(x>xmax)
    {
        code |=RIGHT;
    }
    if(y<ymin)
    {
        code |=TOP;
    }
    if(y>ymax)
    {
        code |=BOTTOM;
    }
    return code;
}

void MainWindow::cohen(float x1,float y1,float x2,float y2)
{
    int code1=compute(x1,y1);
    int code2=compute(x2,y2);
    bool accept=false;

    while(true)
    {
        if((code1==0)&&(code2==0))
        {
            accept=true;
            break;
        }
        else if(code1 & code2)
        {
            break;
        }
        else
        {
            int outcode;
            int x,y;

            if(code1!=0)
            {
                outcode=code1;
            }
            else
            {
                outcode=code2;
            }

            if(outcode & TOP)
            {
                y=ymin;
                x=x1+(x2-x1)*(y-y1)/(y2-y1);
            }
            if(outcode & BOTTOM)
            {
                y=ymax;
                x=x1+(x2-x1)*(y-y1)/(y2-y1);
            }
            if(outcode & RIGHT)
            {
                x=xmax;
                y=y1+(y2-y1)*(x-x1)/(x2-x1);
            }
            if(outcode & LEFT)
            {
                x=xmin;
                y=y1+(y2-y1)*(x-x1)/(x2-x1);
            }

            if(outcode==code1)
            {
                x1=x;
                y1=y;
                code1=compute(x1,y1);
            }
            if(outcode==code2)
            {
                x2=x;
                y2=y;
                code2=compute(x2,y2);
            }

        }

    }
    if(accept)
    {
        clearcanvas();
        dda(x1,y1,x2,y2);
        ui->label->setPixmap(QPixmap::fromImage(img));
    }

}


void MainWindow::on_pushButton_clicked()
{
    int x1=ui->textEdit->toPlainText().toInt();
    int y1=ui->textEdit_2->toPlainText().toInt();
    int x2=ui->textEdit_3->toPlainText().toInt();
    int y2=ui->textEdit_4->toPlainText().toInt();
    dda(x1,y1,x2,y2);
    ui->label->setPixmap(QPixmap::fromImage(img));

}


void MainWindow::on_pushButton_2_clicked()
{
    int x1=ui->textEdit->toPlainText().toInt();
    int y1=ui->textEdit_2->toPlainText().toInt();
    int x2=ui->textEdit_3->toPlainText().toInt();
    int y2=ui->textEdit_4->toPlainText().toInt();
    cohen(x1,y1,x2,y2);

}


void MainWindow::on_pushButton_3_clicked()
{
    clearcanvas();
}

