import QtQuick 2.15
import QtQuick.Templates 2.12 as T

Item  {
    id: control

    width: originText.implicitWidth
    height: originText.implicitHeight

    property string text: ""

    T.Label {
        id: originText
        width: control.width
        height: control.height
        text: qsTrId(control.text) + rootItem.emptyString
    }
}
