import QtQuick 2.0

Rectangle {  //用于显示按下Task按钮时，sd卡未插入度时候
    id: msg_dlg

    property int screen_width: qml_port.get_screen_width()
    property int screen_height: qml_port.get_screen_height()

    x: 0
    y: 0
    width: msg_dlg.screen_width / 2.5
    height: msg_dlg.screen_height / 4
    color: "#7CA6C9"
    visible: true
    z : 10
    signal return_main_page()

    Rectangle {
            anchors.centerIn: parent
            x: parent.x
            y: parent.y
            width: parent.width - 5
            height: parent.height - 5
        Image {
            id: back_img
            anchors.fill: parent
            source: qml_port.get_img_qml_res_path() + "images/setting_background.png"
        }
        Text {
            id: msg_txt
            anchors.centerIn: parent
            font.pixelSize: 18
            color: "#7CA6C9"
            maximumLineCount: 2
            font.bold: true
        }
    }
    function information( text ) {
        msg_txt.text = text;
        msg_dlg.visible = true;
        msg_timer.start();
    }
    function set_interval( s_time ){ //自定义函数   设置定时器的时间
        msg_timer.interval = s_time
    }
    Timer {                   //定时器  作用    在设置时间结束时   停止定时器，让整个框体变为不可视，相当于关闭框，发送return_main_page信号，
        id: msg_timer
        interval: 4000;
        onTriggered: {
            msg_timer.stop()
            msg_dlg.visible = false;
            return_main_page()
            msg_dlg.destroy();  //释放整个框度资源
        }
    }
    Component.onCompleted: {

    }
}

