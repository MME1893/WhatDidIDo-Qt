#include "application.h"

#include "login.h"
#include "signup.h"
#include "Widgets/SplashScreen/splashscreen.h"

application*    application::myInstance = (application*)(QApplication::instance());


application::application(int argc, char *argv[]) : QApplication(argc, argv)
{
    this->signPage = new SignupPage();
    this->loginPage = new LoginPage();
    this->splashscreen = new SplashScreen();
}

void application::init()
{
    application::myInstance = (application*)(QApplication::instance());
    this->splashscreen->show();
    //this->loginPage->show();
}
