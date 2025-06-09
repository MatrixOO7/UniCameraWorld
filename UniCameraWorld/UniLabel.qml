import QtQuick 2.15
import QtQuick.Layouts
import ThemeManager

Rectangle {
    id: root
    clip: true

    property string imgPath: ""
    property string label: "label"


    /*_____________[Colors]______________*/
    property color textColor: "#666666"
    property color backGroundColor: ThemeManager.btnBackGroundColor
    property color hoverColor: ThemeManager.btnHoverColor
    property color borderColor: "green"
    property color enabledColor: "#C6C6C6"

    property color actColor: backGroundColor

    property bool enableHover: false
    property bool isBold: false

    property int fontSize: 14
    property int borderSize: 2
    property int buttonRadius: 6



    signal isClicked()
    signal isLongPress()
    signal isPressed()
    signal isReleased()


    height: 20
    width: 200

    Behavior on color {

        ColorAnimation {
            duration: 500
        }
    }

    radius: buttonRadius
    color: backGroundColor
    border.color: borderColor
    border.width: borderSize

    RowLayout {
        anchors.fill: parent
        Image {
            Layout.fillHeight: true
            Layout.preferredWidth: parent.height
            source: root.imgPath
            visible: root.imgPath !== ""
            fillMode: Image.PreserveAspectFit
            Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
        }

        Text {
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: root.label
            color: root.textColor
            font.pixelSize: root.fontSize
            font.bold: root.isBold
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled: root.enableHover
        enabled: root.enabled

        onEntered: {
            root.actColor = root.hoverColor
        }

        onExited: {
            root.actColor = root.backGroundColor
        }
    }

    onEnabledChanged: {
        if ( enabled === false  ) {
            root.color = root.enabledColor
        } else {
            root.color = root.actColor
        }
    }

    onActColorChanged: {
        root.color = root.actColor
    }
}
