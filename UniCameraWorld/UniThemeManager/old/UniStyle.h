#ifndef UNISTYLE_H
#define UNISTYLE_H

#pragma once

#include <QString>
#include <QObject>
#include <QQmlEngine>

struct uniStyle {
    Q_GADGET
    QML_VALUE_TYPE(uniStyle)

    Q_PROPERTY(bool visibleBorder MEMBER visibleBorder)
    Q_PROPERTY(int borderSize MEMBER borderSize)
    Q_PROPERTY(bool animationEnable MEMBER animationEnable)

public:
    bool visibleBorder = true;
    int borderSize = 3;
    bool animationEnable = true;

};
Q_DECLARE_METATYPE(uniStyle)


#endif // UNISTYLE_H
