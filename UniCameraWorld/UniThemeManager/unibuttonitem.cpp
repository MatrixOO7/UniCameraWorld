#include "unibuttonitem.h"

UniButtonItem::UniButtonItem(QObject *parent)
    : QObject{parent}
{
    m_uniColorState = new UniColorState( this );
    m_uniFont = new UniFont( this );
}

void UniButtonItem::setUniColorState ( UniColorState *value ) {
    if ( value != nullptr) {
        m_uniColorState = value;
        emit uniColorStateChanged();
    }
}

void UniButtonItem::setUniFont ( UniFont *value ) {
    if (value != nullptr) {
        m_uniFont = value;
        emit uniFontChanged();
    }
}

