#include "UniThemeManager.h"
#include <QJsonDocument>
#include <QJsonObject>

UniThemeManager::UniThemeManager(QObject *parent)
    : QObject(parent)
{
    InitManual();
    FindAllThemes();

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

    m_themeList = themeDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);

    qDebug() << "> Theme name [ cnt " << m_themeList.count() << " ]";

    for (auto &item:m_themeList) {
        qDebug() << "> Theme name [ " << item << " ]";
        QDir jsonList = (m_basePath+"Theme/"+item);
        m_theme_json_list.append(jsonList.entryList({"*.json"}, QDir::Files));

        for (auto &item1:m_theme_json_list.last()) {
            qDebug() << ">>>> Lst json [ " << item1 << " ]";
            if ( item1 == QStringLiteral("theme.json") ) {
                uniThemeInfoTypedef info;
                info.Path = m_basePath+"Theme/"+item+"/"+item1;

                LoadThemeInfo(m_basePath+"Theme/"+item+"/"+item1, info);
                m_themeInfo.append(info);
                qDebug() << "> Print info:";
                qDebug() << "Name: " << info.Name;
                qDebug() << "Description: " << info.Description;
                qDebug() << "Author: " << info.Author;
                qDebug() << "Version: " << info.Version;
                qDebug() << "Path: " << info.Path;
            }
        }
    }
}

void UniThemeManager::LoadThemeInfo( QString Path, uniThemeInfoTypedef &Info ) {
    QFile jsonFile(Path);

    if ( !jsonFile.open(QIODevice::ReadOnly | QIODevice::Text) ) {
        qDebug() << ">>> Info json open error";
    }

    QByteArray jsonData = jsonFile.readAll();
    jsonFile.close();

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(jsonData, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        qWarning() << "Chyba při parsování JSON:" << parseError.errorString();
        return;
    }

    QJsonObject obj = doc.object();

    Info.Name = obj.value("name").toString();
    Info.Description = obj.value("description").toString();
    Info.Author = obj.value("author").toString();
    Info.Version = obj.value("version").toString();
    Info.Path = Path;
}
