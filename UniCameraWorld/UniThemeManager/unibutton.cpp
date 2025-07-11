#include "unibutton.h"

UniButton::UniButton(QObject *parent)
    : QObject{parent} {
    m_info = new UniBaseInfo(this);
    m_style = new UniStyle(this);
    m_item = new UniButtonItem(this);

    UniButtonItem *itm = new UniButtonItem(this);
    itm->uniColorState()->uniColor()->setBackground(QColor::fromRgba(0x70FF00FF));

    lst_item.append(itm);
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

void UniButton::switchState( const ButtonState state ) {
    switch ( state ) {
    case normal:
        m_item = lst_item[0];
        emit itemChanged();
        break;
    case clicked:
        m_item = lst_item[1];
        emit itemChanged();
        break;
    case hower:
        m_item = lst_item[2];
        emit itemChanged();
        break;
    case disable:
        m_item = lst_item[3];
        emit itemChanged();
        break;
    default:
        m_item = lst_item[0];
        emit itemChanged();
    }
}
