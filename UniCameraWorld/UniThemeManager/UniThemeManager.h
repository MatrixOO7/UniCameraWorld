#ifndef UNITHEMEMANAGER_V_1
#define UNITHEMEMANAGER_V_1

#pragma once

#include <QObject>
#include <QQmlEngine>
#include <QString>
#include <QMap>
#include <QVariant>
#include <QColor>

#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>

struct uniButtonItemTipedef {
    Q_GADGET
    QML_VALUE_TYPE(uniButtonItemTipedef)

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
Q_DECLARE_METATYPE(uniButtonItemTipedef)

struct uniLabelItemTipedef {
    Q_GADGET
    QML_VALUE_TYPE(uniLabelItemTipedef)

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
Q_DECLARE_METATYPE(uniLabelItemTipedef)

class UniThemeManager : public QObject {
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

    Q_PROPERTY(uniButtonItemTipedef uniButton READ uniButton WRITE SetuniButton NOTIFY uniButtonChanged FINAL)
    Q_PROPERTY(uniLabelItemTipedef uniLabel READ uniLabel WRITE SetuniLabel NOTIFY uniLabelChanged FINAL)

public:
    explicit UniThemeManager(QObject *parent = nullptr);

    void InitManual();

    uniButtonItemTipedef uniButton() const;
    uniLabelItemTipedef uniLabel() const;

    void SetuniButton(uniButtonItemTipedef item);
    void SetuniLabel(uniLabelItemTipedef item);

signals:
    void uniButtonChanged();
    void uniLabelChanged();

private:
    const QString m_basePath = "UniThemeManager/";

    uniButtonItemTipedef m_UniButtonItem;
    uniLabelItemTipedef m_UniLabelItem;

    QStringList m_themeList;

    void FindAllThemes ();
};

#endif // UNITHEMEMANAGER_V_1
