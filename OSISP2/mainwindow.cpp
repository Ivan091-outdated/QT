#include "mainwindow.h"
#include "ui_mainwindow.h"
int PLAYER = 1;
int STEP = 0;
bool INDEX = 0;

#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QLibrary>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStandardItemModel(8,8, this);
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->resizeColumnsToContents();

    ui->pl1->setText(QString::number(psc1->getScore()));
    ui->pl2->setText(QString::number(psc2->getScore()));

    qsrand(time(NULL));

    int arr[8][8] = {
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
    };

    for(int i = 0; i < 8; i++)
    {
        QVector<int> tempVector;
        for(int j = 0; j < 8; j++)
        {
            tempVector.push_back(arr[i][j]);
        }
        vector.push_back(tempVector);
    }

    //Шрифты

    fonts.push_back("Arial");
    fonts.push_back("Comic Sans MS");
    fonts.push_back("Impact");
    fonts.push_back("Verdana");
;}


bool MainWindow::checker()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(vector[i][j] != 0) continue;
            else if((i == 0) && (j == 0))
            {
                if((vector[i+1][j] == 0) || (vector[i][j+1] == 0))
                   return true;
            }
            else if((i == 7) && (j == 0))
            {
                if((vector[i][j+1] == 0) || (vector[i-1][j] == 0))
                    return true;
            }
            else if((i == 7) && (j == 7))
            {
                if((vector[i-1][j] == 0) || (vector[i][j-1] == 0))
                    return true;
            }
            else if((i == 0) && (j == 7))
            {
                if((vector[i+1][j] == 0) || (vector[i][j-1] == 0))
                    return true;
            }
            else if(i == 0)
            {
                if((vector[i+1][j] == 0) || (vector[i][j+1] == 0) || (vector[i][j-1] == 0))
                    return true;
            }
            else if(i == 7)
            {
                if((vector[i][j+1] == 0) || (vector[i-1][j] == 0) || (vector[i][j-1] == 0))
                    return true;
            }
            else if(j == 0)
            {
                if((vector[i+1][j] == 0) || (vector[i][j+1] == 0) || (vector[i-1][j] == 0))
                    return true;
            }
            else if(j == 7)
            {
                if((vector[i+1][j] == 0) || (vector[i-1][j] == 0) || (vector[i][j-1] == 0))
                    return true;
            }
            else
            {
                if((vector[i+1][j] == 0) || (vector[i][j+1] == 0) || (vector[i-1][j] == 0) || (vector[i][j-1] == 0))
                    return true;
            }
        }
    }

    return false;

}

void MainWindow::player1(QModelIndex index)
{
    if(checker())
    {

        if(vector[index.row()][index.column()] == 0)
        {
            model->setData(index, QColor(Qt::red), Qt::BackgroundRole);
            vector[index.row()][index.column()] = 1;
        }
    }
    else
    {
        QMessageBox msg;
        msg.setText("Player 1 lose");
        msg.exec();
        ui->pl2->setText(QString::number(psc2->plusScore()));
        PLAYER = 1;
        STEP = 0;
    }

}


void MainWindow::player2()
{
    if(checker())
    {

        int row = qrand() % 8 ;
        int col = qrand() % 8 ;

        if(vector[row][col] != 0)
        {
           player2();
        }
        else if((row != 0) && (row != 7) && (vector[row+1][col] == 0))
        {
            QModelIndex index;
            index = model->index(row,col);
            model->setData(index, QColor(Qt::green), Qt::BackgroundRole);
            index = model->index(row+1,col);
            model->setData(index, QColor(Qt::green), Qt::BackgroundRole);
            try
            {
                vector[row][col] = 2;
                vector[row+1][col] = 2;
            } catch (...)
            {
                index = model->index(row,col);
                model->setData(index, QColor(Qt::white), Qt::BackgroundRole);
                player2();

            }
            return;
        }
        else if((row != 0) && (row != 7) && (vector[row-1][col] == 0))
        {
            QModelIndex index;
            index = model->index(row,col);
            model->setData(index, QColor(Qt::green), Qt::BackgroundRole);
            index = model->index(row-1,col);
            model->setData(index, QColor(Qt::green), Qt::BackgroundRole);
            try
            {
                vector[row][col] = 2;
                vector[row-1][col] = 2;
            }
            catch (...)
            {
                index = model->index(row,col);
                model->setData(index, QColor(Qt::white), Qt::BackgroundRole);
                player2();
            }
            vector[row][col] = 2;
            vector[row-1][col] = 2;
            return;
        }

        else if((col != 0) && (col != 7) && (vector[row][col+1] == 0))
        {
            QModelIndex index;
            index = model->index(row,col);
            model->setData(index, QColor(Qt::green), Qt::BackgroundRole);
            index = model->index(row,col+1);
            model->setData(index, QColor(Qt::green), Qt::BackgroundRole);
            try
            {
                vector[row][col] = 2;
                vector[row][col+1] = 2;
            }
            catch (...)
            {
                index = model->index(row,col);
                model->setData(index, QColor(Qt::white), Qt::BackgroundRole);
                player2();

            }

            return;

        }

        else if((col != 0) && (col != 7) && (vector[row][col-1] == 0))
        {
            QModelIndex index;
            index = model->index(row,col);
            model->setData(index, QColor(Qt::green), Qt::BackgroundRole);
            index = model->index(row,col-1);
            model->setData(index, QColor(Qt::green), Qt::BackgroundRole);
            try
            {
                vector[row][col] = 2;
                vector[row][col-1] = 2;
            }
            catch (...)
            {
                index = model->index(row,col);
                model->setData(index, QColor(Qt::white), Qt::BackgroundRole);
                player2();

            }

            return;
        }
        else
        {
            player2();

        }
    }

    else
    {
        ui->pl1->setText(QString::number(psc1->plusScore()));
        QMessageBox msg;
        msg.setText("Player 2 lose");
        msg.exec();

        PLAYER = 1;
        STEP = 0;
    }
}

void MainWindow::controller(QModelIndex index)
{
    if(STEP == 0)
    {
        STEP = 1;
        player1(index);
    }
    else if(STEP == 1)
    {
        STEP = 0;
        player1(index);
        player2();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    static const QString LIB_NAME = "helper.dll";

    QLibrary lib( LIB_NAME );

    if(lib.load() ) {

        typedef void ( *NewG )( );       // можно вверх

        NewG new_game = ( NewG ) lib.resolve( "new_game" );

        new_game();
    }

    QModelIndex index;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            index = model->index(i,j);
            model->setData(index, QColor(Qt::white), Qt::BackgroundRole);
            vector[i][j] = 0;

        }
    }
}


void MainWindow::on_pushButton_2_clicked()
{
        static const QString LIB_NAME = "helper.dll";

        QLibrary lib( LIB_NAME );

        if(lib.load() ) {

            typedef void ( *Exit )( );       // можно вверх

            Exit exit_game = ( Exit ) lib.resolve( "exit_game" );

            exit_game();
        }

}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    if(vector[index.row()][index.column()] != 0) return;
        else if(INDEX == 0)
        {
            firstIndex = index;
            controller(index);
            INDEX = 1;
        }
        else if(INDEX == 1)
        {
            if(index.row() == firstIndex.row())
            {
                if((index.column() == (firstIndex.column() + 1)) || (index.column() == (firstIndex.column()-1)))
                {
                    INDEX = 0;
                    controller(index);
                }
                else
                {
                    INDEX = 0;
                    vector[firstIndex.row()][firstIndex.column()] = 0;
                    model->setData(firstIndex, QColor(Qt::white), Qt::BackgroundRole);
                    STEP = 0;
                    return;
                }
            }
            else if(index.column() == firstIndex.column())
            {
                if((index.row() == (firstIndex.row() + 1)) || (index.row() == (firstIndex.row()-1)))
                {
                    INDEX = 0;
                    controller(index);
                }
                else
                {
                    INDEX = 0;
                    vector[firstIndex.row()][firstIndex.column()] = 0;
                    model->setData(firstIndex, QColor(Qt::white), Qt::BackgroundRole);
                    STEP = 0;
                    return;
                }
            }
            else
            {
                INDEX = 0;
                vector[firstIndex.row()][firstIndex.column()] = 0;
                model->setData(firstIndex, QColor(Qt::white), Qt::BackgroundRole);
                STEP = 0;
                return;
            }
        }
}

void MainWindow::on_about_btn_clicked()
{
    about();
}

void MainWindow::on_newStyle_clicked()
{
    QFont f;
    f.setBold(true);
    f.setFamily(fonts[i]);
    f.setPointSize(8);

    ui->pushButton->setFont(f);
    ui->pushButton_2->setFont(f);
    ui->newStyle->setFont(f);
    ui->about_btn->setFont(f);
    if(i == 3) i = 0;
    else i++;
}
