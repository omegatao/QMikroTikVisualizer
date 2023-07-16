import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    anchors.fill: parent
    anchors.centerIn: parent
    StackView{
        id:stackView
        anchors.fill: parent
        initialItem: "GridOne.qml"
    }

}
