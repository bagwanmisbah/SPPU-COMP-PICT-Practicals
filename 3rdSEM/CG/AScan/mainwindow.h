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

private:
    Ui::MainWindow *ui;
    void plotPixel(int x, int y);
    void dda_line(float x1, float y1, float x2, float y2);
    void mousePressEvent(QMouseEvent *event);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};
#endif // MAINWINDOW_H
