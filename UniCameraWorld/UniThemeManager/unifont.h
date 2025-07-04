#ifndef UNIFONT_H
#define UNIFONT_H

#include <QObject>
#include <QQmlEngine>

class UniFont
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString fontFamily READ getFontFamily WRITE setFontFamily NOTIFY fontChanged FINAL)
    Q_PROPERTY(bool isBold READ getIsBold WRITE setIsBold NOTIFY fontChanged FINAL)
    Q_PROPERTY(bool IsUnderLine READ getIsUnderLine WRITE setIsUnderLine NOTIFY fontChanged FINAL)
    Q_PROPERTY(bool isItalic READ getIsItalic WRITE setIsItalic NOTIFY fontChanged FINAL)
    Q_PROPERTY(int fontSize READ getFontSize WRITE setFontSize NOTIFY fontChanged FINAL)

signals:
    void fontLoad();

public:
    UniFont();
    QString getFontFamily() const { return fontFamily; }
    bool getIsBold() const { return isBold; }
    bool getIsUnderLine() const { return isUnderline; }
    bool getIsItalic() const { return isItalic; }
    int getFontSize() const { return fontSize; }

    void setFontFamily( const QString value );
    void setIsBold( const bool value );
    void setIsUnderLine( const bool value );
    void setIsItalic( const bool value );
    void setFontSize( const int value );

private:
    QString fontFamily;
    bool isBold;
    bool isUnderline;
    bool isItalic;
    int fontSize;

    void LoadDefault();
    bool Load(QString path);
};

#endif // UNIFONT_H
