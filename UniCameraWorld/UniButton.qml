import QtQuick 2.15
import QtQuick.Layouts
import UniThemeManager

Rectangle {
    id: root
    clip: true


    property string imgPath: ""
    property string label: "label"

    /*_____________[Colors]______________*/
    property color textColor: UniThemeManager.UniButton.TextColor
    property color backGroundColor:  UniThemeManager.UniButton.BackgroundColor
    property color hoverColor: UniThemeManager.UniButton.HoverBackgroundColor

    property color borderColor: UniThemeManager.UniButton.BorderColor
    property color clickedColor: UniThemeManager.UniButton.ClickedBackgroundColor
    property color enabledColor: UniThemeManager.UniButton.DisabledBackgroundColor

    property color actColor: UniThemeManager.UniButton.BackgroundColor


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
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        enabled: root.enabled

        onEntered: {
            root.actColor = root.hoverColor
        }

        onExited: {
            root.actColor = root.backGroundColor
        }

        onPressed: {
            root.actColor = root.clickedColor
            root.isPressed()
        }

        onReleased: {
            root.actColor = root.backGroundColor
            root.isReleased()
        }

        onClicked: {
            root.isClicked()
        }

        onPressAndHold:{
            root.isLongPress()
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
