#ifndef UNICOLORSOLID_H
#define UNICOLORSOLID_H

#pragma once

#include <QString>
#include <QObject>
#include <QQmlEngine>
#include <QColor>

struct uniColorSolid {
    Q_GADGET
    QML_VALUE_TYPE(uniColorSolid)

    Q_PROPERTY (QColor backGround MEMBER backGround)
    Q_PROPERTY (QColor border MEMBER border)
    Q_PROPERTY (QColor text MEMBER text)

public:
    QColor background;
    QColor border;
    QColor text;
};
Q_DECLARE_METATYPE(uniColorSolid)

#endif // UNICOLORSOLID_H
