import QtQuick 2.0

Rectangle {
    id: interaction_dlg

    property int screen_width: qml_port.get_screen_width()
    property int screen_height: qml_port.get_screen_height()

    x:0
    y:0
    width: interaction_dlg.screen_width / 2.5
    height: interaction_dlg.screen_height / 2.5
    color: "#7CA6C9"
    visible: true
    z : 10

    signal sig_sure_click()
    signal sig_cancel_click()

    Rectangle {
        anchors.centerIn: parent
        x: parent.x
        y: parent.y
        width: parent.width * 0.96
        height: parent.height * 0.96
        /* 背景图 */
        Image {
            id: back_img
            anchors.fill: parent
            source: qml_port.get_img_qml_res_path() + "images/setting_background.png"
        }
        /* 提示文本 */
        Text {
            id: msg_txt
            anchors.top: parent.top
            anchors.topMargin: parent.height * 0.2
            font.pixelSize: parent.width / 10
            color: "#7CA6C9"
            maximumLineCount: 2
            font.bold: true
            text: "    执 行 操 作 ?"
        }
        /* 确定按键 */
        Rectangle {
            id: btn_sure
            anchors.top: parent.top
            anchors.topMargin: parent.height * 0.6
            anchors.left: parent.left
            anchors.leftMargin: parent.width / 12
            width: parent.width / 3
            height: parent.height / 4
            color: "transparent"
            Text {
                anchors.centerIn: parent
                color: "#7CA6C9"
                font.pixelSize: parent.width / 5
                text: qsTr("确 定")
            }
            Image {
                id: btn_sure_img
                anchors.fill: parent
                source: qml_port.get_img_qml_res_path() + (btn_sure.focus?"images/ok_button_s.png":"images/ok_button_n.png")
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                }
                onPressed: {
                    btn_sure.focus = true
                }
                onReleased: {
                    interaction_dlg.focus = true
                    sig_sure_click()
                }
            }
        }
        /* 取消按键 */
        Rectangle {
            id: btn_cancel
            anchors.top: parent.top
            anchors.topMargin: parent.height * 0.6
            anchors.right: parent.right
            anchors.rightMargin: parent.width / 12
            width: parent.width / 3
            height: parent.height / 4
            color: "transparent"
            Text {
                anchors.centerIn: parent
                color: "#7CA6C9"
                font.pixelSize: parent.width / 5
                text: qsTr("取 消")
            }
            Image {
                id: btn_cancel_img
                anchors.fill: parent
                source: qml_port.get_img_qml_res_path() + (btn_cancel.focus?"images/ok_button_s.png":"images/ok_button_n.png")
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                }
                onPressed: {
                    btn_cancel.focus = true
                }
                onReleased: {
                    interaction_dlg.focus = true
                    sig_cancel_click()
                }
            }
        }
    }
}
