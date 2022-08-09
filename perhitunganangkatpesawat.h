#ifndef PERHITUNGANANGKATPESAWAT_H
#define PERHITUNGANANGKATPESAWAT_H

#include <QDialog>

namespace Ui {
class PerhitunganAngkatPesawat;
}

class PerhitunganAngkatPesawat : public QDialog
{
    Q_OBJECT

public:
    explicit PerhitunganAngkatPesawat(QWidget *parent = nullptr);
    ~PerhitunganAngkatPesawat();

private slots:
    void on_hitung_clicked();

private:
    Ui::PerhitunganAngkatPesawat *ui;
};

#endif // PERHITUNGANANGKATPESAWAT_H
