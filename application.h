#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>

class SignupPage;
class LoginPage;
class SplashScreen;

class application : public QApplication
{
    Q_OBJECT
public:
    static application *myInstance;
    static application* instance(){ return application::myInstance; }
    application(int argc, char *argv[]);
    SignupPage * signPage;
    LoginPage * loginPage;
    SplashScreen * splashscreen;
    void init();
};
static inline application *app() {
    return application::instance();
}

#endif // APPLICATION_H
