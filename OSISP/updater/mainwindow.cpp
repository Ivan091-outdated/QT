#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    auto basePath =  qApp->applicationDirPath() + "/../../lib/";
    QFile::rename(basePath + "num_lib.dll", basePath + "num_lib_new1.dll");
    QFile::rename(basePath + "num_lib_new.dll", basePath + "num_lib.dll");
    QFile::rename(basePath + "num_lib_new1.dll", basePath + "num_lib_new.dll");

    MainWindow::close();
}
