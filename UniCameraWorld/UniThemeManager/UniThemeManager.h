#ifndef UNITHEMEMANAGER_V_1
#define UNITHEMEMANAGER_V_1

#include <QObject>
#include <QQmlEngine>
#include <QColor>

class UniThemeManager : public QObject {
    Q_OBJECT

    Q_PROPERTY(QColor btnBackGroundColor READ btnBackGroundColor WRITE setBtnBackGroundColor NOTIFY btnBackGroundColorChanged FINAL)
    Q_PROPERTY(QColor btnHoverColor READ btnHoverColor WRITE setBtnHoverColor NOTIFY btnHoverColorChanged FINAL)

public:
    explicit UniThemeManager ( QObject *parent = nullptr );
    QColor btnBackGroundColor ();

    void setBtnBackGroundColor ( const QColor newColor );

    QColor btnHoverColor ();

    void setBtnHoverColor ( const QColor newColor );

signals:
    void btnBackGroundColorChanged();
    void btnHoverColorChanged();

private:
    QColor m_btnBackGroundColor = QColor("#2A2A2A");
    QColor m_btnHoverColor = QColor("#383838");
    QColor m_btnBorderColor = QColor("#FFFF00");
    QColor m_btnClickedColor = QColor("#FFFF00");
    QColor m_btnEnabledColor = QColor("#FFFF00");

    QColor m_btnTxtBackGroundColor = QColor("#FFFF00");
    QColor m_btnTxtHoverColor = QColor("#FFFF00");
    QColor m_btnTxtClickedColor = QColor("#FFFF00");
    QColor m_btnTxtEnabledColor = QColor("#FFFF00");
};

#endif
