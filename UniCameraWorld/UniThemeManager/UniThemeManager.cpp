#include "UniThemeManager.h"

UniThemeManager::UniThemeManager(QObject *parent)
    : QObject(parent)
{
    InitManual();
}

void UniThemeManager::InitManual()
{
    // UniButton barvy
    m_UniButtonItem.BackgroundColor = QColor::fromRgb(42,42,42); //QColor("#2A2A2A");
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

UniButtonItemTipedef UniThemeManager::UniButton() const
{
    return m_UniButtonItem;
}

UniLabelItemTipedef UniThemeManager::UniLabel() const
{
    return m_UniLabelItem;
}

void UniThemeManager::SetUniButton(UniButtonItemTipedef item)
{
    m_UniButtonItem = item;
    emit UniButtonChanged();
}

void UniThemeManager::SetUniLabel(UniLabelItemTipedef item)
{
    m_UniLabelItem = item;
    emit UniLabelChanged();
}
