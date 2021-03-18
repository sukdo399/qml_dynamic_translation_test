import QtQuick 2.15
import QtQuick.Templates 2.15 as T

Item  {
    id: control

    width: originText.implicitWidth
    height: originText.implicitHeight

    property alias text: originText.text

    Text {
        id: originText
        width: control.width
        height: control.height
    }
}
