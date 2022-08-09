#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString username, password;
    username = ui->lineEdit->text();
    password = ui->lineEdit_2->text();

    if(username == "nabil" && password == "bell")
    {
        MainWindow w;
        w.show();
    }
}

