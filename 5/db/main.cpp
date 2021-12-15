#include "mainwindow.h"

#include <QApplication>
#include <QtSql>

int main(int argc, char *argv[])
{
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName(":memory:");
    sdb.open();
    sdb.exec("Create table user(user_id INTEGER PRIMARY KEY AUTOINCREMENT, name varchar(50), phone varchar(15))");
    sdb.exec("Create table call_u ( \
        from_user INTEGER REFERENCES user(user_id), \
        to_user INTEGER REFERENCES user(user_id), \
        PRIMARY KEY (from_user, to_user))");
    sdb.exec("INSERT INTO user(user_id, name, phone) \
                    VALUES(1, 'Ivan', '+123'),\
                          (2, 'Gleb', '+345'),\
                          (3, 'Alex', '+678');");
    sdb.exec("INSERT INTO call_u(from_user, to_user)\
                    VALUES (1, 2), (2, 3), (3, 1), (1, 3);");


    QApplication a(argc, argv);
    MainWindow w(sdb);
    w.show();
    return a.exec();
}
