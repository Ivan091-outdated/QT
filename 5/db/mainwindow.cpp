#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlQuery>
#include <QSqlError>

MainWindow::MainWindow(QSqlDatabase db, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->db = db;

    ui->table_users->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->table_calls->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QSqlQuery query;
    if (!query.exec("Select * from user")) {
        qWarning() << query.lastError().text();
    } else {
        auto row = 0;
        while (query.next()){
            ui->table_users->insertRow(ui->table_users->rowCount());
            row = ui->table_users->rowCount() - 1;
            for (auto i = 0; i < 3; i++){
                ui->table_users->setItem(row, i, new QTableWidgetItem(query.value(i).toString()));
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_table_users_cellClicked(int row, int column)
{

    auto model = ui->table_users->model();
    auto index = model->index(row, 0);
    QSqlQuery query("Select user_id, name, phone from user\
                    LEFT JOIN call_u ON call_u.to_user = user.user_id\
                    WHERE from_user = ?");
    query.bindValue(0, index.data().toString());
    ui->table_calls->setRowCount(0);

    if (!query.exec()) {
        qWarning() << query.lastError().text();
    } else {
        while (query.next()){
            ui->table_calls->insertRow(0);
            for (auto i = 0; i < 3; i++){
                ui->table_calls->setItem(0, i, new QTableWidgetItem(query.value(i).toString()));
            }
        }
    }
}

