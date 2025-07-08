#ifndef UNIBUTTONITEM_H
#define UNIBUTTONITEM_H

#include <QObject>
#include <QQmlEngine>

#include "unicolorsolid.h"
#include "unicolorgradient.h"

class UniButtonItem : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(UniColorSolid uniColor READ uniColor WRITE setUniColor NOTIFY uniColorChanged FINAL)
    Q_PROPERTY(UniColorGradient uniGradient READ uniGradient WRITE setUniGradient NOTIFY uniGradientChanged FINAL)

signals:
    void uniColorChanged();
    void uniGradientChanged();

public:
    explicit UniButtonItem(QObject *parent = nullptr);


    void setUniColor( UniColorSolid *value );
    void setUniGradient( UniColorGradient *value );

    const UniColorSolid *uniColor() const { return m_uniColor; }
    const UniColorGradient *uniGradient() const { return m_uniGradient; }

private:
    UniColorSolid *m_uniColor;
    UniColorGradient *m_uniGradient;
};

#endif // UNIBUTTONITEM_H
