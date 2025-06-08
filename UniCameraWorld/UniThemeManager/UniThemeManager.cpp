#include "UniThemeManager.h"

UniThemeManager::UniThemeManager ( QObject *parent ) : QObject (parent) {

}

QColor UniThemeManager::btnBackGround () {
    return m_btnBackGround;
}


void UniThemeManager::setBtnBackGround( const QColor newColor ) {
    m_btnBackGround = newColor;
}
