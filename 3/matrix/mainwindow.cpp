#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRandomGenerator64>
#include <QAbstractButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createTable();
    fillTableRandomly();
    highlightTable(3);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(ui->pushButton, &QAbstractButton::pressed, this, &MainWindow::fillTableRandomly);
    connect(ui->pushButton, &QAbstractButton::pressed, [this](){this->highlightTable(3);});
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::updateNumbersFound(int newCount)
{
    ui->label->setText("Found: " + QString::number(newCount));
}

bool MainWindow::isPowOfN(int x, int n){
    while (x % n == 0 && x != 0) {
        x /= n;
    }
    return x == 1;
}

void MainWindow::highlightTable(int n)
{
    auto numbersFound = 0;
    auto model = ui->tableWidget->model();
    auto width = model->columnCount();
    auto heigth = model->columnCount();
    for (auto i = 0; i < heigth; i++){
        for (auto j = 0; j < width; j++){
            auto index = model->index(i, j);
            auto value = index.data().toInt();
            if (isPowOfN(value, n)){
                numbersFound++;
                ui->tableWidget->item(i, j)->setBackground(Qt::lightGray);
            } else {
                ui->tableWidget->item(i, j)->setBackground(Qt::white);
            }
        }
    }
    updateNumbersFound(numbersFound);
}

void MainWindow::createTable()
{
    auto model = ui->tableWidget->model();
    auto width = model->columnCount();
    auto heigth = model->columnCount();
    for (auto i = 0; i < heigth; i++){
        for (auto j = 0; j < width; j++){
            QTableWidgetItem *item=new QTableWidgetItem;
            ui->tableWidget->setItem(i, j, item);
        }
    }
}

void MainWindow::fillTableRandomly()
{
    auto model = ui->tableWidget->model();
    auto width = model->columnCount();
    auto heigth = model->columnCount();
    auto rand = QRandomGenerator::securelySeeded();
    for (auto i = 0; i < heigth; i++){
        for (auto j = 0; j < width; j++){
            ui->tableWidget->item(i, j)->setData(0, rand.bounded(1, 99));
        }
    }
}



