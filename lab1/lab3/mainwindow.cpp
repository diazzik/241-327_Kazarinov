#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&adapter,
            &RestAdapter::responseReady,
            this,
            [=](QString response)
            {
                ui->textEdit->setText(response);
            });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonGetList_clicked()
{
    adapter.getList();
}

void MainWindow::on_pushButtonGetOne_clicked()
{
    int id = ui->lineEditId->text().toInt();

    adapter.getOne(id);
}

void MainWindow::on_pushButtonCreate_clicked()
{
    adapter.createRestaurant();
}

void MainWindow::on_pushButtonUpdate_clicked()
{
    int id = ui->lineEditId->text().toInt();

    adapter.updateRestaurant(id);
}

void MainWindow::on_pushButtonDelete_clicked()
{
    int id = ui->lineEditId->text().toInt();

    adapter.deleteRestaurant(id);
}
