#include "splashscreen.h"
#include "ui_splashscreen.h"
//#include "Config/structure.h"
#include "application.h"
#include <QTimer>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSettings>
#include <QQuickStyle>
#include <QIcon>
#include <QDebug>
#include <QBitmap>
#include "login.h"


AppDefines::AppDefines(QObject *parent):QObject(parent){}

AppDefines::~AppDefines(){}

QString AppDefines::getVersion(){ return "test2"; }

QString AppDefines::getCompanyName(){ return "Baradaran MME"; }

SplashScreen::SplashScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SplashScreen)
{
    ui->setupUi(this);

    QBitmap windowMask(":/images/image/splashMask.bmp");
    resize(windowMask.width(),windowMask.height());
    setMask(windowMask);

    AppDefines appDef(nullptr);
    //qmlRegisterType<AppDefines>("com.pasmart.appDefines",1,0,"AppDefines");
    ui->quickWidget->setSource(QUrl("qrc:/qml/Widgets/SplashScreen/splash.qml"));
    setWindowFlag(Qt::FramelessWindowHint);
    QTimer::singleShot(10000,this,[this](){
        app()->loginPage->show();
        this->close();
    });
}

SplashScreen::~SplashScreen()
{
    delete ui;
}
