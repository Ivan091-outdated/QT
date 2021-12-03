#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtMath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(this->WinWidth, this->WinHeight);

    auto timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::animate);
    timer->start(1);
}

void MainWindow::animate()
{
    repaint();
}

void MainWindow::drawFigure(QPainter* painter, qreal x, qreal y)
{
    int a = 40;
    int b = 120;
    int r = 30;

    QRect MyRectangle(x - a/2, y - b, a, b);
    QRect MyEllipse(x - r, y, 2*r, 2*r);

    QPen MyRedPen(Qt::red, 4);
    painter->setPen(MyRedPen);
    painter->drawRect(MyRectangle);
    painter->drawEllipse(MyEllipse);

    QPen MyBluePen(Qt::blue, 4);
    QRect MyCenterEllipse(x - 1, y - 1, 2, 2);
    painter->setPen(MyBluePen);
    painter->drawEllipse(MyCenterEllipse);
}

void MainWindow::drawText(QPainter* painter)
{
    QPen pen(Qt::green, 5);
    painter->setPen(pen);

    QFont font ("Arial", 16, QFont::Medium);
    painter->setFont(font);

    painter->translate(20, 500);
    painter->rotate(-90);

    QString str = "Графические примитивы в библиотеке QT";
    painter->drawText(0,0, str);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    this->drawFigure(&painter,  WinWidth / 2 + x, WinHeight / 2 + y);
    this->drawText(&painter);

    y = 50 * qCos(x / 10);
    if(moveLeft)
    {
        x -= .1;
        if (x < -WinWidth / 2) {
            moveLeft = false;
        }
    }
    else
    {
        x += .1;
        if (x > WinWidth / 2) {
            moveLeft = true;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
