#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    int x1,y1,x2,y2,x3,y3;
    int tx,ty;
    float sx,sy;
    int theta;
    float rad;
    float p,q,r,s;

    void dda(int x1, int y1, int x2, int y2);
};
#endif // MAINWINDOW_H
