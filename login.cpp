#include "login.h"
#include "ui_login.h"
#include "application.h"
#include "signup.h"
//#include <QGraphicsDropShadowEffect>
#include <QtWidgets>
LoginPage::LoginPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    //setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    ui->setupUi(this);

}

LoginPage::~LoginPage()
{
    delete ui;
}


void LoginPage::on_pushButton_clicked()
{
//    app()->nextPage->show();
//    this->password      = this->ui->usernameLineEdit->text();
//    this->close();
}


void LoginPage::on_pushButton_6_clicked() // sign_up
{

}


void LoginPage::on_signupButton_clicked()
{
    app()->signPage->show();
    this->close();
}

