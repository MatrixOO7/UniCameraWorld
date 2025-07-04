#ifndef UNIBASEINFO_H
#define UNIBASEINFO_H

#include <QObject>
#include <QQmlEngine>

class UniBaseInfo
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString  name READ getName WRITE setName NOTIFY baseInfoChanged FINAL)
    Q_PROPERTY(QString version READ getVersion WRITE setVersion NOTIFY baseInfoChanged FINAL)
    Q_PROPERTY(QString description READ getDescription WRITE setDescription NOTIFY baseInfoChanged FINAL)
    Q_PROPERTY(QSTRING author READ getAuthor WRITE setAuthor NOTIFY baseInfoChanged FINAL)

signals:
    void baseInfoChanged();

public:
    enum class  States{
        Normal,
        Hover,
        Clicked,
        Disabled
    };
    Q_ENUM_NS(States)

    UniBaseInfo();

    QString name;
    QString version;
    QString description;
    QString author;

    QString StatesToString(States states);
    States StatesToEnum(QString asString);

    void setName( QString value );
    void setVersion( QString value );
    void setDescription( QString value );
    void setAuthor( QString value );

    QString getName() const { return name; }
    QString getVersion() const { return version; }
    QString getDescription() const { return description; }
    QString getAuthor() const { return author; }

private:
    void LoadDefault();
    bool Load(QString path);
};

#endif // UNIBASEINFO_H
