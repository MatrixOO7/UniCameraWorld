import QtQuick
import QtQuick.Controls
import QtQuick.Layouts


Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Drawer{
        id: sideMenu
        height: root.height
        width: root.width / 3
        ColumnLayout {
            id: sideMenuLayout
            spacing: 10
            Text {
                id:sideMenuTitleText
                text: "Menu"
            }
            Button {
                id: idPhoto
                Layout.preferredWidth: root.width / 3
                Text {
                    text: "Foto výbava"
                }
            }
            Button {
                Layout.preferredWidth: root.width / 3
                Text {
                    text: "Planovani"
                }
            }

            Button {
                id: idAccoun
                Layout.preferredWidth: root.width / 3
                Text {
                    text: "Účet"
                }
            }

            Button {
                id: appThemeDSelect
                Layout.preferredWidth: root.width / 3
                Text {
                    text: "Nastavení temata"
                }
            }

            Button {
                id: idConfig
                Layout.preferredWidth: root.width / 3
                Text {
                    text: "Nastavení"
                }
            }
        }
    }
}
