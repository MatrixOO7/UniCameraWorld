#include "unibutton.h"

UniButton::UniButton(QObject *parent)
    : QObject{parent} {
    m_info = new UniBaseInfo(this);
    m_style = new UniStyle(this);
    m_item = new UniButtonItem(this);
}

void UniButton::setInfo( UniBaseInfo *value ) {
    if ( m_info != nullptr  ) {
        m_info = value;
        emit infoChanged();
    }
}

void UniButton::setStyle( UniStyle *value ) {
    if ( m_style != nullptr ) {
        m_style = value;
        emit styleChanged();
    }
}

void UniButton::setItem( UniButtonItem *value ) {
    if( m_item != nullptr ) {
        m_item = value;
        emit itemChanged();
    }
}

void UniButton::setButtonState( ButtonState value ) {
    if ( value != m_buttonState ) {
        m_buttonState = value;
        emit buttonStateChanged();
    }
}

void UniButton::setButtonType( ButtonType value ) {
    if ( value != m_buttonType ) {
        m_buttonType = value;
        emit buttonTypeChanged();
    }
}
