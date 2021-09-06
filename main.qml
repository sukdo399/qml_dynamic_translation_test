import QtQuick 2.15

Rectangle {
    id: rect
    width: 340; height: 150

    Column {
        MyText {
            //% "Hello"
            text: qsTrId("Hello")// + rootItem.emptyString
        }
    }

    Row {
        anchors.verticalCenter: parent.verticalCenter
        Button { label: "English"; onClicked: rootItem.selectLanguage("en"); }
        Button { label: "Korean"; onClicked: rootItem.selectLanguage("ko"); }
        Button { label: "French"; onClicked: rootItem.selectLanguage("fr"); }
    }
}
