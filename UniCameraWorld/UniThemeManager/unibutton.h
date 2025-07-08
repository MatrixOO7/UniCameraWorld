#ifndef UNIBUTTON_H
#define UNIBUTTON_H

#include <QObject>
#include <QQmlEngine>

class UniButton : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit UniButton(QObject *parent = nullptr);

signals:
};

#endif // UNIBUTTON_H
