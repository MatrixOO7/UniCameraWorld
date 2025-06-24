#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "UniThemeManager/UniThemeManager.h"
#include <QColor>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterSingletonInstance("UniThemeManager", 1, 1, "UniThemeManager", new UniThemeManager());
    qRegisterMetaType<uniButtonItemTipedef>();
    qRegisterMetaType<uniLabelItemTipedef>();
    qRegisterMetaType<uniMainWindowItemTypedef>();
    qRegisterMetaType<uniSideMenuItemTypedef>();
    qRegisterMetaType<uniThemeInfoTypedef>();

    qmlRegisterUncreatableType<QColor>("QtQuick", 2, 15, "QColor", "Cannot create QColor in QML");
    qRegisterMetaType<QColor>("QColor");


    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("UniCameraWorld", "Main");

    return app.exec();
}
