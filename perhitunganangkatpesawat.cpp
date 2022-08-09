#include "perhitunganangkatpesawat.h"
#include "ui_perhitunganangkatpesawat.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

PerhitunganAngkatPesawat::PerhitunganAngkatPesawat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PerhitunganAngkatPesawat)
{
    ui->setupUi(this);
}

PerhitunganAngkatPesawat::~PerhitunganAngkatPesawat()
{
    delete ui;
}

float CalculateISA(float h, int outParam){
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

void PerhitunganAngkatPesawat::on_hitung_clicked()
{
        float rho, L;
        QString strH, strV, strCL, strS;
        strH = ui->tinggiTerbang->text();
        strV = ui->kecTerbang->text();
        strS = ui->areaSayap->text();
        strCL = ui->kofLift->text();
        float h, v, s, CL;
        h = strH.toFloat();
        v = strV.toFloat();
        s = strS.toFloat();
        CL = strCL.toFloat();


        rho = CalculateISA(h, 2);
        L = 0.5 * rho * v*v *s * CL;

        ui->lift->setText(QString::number(L) + "(N)\n");

}

