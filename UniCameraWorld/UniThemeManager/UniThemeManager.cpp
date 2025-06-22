#include "UniThemeManager.h"

UniThemeManager::UniThemeManager(QObject *parent)
    : QObject(parent)
{
    InitManual();
    FindAllThemes();
}

void UniThemeManager::InitManual()
{
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

uniButtonItemTipedef UniThemeManager::uniButton() const
{
    return m_UniButtonItem;
}

uniLabelItemTipedef UniThemeManager::uniLabel() const
{
    return m_UniLabelItem;
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

void UniThemeManager::FindAllThemes() {
    //QDir themeDir("UniThemeManager/Theme");
    QDir themeDir(m_basePath+"Theme");

    m_themeList = themeDir.entryList(QStringList() << "*.json" << "*.JSON",QDir::Files);

    qDebug() << "> Theme name [ cnt " << m_themeList.count() << " ]";

    foreach (QString item, m_themeList) {
        qDebug() << "> Theme name [ " << item << " ]";
    }
}
