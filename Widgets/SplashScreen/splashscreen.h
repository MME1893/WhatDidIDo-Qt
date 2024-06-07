#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QWidget>

namespace Ui {
class SplashScreen;
}


/**
 * @brief
 *
 */
class AppDefines : public QObject {
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @param parent
     */
    AppDefines(QObject *parent=nullptr);
    /**
     * @brief
     *
     */
    ~AppDefines();

    /**
     * @brief
     *
     * @return QString
     */
    Q_INVOKABLE QString getVersion();
    Q_INVOKABLE QString getCompanyName();
};

/**
 * @brief
 *
 */
class SplashScreen : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @param parent
     */
    explicit SplashScreen(QWidget *parent = nullptr);
    /**
     * @brief
     *
     */
    ~SplashScreen();

private:
    Ui::SplashScreen *ui; /**< TODO: describe */
};

#endif // SPLASHSCREEN_H
