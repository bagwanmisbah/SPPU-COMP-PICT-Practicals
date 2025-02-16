#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <iostream>
using namespace std;
QImage img(500,500,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DDA(0,250,500,250);
    DDA(250,0,250,500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DDA(int x1,int y1,int x2,int y2)
{
    float dx,dy,length,xinc,yinc,x,y;
    dx=(x2-x1);
    dy=(y2-y1);
    if(abs(dx)>=abs(dy))
        length=abs(dx);
    else
        length =abs(dy);
    xinc=dx/length;
    yinc=dy/length;
    int i=0;
    x=x1;
    y=y1;
    while(i<length)
    {
        img.setPixel(int(x),int (y),qRgb(255,255,255));
        x=x+xinc;
        y=y+yinc;
        i++;

    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_pushButton_2_clicked()
{
    DDA(x1+250,y1+250,x2+250,y2+250);
    tx=ui->textEdit_5->toPlainText().toInt();
    ty=ui->textEdit_6->toPlainText().toInt();

    x1=x1+tx;
    x2=x2+tx;
    y1=y1+ty;
    y2=y2+ty;
    DDA(x1+250,y1+250,x2+250,y2+250);

}


void MainWindow::on_pushButton_clicked()
{
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_5->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    DDA(x1+250,y1+250,x2+250,y2+250);
    ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::on_pushButton_3_clicked()
{
    sx=ui->textEdit_7->toPlainText().toFloat();
    sy=ui->textEdit_8->toPlainText().toFloat();
    x1=x1*sx;
    y1=y1*sy;
    x2=x2*sx;
    y2=y2*sy;

    DDA(x1+250,y1+250,x2+250,y2+250);
}

void MainWindow::on_pushButton_4_clicked()
{
    theta=ui->textEdit_9->toPlainText().toInt();

    rad=theta*(3.14/180);


    p=x1*cos(rad)-y1*sin(rad);
    q=x1*sin(rad)+y1*cos(rad);
    r=x2*cos(rad)-y2*sin(rad);
    s=x2*sin(rad)+y2*cos(rad);

    DDA(p+250,q+250,r+250,s+250);

}
