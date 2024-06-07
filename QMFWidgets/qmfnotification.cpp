#include "qmfnotification.h"
#include "ui_qmfnotification.h"
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QTimer>

QMFNotification::QMFNotification(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QMFNotification)
{
    ui->setupUi(this);
    init();
}

QMFNotification::~QMFNotification()
{
    delete ui;
    delete fadeOutTimer;
    delete animation;
}

void QMFNotification::init()
{
    fadeOutTimer    = new QTimer(this);
    connect(fadeOutTimer,SIGNAL(timeout()),this,SLOT(fadeOut()));

    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    setGraphicsEffect(eff);

    animation       = new QPropertyAnimation(eff,"opacity");

    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setParent(0);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    setAttribute(Qt::WA_PaintOnScreen);
}

void QMFNotification::stop(quint16 ms)
{
    if( !isHidden() && ms > 0 )
    {
        fadeOutTimer->stop();
        QTimer::singleShot(ms,this,SLOT(stop()));
    }
    else if( !isHidden() )
        fadeOut();
}

void QMFNotification::setNotification(const QString headerTitle, const QString notification, const QPixmap &nifiicationPixmap,const QtMFW::Status status , const quint16 duration)
{
    if( !isHidden() )
        hide();
    fadeOutTimer->stop();
    animation->stop();

    ui->widget_bg->setStyleSheet(QString("#widget_bg {background-color: \"%1\";}").arg(QtMFW::StatusColor[status]));
    ui->lbl_icon->setPixmap(nifiicationPixmap);
    ui->lbl_headerTitle->setText(headerTitle);
    ui->lbl_notification->setText(notification);

    fadeIn();
    fadeOutTimer->start(duration);
}


void QMFNotification::fadeIn()
{
    show();
    disconnect(animation,0,0,0);

    animation->setDuration(1000);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();
}

void QMFNotification::fadeOut()
{
    animation->setDuration(1000);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
    connect(animation,SIGNAL(finished()),this,SLOT(hide()));
}
