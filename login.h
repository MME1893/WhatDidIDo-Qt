#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class LoginPage : public QWidget
{
    Q_OBJECT

public:
    LoginPage(QWidget *parent = nullptr);
    ~LoginPage();
    QString username;
    QString password;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_signupButton_clicked();

private:
    Ui::Widget *ui;
};
#endif // LOGIN_H
