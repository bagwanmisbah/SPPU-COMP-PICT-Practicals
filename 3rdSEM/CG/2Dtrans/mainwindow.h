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

    void plotPixel(int x, int y);
    void drawAxis();
    void drawTriangle(int xver[], int yver[]);
    void Translate(int tx, int ty);
    void Scale(int sx, int sy);
    void Rotate(float theta);
    void dda_line(float x1, float y1, float x2, float y2);
    void on_btn_clear_clicked();
    void on_btn_clear_2_clicked();
private slots:
    void on_btn_translate_clicked();

    void on_btn_scale_clicked();

    void on_btn_rotate_clicked();

    void on_btn_draw_obj_clicked();


private:

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
