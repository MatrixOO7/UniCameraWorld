#include "unicolorstate.h"

UniColorState::UniColorState( QObject *parent ) : QObject(parent) {
    m_uniColor = new UniColorSolid ( this );
    m_uniGradient = new UniColorGradient ( this );
}

void UniColorState::setUniColor ( UniColorSolid *value ) {
    if ( value != nullptr ) {
        m_uniColor = value;
        emit uniColorChanged();
    }
}

void UniColorState::setUniGradient ( UniColorGradient *value ) {
    if ( value != nullptr ) {
        m_uniGradient = value;
        emit uniGradientChanged();
    }
}
