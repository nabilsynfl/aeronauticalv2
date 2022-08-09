#ifndef MENGHITUNGATMOSFERISA_H
#define MENGHITUNGATMOSFERISA_H

#include <QDialog>

namespace Ui {
class MenghitungAtmosferISA;
}

class MenghitungAtmosferISA : public QDialog
{
    Q_OBJECT

public:
    explicit MenghitungAtmosferISA(QWidget *parent = nullptr);
    ~MenghitungAtmosferISA();

private slots:
    void on_hitung_clicked();

private:
    Ui::MenghitungAtmosferISA *ui;
};

#endif // MENGHITUNGATMOSFERISA_H
