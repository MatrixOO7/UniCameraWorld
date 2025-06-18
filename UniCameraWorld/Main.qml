import QtQuick
import QtQuick.Controls
import QtQuick.Layouts


Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    color: "#2A2A2A"

    //property double sideMenuWidth: root.width / 3
    property double sideMenuWidth: root.width - 150

    Image {
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        source: "Resource/Image/logo.png"
    }

    Drawer{
        id: sideMenu
        height: root.height
        width: root.sideMenuWidth
        property double buttonsHeight: 40

        background: Rectangle {
            color: "#903A3A3A"
            border.width: 0
        }

        ColumnLayout {
            id: sideMenuLayout
            anchors.fill: parent
            Layout.fillWidth: true
            anchors.margins: 16
            spacing: 10

            UniLabel {
                id: titleText
                Layout.preferredHeight: 50
                Layout.fillWidth: true
                label: "Menu"
                enableHover: true
                isBold: true
                fontSize: 30
                backGroundColor: "transparent"
                borderColor: "transparent"
                hoverColor: "#C49700"
                textColor: "#E5E4E2"
            }

            ScrollView {
                Layout.fillHeight: true
                Layout.fillWidth: true
                //Layout.preferredWidth: titleText.width
                ScrollBar.horizontal.policy: ScrollBar.AlwaysOff

                ColumnLayout {
                    id: scrollMenuArea
                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    UniButton {
                        Layout.preferredWidth: titleText.width
                        Layout.preferredHeight: sideMenu.buttonsHeight
                        label: "Home"
                    }

                    UniButton {
                        Layout.preferredWidth: titleText.width
                        Layout.preferredHeight: sideMenu.buttonsHeight
                        label: "Foto výbava"
                        onIsClicked: {
                            console.debug ("Test clicked")
                        }
                    }

                    UniButton {
                        Layout.preferredWidth: titleText.width
                        Layout.preferredHeight: sideMenu.buttonsHeight
                        label: "Planovani"
                    }
                }
            }

            ColumnLayout {
                Layout.preferredHeight: 50
                Layout.fillWidth: true
                UniButton {
                    Layout.fillWidth: true
                    Layout.preferredHeight: sideMenu.buttonsHeight
                    label: "Nastaveni tématu"
                    onIsClicked: {
                        appSetting.enabled = false
                    }
                }

                UniButton {
                    Layout.fillWidth: true
                    Layout.preferredHeight: sideMenu.buttonsHeight
                    label: "Nastaveni účtu"
                    onIsClicked: {
                        appSetting.enabled = true
                    }
                }

                UniButton {
                    id: appSetting
                    Layout.fillWidth: true
                    Layout.preferredHeight: sideMenu.buttonsHeight
                    label: "Nastaveni aplikace"
                    onIsClicked: {
                        console.debug ("Test disabled clicked")
                    }
                }
            }
        }
    }
}
