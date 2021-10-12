import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

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

            Loader {
                id: loader
                sourceComponent: Text {
                    text: qsTr("Hello")
                }
            }

            Text {
                text: "MyHello"
            }
        }

        Row {
            anchors.verticalCenter: parent.verticalCenter
            Button {
                text: "English"
                onClicked: {
                    rootItem.selectLanguage("en")
                    loader.active = false
                    loader.active = true
                }
            }
            Button {
                text: "Spanish"
                onClicked: {
                    rootItem.selectLanguage("sp")
                    loader.active = false
                    loader.active = true
                }
            }
            Button {
                text: "French"
                onClicked: {
                    rootItem.selectLanguage("fr")
                    loader.active = false
                    loader.active = true
                }
            }
        }
    }
}
