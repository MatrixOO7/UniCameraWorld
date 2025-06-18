#ifndef UNITHEMEMANAGER_V_1
#define UNITHEMEMANAGER_V_1

#pragma once

#include <QObject>
#include <QQmlEngine>
#include <QString>
#include <QMap>
#include <QVariant>
#include <QColor>

struct UniButtonItemTipedef {
    Q_GADGET
    QML_ELEMENT

    Q_PROPERTY(QColor BackgroundColor MEMBER BackgroundColor)
    Q_PROPERTY(QColor BorderColor MEMBER BorderColor)
    Q_PROPERTY(QColor TextColor MEMBER TextColor)

    Q_PROPERTY(QColor HoverBackgroundColor MEMBER HoverBackgroundColor)
    Q_PROPERTY(QColor HoverBorderColor MEMBER HoverBorderColor)
    Q_PROPERTY(QColor HoverTextColor MEMBER HoverTextColor)

    Q_PROPERTY(QColor ClickedBackgroundColor MEMBER ClickedBackgroundColor)
    Q_PROPERTY(QColor ClickedBorderColor MEMBER ClickedBorderColor)
    Q_PROPERTY(QColor ClickedTextColor MEMBER ClickedTextColor)

    Q_PROPERTY(QColor DisabledBackgroundColor MEMBER DisabledBackgroundColor)
    Q_PROPERTY(QColor DisabledBorderColor MEMBER DisabledBorderColor)
    Q_PROPERTY(QColor DisabledTextColor MEMBER DisabledTextColor)

public:
    QColor BackgroundColor;
    QColor BorderColor;
    QColor TextColor;

    QColor HoverBackgroundColor;
    QColor HoverBorderColor;
    QColor HoverTextColor;

    QColor ClickedBackgroundColor;
    QColor ClickedBorderColor;
    QColor ClickedTextColor;

    QColor DisabledBackgroundColor;
    QColor DisabledBorderColor;
    QColor DisabledTextColor;
};

struct UniLabelItemTipedef {
    Q_GADGET
    QML_ELEMENT

    Q_PROPERTY(QColor BackgroundColor MEMBER BackgroundColor)
    Q_PROPERTY(QColor BorderColor MEMBER BorderColor)
    Q_PROPERTY(QColor TextColor MEMBER TextColor)

    Q_PROPERTY(QColor HoverBackgroundColor MEMBER HoverBackgroundColor)
    Q_PROPERTY(QColor HoverBorderColor MEMBER HoverBorderColor)
    Q_PROPERTY(QColor HoverTextColor MEMBER HoverTextColor)

    Q_PROPERTY(QColor DisabledBackgroundColor MEMBER DisabledBackgroundColor)
    Q_PROPERTY(QColor DisabledBorderColor MEMBER DisabledBorderColor)
    Q_PROPERTY(QColor DisabledTextColor MEMBER DisabledTextColor)

public:
    QColor BackgroundColor;
    QColor BorderColor;
    QColor TextColor;

    QColor HoverBackgroundColor;
    QColor HoverBorderColor;
    QColor HoverTextColor;

    QColor DisabledBackgroundColor;
    QColor DisabledBorderColor;
    QColor DisabledTextColor;
};

class UniThemeManager : public QObject {
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(UniButtonItemTipedef UniButton READ UniButton WRITE SetUniButton NOTIFY UniButtonChanged FINAL)
    Q_PROPERTY(UniLabelItemTipedef UniLabel READ UniLabel WRITE SetUniLabel NOTIFY UniLabelChanged FINAL)

public:
    explicit UniThemeManager(QObject *parent = nullptr);

    void InitManual();

    UniButtonItemTipedef UniButton() const;
    UniLabelItemTipedef UniLabel() const;

    void SetUniButton(UniButtonItemTipedef item);
    void SetUniLabel(UniLabelItemTipedef item);

signals:
    void UniButtonChanged();
    void UniLabelChanged();

private:
    UniButtonItemTipedef m_UniButtonItem;
    UniLabelItemTipedef m_UniLabelItem;
};

#endif // UNITHEMEMANAGER_V_1
