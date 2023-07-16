import QtQuick
import QtWebEngine

Item {
    id: echartsView
    WebEngineView{
        anchors.fill: parent
        url: "qrc:/pages/index.html"
        id: webView
    }
}
