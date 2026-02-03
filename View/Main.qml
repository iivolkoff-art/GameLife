import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "Game Life"
    color: "#1a1a1a"

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        Text {
            text: "ИГРА ЖИЗНЬ"
            Layout.alignment: Qt.AlignHCenter
            Layout.topMargin: 30
            font.pixelSize: 36
            font.bold: true
            font.letterSpacing: 2
            color: "#00ff00"
        }

        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true

            TableView {
                id: tableView
                anchors.centerIn: parent
                width: Math.min(contentWidth, parent.width - 40)
                height: Math.min(contentHeight, parent.height - 40)
                columnSpacing: 1
                rowSpacing: 1
                clip: true

                delegate: Rectangle {
                    implicitWidth: 22
                    implicitHeight: 22
                    color: "#252525"
                    radius: 2

                    Text {
                        anchors.centerIn: parent
                        text: model.isAlive ? "★" : "•"
                        font.pixelSize: 20
                        color: model.isAlive ? "#00ff00" : "#444444"
                    }
                }

                model: myLifeModel
            }
        }
    }
}
