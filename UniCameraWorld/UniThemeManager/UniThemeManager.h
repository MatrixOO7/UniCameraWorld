#ifndef UNITHEMEMANAGER_V_1
#define UNITHEMEMANAGER_V_1

#include <QObject>
#include <QQmlEngine>
#include <QColor>

class UniThemeManager : public QObject {
    Q_OBJECT

    Q_PROPERTY(QColor btnBackGround READ btnBackGround WRITE setBtnBackGround NOTIFY btnBackGroundChanged FINAL)

public:
    explicit UniThemeManager ( QObject *parent = nullptr );
    QColor btnBackGround ();

    void setBtnBackGround ( const QColor newColor );

signals:
    void btnBackGroundChanged();

private:
    QColor m_btnBackGround = QColor("#FFFF00");
};

#endif
