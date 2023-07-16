import QtQuick
import QtWebEngine
import QtQuick.Controls
import QtQuick.Layouts

//function addDataToView(){
//    webView.runJavaScript("document.title", function(result){console.log(result)});
//}

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("QMikroTikVisualizer")
        StatusBar{
            id: statusBar
            anchors{
                top: parent.top
                left: parent.left
                right: parent.right
            }
            height: 50
        }

        Loader{
            id: mainLoader
            anchors{
                left: parent.left
                right: parent.right
                top: statusBar.bottom
                bottom: parent.bottom
            }
            source: "StackViewPage.qml"
        }
    }
