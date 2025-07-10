#ifndef UNIBUTTONITEM_H
#define UNIBUTTONITEM_H

#include <QObject>
#include <QQmlEngine>

#include "unicolorstate.h"
#include "unifont.h"

class UniButtonItem : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(UniColorState *uniColorState READ uniColorState WRITE setUniColorState NOTIFY uniColorStateChanged FINAL)
    Q_PROPERTY(UniFont *uniFont READ uniFont WRITE setUniFont NOTIFY uniFontChanged FINAL)

signals:
    void uniColorStateChanged();
    void uniFontChanged();

public:
    explicit UniButtonItem (QObject *parent = nullptr);

    void setUniColorState ( UniColorState *value );
    void setUniFont ( UniFont *value );

    UniColorState *uniColorState () const { return m_uniColorState; }
    UniFont *uniFont () const { return m_uniFont; }

private:
    UniColorState *m_uniColorState;
    UniFont *m_uniFont;
};

#endif // UNIBUTTONITEM_H
