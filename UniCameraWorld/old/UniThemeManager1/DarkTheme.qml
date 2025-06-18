import QtQuick


    //QColor m_btnBackGroundColor = QColor("#2A2A2A");
    //QColor m_btnHoverColor = QColor("#383838");
    //QColor m_btnBorderColor = QColor("#FFFF00");
    //QColor m_btnClickedColor = QColor("#FFFF00");
    //QColor m_btnEnabledColor = QColor("#FFFF00");

    //QColor m_btnTxtBackGroundColor = QColor("#FFFF00");
    //QColor m_btnTxtHoverColor = QColor("#FFFF00");
    //QColor m_btnTxtClickedColor = QColor("#FFFF00");
    //QColor m_btnTxtEnabledColor = QColor("#FFFF00");


Item {
    id: root
    property string themeName: "DarkTheme"
    property double version: 1.0

    UniThemeItem {
        normalBtn.backgroundColor: "red"
    }
}
