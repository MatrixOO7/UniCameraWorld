#ifndef UNICOLORGRADIENT_H
#define UNICOLORGRADIENT_H

#include <QObject>
#include <QQmlEngine>
#include <QColor>

class UniColorGradient : QObject
{
    Q_OBJECT
    QML_ELEMENT



signals:

public:
    enum GradientType {
        None = 0,
        Linear,
        Radial,
        EndColorCenter
    };
    Q_ENUM(GradientType)

    explicit UniColorGradient( QObject *parent = nullptr );
    Q_INVOKABLE void LoadDefault();
    Q_INVOKABLE bool Load( const QJsonDocument &doc );

private:
    QColor m_colorStart;
    QColor m_colorEnd;
    GradientType m_type;

};

#endif // UNICOLORGRADIENT_H
