#include "signup.h"
#include "ui_signup.h"
#include <QFileDialog>
#include "application.h"
#include "login.h"
#include <qdebug.h>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>

SignupPage::SignupPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::next)
{
//    setWindowFlags(Qt::FramelessWindowHint);
//    setAttribute(Qt::WA_TranslucentBackground);
    ui->setupUi(this);

    this->waitDialog = new QMFWaitDialog();
    this->notifDialog = new QMFNotification();

}

SignupPage::~SignupPage()
{
    delete ui;
}

//void SignupPage::on_pushButton_clicked()
//{
//    QString file = QFileDialog::getOpenFileName(this, tr("Open File"), "/debug", tr("default (*.*)"));
//    qDebug() << file;
//    this->ui->label->setPixmap(QPixmap(file));

//}


//void SignupPage::on_pushButton_2_clicked()
//{
//    this->close();
//    app()->loginPage->show();
//}


void SignupPage::on_signupButton_clicked()
{
    QString username = this->ui->usernameLineEdit->text();
    QString password = this->ui->passwordLineEdit->text();
    QString age = QString::number(this->ui->ageSpinBox->value());
    QString email = this->ui->emailLineEdit->text();
    QString role = "Soton";

    QNetworkAccessManager *mgr = new QNetworkAccessManager(this);
    const QUrl url(QStringLiteral("http://172.20.40.193:8080/api/register/"));
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject obj;
    obj["name"] = username;
    obj["password"] = password;
    obj["age"] = age;
    obj["role"] = role;
    obj["email"] = email;

    QJsonDocument doc(obj);
    QByteArray data = doc.toJson();
    QNetworkReply *reply = mgr->post(request, data);

    waitDialog->setTitle("Please wait");
    waitDialog->start();

    QObject::connect(reply, &QNetworkReply::finished, [=](){

        waitDialog->stop();
        if(reply->error() == QNetworkReply::NoError){
            QString contents = QString::fromUtf8(reply->readAll());
            qDebug() << contents;

            this->notifDialog->setNotification("Registeration Succseedful",QString("%1 Registered Successfully in database").arg(username),
                                               QPixmap(":/image/res/images/signal-button.png"),QtMFW::successed,5000);
        }
        else{
            QString err = reply->errorString();
            qDebug() << err;

            this->notifDialog->setNotification("Registeration faild",QString("%1 Can Not added to database").arg(username),
                                               QPixmap(":/image/res/images/signal-button.png"),QtMFW::failed,5000);

        }
        reply->deleteLater();
    });
}


void SignupPage::on_cancelButton_clicked()
{
    this->close();
    app()->loginPage->show();
}

