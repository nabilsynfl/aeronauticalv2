#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menghitungatmosferisa.h"
#include "kecepatangravitasi.h"
#include "perhitunganangkatpesawat.h"
#include "perhitungantarikpesawat.h"

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
    MenghitungAtmosferISA menghitung;
    menghitung.setModal(true);
    menghitung.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    KecepatanGravitasi kecgravitasi;
    kecgravitasi.setModal(true);
    kecgravitasi.exec();
}


void MainWindow::on_pushButton_3_clicked()
{
    PerhitunganAngkatPesawat angkatPesawat;
    angkatPesawat.setModal(true);
    angkatPesawat.exec();
}


void MainWindow::on_pushButton_4_clicked()
{
    PerhitunganTarikPesawat tarikPesawat;
    tarikPesawat.setModal(true);
    tarikPesawat.exec();
}

