#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

#include <QFontDialog>
#include <QFont>
#include <QColorDialog>
#include <QColor>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNovo_triggered()
{
    file_place = "";
    ui->textEdit->clear();
    ui->textEdit->setFocus();
}

void MainWindow::on_actionAbrir_triggered()
{
    QString fileFilter = "Todos Arquivos (*.*) ;; Arquivos de Texto (*.txt)";
    QString fileName = QFileDialog::getOpenFileName(this, "Abrir", QDir::homePath(), fileFilter);
    QFile file(fileName);
    file_place = fileName;
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "", "Arquivo não pôde ser aberto");
        return;
    }

    QTextStream input(&file);
    QString text = input.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::on_actionSalvar_Novo_triggered()
{
    QString fileFilter = "Todos Arquivos (*.*) ;; Arquivos de Texto (*.txt)";
    QString fileName = QFileDialog::getSaveFileName(this, "Salvar Como", QDir::homePath(), fileFilter);
    QFile file(fileName);
    file_place = fileName;
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "", "Arquivo não pôde ser salvo");
        return;
    }

    QTextStream output(&file);
    QString text = ui->textEdit->toPlainText();
    output << text;
    file.flush();
    file.close();
}


void MainWindow::on_actionSlavar_triggered()
{
    QFile file(file_place);
    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "", "Arquivo não pôde ser salvo");
        return;
    }

    QTextStream output(&file);
    QString text = ui->textEdit->toPlainText();
    output << text;
    file.flush();
    file.close();
}


void MainWindow::on_actionFechar_triggered()
{
    close();
}


void MainWindow::on_actionCopiar_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionRecortar_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionColar_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionDesfazer_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionFonte_triggered()
{
    bool font_ok;
    QFont fonte = QFontDialog::getFont(&font_ok, this);
    if (font_ok) {
        ui->textEdit->setFont(fonte);
    } else {
        return;
    }
}


void MainWindow::on_actionCor_triggered()
{
    QColor cor = QColorDialog::getColor(Qt::black, this, "Escolha uma Cor");
    if (cor.isValid()) {
        ui->textEdit->setTextColor(cor);
    }
}


void MainWindow::on_actionCor_do_Fundo_triggered()
{
    QColor cor = QColorDialog::getColor(Qt::black, this, "Escolha uma Cor");
    if (cor.isValid()) {
        ui->textEdit->setTextBackgroundColor(cor);
    }
}


void MainWindow::on_actionImprimir_triggered()
{

}

