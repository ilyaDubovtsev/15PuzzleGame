#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "form.h"
#include "ui_form.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_4_clicked() // Выход.
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Exit", "Do you really want to leave the game?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        close();
    }
}

void MainWindow::on_pushButton_clicked() // Старт.
{
    Form *f = new Form();
    f->show();
    this->close();
}

