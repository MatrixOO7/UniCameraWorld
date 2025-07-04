#ifndef UNIBASEINFO_H
#define UNIBASEINFO_H

#pragma once

#include <QString>
#include <QObject>
#include <QQmlEngine>

struct uniBaseInfo {
    Q_GADGET
    QML_VALUE_TYPE(uniBaseInfo)
    Q_PROPERTY(int id MEMBER id)
    Q_PROPERTY(QString name MEMBER name)
    Q_PROPERTY(QString defaultText MEMBER defaultText)

public:
    int id;
    QString name;
    QString defaultText;
};
Q_DECLARE_METATYPE(uniBaseInfo)

#endif // UNIBASEINFO_H
