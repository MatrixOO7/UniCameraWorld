#ifndef UNICOLORSTATE_H
#define UNICOLORSTATE_H

#include <QObject>
#include <QQmlEngine>
#include <QJsonDocument>
#include "unicolorsolid.h"
#include "unicolorgradient.h"

class UniColorState : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(UniColorSolid *uniColor READ uniColor WRITE setUniColor NOTIFY uniColorChanged FINAL)
    Q_PROPERTY(UniColorGradient *uniGradient READ uniGradient WRITE setUniGradient NOTIFY uniGradientChanged FINAL)

signals:
    void uniColorChanged();
    void uniGradientChanged();

public:
    explicit UniColorState( QObject *parent = nullptr );

    void setUniColor ( UniColorSolid *value );
    void setUniGradient ( UniColorGradient *value );

    UniColorSolid *uniColor() const { return m_uniColor; }
    UniColorGradient *uniGradient() const { return m_uniGradient; }

private:
    UniColorSolid *m_uniColor;
    UniColorGradient *m_uniGradient;
};

#endif // UNICOLORSTATE_H
