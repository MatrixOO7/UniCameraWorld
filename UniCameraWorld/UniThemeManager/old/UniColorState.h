#ifndef UNICOLORSTATE_H
#define UNICOLORSTATE_H

#pragma once

#include <QString>
#include <QObject>
#include <QQmlEngine>
#include "UniColorSolid.h"
#include "UniColorGradien.h"

struct uniColorState {
    Q_GADGET
    QML_VALUE_TYPE(uniBaseInfo)

    Q_PROPERTY (uniColorSolid solid MEMBER solid)
    Q_PROPERTY (uniColorGradient gradient MEMBER gradient)

public:
    uniColorSolid solid;
    uniColorGradient gradient;
};
Q_DECLARE_METATYPE(uniColorState)

#endif // UNICOLORSTATE_H
