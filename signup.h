#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include <ActiveQt/QAxWidget>
#include "QMFWidgets/qmfwaitdialog.h"
#include "QMFWidgets/qmfnotification.h"

namespace Ui {
class next;
}

class SignupPage : public QWidget
{
    Q_OBJECT

public:
    explicit SignupPage(QWidget *parent = nullptr);
    ~SignupPage();

private slots:
    void on_signupButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::next *ui;
    QMFWaitDialog *waitDialog;
    QMFNotification *notifDialog;
};

#endif // SIGNUP_H
