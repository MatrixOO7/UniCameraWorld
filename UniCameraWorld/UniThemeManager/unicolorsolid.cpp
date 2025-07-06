#include "unicolorsolid.h"

UniColorSolid::UniColorSolid(QObject *parent) {}

void UniColorSolid::LoadDefault() {

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
