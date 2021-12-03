#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <QIcon>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void animate();

private:
    Ui::MainWindow *ui;
    int WinWidth = 900;
    int WinHeight = 500;
    qreal x = 0;
    qreal y = 0;
    bool moveLeft = true;

protected:
    void drawFigure(QPainter* painter, qreal x, qreal y);
    void drawText(QPainter* painter);
    void paintEvent(QPaintEvent* event);
};
#endif // MAINWINDOW_HPP
