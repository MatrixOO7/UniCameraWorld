#ifndef UNIBUTTON_H
#define UNIBUTTON_H

#pragma once

#include <QString>
#include <QObject>
#include <QQmlEngine>

#include "UniBaseInfo.h"
#include "UniButtonPart.h"

struct uniButton {
    Q_GADGET
    QML_VALUE_TYPE(uniButton)

    Q_PROPERTY(QString fontFamily MEMBER fontFamily)
    Q_PROPERTY(bool isBold MEMBER isBold)

public:
    uniBaseInfo baseInfo;
    QList <uniButtonPart> lstButtons;
};
Q_DECLARE_METATYPE(uniButton)

#endif // UNIBUTTON_H
