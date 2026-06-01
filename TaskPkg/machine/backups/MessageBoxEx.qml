import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Window 2.0
import QtGraphicalEffects 1.0

Rectangle {
    id: share_box

    width:  change_model.is_640x480_size() ? 350:200
    height: change_model.is_640x480_size() ? 200:97
    visible: true
    focus: true
    //radius: change_model.is_640x480_size() ? 12: 6
    z : 10
    signal ok_btn_clicked()
    signal cancel_btn_clicked()
    property alias text: prompt_text.text
    color: change_model.is_640x480_size() ? "#7CA6C9":"transparent"
    border.color: "black"
    border.width: change_model.is_640x480_size() ? 1:0


    Image{
        id:back_img
        anchors.centerIn: parent;
        width: (change_model.is_640x480_size() ? 350:200) - 8
        height: (change_model.is_640x480_size() ? 200:97) - 8
        smooth: true
        //source: change_model.is_640x480_size() ? "":qml_port.get_img_qml_res_path() + "images/load_last_set_bg.png"
        source: qml_port.get_img_qml_res_path() + "images/setting_background.png"
        visible: true
    }

    Text{
        id: prompt_text
        anchors.top: parent.top
        anchors.topMargin: change_model.is_640x480_size() ? 50:15
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: change_model.is_640x480_size() ? 25:18
        wrapMode: Text.WrapAnywhere

        width: share_box.width - (change_model.is_640x480_size() ? 40:18 )
        height:  font.pixelSize * 2 + 10
        font.bold: true
        elide: Text.ElideMiddle
        color: "#7CA6C9"
        maximumLineCount: 2
    }

    Rectangle  {
        id: b_messgae_yes
        anchors.top: parent.top
        anchors.topMargin: change_model.is_640x480_size() ? 130:59
        anchors.left: parent.left
        anchors.leftMargin: change_model.is_640x480_size() ? 60:20
        width: change_model.is_640x480_size() ? 100:70
        height: change_model.is_640x480_size() ? 45:28
        color: "transparent"
        focus: false
        //radius: 6
        signal agin_set_updown_disable();
        Text{
            anchors.centerIn: parent
            font.pixelSize: change_model.is_640x480_size() ? 22:15
            color: "#7CA6C9"
            text: "确定"
        }
        Image {
            id: yesImage
            source: yesImage_source()
            function yesImage_source() {
                if(b_messgae_yes.focus)
                    yesImage.source = qml_port.get_img_qml_res_path() + "images/ok_button_s.png"
                else
                    yesImage.source = qml_port.get_img_qml_res_path() + "images/ok_button_n.png"
            }
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                share_box.ok_btn_clicked();
                console.log("b_messgae_yes     ok    ok_btn_clicked----------------------------------------------");
            }
            onPressed: {
                yesImage.source = qml_port.get_img_qml_res_path() + "images/ok_button_s.png"
            }
            onReleased: {
                yesImage.source = qml_port.get_img_qml_res_path() + "images/ok_button_n.png"
            }
        }
    }
    Rectangle {
        id: b_message_no
        anchors.top: parent.top
        anchors.topMargin: change_model.is_640x480_size() ? 130:59
        anchors.left: parent.left
        anchors.leftMargin: change_model.is_640x480_size() ? 190:110
        //radius: 6
        width: change_model.is_640x480_size() ? 100:70
        height: change_model.is_640x480_size() ? 45:28
        color: "transparent"
        focus: false
        Text{
            anchors.centerIn: parent
            font.pixelSize: change_model.is_640x480_size() ? 22:15
            color: "#7CA6C9"
            text: "取消"
        }
        Image {
            id: noImage
            source: noImage_source()
            function noImage_source() {
                if(b_message_no.focus)
                    noImage.source = qml_port.get_img_qml_res_path() + "images/ok_button_s.png"
                else
                    noImage.source = qml_port.get_img_qml_res_path() + "images/ok_button_n.png"
            }
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                share_box.cancel_btn_clicked();
                console.log("b_message_no     cancel    cancel_btn_clicked---------------------onClicked-------------------------");
            }
            onPressed: {
                noImage.source = qml_port.get_img_qml_res_path() + "images/ok_button_s.png"
                console.log("b_message_no     cancel    cancel_btn_clicked---------------------onPressed-------------------------");
            }
            onReleased: {
                noImage.source = qml_port.get_img_qml_res_path() + "images/ok_button_n.png"
                console.log("b_message_no     cancel    cancel_btn_clicked---------------------onReleased-------------------------");
            }
        }
    }

    Keys.enabled: true
    Keys.onReleased: {
        console.log("#### [MessageBoxEx] [Keys.onReleased] ------>");
        switch(event.key) {
            case 0x1000037:  //上
                break;
            case 0x1000038:  //下
                break;
            case 0x1000039:  //左
                if(share_box.focus)
                    b_message_no.focus = true
                else if(b_message_no.focus)
                    b_messgae_yes.focus = true
                else if(b_messgae_yes.focus)
                    b_message_no.focus = true
                yesImage.yesImage_source()
                noImage.noImage_source()
                break;
            case 0x1000025:  //右
                if(share_box.focus)
                    b_messgae_yes.focus = true
                else if(b_messgae_yes.focus)
                    b_message_no.focus = true
                else if(b_message_no.focus)
                    b_messgae_yes.focus = true
                yesImage.yesImage_source()
                noImage.noImage_source()
                break;
            case 0x1000004:  //中
                if(b_messgae_yes.focus)
                    share_box.ok_btn_clicked();
                else if(b_message_no.focus)
                    share_box.cancel_btn_clicked();
                break;
        }
        event.accepted = true
    }
}


