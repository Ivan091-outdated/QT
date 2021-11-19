#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QFontDialog>
#include <QSettings>
#include <QTextEdit>
#include <Qt>
#include <QFileDialog>

MainWindow::MainWindow(const QString &fileName, QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadFile(fileName);

    QSettings settings;

    auto font = settings.value("viewFont", QApplication::font()).value<QFont>();
    ui->textEdit->setFont(font);

    connect(ui->actionClose, &QAction::triggered, this, &QMainWindow::close);
    connect(ui->actionExit, &QAction::triggered, &QApplication::closeAllWindows);
    connect(ui->textEdit, &QTextEdit::textChanged, [this](){this->setWindowModified(true);});

    connect(ui->actionAboutQT, &QAction::triggered, &QApplication::aboutQt);

    connect(ui->actionCut, &QAction::triggered, ui->textEdit, &QTextEdit::cut);
    connect(ui->actionCopy, &QAction::triggered, ui->textEdit, &QTextEdit::copy);
    connect(ui->actionPaste, &QAction::triggered, ui->textEdit, &QTextEdit::paste);
    connect(ui->actionUndo, &QAction::triggered, ui->textEdit, &QTextEdit::undo);
    connect(ui->actionRedo, &QAction::triggered, ui->textEdit, &QTextEdit::redo);

    ui->actionCut->setEnabled(false);
    ui->actionCopy->setEnabled(false);
    ui->actionUndo->setEnabled(false);
    ui->actionRedo->setEnabled(false);

    connect(ui->textEdit, &QTextEdit::copyAvailable, ui->actionCut, &QAction::setEnabled);
    connect(ui->textEdit, &QTextEdit::copyAvailable, ui->actionCopy, &QAction::setEnabled);
    connect(ui->textEdit, &QTextEdit::undoAvailable, ui->actionUndo, &QAction::setEnabled);
    connect(ui->textEdit, &QTextEdit::redoAvailable, ui->actionRedo, &QAction::setEnabled);

    connect(ui->actionSaveAs, &QAction::triggered, this, &MainWindow::saveFileAs);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::saveFile);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (this->isWindowModified()){
        auto button = QMessageBox::warning(this, "Document Modified",
                                           "The document has been modified. "
                                           "Do you want to save your changes?\n"
                                           "You will lose and unsaved changes.",
                                           QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
                                           QMessageBox::Cancel);
        switch(button){
            case QMessageBox::Yes:
                if (saveFile()){
                    event->accept();
                } else {
                    event->ignore();
                }
                break;
            case QMessageBox::No:
                event->accept();
                break;
            case QMessageBox::Cancel:
                event->ignore();
                break;
            default:
                event->ignore();
        }

    } else {
        event->accept();
    }
}


void MainWindow::on_actionNew_triggered()
{
    auto editor = new MainWindow;
    editor->show();
}


void MainWindow::on_actionSelectFont_triggered()
{
    bool isOk;
    auto font = QFontDialog::getFont(&isOk, ui->textEdit->font(), this);
    if (isOk){
        QSettings settings;
        settings.setValue("viewFont", font);
        ui->textEdit->setFont(font);
    }
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "about", "about");
}

void MainWindow::loadFile(const QString &fileName){
    if (fileName.isEmpty()){
        setFileName(QString());
        return;
    }

    QFile file(fileName);

    auto isOpen = file.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!isOpen){
        QMessageBox::warning(this, "File error", "The file is not opened");
        setFileName(QString());
        return;
    }

    ui->textEdit->setText(file.readAll());

    file.close();
    setFileName(fileName);
    setWindowModified(false);
}

void MainWindow::setFileName(const QString &fileName)
{
    auto title = QString("%1[*] - %2")
            .arg(fileName.isEmpty()?"untitled":QFileInfo(fileName).fileName(), QApplication::applicationName());
    this->setWindowTitle(title);
    this->fileName = fileName;
}


void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        "Open document", QDir::currentPath());
    if (!fileName.isEmpty() && !isWindowModified()){
        loadFile(fileName);
    } else {
        auto editor = new MainWindow(fileName);
        editor->show();
    }
}

bool MainWindow::saveFile()
{
    if (fileName.isEmpty()){
        return saveFileAs();
    }
    QFile file(fileName);
    auto isOpen = file.open(QIODevice::WriteOnly | QIODevice::Text);
    if (!isOpen){
        QMessageBox::warning(this, "File error", "The file is not opened");
        setFileName(QString());
        return false;
    }

    file.write(ui->textEdit->toPlainText().toUtf8());

    file.close();
    setWindowModified(false);
    return true;
}

bool MainWindow::saveFileAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save document",
       this->fileName.isEmpty()?QDir::currentPath():this->fileName);
    if (fileName.isEmpty()){
        return false;
    }
    setFileName(fileName);
    return saveFile();
}

