#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushDet->click();
    ui->push3x3->click();
    ui->labelWarning->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushEqual_clicked()
{
    ui->labelWarning->hide();
    if (MainWindow::modeFlag == 1)
    {
        if (MainWindow::dimFlag == 2)
        {
            ui->lcdNumber->display(det2());
        }
        else if (MainWindow::dimFlag == 3)
        {
            ui->lcdNumber->display(det3());
        }
        else if (MainWindow::dimFlag == 4)
        {
            ui->lcdNumber->display(det4());
        }
    }
    else if (MainWindow::modeFlag == 2)
    {
        if (MainWindow::dimFlag == 2)
        {
            inverse_2x2();
        }
        else if (MainWindow::dimFlag == 3)
        {
            inverse_3x3();
        }
        else if (MainWindow::dimFlag == 4)
        {
            inverse_4x4();
        }
    }
    else if (MainWindow::modeFlag == 3)
    {
        MainWindow::transpose();
    }
    else if (MainWindow::modeFlag == 4)
    {
        MainWindow::add();
    }
    else if (MainWindow::modeFlag == 5)
    {
        MainWindow::subtract();
    }
    else if (MainWindow::modeFlag == 6)
    {
        MainWindow::multiply();
    }
}

void MainWindow::hide_3x3()
{
    ui->num_1x3->hide();
    ui->num_2x3->hide();
    ui->num_3x1->hide();
    ui->num_3x2->hide();
    ui->num_3x3->hide();

    ui->num2_1x3->hide();
    ui->num2_2x3->hide();
    ui->num2_3x1->hide();
    ui->num2_3x2->hide();
    ui->num2_3x3->hide();

    ui->num3_1x3->hide();
    ui->num3_2x3->hide();
    ui->num3_3x1->hide();
    ui->num3_3x2->hide();
    ui->num3_3x3->hide();
}

void MainWindow::hide_4x4()
{
    ui->num_1x4->hide();
    ui->num_2x4->hide();
    ui->num_3x4->hide();
    ui->num_4x1->hide();
    ui->num_4x2->hide();
    ui->num_4x3->hide();
    ui->num_4x4->hide();

    ui->num2_1x4->hide();
    ui->num2_2x4->hide();
    ui->num2_3x4->hide();
    ui->num2_4x1->hide();
    ui->num2_4x2->hide();
    ui->num2_4x3->hide();
    ui->num2_4x4->hide();

    ui->num3_1x4->hide();
    ui->num3_2x4->hide();
    ui->num3_3x4->hide();
    ui->num3_4x1->hide();
    ui->num3_4x2->hide();
    ui->num3_4x3->hide();
    ui->num3_4x4->hide();
}

void MainWindow::hide_right()
{
    ui->num2_1x1->hide();
    ui->num2_1x2->hide();
    ui->num2_1x3->hide();
    ui->num2_1x4->hide();
    ui->num2_2x1->hide();
    ui->num2_2x2->hide();
    ui->num2_2x3->hide();
    ui->num2_2x4->hide();
    ui->num2_3x1->hide();
    ui->num2_3x2->hide();
    ui->num2_3x3->hide();
    ui->num2_3x4->hide();
    ui->num2_4x1->hide();
    ui->num2_4x2->hide();
    ui->num2_4x3->hide();
    ui->num2_4x4->hide();
}

void MainWindow::hide_binary()
{
    //ui->pushSwap->hide();
    ui->num3_1x1->hide();
    ui->num3_1x2->hide();
    ui->num3_1x3->hide();
    ui->num3_1x4->hide();
    ui->num3_2x1->hide();
    ui->num3_2x2->hide();
    ui->num3_2x3->hide();
    ui->num3_2x4->hide();
    ui->num3_3x1->hide();
    ui->num3_3x2->hide();
    ui->num3_3x3->hide();
    ui->num3_3x4->hide();
    ui->num3_4x1->hide();
    ui->num3_4x2->hide();
    ui->num3_4x3->hide();
    ui->num3_4x4->hide();
}

void MainWindow::show_3x3()
{
    ui->num_1x3->show();
    ui->num_2x3->show();
    ui->num_3x1->show();
    ui->num_3x2->show();
    ui->num_3x3->show();

    if (modeFlag != 1)
    {
        ui->num2_1x3->show();
        ui->num2_2x3->show();
        ui->num2_3x1->show();
        ui->num2_3x2->show();
        ui->num2_3x3->show();
    }
    if (modeFlag > 3)
    {
        ui->num3_1x3->show();
        ui->num3_2x3->show();
        ui->num3_3x3->show();
        ui->num3_3x1->show();
        ui->num3_3x2->show();
    }
}

void MainWindow::show_4x4()
{
    ui->num_1x4->show();
    ui->num_2x4->show();
    ui->num_3x4->show();
    ui->num_4x1->show();
    ui->num_4x2->show();
    ui->num_4x3->show();
    ui->num_4x4->show();

    if (modeFlag != 1)
    {
        ui->num2_1x4->show();
        ui->num2_2x4->show();
        ui->num2_3x4->show();
        ui->num2_4x1->show();
        ui->num2_4x2->show();
        ui->num2_4x3->show();
        ui->num2_4x4->show();
    }

    if (modeFlag > 3)
    {
        ui->num3_1x4->show();
        ui->num3_2x4->show();
        ui->num3_3x4->show();
        ui->num3_4x1->show();
        ui->num3_4x2->show();
        ui->num3_4x3->show();
        ui->num3_4x4->show();
    }
}

void MainWindow::show_right()
{
    ui->num2_1x1->show();
    ui->num2_1x2->show();
    ui->num2_2x1->show();
    ui->num2_2x2->show();

    if (dimFlag > 2)
    {
        ui->num2_1x3->show();
        ui->num2_2x3->show();
        ui->num2_3x1->show();
        ui->num2_3x2->show();
        ui->num2_3x3->show();
    }

    if (dimFlag > 3)
    {
        ui->num2_1x4->show();
        ui->num2_2x4->show();
        ui->num2_3x4->show();
        ui->num2_4x1->show();
        ui->num2_4x2->show();
        ui->num2_4x3->show();
        ui->num2_4x4->show();
    }

}

void MainWindow::show_binary()
{
    //ui->pushSwap->show();
    show_right();
    ui->num3_1x1->show();
    ui->num3_1x2->show();
    ui->num3_2x1->show();
    ui->num3_2x2->show();

    if (dimFlag == 4)
    {
        ui->num3_1x4->show();
        ui->num3_2x4->show();
        ui->num3_3x4->show();
        ui->num3_4x4->show();
        ui->num3_4x1->show();
        ui->num3_4x2->show();
        ui->num3_4x3->show();
    }

    if (dimFlag > 2)
    {
        ui->num3_1x3->show();
        ui->num3_2x3->show();
        ui->num3_3x3->show();
        ui->num3_3x1->show();
        ui->num3_3x2->show();
    }
}

void MainWindow::on_push2x2_clicked()
{
    hide_3x3();
    hide_4x4();
    MainWindow::dimFlag = 2;
}

void MainWindow::on_push3x3_clicked()
{
    hide_4x4();
    show_3x3();
    MainWindow::dimFlag = 3;
}

void MainWindow::on_push4x4_clicked()
{
    show_4x4();
    show_3x3();
    MainWindow::dimFlag = 4;
}

void MainWindow::update_matrices()
{
    matrix_1[0][0] = ui->num_1x1->toPlainText().toDouble();
    matrix_1[0][1] = ui->num_1x2->toPlainText().toDouble();
    matrix_1[0][2] = ui->num_1x3->toPlainText().toDouble();
    matrix_1[0][3] = ui->num_1x4->toPlainText().toDouble();
    matrix_1[1][0] = ui->num_2x1->toPlainText().toDouble();
    matrix_1[1][1] = ui->num_2x2->toPlainText().toDouble();
    matrix_1[1][2] = ui->num_2x3->toPlainText().toDouble();
    matrix_1[1][3] = ui->num_2x4->toPlainText().toDouble();
    matrix_1[2][0] = ui->num_3x1->toPlainText().toDouble();
    matrix_1[2][1] = ui->num_3x2->toPlainText().toDouble();
    matrix_1[2][2] = ui->num_3x3->toPlainText().toDouble();
    matrix_1[2][3] = ui->num_3x4->toPlainText().toDouble();
    matrix_1[3][0] = ui->num_4x1->toPlainText().toDouble();
    matrix_1[3][1] = ui->num_4x2->toPlainText().toDouble();
    matrix_1[3][2] = ui->num_4x3->toPlainText().toDouble();
    matrix_1[3][3] = ui->num_4x4->toPlainText().toDouble();

    matrix_2[0][0] = ui->num2_1x1->toPlainText().toDouble();
    matrix_2[0][1] = ui->num2_1x2->toPlainText().toDouble();
    matrix_2[0][2] = ui->num2_1x3->toPlainText().toDouble();
    matrix_2[0][3] = ui->num2_1x4->toPlainText().toDouble();
    matrix_2[1][0] = ui->num2_2x1->toPlainText().toDouble();
    matrix_2[1][1] = ui->num2_2x2->toPlainText().toDouble();
    matrix_2[1][2] = ui->num2_2x3->toPlainText().toDouble();
    matrix_2[1][3] = ui->num2_2x4->toPlainText().toDouble();
    matrix_2[2][0] = ui->num2_3x1->toPlainText().toDouble();
    matrix_2[2][1] = ui->num2_3x2->toPlainText().toDouble();
    matrix_2[2][2] = ui->num2_3x3->toPlainText().toDouble();
    matrix_2[2][3] = ui->num2_3x4->toPlainText().toDouble();
    matrix_2[3][0] = ui->num2_4x1->toPlainText().toDouble();
    matrix_2[3][1] = ui->num2_4x2->toPlainText().toDouble();
    matrix_2[3][2] = ui->num2_4x3->toPlainText().toDouble();
    matrix_2[3][3] = ui->num2_4x4->toPlainText().toDouble();

    matrix_3[0][0] = ui->num3_1x1->toPlainText().toDouble();
    matrix_3[0][1] = ui->num3_1x2->toPlainText().toDouble();
    matrix_3[0][2] = ui->num3_1x3->toPlainText().toDouble();
    matrix_3[0][3] = ui->num3_1x4->toPlainText().toDouble();
    matrix_3[1][0] = ui->num3_2x1->toPlainText().toDouble();
    matrix_3[1][1] = ui->num3_2x2->toPlainText().toDouble();
    matrix_3[1][2] = ui->num3_2x3->toPlainText().toDouble();
    matrix_3[1][3] = ui->num3_2x4->toPlainText().toDouble();
    matrix_3[2][0] = ui->num3_3x1->toPlainText().toDouble();
    matrix_3[2][1] = ui->num3_3x2->toPlainText().toDouble();
    matrix_3[2][2] = ui->num3_3x3->toPlainText().toDouble();
    matrix_3[2][3] = ui->num3_3x4->toPlainText().toDouble();
    matrix_3[3][0] = ui->num3_4x1->toPlainText().toDouble();
    matrix_3[3][1] = ui->num3_4x2->toPlainText().toDouble();
    matrix_3[3][2] = ui->num3_4x3->toPlainText().toDouble();
    matrix_3[3][3] = ui->num3_4x4->toPlainText().toDouble();
}

double MainWindow::det_minor_3(double a[4][4], int row, int col)
{
    double b[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            if (i < row)
            {
                if (j < col)
                {
                    b[i][j] = a[i][j];
                }
                else if (j > col)
                {
                    b[i][j-1] = a[i][j];
                }
            }
            else if (i > row)
            {
                if (j < col)
                {
                    b[i-1][j] = a[i][j];
                }
                else if (j > col)
                {
                    b[i-1][j-1] = a[i][j];
                }
            }
        }
    return det_from_3x3(b);
}

double MainWindow::det_minor_2(double a[4][4], int row, int col)
{
    double b[2][2];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            if (i < row)
            {
                if (j < col)
                {
                    b[i][j] = a[i][j];
                }
                else if (j > col)
                {
                    b[i][j-1] = a[i][j];
                }
            }
            else if (i > row)
            {
                if (j < col)
                {
                    b[i-1][j] = a[i][j];
                }
                else if (j > col)
                {
                    b[i-1][j-1] = a[i][j];
                }
            }
        }
    return b[0][0] * b[1][1] - b[0][1] * b[1][0];
}

double MainWindow::det_from_3x3(double a[4][4])
{
    return    a[0][0] * a[1][1] * a[2][2] +
              a[1][0] * a[2][1] * a[0][2] +
              a[2][0] * a[0][1] * a[1][2] -
              a[0][2] * a[1][1] * a[2][0] -
              a[1][2] * a[2][1] * a[0][0] -
              a[2][2] * a[0][1] * a[1][0];
}

double MainWindow::det2()
{
    double a[2][2];
    a[0][0] = ui->num_1x1->toPlainText().toDouble();
    a[0][1] = ui->num_1x2->toPlainText().toDouble();
    a[1][0] = ui->num_2x1->toPlainText().toDouble();
    a[1][1] = ui->num_2x2->toPlainText().toDouble();

    return  a[0][0] * a[1][1] -
            a[0][1] * a[1][0];

}

double MainWindow::det3()
{
    update_matrices();

    return det_from_3x3(matrix_1);
}

double MainWindow::det4()
{
    update_matrices();

    return  matrix_1[0][0] * det_minor_3(matrix_1,0,0) -
            matrix_1[0][1] * det_minor_3(matrix_1,0,1) +
            matrix_1[0][2] * det_minor_3(matrix_1,0,2) -
            matrix_1[0][3] * det_minor_3(matrix_1,0,3);
}

void MainWindow::transpose()
{
    ui->num2_1x1->setPlainText(ui->num_1x1->toPlainText());
    ui->num2_2x2->setPlainText(ui->num_2x2->toPlainText());
    ui->num2_3x3->setPlainText(ui->num_3x3->toPlainText());
    ui->num2_4x4->setPlainText(ui->num_4x4->toPlainText());
    ui->num2_1x2->setPlainText(ui->num_2x1->toPlainText());
    ui->num2_1x3->setPlainText(ui->num_3x1->toPlainText());
    ui->num2_1x4->setPlainText(ui->num_4x1->toPlainText());
    ui->num2_2x1->setPlainText(ui->num_1x2->toPlainText());
    ui->num2_2x3->setPlainText(ui->num_3x2->toPlainText());
    ui->num2_2x4->setPlainText(ui->num_4x2->toPlainText());
    ui->num2_3x1->setPlainText(ui->num_1x3->toPlainText());
    ui->num2_3x2->setPlainText(ui->num_2x3->toPlainText());
    ui->num2_3x4->setPlainText(ui->num_4x3->toPlainText());
    ui->num2_4x1->setPlainText(ui->num_1x4->toPlainText());
    ui->num2_4x2->setPlainText(ui->num_2x4->toPlainText());
    ui->num2_4x3->setPlainText(ui->num_3x4->toPlainText());
}

void MainWindow::inverse_2x2()
{
    double detA = det2();

    if (detA == 0)
    {
        ui->labelWarning->show();
        return;
    }

    double a[2][2];
    a[0][0] = ui->num_2x2->toPlainText().toDouble() / detA;
    a[0][1] = ui->num_1x2->toPlainText().toDouble() / -detA;
    a[1][0] = ui->num_2x1->toPlainText().toDouble() / -detA;
    a[1][1] = ui->num_1x1->toPlainText().toDouble() / detA;
    ui->num2_1x1->setPlainText(QString::number(a[0][0]));
    ui->num2_1x2->setPlainText(QString::number(a[0][1]));
    ui->num2_2x1->setPlainText(QString::number(a[1][0]));
    ui->num2_2x2->setPlainText(QString::number(a[1][1]));
}

void MainWindow::inverse_3x3()
{
    update_matrices();

    double detA = det3();

    if (detA == 0)
    {
        ui->labelWarning->show();
        return;
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            matrix_2[j][i] = det_minor_2(matrix_1,i,j) / detA;
            if ((i + j) % 2 == 1)
            {
                matrix_2[j][i] = -matrix_2[j][i];
            }
        }

    ui->num2_1x1->setPlainText(QString::number(matrix_2[0][0]));
    ui->num2_1x2->setPlainText(QString::number(matrix_2[0][1]));
    ui->num2_1x3->setPlainText(QString::number(matrix_2[0][2]));
    ui->num2_2x1->setPlainText(QString::number(matrix_2[1][0]));
    ui->num2_2x2->setPlainText(QString::number(matrix_2[1][1]));
    ui->num2_2x3->setPlainText(QString::number(matrix_2[1][2]));
    ui->num2_3x1->setPlainText(QString::number(matrix_2[2][0]));
    ui->num2_3x2->setPlainText(QString::number(matrix_2[2][1]));
    ui->num2_3x3->setPlainText(QString::number(matrix_2[2][2]));


}

void MainWindow::inverse_4x4()
{
    update_matrices();

    double detA = det4();

    if (detA == 0)
    {
        ui->labelWarning->show();
        return;
    }

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            matrix_2[j][i] = det_minor_3(matrix_1,i,j) / detA;
            if ((i + j) % 2 == 1)
            {
                matrix_2[j][i] = -matrix_2[j][i];
            }
        }

    ui->num2_1x1->setPlainText(QString::number(matrix_2[0][0]));
    ui->num2_1x2->setPlainText(QString::number(matrix_2[0][1]));
    ui->num2_1x3->setPlainText(QString::number(matrix_2[0][2]));
    ui->num2_1x4->setPlainText(QString::number(matrix_2[0][3]));
    ui->num2_2x1->setPlainText(QString::number(matrix_2[1][0]));
    ui->num2_2x2->setPlainText(QString::number(matrix_2[1][1]));
    ui->num2_2x3->setPlainText(QString::number(matrix_2[1][2]));
    ui->num2_2x4->setPlainText(QString::number(matrix_2[1][3]));
    ui->num2_3x1->setPlainText(QString::number(matrix_2[2][0]));
    ui->num2_3x2->setPlainText(QString::number(matrix_2[2][1]));
    ui->num2_3x3->setPlainText(QString::number(matrix_2[2][2]));
    ui->num2_3x4->setPlainText(QString::number(matrix_2[2][3]));
    ui->num2_4x1->setPlainText(QString::number(matrix_2[3][0]));
    ui->num2_4x2->setPlainText(QString::number(matrix_2[3][1]));
    ui->num2_4x3->setPlainText(QString::number(matrix_2[3][2]));
    ui->num2_4x4->setPlainText(QString::number(matrix_2[3][3]));

}

void MainWindow::add()
{
    update_matrices();
    ui->num3_1x1->setPlainText(QString::number(matrix_1[0][0] + matrix_2[0][0]));
    ui->num3_1x2->setPlainText(QString::number(matrix_1[0][1] + matrix_2[0][1]));
    ui->num3_1x3->setPlainText(QString::number(matrix_1[0][2] + matrix_2[0][2]));
    ui->num3_1x4->setPlainText(QString::number(matrix_1[0][3] + matrix_2[0][3]));
    ui->num3_2x1->setPlainText(QString::number(matrix_1[1][0] + matrix_2[1][0]));
    ui->num3_2x2->setPlainText(QString::number(matrix_1[1][1] + matrix_2[1][1]));
    ui->num3_2x3->setPlainText(QString::number(matrix_1[1][2] + matrix_2[1][2]));
    ui->num3_2x4->setPlainText(QString::number(matrix_1[1][3] + matrix_2[1][3]));
    ui->num3_3x1->setPlainText(QString::number(matrix_1[2][0] + matrix_2[2][0]));
    ui->num3_3x2->setPlainText(QString::number(matrix_1[2][1] + matrix_2[2][1]));
    ui->num3_3x3->setPlainText(QString::number(matrix_1[2][2] + matrix_2[2][2]));
    ui->num3_3x4->setPlainText(QString::number(matrix_1[2][3] + matrix_2[2][3]));
    ui->num3_4x1->setPlainText(QString::number(matrix_1[3][0] + matrix_2[3][0]));
    ui->num3_4x2->setPlainText(QString::number(matrix_1[3][1] + matrix_2[3][1]));
    ui->num3_4x3->setPlainText(QString::number(matrix_1[3][2] + matrix_2[3][2]));
    ui->num3_4x4->setPlainText(QString::number(matrix_1[3][3] + matrix_2[3][3]));
}

void MainWindow::subtract()
{
    update_matrices();
    ui->num3_1x1->setPlainText(QString::number(matrix_1[0][0] - matrix_2[0][0]));
    ui->num3_1x2->setPlainText(QString::number(matrix_1[0][1] - matrix_2[0][1]));
    ui->num3_1x3->setPlainText(QString::number(matrix_1[0][2] - matrix_2[0][2]));
    ui->num3_1x4->setPlainText(QString::number(matrix_1[0][3] - matrix_2[0][3]));
    ui->num3_2x1->setPlainText(QString::number(matrix_1[1][0] - matrix_2[1][0]));
    ui->num3_2x2->setPlainText(QString::number(matrix_1[1][1] - matrix_2[1][1]));
    ui->num3_2x3->setPlainText(QString::number(matrix_1[1][2] - matrix_2[1][2]));
    ui->num3_2x4->setPlainText(QString::number(matrix_1[1][3] - matrix_2[1][3]));
    ui->num3_3x1->setPlainText(QString::number(matrix_1[2][0] - matrix_2[2][0]));
    ui->num3_3x2->setPlainText(QString::number(matrix_1[2][1] - matrix_2[2][1]));
    ui->num3_3x3->setPlainText(QString::number(matrix_1[2][2] - matrix_2[2][2]));
    ui->num3_3x4->setPlainText(QString::number(matrix_1[2][3] - matrix_2[2][3]));
    ui->num3_4x1->setPlainText(QString::number(matrix_1[3][0] - matrix_2[3][0]));
    ui->num3_4x2->setPlainText(QString::number(matrix_1[3][1] - matrix_2[3][1]));
    ui->num3_4x3->setPlainText(QString::number(matrix_1[3][2] - matrix_2[3][2]));
    ui->num3_4x4->setPlainText(QString::number(matrix_1[3][3] - matrix_2[3][3]));
}

void MainWindow::multiply()
{
    update_matrices();
    for (int i = 0; i < dimFlag; i++)
    {
        for (int j = 0; j < dimFlag; j++)
        {
            matrix_3[i][j] = 0;
            for (int k = 0; k < dimFlag; k++)
            {
                matrix_3[i][j] += matrix_1[i][k] * matrix_2[k][j];
            }
        }
    }
    ui->num3_1x1->setPlainText(QString::number(matrix_3[0][0]));
    ui->num3_1x2->setPlainText(QString::number(matrix_3[0][1]));
    ui->num3_1x3->setPlainText(QString::number(matrix_3[0][2]));
    ui->num3_1x4->setPlainText(QString::number(matrix_3[0][3]));
    ui->num3_2x1->setPlainText(QString::number(matrix_3[1][0]));
    ui->num3_2x2->setPlainText(QString::number(matrix_3[1][1]));
    ui->num3_2x3->setPlainText(QString::number(matrix_3[1][2]));
    ui->num3_2x4->setPlainText(QString::number(matrix_3[1][3]));
    ui->num3_3x1->setPlainText(QString::number(matrix_3[2][0]));
    ui->num3_3x2->setPlainText(QString::number(matrix_3[2][1]));
    ui->num3_3x3->setPlainText(QString::number(matrix_3[2][2]));
    ui->num3_3x4->setPlainText(QString::number(matrix_3[2][3]));
    ui->num3_4x1->setPlainText(QString::number(matrix_3[3][0]));
    ui->num3_4x2->setPlainText(QString::number(matrix_3[3][1]));
    ui->num3_4x3->setPlainText(QString::number(matrix_3[3][2]));
    ui->num3_4x4->setPlainText(QString::number(matrix_3[3][3]));
}

void MainWindow::on_pushDet_clicked()
{
    hide_right();

    ui->lcdNumber->show();
    hide_binary();

    MainWindow::modeFlag = 1;
}

void MainWindow::on_pushInv_clicked()
{
    show_right();

    ui->lcdNumber->hide();
    hide_binary();

    if (dimFlag != 4)
    {
        hide_4x4();
    }
    if (dimFlag == 2)
    {
        hide_3x3();
    }

    MainWindow::modeFlag = 2;
}

void MainWindow::on_pushTrs_clicked()
{
    show_right();

    ui->lcdNumber->hide();
    hide_binary();

    if (dimFlag != 4)
    {
        hide_4x4();
    }
    if (dimFlag == 2)
    {
        hide_3x3();
    }


    MainWindow::modeFlag = 3;
}

void MainWindow::on_pushClear_clicked()
{
    ui->num2_1x1->clear();
    ui->num2_1x2->clear();
    ui->num2_1x3->clear();
    ui->num2_1x4->clear();
    ui->num2_2x1->clear();
    ui->num2_2x2->clear();
    ui->num2_2x3->clear();
    ui->num2_2x4->clear();
    ui->num2_3x1->clear();
    ui->num2_3x2->clear();
    ui->num2_3x3->clear();
    ui->num2_3x4->clear();
    ui->num2_4x1->clear();
    ui->num2_4x2->clear();
    ui->num2_4x3->clear();
    ui->num2_4x4->clear();

    ui->num_1x1->clear();
    ui->num_1x2->clear();
    ui->num_1x3->clear();
    ui->num_1x4->clear();
    ui->num_2x1->clear();
    ui->num_2x2->clear();
    ui->num_2x3->clear();
    ui->num_2x4->clear();
    ui->num_3x1->clear();
    ui->num_3x2->clear();
    ui->num_3x3->clear();
    ui->num_3x4->clear();
    ui->num_4x1->clear();
    ui->num_4x2->clear();
    ui->num_4x3->clear();
    ui->num_4x4->clear();

    ui->num3_1x1->clear();
    ui->num3_1x2->clear();
    ui->num3_1x3->clear();
    ui->num3_1x4->clear();
    ui->num3_2x1->clear();
    ui->num3_2x2->clear();
    ui->num3_2x3->clear();
    ui->num3_2x4->clear();
    ui->num3_3x1->clear();
    ui->num3_3x2->clear();
    ui->num3_3x3->clear();
    ui->num3_3x4->clear();
    ui->num3_4x1->clear();
    ui->num3_4x2->clear();
    ui->num3_4x3->clear();
    ui->num3_4x4->clear();

    ui->lcdNumber->display(0);
}

void MainWindow::on_pushAdd_clicked()
{
    show_binary();
    ui->lcdNumber->hide();
    modeFlag = 4;
}


void MainWindow::on_pushSub_clicked()
{
    show_binary();
    ui->lcdNumber->hide();
    modeFlag = 5;
}


void MainWindow::on_pushMul_clicked()
{
    show_binary();
    ui->lcdNumber->hide();
    modeFlag = 6;
}




