#include "unicolorsolid.h"

UniColorSolid::UniColorSolid(QObject *parent) : QObject(parent) {
    LoadDefault();
}

void UniColorSolid::LoadDefault() {
    m_background = QColor::fromRgba(0x70FF00FF);
}

bool UniColorSolid::Load( const QJsonDocument &doc ) {

    return false;
}

void UniColorSolid::setBackground ( const QColor value) {
    if ( m_background != value ) {
        m_background = value;
        emit backgroundChanged();
    }
}

void UniColorSolid::setBorder ( const QColor value ) {
    if ( m_border != value ) {
        m_border = value;
        emit borderChanged();
    }
}

void UniColorSolid::setText ( const QColor value ) {
    if ( m_text != value ) {
        m_text = value;
        emit textChanged();
    }
}
