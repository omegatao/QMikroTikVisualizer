import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: statusBar
    property int fontPixelSize: 30
    property var textColor: "white"
    Rectangle{
        anchors.fill: parent
        color: "black"
        Button{
            id:homeButton
            text: "Home"
            font.pixelSize: fontPixelSize
            anchors{
                left: parent.left
                top: parent.top
            }
            height: parent.height
            onClicked: mainLoader.source = "StackViewPage.qml"
        }

        RowLayout{
            id:statusTextRow
            anchors{
                right: parent.right
                top: parent.top
            }
            height: parent.height
            spacing: 10.0

            Text {
                id: cpuUsageStatus
                text: qsTr("CPU:95%")
                font.pixelSize: fontPixelSize
                color: textColor
            }

            Text {
                id: tempStatus
                text: qsTr("40℃")
                font.pixelSize: fontPixelSize
                color: textColor
            }

            Text {
                id: currentTime
                text: qsTr("13:21 PM")
                font.pixelSize: fontPixelSize
                color: textColor
            }

        }
    }
}
