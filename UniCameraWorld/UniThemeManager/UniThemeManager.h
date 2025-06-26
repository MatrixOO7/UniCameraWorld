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

struct uniMainWindowItemTypedef {
    Q_GADGET
    QML_VALUE_TYPE(uniMainWindowItemTypedef)

    Q_PROPERTY(QColor BackgroundColor MEMBER BackgroundColor)

public:
    QColor BackgroundColor;
};
Q_DECLARE_METATYPE(uniMainWindowItemTypedef)

struct uniSideMenuItemTypedef {
    Q_GADGET
    QML_VALUE_TYPE(uniSideMenuItemTypedef)

    Q_PROPERTY(QColor BackgroundColor MEMBER BackgroundColor)

public:
    QColor BackgroundColor;
};
Q_DECLARE_METATYPE(uniSideMenuItemTypedef)

struct uniThemeInfoTypedef {
    Q_GADGET
    QML_VALUE_TYPE(uniThemeInfoTypedef)

    Q_PROPERTY(QString Name MEMBER Name)
    Q_PROPERTY(QString Description MEMBER Description)
    Q_PROPERTY(QString Version MEMBER Version)
    Q_PROPERTY(QString Author MEMBER Author)
    Q_PROPERTY(QString Path MEMBER Path)

public:
    QString Name;
    QString Description;
    QString Version;
    QString Author;
    QString Path;

    /*__________[tyto funkce tu jsou kvuli Q_GADGET aby vedel ze nastala zmnena - start]__________*/
    bool operator==(const uniThemeInfoTypedef &other) const {
        return Name == other.Name &&
               Description == other.Description &&
               Version == other.Version &&
               Author == other.Author &&
               Path == other.Path;
    }

    bool operator!=(const uniThemeInfoTypedef &other) const {
        return !(*this == other);
    }
    /*__________[tyto funkce tu jsou kvuli Q_GADGET aby vedel ze nastala zmnena - end]__________*/
};
Q_DECLARE_METATYPE(uniThemeInfoTypedef)

struct stThemeList {
    Q_GADGET
    QML_VALUE_TYPE(stThemeList)

    Q_PROPERTY(uniThemeInfoTypedef Info MEMBER Info)
    Q_PROPERTY(QString DirName MEMBER DirName)
    Q_PROPERTY(QStringList FileList MEMBER FileList)

public:
    uniThemeInfoTypedef Info;
    QString DirName;
    QStringList FileList;
};
Q_DECLARE_METATYPE(stThemeList)



class UniThemeManager : public QObject {
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

    Q_PROPERTY(uniButtonItemTipedef uniButton READ uniButton WRITE SetuniButton NOTIFY uniButtonChanged FINAL)
    Q_PROPERTY(uniLabelItemTipedef uniLabel READ uniLabel WRITE SetuniLabel NOTIFY uniLabelChanged FINAL)
    Q_PROPERTY(uniMainWindowItemTypedef uniMainWindow READ uniMainWindow WRITE SetuniMainWindow NOTIFY uniMainWindowChanged FINAL)
    Q_PROPERTY(uniSideMenuItemTypedef uniSideMenu READ uniSideMenu WRITE SetuniSideMenu NOTIFY uniSideMenuChanged FINAL)

public:
    explicit UniThemeManager(QObject *parent = nullptr);

    void InitManual();

    uniButtonItemTipedef uniButton() const;
    uniLabelItemTipedef uniLabel() const;
    uniMainWindowItemTypedef uniMainWindow() const;
    uniSideMenuItemTypedef uniSideMenu() const;

    void SetuniButton(uniButtonItemTipedef item);
    void SetuniLabel(uniLabelItemTipedef item);
    void SetuniMainWindow(uniMainWindowItemTypedef item);
    void SetuniSideMenu(uniSideMenuItemTypedef item);

signals:
    void uniButtonChanged();
    void uniLabelChanged();
    void uniMainWindowChanged();
    void uniSideMenuChanged();

private:
    const QString m_basePath = "UniThemeManager/";

    uniButtonItemTipedef m_UniButtonItem;
    uniLabelItemTipedef m_UniLabelItem;
    uniMainWindowItemTypedef m_UniMainWindowItem;
    uniSideMenuItemTypedef m_UniSideMenuItem;



    QList<stThemeList> m_themeList;

    /*_______[Load themes from files]_______*/
    void FindAllThemes ();
    void LoadThemeInfo( QString Path, uniThemeInfoTypedef &info );
    bool JsonLoader(QString Path, QJsonDocument &doc);


    /*_______[Load default colors]_______*/
    void DefaultLoad_button();
    void DefaultLoad_label();
    void DefaultLoad_mainWindow();
    void DefaultLoad_sideMenu();
};

#endif // UNITHEMEMANAGER_V_1
