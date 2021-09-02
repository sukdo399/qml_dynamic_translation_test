import QtQuick 2.15
import QtQuick.Templates 2.12 as T

Item  {
    id: control

    width: originText.implicitWidth
    height: originText.implicitHeight

//    property alias text: originText.text
    property string text: ""

    Connections {
        target: rootItem
        function onLanguageChanged() {
            originText.text = qsTrId(originText.sourceText)
        }
    }

    T.Label {
        id: originText
        width: control.width
        height: control.height
        text: control.text
        property string sourceText: rootItem.getSourceText(text)
    }
}
