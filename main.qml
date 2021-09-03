import QtQuick 2.15
import QtQuick.Window 2.12

Window {
    visible: true
    width: 1920
    height: 720-106
    Rectangle {
        id: rect
        width: 340; height: 150

        Column {
            Text {
                text: qsTr("Hello")
            }
        }

        Row {
            anchors.verticalCenter: parent.verticalCenter
            Button { label: "English"; onClicked: rootItem.selectLanguage("en"); }
            Button { label: "Spanish"; onClicked: rootItem.selectLanguage("sp"); }
            Button { label: "French"; onClicked: rootItem.selectLanguage("fr"); }
        }
    }
}
