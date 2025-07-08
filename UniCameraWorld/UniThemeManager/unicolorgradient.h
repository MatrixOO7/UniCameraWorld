#ifndef UNICOLORGRADIENT_H
#define UNICOLORGRADIENT_H

#include <QObject>
#include <QQmlEngine>
#include <QColor>
#include <QJsonDocument>

class UniColorGradient : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QColor colorStart READ colorStart WRITE setColorStart NOTIFY colorStartChanged FINAL)
    Q_PROPERTY(QColor colorEnd READ colorEnd WRITE setColorEnd NOTIFY colorEndChanged FINAL)
    Q_PROPERTY(UniColorGradient::GradientType type READ type WRITE setType NOTIFY typeChanged FINAL)



signals:
    void colorStartChanged();
    void colorEndChanged();
    void typeChanged();

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

    QColor colorStart() const { return m_colorStart; }
    QColor colorEnd () const { return m_colorEnd; }
    GradientType type () const { return m_type; }

    void setColorStart( const QColor value );
    void setColorEnd( const QColor value );
    void setType( const GradientType value );

private:
    QColor m_colorStart;
    QColor m_colorEnd;
    GradientType m_type;

};

#endif // UNICOLORGRADIENT_H
