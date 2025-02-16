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

    //void plotpixel(float x1, float y1);
    //void dda(float x1, float y1, float x2, float y2);
    void koch(int it, int x1, int y1, int x5, int y5);
    void dda(int x1, int y1, int x2, int y2);
    void plotpixel(int x1, int y1);
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
