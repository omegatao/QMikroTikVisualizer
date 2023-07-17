import QtQuick
import QtWebEngine

Item {
    id: echartsView
    WebEngineView{
        anchors.fill: parent
        url: "qrc:/pages/connectionInfo.html"
        id: webView
    }
}
