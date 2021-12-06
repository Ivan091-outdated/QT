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
    void setNum(quint64 num);

signals:
    void numSet(quint64 num);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void createItem(int base);
    QString currentNumToString(quint64 base);

    quint64 currentNum;
    quint64 min = 0;
    quint64 max = 999999999999999999u;
};
#endif // MAINWINDOW_H
