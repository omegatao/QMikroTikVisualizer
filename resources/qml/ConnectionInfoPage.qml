import QtQuick
import QtWebEngine

Item {
    id: connectionView
    WebEngineView{
        anchors.fill: parent
        url: "qrc:/pages/connectionInfo.html"
        id: connectionWebView
    }
}
