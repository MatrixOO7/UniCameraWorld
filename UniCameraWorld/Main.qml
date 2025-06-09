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
        Rectangle {
            anchors.fill: parent
            color: "#3A3A3A"

            ColumnLayout {
                id: sideMenuLayout
                anchors.fill: parent
                anchors.margins: 16
                spacing: 10

                UniLabel {
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

                ColumnLayout {
                    Layout.fillHeight: true
                    UniButton {
                        Layout.fillWidth: parent
                        Layout.preferredHeight: sideMenu.buttonsHeight
                        label: "Foto výbava"
                        onIsClicked: {
                            console.debug ("Test clicked")
                        }
                    }

                    UniButton {
                        Layout.fillWidth: parent
                        Layout.preferredHeight: sideMenu.buttonsHeight
                        label: "Planovani"
                    }
                }

                ColumnLayout {
                    Layout.preferredHeight: 50
                    UniButton {
                        Layout.fillWidth: parent
                        Layout.preferredHeight: sideMenu.buttonsHeight
                        label: "Nastaveni tématu"
                        onIsClicked: {
                            appSetting.enabled = false
                        }
                    }

                    UniButton {
                        Layout.fillWidth: parent
                        Layout.preferredHeight: sideMenu.buttonsHeight
                        label: "Nastaveni účtu"
                        onIsClicked: {
                            appSetting.enabled = true
                        }
                    }

                    UniButton {
                        id: appSetting
                        Layout.fillWidth: parent
                        Layout.preferredHeight: sideMenu.buttonsHeight
                        label: "Nastaveni aplikace"
                       // enabled: false
                        onIsClicked: {
                            console.debug ("Test disabled clicked")
                        }
                    }
                }
            }
        }
    }
}
