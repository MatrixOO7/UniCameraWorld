#ifndef UNIBASEINFO_H
#define UNIBASEINFO_H

#include <QObject>
#include <QQmlEngine>
#include <QString>
#include <QJsonDocument>

class UniBaseInfo : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString  name READ name WRITE setName NOTIFY nameChanged FINAL)
    Q_PROPERTY(QString version READ version WRITE setVersion NOTIFY versionChanged FINAL)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged FINAL)
    Q_PROPERTY(QString author READ author WRITE setAuthor NOTIFY authorChanged FINAL)

signals:
    void nameChanged();
    void versionChanged();
    void descriptionChanged();
    void authorChanged();

public:
    enum class  States{
        Normal,
        Hover,
        Clicked,
        Disabled
    };
    Q_ENUM(States)

    explicit UniBaseInfo( QObject *parent = nullptr );

    Q_INVOKABLE void LoadDefault();
    Q_INVOKABLE bool Load( const QJsonDocument &doc );

    QString StatesToString( const States states);
    States StatesToEnum( const QString asString);

    void setName( const QString value );
    void setVersion( const QString value );
    void setDescription( const QString value );
    void setAuthor( const QString value );

    QString name() const { return m_name; }
    QString version() const { return m_version; }
    QString description() const { return m_description; }
    QString author() const { return m_author; }

private:
    QString m_name;
    QString m_version;
    QString m_description;
    QString m_author;


};

#endif // UNIBASEINFO_H
