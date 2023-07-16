import QtQuick
import QtWebEngine

Item {
    id: cpuInfoView
    WebEngineView{
        anchors.fill: parent
        url: "qrc:/pages/cpuInfo.html"
        id: webView
    }
}
