#ifndef UNICOLORGRADIEN_H
#define UNICOLORGRADIEN_H

#pragma once

#include <QString>
#include <QObject>
#include <QQmlEngine>
#include <QColor>

struct uniColorGradient {
    Q_GADGET
    QML_VALUE_TYPE(uniColorGradient)

    Q_PROPERTY (QColor colorStart MEMBER colorStart)
    Q_PROPERTY (QColor colorEnd MEMBER colorEnd)
    Q_PROPERTY (GradientType type MEMBER type)

public:
    enum GradientType {
        None = 0,
        Linear,
        Radial,
        EndColorCenter
    };
    Q_ENUM(GradientType)

    QColor colorStart;
    QColor colorEnd;
    GradientType type = None;

    static GradientType fromString(const QString &typeStr) {
        if (typeStr.compare("linear", Qt::CaseInsensitive) == 0)
            return Linear;
        if (typeStr.compare("radial", Qt::CaseInsensitive) == 0)
            return Radial;
        if (typeStr.compare("endcolorcenter", Qt::CaseInsensitive) == 0)
            return EndColorCenter;
        return None;
    }

    bool isValid() const {
        return type != None;
    }
};
Q_DECLARE_METATYPE(uniColorGradient)

#endif // UNICOLORGRADIEN_H
