#include "UniThemeManager.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

UniThemeManager::UniThemeManager(QObject *parent)
    : QObject(parent)
{
    InitManual();
    FindAllThemes();

    LoadTheme("Unicorn");

}

void UniThemeManager::InitManual()
{
    DefaultLoad_button();
    DefaultLoad_label();
    DefaultLoad_mainWindow();
    DefaultLoad_sideMenu();
}

void UniThemeManager::DefaultLoad_button() {
    // UniButton barvy
    m_UniButtonItem.BackgroundColor = QColor::fromRgba(0x902A2A2A); //  QColor("#902A2A2A");
    m_UniButtonItem.BorderColor = QColor::fromRgba(0xFF444444); // QColor("#444444");
    m_UniButtonItem.TextColor = QColor::fromRgba(0xFFFFFFFF); // QColor("#FFFFFF");

    m_UniButtonItem.HoverBackgroundColor = QColor::fromRgba(0xFF3A3A3A); //  QColor("#3A3A3A");
    m_UniButtonItem.HoverBorderColor =  QColor::fromRgba(0xFF555555); //QColor("#555555");
    m_UniButtonItem.HoverTextColor = QColor::fromRgba(0xFFFFFFFF); //  QColor("#FFFFFF");

    m_UniButtonItem.ClickedBackgroundColor = QColor::fromRgba(0xFF1A1A1A);  //QColor("#1A1A1A");
    m_UniButtonItem.ClickedBorderColor = QColor::fromRgba(0xFF666666); //  QColor("#666666");
    m_UniButtonItem.ClickedTextColor = QColor::fromRgba(0xFFFFFFFF); //  QColor("#FFFFFF");

    m_UniButtonItem.DisabledBackgroundColor = QColor::fromRgba(0xFF111111); // QColor("#111111");
    m_UniButtonItem.DisabledBorderColor = QColor::fromRgba(0xFF222222); //  QColor("#222222");
    m_UniButtonItem.DisabledTextColor = QColor::fromRgba(0xFF888888); //  QColor("#888888");
}

void UniThemeManager::DefaultLoad_label() {
    // UniLabel barvy
    m_UniLabelItem.BackgroundColor = QColor::fromRgba(0x30C49700);
    m_UniLabelItem.BorderColor = QColor("transparent");
    m_UniLabelItem.TextColor = QColor::fromRgba(0xFFCCCCCC); //  QColor("#CCCCCC");

    m_UniLabelItem.HoverBackgroundColor = QColor::fromRgba(0xFFC49700);
    m_UniLabelItem.HoverBorderColor = QColor("transparent");
    m_UniLabelItem.HoverTextColor = QColor::fromRgba(0xFFEEEEEE); //  QColor("#EEEEEE");

    m_UniLabelItem.DisabledBackgroundColor = QColor("transparent");
    m_UniLabelItem.DisabledBorderColor = QColor("transparent");
    m_UniLabelItem.DisabledTextColor = QColor::fromRgba(0xFF777777); // QColor("#777777");
}

void UniThemeManager::DefaultLoad_mainWindow(){
    m_UniMainWindowItem.BackgroundColor = QColor::fromRgba(0x30C49700);
}

void UniThemeManager::DefaultLoad_sideMenu() {
    m_UniSideMenuItem.BackgroundColor = QColor::fromRgba(0x30C49700);
}

uniButtonItemTipedef UniThemeManager::uniButton() const
{
    return m_UniButtonItem;
}

uniLabelItemTipedef UniThemeManager::uniLabel() const
{
    return m_UniLabelItem;
}

uniMainWindowItemTypedef UniThemeManager::uniMainWindow() const {
    return m_UniMainWindowItem;
}

uniSideMenuItemTypedef UniThemeManager::uniSideMenu() const {
    return m_UniSideMenuItem;
}

void UniThemeManager::SetuniButton(uniButtonItemTipedef item)
{
    m_UniButtonItem = item;
    emit uniButtonChanged();
}

void UniThemeManager::SetuniLabel(uniLabelItemTipedef item)
{
    m_UniLabelItem = item;
    emit uniLabelChanged();
}

void UniThemeManager::SetuniSideMenu(uniSideMenuItemTypedef item)
{
    m_UniSideMenuItem = item;
    emit uniSideMenuChanged();
}

void UniThemeManager::SetuniMainWindow(uniMainWindowItemTypedef item)
{
    m_UniMainWindowItem = item;
    emit uniMainWindowChanged();
}

void UniThemeManager::FindAllThemes() {
    QDir themeDir(m_basePath+"Theme");
    stThemeList themeItem;

    QStringList dirList = themeDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);

    qDebug() << "> Theme name [ cnt " << m_themeList.count() << " ]";

    int cntLoader = 0;

    /*______________[Dir path loader]__________________*/
    for (auto &item:dirList) {
        themeItem.DirName = item;
        QDir jsonList = (m_basePath+"Theme/"+item);
        QStringList m_theme_dir_list;

        m_theme_dir_list.append(jsonList.entryList({"*.json"}, QDir::Files));
        cntLoader = 0;
        themeItem.FileList.clear();
        /*_____________[File path loader]_______________*/
        for (auto &item1:m_theme_dir_list) {
            themeItem.FileList.append(item1);
            cntLoader++;
            if ( item1 == QStringLiteral("theme.json") ) {
                themeItem.Info.Path = m_basePath+"Theme/"+item+"/"+item1;
                LoadThemeInfo(m_basePath+"Theme/"+item+"/", themeItem.Info);
            }
        }
        m_themeList.append(themeItem);
        qDebug() << "Tleme  json loader cnt " << cntLoader;
    }
}

void UniThemeManager::LoadThemeInfo( QString Path, uniThemeInfoTypedef &Info ) {
    QJsonDocument doc;

    if (!JsonLoader(Path+"/theme.json", doc)) {
        qDebug() << "> Error with load json file...";
        return;
    }

    QJsonObject obj = doc.object();

    Info.Name = obj.value("name").toString();
    Info.Description = obj.value("description").toString();
    Info.Author = obj.value("author").toString();
    Info.Version = obj.value("version").toString();
    Info.Path = Path;
}

bool UniThemeManager::JsonLoader(QString Path, QJsonDocument &doc) {
    QFile jsonFile(Path);

    if ( !jsonFile.open(QIODevice::ReadOnly | QIODevice::Text) ) {
        qDebug() << ">>> Info json open error";
        return false;
    }

    QByteArray jsonData = jsonFile.readAll();
    jsonFile.close();

    QJsonParseError parseError;
    doc = QJsonDocument::fromJson(jsonData, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        qWarning() << "Chyba při parsování JSON:" << parseError.errorString();
        return false;
    }

    return true;
}

bool UniThemeManager::LoadTheme(QString themeName) {
#define totalElements 4

    int themeElementsCount = 0;

    qDebug() << "Themes coun " << m_themeList.count();
    qDebug() << "Theme json count " << m_themeList.at(1).FileList.count();

    for ( auto &item:m_themeList ) {
        if ( item.Info.Name == themeName ) {
            qDebug() << "Cnt???  " << item.FileList.count();
            for ( const QString &themeFile:item.FileList ) {

                if ( !Load_button(item.Info.Path, themeFile) ) {
                    DefaultLoad_button();
                } else {
                    themeElementsCount++;
                }

                if ( !Load_label(item.Info.Path, themeFile) ) {
                    DefaultLoad_label();
                } else {
                    themeElementsCount++;
                }

                if ( !Load_mainWindow(item.Info.Path, themeFile) ) {
                    DefaultLoad_mainWindow();
                } else {
                    themeElementsCount++;
                }

                if ( !Load_sideMenu(item.Info.Path, themeFile) ) {
                    DefaultLoad_sideMenu();
                } else {
                    themeElementsCount++;
                }
            }

            if (themeElementsCount != totalElements ) {
                qDebug() << "> Error test " << themeElementsCount << " || " << totalElements;
                qDebug() << ">>> Some error with load theme...";
            } else {
                qDebug() << ">>> All themes load successfull...";
            }

            m_lastPath = themeName;
            return true;
        }
    }

    qDebug() << ">>> Theme load failed...";
    return false;
}

bool UniThemeManager::LoadLastTheme() {
    return false;
}


bool UniThemeManager::Load_button( QString basePath, QString fileName ) {
    if ( fileName.toLower() == "button.json" ) {
        qDebug() << ">> Fake load button :: " << basePath+fileName;
        QJsonDocument doc;
        if (!JsonLoader(basePath+fileName, doc)) {
            return false;
        }

        QJsonObject obj = doc.object();
        QJsonArray colorArray = obj.value("states").toArray();

        for (const QJsonValue &val : colorArray) {
            qDebug() << val.toString();
        }




        return true;
    }
    return false;
}

bool UniThemeManager::Load_label( QString basePath, QString fileName ) {
    if ( fileName.toLower() == "label.json" ) {
        qDebug() << ">> Fake load label :: " << basePath+fileName;
        return true;
    }
    return false;
}

bool UniThemeManager::Load_mainWindow( QString basePath, QString fileName ) {
    if ( fileName.toLower() == "mainwindow.json" ) {
        qDebug() << ">> Fake load main window :: " << basePath+fileName;
        return true;
    }
    return false;
}

bool UniThemeManager::Load_sideMenu( QString basePath, QString fileName ) {
    if ( fileName.toLower() == "sidemenu.json" ) {
        qDebug() << ">> Fake load side menu :: " << basePath+fileName;
        return true;
    }
    return false;
}
