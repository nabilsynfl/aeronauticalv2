#include "menghitungatmosferisa.h"
#include "ui_menghitungatmosferisa.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

MenghitungAtmosferISA::MenghitungAtmosferISA(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenghitungAtmosferISA)
{
    ui->setupUi(this);
}

MenghitungAtmosferISA::~MenghitungAtmosferISA()
{
    delete ui;
}

void MenghitungAtmosferISA::on_hitung_clicked()
{
        float T, P, rho, li, Ti, rhoi, Pi, Hi;
        float R = 29.271; // in m/k
        char NamaLapisan[32];
        QString strH = ui->tinggiTerbang->text();
        double h = strH.toFloat();


        if ((0 <= h) & (h <= 11000))
        {
            Hi = 0;
            li = -0.0065;
            Ti = 288.15;
            rhoi = 1.2250;
            Pi = 101325;
            strcpy(NamaLapisan, "Troposphere");
        }

        if ((11000 <= h) & (h <= 20000))
        {
            Hi = 11000;
            li = 0;
            Ti = 216.65;
            rhoi = 0.3639;
            Pi = 22632;
            strcpy(NamaLapisan, "Stratosphere Bottom");
        }

        if ((20000 <= h) & (h <= 32000))
        {
            Hi = 20000;
            li = 0.0010;
            Ti = 216.65;
            rhoi = 0.0880;
            Pi = 5475;
            strcpy(NamaLapisan, "Stratosphere Mid");
        }

        if ((32000 <= h) & (h <= 47000))
        {
            Hi = 32000;
            li = 0.0028;
            Ti = 228.65;
            rhoi = 0.0132;
            Pi = 868;
            strcpy(NamaLapisan, "Strtosphere Top");
        }

        if ((47000 <= h) & (h <= 51000))
        {
            Hi = 47000;
            li = 0;
            Ti = 270.65;
            rhoi = 0.0014;
            Pi = 110.90;
            strcpy(NamaLapisan, "Stratopause");
        }

        if ((51000 <= h) & (h <= 71000))
        {
            Hi = 51000;
            li = -0.0028;
            Ti = 270.65;
            rhoi = 0.00084;
            Pi = 66.90;
            strcpy(NamaLapisan, "Mesosphere bottom");
        }

        if ((71000 <= h) & (h <= 80000))
        {
            Hi = 71000;
            li = -0.0020;
            Ti = 214.65;
            rhoi = 0.00006;
            Pi = 3.95;
            strcpy(NamaLapisan, "Mesosphere top");
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

        ui->tinggiTerbangHasil->setText(QString::number(h) + "(n)");
        ui->temperaturUdara->setText(QString::number(T) + "(K)");
        ui->tekananUdara->setText(QString::number(P) + "(Pa)");
        ui->kepadatanUdara->setText(QString::number(rho) + "(kg/m^3)");
        ui->namaLapisan->setText(NamaLapisan);

}

