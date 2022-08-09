#ifndef KECEPATANGRAVITASI_H
#define KECEPATANGRAVITASI_H

#include <QDialog>

namespace Ui {
class KecepatanGravitasi;
}

class KecepatanGravitasi : public QDialog
{
    Q_OBJECT

public:
    explicit KecepatanGravitasi(QWidget *parent = nullptr);
    ~KecepatanGravitasi();

private slots:
    void on_pushButton_clicked();

    void on_hitung_clicked();

private:
    Ui::KecepatanGravitasi *ui;
};

#endif // KECEPATANGRAVITASI_H
