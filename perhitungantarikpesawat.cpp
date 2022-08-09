#include "perhitungantarikpesawat.h"
#include "ui_perhitungantarikpesawat.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


PerhitunganTarikPesawat::PerhitunganTarikPesawat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PerhitunganTarikPesawat)
{
    ui->setupUi(this);
}

PerhitunganTarikPesawat::~PerhitunganTarikPesawat()
{
    delete ui;
}

float CalculateISA2(float h, int outParam){
    float T, P, rho, li, Ti, rhoi, Pi, Hi;
    float R = 29.271; // in m/k

    if ((0 <= h) & (h <= 11000))
    {
        Hi = 0;
        li = -0.0065;
        Ti = 288.15;
        rhoi = 1.2250;
        Pi = 101325;
    }

    if ((11000 <= h) & (h <= 20000))
    {
        Hi = 11000;
        li = 0;
        Ti = 216.65;
        rhoi = 0.3639;
        Pi = 22632;
    }

    if ((20000 <= h) & (h <= 32000))
    {
        Hi = 20000;
        li = 0.0010;
        Ti = 216.65;
        rhoi = 0.0880;
        Pi = 5475;
    }

    if ((32000 <= h) & (h <= 47000))
    {
        Hi = 32000;
        li = 0.0028;
        Ti = 228.65;
        rhoi = 0.0132;
        Pi = 868;
    }

    if ((47000 <= h) & (h <= 51000))
    {
        Hi = 47000;
        li = 0;
        Ti = 270.65;
        rhoi = 0.0014;
        Pi = 110.90;
    }

    if ((51000 <= h) & (h <= 71000))
    {
        Hi = 51000;
        li = -0.0028;
        Ti = 270.65;
        rhoi = 0.00084;
        Pi = 66.90;
    }

    if ((71000 <= h) & (h <= 80000))
    {
        Hi = 71000;
        li = -0.0020;
        Ti = 214.65;
        rhoi = 0.00006;
        Pi = 3.95;
    }

    if (li != 0)
    {
        T = Ti * (1+li/Ti*(h - Hi));
        P = Pi * pow(1 + li/Ti * (h - Hi), -1/(R*li));
        rho = rhoi * pow(1 + li/Ti*(h-Hi), -(1+1/(R*li)));
    }
    else
    {
        T = Ti;
        P = Pi * exp(-(h-Hi)/(R*Ti));
        rho = rhoi * exp(-(h-Hi)/(R*Ti));
    }

    float fResult = 0;
    if(outParam == 0) fResult = T;
    if(outParam == 1) fResult = P;
    if(outParam == 2) fResult = rho;
    return fResult;
}

void PerhitunganTarikPesawat::on_pushButton_clicked()
{
        float h, v, s, CD, rho, D;
        QString strH, strV, strCD, strS;
        strH = ui->tinggiTerbang->text();
        strV = ui->kecTerbang->text();
        strS = ui->areaSayap->text();
        strCD = ui->kofDrag->text();

        h = strH.toFloat();
        v = strV.toFloat();
        s = strS.toFloat();
        CD = strCD.toFloat();

        float T = CalculateISA2(h, 0); //return temperature
        float P = CalculateISA2(h, 1); //return Pressure
        rho = CalculateISA2(h, 2); //return Density
        D = 0.5 * rho * v*v * s * CD;

        ui->suhuUdara->setText(QString::number(T) + "(K)\n");
        ui->tekananUdara->setText(QString::number(P) + "(Pa)\n");
        ui->kerapatanUdara->setText(QString::number(rho) + "(kg/m^3)\n");
        ui->gayaHambat->setText(QString::number(D) + "(N)\n");


}

