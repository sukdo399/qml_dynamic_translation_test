import QtQuick 2.15

Item  {
    id: control

    width: originText.implicitWidth
    height: originText.implicitHeight

    property string text: ""

    Text {
        id: originText
        width: control.width
        height: control.height
        text: qsTr(control.text) + rootItem.emptyString
    }
}
