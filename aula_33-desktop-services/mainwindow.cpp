#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString link = "https://encontreiJesus.com";
    QDesktopServices::openUrl(link);
}


void MainWindow::on_pushButton_2_clicked()
{
    QString fileApp = "/usr/bin/mousepad";
    QDesktopServices::openUrl(fileApp);
}

