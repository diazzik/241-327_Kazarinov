#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "restadapter.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonGetList_clicked();

    void on_pushButtonGetOne_clicked();

    void on_pushButtonCreate_clicked();

    void on_pushButtonUpdate_clicked();

    void on_pushButtonDelete_clicked();

private:
    Ui::MainWindow *ui;

    RestAdapter adapter;
};

#endif
