#ifndef UNIBUTTON_H
#define UNIBUTTON_H

#include <QObject>
#include <QQmlEngine>
#include "unibuttonitem.h"
#include "unistyle.h"
#include "unibaseinfo.h"

class UniButton : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(UniBaseInfo *info READ info WRITE setInfo NOTIFY infoChanged FINAL)
    Q_PROPERTY(UniStyle *style READ style WRITE setStyle NOTIFY styleChanged FINAL)
    Q_PROPERTY(UniButtonItem *item READ item WRITE setItem NOTIFY itemChanged FINAL)
    Q_PROPERTY(UniButton::ButtonState buttonState READ buttonState WRITE setButtonState NOTIFY buttonStateChanged FINAL)
    Q_PROPERTY(UniButton::ButtonType buttonType READ buttonType WRITE setButtonType NOTIFY buttonTypeChanged FINAL)

signals:
    void infoChanged();
    void styleChanged();
    void itemChanged();
    void buttonStateChanged();
    void buttonTypeChanged();

public:
    enum ButtonState {
        normal,
        clicked,
        hower,
        disable
    };
    Q_ENUM(ButtonState)

    enum ButtonType {
        dark,
        light,
        modern_dark,
        modern_light,
        unicorn
    };
    Q_ENUM(ButtonType)


    explicit UniButton(QObject *parent = nullptr);

    // Q_INVOKABLE - zpristupni funkce v qml

    void setInfo( UniBaseInfo *value );
    void setStyle( UniStyle *value );
    void setItem( UniButtonItem *value );
    void setButtonState( ButtonState value );
    void setButtonType( ButtonType value );

    UniBaseInfo *info () const { return m_info; }
    UniStyle *style() const { return m_style; }
    UniButtonItem *item () const { return m_item; }
    ButtonState buttonState () const { return m_buttonState; }
    ButtonType buttonType () const { return m_buttonType; }

    Q_INVOKABLE void switchState( const ButtonState state );

private:
    UniBaseInfo *m_info;
    UniStyle *m_style;
    UniButtonItem *m_item;
    ButtonState m_buttonState = normal;
    ButtonType m_buttonType = unicorn;

    QList<UniButtonItem*> lst_item;
};

#endif // UNIBUTTON_H
