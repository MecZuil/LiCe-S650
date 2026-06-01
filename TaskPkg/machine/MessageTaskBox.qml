import QtQuick 2.0
import QtQuick.Controls 1.1

Rectangle {
    id: share_box_b

    property int screen_width: qml_port.get_screen_width()
    property int screen_height: qml_port.get_screen_height()

    width: share_box_b.screen_width / 2.2
    height: share_box_b.screen_height / 4
    visible: false
    anchors.centerIn: parent
    //radius: change_model.is_640x480_size() ? 12 : 6
    z : 10
    //color: "#d5d5d5"
    color: "#7CA6C9"

    Image {
        id: message_task_bake
        anchors.centerIn: parent
        width: parent.width - 6
        height: parent.height - 6
        source: qml_port.get_img_qml_res_path() + "images/setting_background.png"
        MouseArea {
            anchors.fill: parent
            onClicked: {}
        }
    }

    Text{
        id: prompt_text
        text: qsTr("加载中 ") //+ prompt_task_text.text
        color: "#7CA6C9"
        anchors.verticalCenter: share_box_b.verticalCenter
        anchors.left: share_box_b.left
        anchors.leftMargin: share_box_b.screen_width / 20
        font.pixelSize: share_box_b.screen_width / 24
        font.bold: true
    }
    Text{
        id: prompt_task_text
        text: qsTr(". . .")
        color: "#7CA6C9"
        anchors.verticalCenter: share_box_b.verticalCenter
        anchors.left: prompt_text.right
        anchors.leftMargin: 2
        font.pixelSize: share_box_b.screen_width / 24
        font.bold: true
    }
    Timer{
        id: task_box_timer
        property int b_time: 0
        interval: 500
        repeat: true
        running: false
        triggeredOnStart: true
        onTriggered: {
            b_time ++;
            if(b_time == 1){
                prompt_task_text.text = qsTr("")
            }
            if(b_time == 2){
                prompt_task_text.text = qsTr(".")
            }
            if(b_time == 3){
                prompt_task_text.text = qsTr(". .")
            }
            if(b_time == 4){
                prompt_task_text.text = qsTr(". . .")
            }
            if(b_time > 4){
                b_time = 0;
            }
        }
    }
    MouseArea{
        anchors.fill: parent
        onClicked: {
        }
        onPressed: {
        }
        onReleased: {
        }
    }

    function open_task_msg_box( b_yes ) {
        console.log("open_task_msg_box ------------------- ")
        task_box_timer.b_time = 0;
        if( b_yes ) {
            console.log("share_box_b.visible ------_____________________________________________________----true--------- ")
            share_box_b.visible = true;
            //task_box_timer.start();
        } else {
            //task_box_timer.stop();
            console.log("share_box_b.visible ------_____________________________________________________----false--------- ")
            share_box_b.visible = false
        }
    }
}

