#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QSqlDatabase db, QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_table_users_cellClicked(int row, int column);

private:
    QSqlDatabase db;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
