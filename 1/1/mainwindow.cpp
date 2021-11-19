#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPalette>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QSlider>
#include <QSpinBox>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_spinBoxRed_valueChanged(int arg1)
{
    ui->horizontalSliderRed->setValue(arg1);
    update_color();
}


void MainWindow::on_spinBoxGreen_valueChanged(int arg1)
{
    ui->horizontalSliderGreen->setValue(arg1);
    update_color();
}


void MainWindow::on_spinBoxBlue_valueChanged(int arg1)
{
    ui->horizontalSliderBlue->setValue(arg1);
    update_color();
}


void MainWindow::on_horizontalSliderRed_valueChanged(int value)
{
    ui->spinBoxRed->setValue(value);
    update_color();
}


void MainWindow::on_horizontalSliderGreen_valueChanged(int value)
{
    ui->spinBoxGreen->setValue(value);
    update_color();
}


void MainWindow::on_horizontalSliderBlue_valueChanged(int value)
{
    ui->spinBoxBlue->setValue(value);
    update_color();
}

void MainWindow::update_color(){
    auto r = ui->horizontalSliderRed->value();
    auto g = ui->horizontalSliderGreen->value();
    auto b = ui->horizontalSliderBlue->value();
    ui->plainText->setStyleSheet("QPlainTextEdit {background-color:" + QString("#%1").arg(QColor(r, g, b).rgb(), 6, 16) +";}");
}

