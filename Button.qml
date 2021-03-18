import QtQuick 2.0

Rectangle {
    id: root;
    property string label;
    signal clicked()
    width: 120
    height: 30
    color: mouse.pressed ? "lightgray" : "white"
    radius: 4
    border.width: 1
    border.color: "gray"
    MouseArea {
        id: mouse
        anchors.fill: parent
        onClicked: root.clicked();
    }
    Text {
        anchors.centerIn: parent
        text: root.label
    }
}
