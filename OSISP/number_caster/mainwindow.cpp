#include "mainwindow.h"
#include "numberitem.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QSizePolicy>
#include <QSpinBox>
#include <QString>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createItem(10);
    createItem(2);
    createItem(16);
    setNum(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setNum(quint64 num)
{
    if (num < min){
        currentNum = min;
    } else if (num > max) {
        currentNum = max;
    } else {
        currentNum = num;
    }
    emit numSet(currentNum);
}

void MainWindow::createItem(int base)
{
    auto parent = new QWidget;
    parent->setLayout(new QHBoxLayout);

    auto spinBox = new QSpinBox(parent);
    auto textArea = new QTextEdit(parent);
    auto closeButton = new QPushButton(parent);

    parent->layout()->addWidget(spinBox);
    parent->layout()->addWidget(textArea);
    parent->layout()->addWidget(closeButton);
    ui->verticalLayout->addWidget(parent);

    spinBox->setValue(base);
    spinBox->setMinimum(2);
    spinBox->setMaximum(16);
    spinBox->setMinimumSize(100, 100);

    auto font = textArea->font();
    font.setPointSize(30);
    font.setFamily("Consolas");
    textArea->setFont(font);
    spinBox->setFont(font);

    auto setTextLambda = [this, textArea, spinBox](){
        textArea->setText(currentNumToString(spinBox->value()));
    };

    setTextLambda();

    connect(this, &MainWindow::numSet, parent, setTextLambda);

    connect(spinBox, &QSpinBox::valueChanged, parent, setTextLambda);

    connect(textArea, &QTextEdit::textChanged, parent, [this, textArea, spinBox](){
        auto string = textArea->toPlainText();
        if (string.isEmpty()){
            textArea->blockSignals(true);
            setNum(min);
            textArea->blockSignals(false);
        }
        bool isOK = false;
        auto value = string.toULongLong(&isOK, spinBox->value());
        if (isOK){
            textArea->blockSignals(true);
            setNum(value);
            textArea->blockSignals(false);
        } else {
            textArea->undo();
        }
        textArea->moveCursor(QTextCursor::EndOfLine);
    });

    connect(closeButton, &QPushButton::clicked, parent, [parent](){
        delete parent;
    });
}

QString MainWindow::currentNumToString(quint64 base)
{
    return numToString(currentNum, base);
}

QString MainWindow::numToString(quint64 num, int base)
{
    return QString::number(num, base).toUpper();
}


void MainWindow::on_pushButton_clicked()
{
    if (this->ui->verticalLayout->count() < 6){
        createItem(10);
    }
}

