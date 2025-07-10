import QtQuick 2.15
import QtQuick.Layouts
import UniThemeManager

Rectangle {
    id: root
    clip: true

    property string imgPath: ""
    property string label: "label"

    /*_____________[Colors]______________*/
    property color borderColor: UniThemeManager.uniButton.BorderColor

    property color actBackGroundColor: UniThemeManager.uniButton.BackgroundColor
    property color textColor: UniThemeManager.uniButton.TextColor

    property int fontSize: 14
    property int borderSize: 2
    property int buttonRadius: 6

    signal isClicked()
    signal isLongPress()
    signal isPressed()
    signal isReleased()


    height: 20
    width: 200

    radius: buttonRadius
    color: actBackGroundColor
    border.color: borderColor
    border.width: borderSize

    Behavior on color {
       ColorAnimation {
           duration: 500
       }
    }

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
            id: lbl
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
            //root.actBackGroundColor = UniThemeManager.uniButton.HoverBackgroundColor
            root.textColor = UniThemeManager.uniButton.HoverTextColor
            root.actBackGroundColor = UniThemeManager.testButton.item.uniColorState.uniColor.background
        }

        onExited: {
            root.actBackGroundColor = UniThemeManager.uniButton.BackgroundColor
            root.textColor = UniThemeManager.uniButton.TextColor
        }

        onPressed: {
            root.actBackGroundColor = UniThemeManager.uniButton.ClickedBackgroundColor
            root.textColor = UniThemeManager.uniButton.ClickedTextColor
            root.isPressed()
        }

        onReleased: {
            root.actBackGroundColor = UniThemeManager.uniButton.BackgroundColor
            root.textColor = UniThemeManager.uniButton.TextColor
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
            root.color = UniThemeManager.uniButton.DisabledBackgroundColor
        } else {
            root.color = root.actBackGroundColor
        }
    }

    onActBackGroundColorChanged: {
        root.color = root.actBackGroundColor
    }

    onTextColorChanged: {
        lbl.color = root.textColor
    }
}
