#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColor>

QImage img=QImage(600,600,QImage::Format_RGB888);
QColor color =Qt::green;


int numc=3;
int vx[]={30,30,100};
int vy[]={100,30,30};


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    drawaxis();
    drawtriangle(vx,vy);
    ui->label->setPixmap(QPixmap::fromImage(img));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawaxis()
{
    dda(0,300,600,300);
    dda(300,0,300,600);
}

void MainWindow::drawtriangle(int vx[],int vy[])
{
    dda(vx[0]+300,300-vy[0],vx[1]+300,300-vy[1]);
    dda(vx[1]+300,300-vy[1],vx[2]+300,300-vy[2]);
    dda(vx[0]+300,300-vy[0],vx[2]+300,300-vy[2]);
    ui->label->setPixmap(QPixmap::fromImage(img));
}
void MainWindow::plotpixel(int x,int y)
{
    img.setPixel(x,y,color.rgb());
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
    float x=x1;
    float y=y1;
    float xinc=dx/steps;
    float yinc=dy/steps;

    for(int i=0;i<steps;i++)
    {
        x=x+xinc;
        y=y+yinc;
        plotpixel(x,y);
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::translate(int tx,int ty)
{
    int tvx[numc];
    int tvy[numc];
    for(int i=0;i<numc;i++)
    {
        tvx[i]=vx[i]+tx;
        tvy[i]=vy[i]+ty;
    }
    drawtriangle(tvx,tvy);
}
void MainWindow::scale(int sx,int sy)
{
    int svx[numc];
    int svy[numc];
    for(int i=0;i<numc;i++)
    {
        svx[i]=vx[i]*sx;
        svy[i]=vy[i]*sy;
    }
    drawtriangle(svx,svy);
}
void MainWindow::rotate(float theta)
{
    int rvx[numc];
    int rvy[numc];
    theta=theta*3.14/180;
    for(int i=0;i<numc;i++)
    {
        float x=vx[i];
        float y=vy[i];

        rvx[i]=x*cos(theta)-y*sin(theta);
        rvy[i]=x*sin(theta)+y*cos(theta);
    }
    drawtriangle(rvx,rvy);
}


void MainWindow::on_pushButton_clicked()
{
    int tx=ui->textEdit->toPlainText().toFloat();
    int ty=ui->textEdit_2->toPlainText().toFloat();
    translate(tx,ty);
    ui->label->setPixmap(QPixmap::fromImage(img));

}


void MainWindow::on_pushButton_2_clicked()
{

    int sx=ui->textEdit_3->toPlainText().toFloat();
    int sy=ui->textEdit_4->toPlainText().toFloat();
    scale(sx,sy);
    ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::on_pushButton_3_clicked()
{

    float theta=ui->textEdit_5->toPlainText().toFloat();
    rotate(theta);
    ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::on_pushButton_4_clicked()
{
    img.fill(qRgb(0,0,0));
    drawaxis();
    drawtriangle(vx,vy);

}

