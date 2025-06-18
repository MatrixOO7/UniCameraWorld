import QtQuick

QtObject {
    id: root
    UniButtonItem {
        id: normalBtn
        backgroundColor: "red"
        borderColor: "red"

    }

    UniButtonItem {
        id: cancelBtn
    }

    UniButtonItem {
        id: acceptBtn
    }

    UniLabelItem {
        id: menuLbl
    }

    UniLabelItem {
        id: labelLbl
    }

    property alias <UniButtonItem> normalBtn: normalBtn
    property alias <UniButtonItem> cancelBtn: cancelBtn
    property alias <UniButtonItem> acceptBtn: acceptBtn

    property alias <UniLabelItem> menuLbl: menuLbl
    property alias <UniLabelItem> labelLbl: labelLbl
}
