#ifndef UNIFONT_H
#define UNIFONT_H

#include <QObject>
#include <QQmlEngine>
#include <QJsonDocument>

class UniFont : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(const QString fontFamily READ fontFamily WRITE setFontFamily NOTIFY fontChanged FINAL)
    Q_PROPERTY(bool isBold READ isBold WRITE setIsBold NOTIFY isBoldChanged FINAL)
    Q_PROPERTY(bool IsUnderLine READ isUnderLine WRITE setIsUnderLine NOTIFY isUnderLineChanged FINAL)
    Q_PROPERTY(bool isItalic READ isItalic WRITE setIsItalic NOTIFY isItalicChanged FINAL)
    Q_PROPERTY(int fontSize READ fontSize WRITE setFontSize NOTIFY isFontSizeChanged FINAL)

signals:
    void fontChanged();
    void isBoldChanged();
    void isUnderLineChanged();
    void isItalicChanged();
    void isFontSizeChanged();

public:
    explicit UniFont( QObject *parent = nullptr );

    Q_INVOKABLE void LoadDefault();
    Q_INVOKABLE bool Load( const QJsonDocument &doc );

    QString fontFamily() const { return m_fontFamily; }
    bool isBold() const { return m_isBold; }
    bool isUnderLine() const { return m_isUnderline; }
    bool isItalic() const { return m_isItalic; }
    int fontSize() const { return m_fontSize; }

    void setFontFamily( const QString value );
    void setIsBold( const bool value );
    void setIsUnderLine( const bool value );
    void setIsItalic( const bool value );
    void setFontSize( const int value );

private:
    QString m_fontFamily;
    bool m_isBold;
    bool m_isUnderline;
    bool m_isItalic;
    int m_fontSize;


};

#endif // UNIFONT_H
