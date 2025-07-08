#ifndef UNISTYLE_H
#define UNISTYLE_H

#include <QObject>
#include <QQmlEngine>
#include <QJsonDocument>

class UniStyle : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(int borderSize READ borderSize WRITE setBorderSize NOTIFY borderSizeChanged FINAL)
    Q_PROPERTY(bool isVisibleBorder READ isVisibleBorder WRITE setIsVisibleBorder NOTIFY isVisibleBorderChanged FINAL)
    Q_PROPERTY(bool isHoverEnable READ isHoverEnable WRITE setIsHoverEnable NOTIFY isHoverEnableChanged FINAL)
    Q_PROPERTY(bool isAnimationEnable READ isAnimationEnable WRITE setIsAnimationEnable NOTIFY isAnimationEnableChanged FINAL)

signals:
    void borderSizeChanged();
    void isVisibleBorderChanged();
    void isHoverEnableChanged();
    void isAnimationEnableChanged();

public:
    UniStyle( QObject *parent = nullptr );

    Q_INVOKABLE void LoadDefault();
    Q_INVOKABLE bool Load(const QString path);

    int borderSize() const { return m_borderSize; }
    bool isVisibleBorder() const { return m_isVisibleBorder; }
    bool isHoverEnable() const { return m_isHoverEnable; }
    bool isAnimationEnable() const { return m_isAnimationEnable; }

    void setBorderSize ( const int value );
    void setIsVisibleBorder( const bool value );
    void setIsHoverEnable( const bool value );
    void setIsAnimationEnable ( const bool value );

private:
    bool m_isVisibleBorder;
    int m_borderSize;
    bool m_isHoverEnable;
    bool m_isAnimationEnable;


};

#endif // UNISTYLE_H
