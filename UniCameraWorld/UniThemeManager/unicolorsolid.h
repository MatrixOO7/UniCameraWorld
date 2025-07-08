#ifndef UNICOLORSOLID_H
#define UNICOLORSOLID_H

#include <QObject>
#include <QQmlEngine>
#include <QColor>
#include <QJsonDocument>

class UniColorSolid : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QColor background READ background WRITE setBackground NOTIFY backgroundChanged FINAL)
    Q_PROPERTY(QColor border READ border WRITE setBorder NOTIFY borderChanged FINAL)
    Q_PROPERTY(QColor text READ text WRITE setText NOTIFY textChanged FINAL)

signals:
    void backgroundChanged();
    void borderChanged();
    void textChanged();

public:
    explicit UniColorSolid(QObject *parent = nullptr);

    void setBackground ( const QColor value);
    void setBorder ( const QColor value );
    void setText ( const QColor value );

    Q_INVOKABLE void LoadDefault();
    Q_INVOKABLE bool Load( const QJsonDocument &doc );

    QColor background () const { return m_background; }
    QColor border () const { return m_border; }
    QColor text () const { return m_text; }

private:
    QColor m_background;
    QColor m_border;
    QColor m_text;
};

#endif // UNICOLORSOLID_H
