#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "UniThemeManager/UniThemeManager.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterSingletonInstance("UniThemeManager", 1, 1, "UniThemeManager", new UniThemeManager());
    qmlRegisterUncreatableType<UniButtonItemTipedef>("UniThemeManager", 1, 1, "uniButtonItemTipedef", "Used internally");
    qmlRegisterUncreatableType<UniLabelItemTipedef>("UniThemeManager", 1, 1, "uniLabelItemTipedef", "Used internally");


    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("UniCameraWorld", "Main");

    return app.exec();
}
