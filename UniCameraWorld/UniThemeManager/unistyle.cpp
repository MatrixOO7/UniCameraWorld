#include "unistyle.h"

UniStyle::UniStyle( QObject *parent ) {}

void UniStyle::LoadDefault() {
    m_isVisibleBorder = true;
    int m_borderSize = 2;
    bool m_isHoverEnable = true;
    bool m_isAnimationEnable = true;
}

bool UniStyle::Load( const QString path) {
    return false;
}

void UniStyle::setBorderSize ( const int value ) {
    if ( m_borderSize != value ) {
        m_borderSize = value;
        emit borderSizeChanged();
    }
}

void UniStyle::setIsVisibleBorder( const bool value ) {
    if ( m_isVisibleBorder != value ) {
        m_isVisibleBorder = value;
        emit isVisibleBorderChanged();
    }
}

void UniStyle::setIsHoverEnable( const bool value ) {
    if ( m_isHoverEnable != value ) {
        m_isHoverEnable = value;
        emit isHoverEnableChanged();
    }
}

void UniStyle::setIsAnimationEnable ( const bool value ) {
    if ( m_isAnimationEnable != value ) {
        m_isAnimationEnable = value;
        emit isAnimationEnableChanged();
    }
}
