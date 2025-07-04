#ifndef UNIFONT_H
#define UNIFONT_H

#pragma once

#include <QString>
#include <QObject>
#include <QQmlEngine>

struct uniFont {
    Q_GADGET
    QML_VALUE_TYPE(uniFont)

    Q_PROPERTY(QString fontFamily MEMBER fontFamily)
    Q_PROPERTY(bool isBold MEMBER isBold)
    Q_PROPERTY(bool isUnderline MEMBER isUnderline)
    Q_PROPERTY(bool isItalic MEMBER isItalic)
    Q_PROPERTY(int fontSize MEMBER fontSize)

public:
    QString fontFamily = "Arial";
    bool isBold = false;
    bool isUnderline = false;
    bool isItalic = false;
    int fontSize = 12;
};
Q_DECLARE_METATYPE(uniFont)

#endif // UNIFONTSTATE_H
