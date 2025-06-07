import QtQuick
import QtQuick.Controls
import QtQuick.Layouts


Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property double sideMenuWidth: root.width / 3

    Drawer{
        id: sideMenu
        height: root.height
        width: root.sideMenuWidth
        ColumnLayout {
            id: sideMenuLayout
            anchors.fill: parent
            spacing: 10
            Text {
                Layout.preferredHeight: 10
                Layout.fillWidth: true
                id:sideMenuTitleText
                text: "Menu"
            }

            ColumnLayout {
                Layout.fillHeight: true
                UniButton {
                    Layout.fillWidth: parent
                    Layout.preferredHeight: 50
                    label: "Foto výbava"
                    onIsClicked: {
                        console.debug ("Test clicked")
                    }
                }

                UniButton {
                    Layout.fillWidth: parent
                    Layout.preferredHeight: 50
                    label: "Planovani"
                }
            }

            ColumnLayout {
                Layout.preferredHeight: 50
                UniButton {
                    Layout.fillWidth: parent
                    Layout.preferredHeight: 50
                    label: "Nastaveni tématu"
                    onIsClicked: {
                        appSetting.enabled = false
                    }
                }

                UniButton {
                    Layout.fillWidth: parent
                    Layout.preferredHeight: 50
                    label: "Nastaveni účtu"
                    onIsClicked: {
                        appSetting.enabled = true
                    }
                }

                UniButton {
                    id: appSetting
                    Layout.fillWidth: parent
                    Layout.preferredHeight: 50
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
