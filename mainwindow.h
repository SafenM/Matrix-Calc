#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>

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
    void on_pushEqual_clicked();
//show or hide overlay elements
    void hide_3x3();
    void hide_4x4();
    void hide_right();
    void hide_binary();

    void show_3x3();
    void show_4x4();
    void show_right();
    void show_binary();


//dimension choosing buttons
    void on_push2x2_clicked();
    void on_push3x3_clicked();
    void on_push4x4_clicked();
//math functions
    void update_matrices();

    double det_from_3x3(double a[4][4]);
    double det_minor_3(double a[4][4], int row, int col);
    double det_minor_2(double a[4][4], int row, int col);
    double det2();
    double det3();
    double det4();

    void transpose();

    void inverse_2x2();
    void inverse_3x3();
    void inverse_4x4();

    void add();
    void subtract();
    void multiply();

//control
    void on_pushDet_clicked();

    void on_pushInv_clicked();

    void on_pushTrs_clicked();

    void on_pushClear_clicked();

    //void on_pushSomething_clicked();

    void on_pushAdd_clicked();

    void on_pushSub_clicked();

    void on_pushMul_clicked();


private:
    Ui::MainWindow *ui;
    int dimFlag = 4; // 2 for 2x2, 3 for 3x3, 4 for 4x4
    int modeFlag = 1; // 1 for det, 2 for inv, 3 for trs, 4 for add, 5 for sub, 6 for mul
    double matrix_1[4][4];
    double matrix_2[4][4];
    double matrix_3[4][4];
};
#endif // MAINWINDOW_H
