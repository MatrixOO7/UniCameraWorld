#include "unibuttonitem.h"

UniButtonItem::UniButtonItem(QObject *parent)
    : QObject{parent}
{
    m_uniColor = new UniColorSolid( this );
    m_uniGradient = new UniColorGradient( this );
}

void UniButtonItem::setUniColor(UniColorSolid* value) {
    if (value != m_uniColor && value != nullptr) {
        m_uniColor = value;
        emit uniColorChanged();
    }
}

void UniButtonItem::setUniGradient( UniColorGradient *value ) {
    if ( value != m_uniGradient && value != nullptr ) {
        m_uniGradient = value;
        emit uniGradientChanged();
    }
}
