#include "login.h"

#include "application.h"

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    application a(argc, argv);
    a.init();
    return a.exec();
}
