#include "kecepatangravitasi.h"
#include "ui_kecepatangravitasi.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

KecepatanGravitasi::KecepatanGravitasi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KecepatanGravitasi)
{
    ui->setupUi(this);
}

KecepatanGravitasi::~KecepatanGravitasi()
{
    delete ui;
}



void KecepatanGravitasi::on_hitung_clicked()
{
    #define PT 3.14159

    float phirad, G, Me, Re, ohme, g;
    QString str1, str2;
    str1 = ui->tinggiTerbang->text();
    double h = str1.toFloat();
    str2 = ui->sudutLintang->text();
    double phideg = str1.toFloat();

    G = 6.67e-11;
    Me = 5.98e24;
    Re = 6371000;
    ohme = 7.29e-5;




    phirad = phideg / 180 * PT;
    g = G*Me/((Re+h) * (Re+h));
    g = g - ohme*ohme*(Re+h)*cos(phirad)*cos(phirad);

    ui->tinggiTerbangHasil->setText(QString::number(h) + "(m)");
}




void KecepatanGravitasi::on_pushButton_clicked()
{
    #define PT 3.14159

    float phirad, G, Me, Re, ohme, g;
    QString str1, str2;
    str1 = ui->tinggiTerbang->text();
    double h = str1.toFloat();
    str2 = ui->sudutLintang->text();
    double phideg = str2.toFloat();

    G = 6.67e-11;
    Me = 5.98e24;
    Re = 6371000;
    ohme = 7.29e-5;




    phirad = phideg / 180 * PT;
    g = G*Me/((Re+h) * (Re+h));
    g = g - ohme*ohme*(Re+h)*cos(phirad)*cos(phirad);

    ui->tinggiTerbangHasil->setText(QString::number(h) + "(n)");
    ui->posisiLintang->setText(QString::number(phideg) + "(deg)");
    ui->kecGravitasi->setText(QString::number(g) + "(n/s^2)");
}

