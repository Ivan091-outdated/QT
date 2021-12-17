#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QModelIndex>
#include <QVector>
#include <time.h>
#include <QTime>
#include <QFont>
#include <QRandomGenerator>
#include "score.h"
#include "about.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void player1(QModelIndex index);
    void player2();
    void controller(QModelIndex index);
    bool checker();
    void changeStyle();
    ~MainWindow();


private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_about_btn_clicked();

    void on_newStyle_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    QVector <QVector<int>> vector;
    QVector <QString> fonts;
    QModelIndex firstIndex;
    int i = 0;

    score *psc1 = new score(0);
    score *psc2 = new score(0);
};
#endif // MAINWINDOW_H
