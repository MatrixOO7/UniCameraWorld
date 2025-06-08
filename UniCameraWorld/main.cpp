#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "UniThemeManager/UniThemeManager.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    static UniThemeManager themeManager;
    qmlRegisterSingletonInstance("ThemeManager", 1, 0, "ThemeManager", &themeManager);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("UniCameraWorld", "Main");

    return app.exec();
}
