#ifndef PERHITUNGANTARIKPESAWAT_H
#define PERHITUNGANTARIKPESAWAT_H

#include <QDialog>

namespace Ui {
class PerhitunganTarikPesawat;
}

class PerhitunganTarikPesawat : public QDialog
{
    Q_OBJECT

public:
    explicit PerhitunganTarikPesawat(QWidget *parent = nullptr);
    ~PerhitunganTarikPesawat();

private slots:
    void on_pushButton_clicked();

private:
    Ui::PerhitunganTarikPesawat *ui;
};

#endif // PERHITUNGANTARIKPESAWAT_H
