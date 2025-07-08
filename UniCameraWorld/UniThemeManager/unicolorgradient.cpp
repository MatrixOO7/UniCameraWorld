#include "unicolorgradient.h"

UniColorGradient::UniColorGradient( QObject *parent ) : QObject(parent) {}

void UniColorGradient::LoadDefault() {

}

bool UniColorGradient::Load( const QJsonDocument &doc ) {
    return false;
}

void UniColorGradient::setColorStart( const QColor value ) {
    if ( m_colorStart != value ) {
        m_colorStart = value;
        emit colorStartChanged();
    }
}

void UniColorGradient::setColorEnd( const QColor value ) {
    if ( m_colorEnd != value ) {
        m_colorEnd = value;
        emit colorStartChanged();
    }
}

void UniColorGradient::setType( const GradientType value ) {
    if ( m_type != value ) {
        m_type = value;
        emit typeChanged();
    }
}
