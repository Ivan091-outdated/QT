#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
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

private slots:
    void on_spinBoxRed_valueChanged(int arg1);

    void on_spinBoxGreen_valueChanged(int arg1);

    void on_spinBoxBlue_valueChanged(int arg1);

    void on_horizontalSliderRed_valueChanged(int value);

    void on_horizontalSliderGreen_valueChanged(int value);

    void on_horizontalSliderBlue_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    void update_color();
};
#endif // MAINWINDOW_H
