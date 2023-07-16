import QtQuick
import QtQuick.Layouts

Item {
    ListModel{
        id: listModel
        ListElement{name: "CPU info"; page: "CPUInfoPage.qml"}
        ListElement{name: "Connection info"; page: "ConnectionInfoPage.qml"}
    }

    GridView{
        id: gridView
        anchors.fill: parent
        anchors.centerIn: parent
        model: listModel
        cellHeight: 240
        cellWidth: 240
        delegate: Rectangle{
            width: 200
            height: 200
            color:"gray"
            radius: 5
            Text{
                color: "white"
                text: name
                anchors.centerIn: parent
            }
            MouseArea{
                anchors.fill: parent
                onClicked: mainLoader.source = page
            }
        }
    }
}
