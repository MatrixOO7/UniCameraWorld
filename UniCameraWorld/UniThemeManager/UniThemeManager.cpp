#include "UniThemeManager.h"

UniThemeManager::UniThemeManager(QObject *parent)
    : QObject(parent)
{
    InitManual();
}

void UniThemeManager::InitManual()
{
    // UniButton barvy
    m_UniButtonItem.BackgroundColor = QColor("#902A2A2A");
    m_UniButtonItem.BorderColor = QColor("#444444");
    m_UniButtonItem.TextColor = QColor("#FFFFFF");

    m_UniButtonItem.HoverBackgroundColor = QColor("#3A3A3A");
    m_UniButtonItem.HoverBorderColor = QColor("#555555");
    m_UniButtonItem.HoverTextColor = QColor("#FFFFFF");

    m_UniButtonItem.ClickedBackgroundColor = QColor("#1A1A1A");
    m_UniButtonItem.ClickedBorderColor = QColor("#666666");
    m_UniButtonItem.ClickedTextColor = QColor("#FFFFFF");

    m_UniButtonItem.DisabledBackgroundColor = QColor("#111111");
    m_UniButtonItem.DisabledBorderColor = QColor("#222222");
    m_UniButtonItem.DisabledTextColor = QColor("#888888");

    // UniLabel barvy
    m_UniLabelItem.BackgroundColor = QColor("transparent");
    m_UniLabelItem.BorderColor = QColor("transparent");
    m_UniLabelItem.TextColor = QColor("#CCCCCC");

    m_UniLabelItem.HoverBackgroundColor = QColor("transparent");
    m_UniLabelItem.HoverBorderColor = QColor("transparent");
    m_UniLabelItem.HoverTextColor = QColor("#EEEEEE");

    m_UniLabelItem.DisabledBackgroundColor = QColor("transparent");
    m_UniLabelItem.DisabledBorderColor = QColor("transparent");
    m_UniLabelItem.DisabledTextColor = QColor("#777777");
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
