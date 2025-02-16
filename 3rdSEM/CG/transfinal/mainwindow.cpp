#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>

QImage img(500,500,QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dda(0,250,500,250);
    dda(250,0,250,500);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::dda(int x1,int y1,int x2,int y2)
{
    float dx,dy,xinc,yinc,len;
    int x,y;
    dx=(x2-x1);
    dy=(y2-y1);
    if(abs(dx)>=abs(dy))
    {
        len=abs(dx);
    }
    else
    {
        len=abs(dy);
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
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_clicked()
{
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    //x3=ui->textEdit_11->toPlainText().toInt();
    //y3=ui->textEdit_10->toPlainText().toInt();
    //dda(x1,y1,x2,y2);
    //dda(x2,y2,x3,y3);
    //dda(x1,y1,x2,y2);
    dda(x1+250,y1+250,x2+250,y2+250);
}

void MainWindow::on_pushButton_2_clicked()
{
    tx=ui->textEdit_6->toPlainText().toInt();
    ty=ui->textEdit_7->toPlainText().toInt();
    x1=x1+tx;
    y1=y1+ty;
    x2=x2+tx;
    y2=y2+ty;
    dda(x1+250,y1+250,x2+250,y2+250);

}
void MainWindow::on_pushButton_3_clicked()
{
    sx=ui->textEdit_8->toPlainText().toInt();
    sy=ui->textEdit_9->toPlainText().toInt();
    x1=x1*sx;
    y1=y1*sy;
    x2=x2*sx;
    y2=y2*sy;
    dda(x1+250,y1+250,x2+250,y2+250);

}
void MainWindow::on_pushButton_5_clicked()
{
    //dda(100,200,200,300);
    //dda(200,300,300,200);
    //dda(300,200,100,200); //intersects

    dda(0,50,50,100);
    dda(50,100,100,50);
    dda(100,50,0,50); //small tri

    //dda(x1,y1,x2,y2);
    //dda(x2,y2,x3,y3);
    //dda(x1,y1,x2,y2);
}

void MainWindow::on_pushButton_6_clicked()
{
    float mx,my;
    float nx1,ny1,nx2,ny2,nx3,ny3;
    //sx=ui->textEdit_8->toPlainText().toInt();
    //sy=ui->textEdit_9->toPlainText().toInt();
    /*
    mx=(x1+x2+x3)/3;
    my=(y1+y2+y3)/3;
    nx1=mx+(x1-mx)*sx;
    ny1=my+(y1-my)*sy;
    nx2=mx+(x2-mx)*sx;
    ny2=my+(y2-my)*sy;
    nx3=mx+(x3-mx)*sx;
    ny3=my+(y3-my)*sy;
    dda(nx1,ny1,nx2,ny2);
    dda(nx2,ny2,nx3,ny3);
    dda(nx1,ny1,nx2,ny2);*/

    sx=1.5;
    sy=1.5;
    mx=(0+50+100)/3;
    my=(50+100+50)/3;
    nx1=mx+(0-mx)*sx;
    ny1=my+(50-my)*sy;
    nx2=mx+(50-mx)*sx;
    ny2=my+(100-my)*sy;
    nx3=mx+(100-mx)*sx;
    ny3=my+(50-my)*sy;
    dda(nx1,ny1,nx2,ny2);
    dda(nx2,ny2,nx3,ny3);
    dda(nx1,ny1,nx2,ny2);

    //dda(x1*sx,y1*sy,x2*sx,y2*sy);
    //dda(x2*sx,y2*sy,x3*sx,y3*sy);
    //dda(x1*sx,y1*sy,x2*sx,y2*sy);
}
void MainWindow::on_pushButton_4_clicked()
{
    theta=ui->textEdit_9->toPlainText().toInt();
    rad=theta*(3.14/180);
    p=x1*cos(rad)-y1*sin(rad);
    q=x1*sin(rad)+y1*cos(rad);
    r=x2*cos(rad)-y2*sin(rad);
    s=x2*sin(rad)+y2*cos(rad);
    dda(x1+250,y1+250,x2+250,y2+250);

}

