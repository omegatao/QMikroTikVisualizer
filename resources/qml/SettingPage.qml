import QtQuick
import QtQuick.Controls

Item {
    Column{
        anchors.fill: parent
        Row{
            Text {
                id: userName
                text: qsTr("User Name:")
            }

            TextField{
                id: userNameEdit
                placeholderText: qsTr("input the user name in your MikroTik router")
            }
        }

        Row{
            Text {
                id: routerAddress
                text: qsTr("Router IP Address:")
            }

            TextField{
                id: routerAddressEdit
                placeholderText: qsTr("192.168.1.1")
            }

    }

}
