#include "UniThemeManager.h"

UniThemeManager::UniThemeManager ( QObject *parent ) : QObject (parent) {

}

QColor UniThemeManager::btnBackGroundColor () {
    return m_btnBackGroundColor;
}


void UniThemeManager::setBtnBackGroundColor( const QColor newColor ) {
    m_btnBackGroundColor = newColor;
}

QColor UniThemeManager::btnHoverColor () {
    return m_btnHoverColor;
}


void UniThemeManager::setBtnHoverColor( const QColor newColor ) {
    m_btnHoverColor = newColor;
}
