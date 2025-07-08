#ifndef UNICOLORSTATE_H
#define UNICOLORSTATE_H

#include <QObject>
#include <QQmlEngine>
#include <QJsonDocument>

class UniColorState : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit UniColorState( QObject *parent = nullptr );
};

#endif // UNICOLORSTATE_H
