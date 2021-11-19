#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;

    void updateNumbersFound(int newCount);

    bool isPowOfN(int x, int n);

    void highlightTable(int n);

    void createTable();

private slots:
    void fillTableRandomly();
};
#endif // MAINWINDOW_H
