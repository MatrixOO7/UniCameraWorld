#include "unifont.h"

UniFont::UniFont( QObject *parent ) : QObject(parent) {}

void UniFont::LoadDefault() {
    m_fontFamily = "Arial";
    m_fontSize = 12;
    m_isBold = false;
    m_isUnderline = false;
    m_isItalic = false;
}

bool UniFont::Load( const QJsonDocument &doc) {
    return false;
}

void UniFont::setFontFamily( const QString value ) {
    if ( m_fontFamily != value ) {
        m_fontFamily = value;
        emit fontChanged();
    }
}

void UniFont::setIsBold( const bool value ) {
    if ( m_isBold != value ) {
        m_isBold = value;
        emit isBoldChanged();
    }
}

void UniFont::setIsUnderLine( const bool value ) {
    if ( m_isUnderline != value ) {
        m_isUnderline = value;
        emit isUnderLineChanged();
    }
}

void UniFont::setIsItalic( const bool value ) {
    if ( m_isItalic != value ) {
        m_isItalic = value;
        emit isItalicChanged();
    }
}

void UniFont::setFontSize( const int value ) {
    if ( m_fontSize != value ) {
        m_fontSize = value;
        emit isFontSizeChanged();
    }
}
