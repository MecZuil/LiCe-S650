import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Window 2.0
import QtGraphicalEffects 1.0

Rectangle {
    id: share_box

    property int screen_width : qml_port.get_screen_width();
    property int screen_height : qml_port.get_screen_height();

    width: share_box.screen_width / 2.2
    height: share_box.screen_height / 2.5
    visible: true
    focus: true
    //radius: change_model.is_640x480_size() ? 12: 6
    z : 10
    signal ok_btn_clicked()
    signal cancel_btn_clicked()
    property alias text: prompt_text.text
    color: "#7CA6C9"
    border.color: "black"
    border.width: change_model.is_640x480_size() ? 1:0


    Image{
        id:back_img
        anchors.centerIn: parent;
        width: share_box.width - 6
        height: share_box.height - 6
        smooth: true
        //source: change_model.is_640x480_size() ? "":qml_port.get_img_qml_res_path() + "images/load_last_set_bg.png"
        source: qml_port.get_img_qml_res_path() + "images/setting_background.png"
        visible: true
    }

    Text{
        id: prompt_text
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.top: parent.top
        anchors.topMargin: share_box.width / 20
        font.pixelSize: share_box.width / 15
        wrapMode: Text.WrapAnywhere

        width: share_box.width - share_box.width/20
        height:  font.pixelSize * 2 + 10
        font.bold: true
        elide: Text.ElideMiddle
        color: "#7CA6C9"
        maximumLineCount: 2
    }

    Rectangle  {
        id: b_messgae_yes
        anchors.top: parent.top
        anchors.topMargin: parent.height * 0.6
        anchors.left: parent.left
        anchors.leftMargin: parent.width / 8
        width: parent.width / 4
        height: parent.height * 0.2
        color: "transparent"
        focus: false
        //radius: 6
        signal agin_set_updown_disable();
        Text{
            anchors.centerIn: parent
            font.pixelSize: share_box.width / 20
            color: "#7CA6C9"
            text: " 确   定"
        }
        Image {
            id: yesImage
            anchors.fill: parent
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
                yesImage.focus = false
                yesImage.source = qml_port.get_img_qml_res_path() + "images/ok_button_n.png"
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
        anchors.topMargin: parent.height * 0.6
        anchors.left: b_messgae_yes.right
        anchors.leftMargin: parent.width/4
        width: parent.width / 4
        height: parent.height * 0.2
        color: "transparent"
        focus: false
        Text{
            anchors.centerIn: parent
            font.pixelSize: share_box.width / 20
            color: "#7CA6C9"
            text: " 取   消"
        }
        Image {
            id: noImage
            anchors.fill: parent
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
                noImage.focus = false
                noImage.source = qml_port.get_img_qml_res_path() + "images/ok_button_n.png"
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

    function init_dlg() {
        console.log("#### [MessageBoxEx] [init_dlg] : running . . .\r\n\r\n")
        share_box.focus = true
        b_message_no.focus = false
        b_messgae_yes.focus = false
        noImage.source = qml_port.get_img_qml_res_path() + "images/ok_button_n.png"
        yesImage.source = qml_port.get_img_qml_res_path() + "images/ok_button_n.png"
    }

    Keys.enabled: true
    Keys.onReleased: {
        console.log("#### [MessageBoxEx] [Keys.onReleased] ------>");
        switch(event.key) {
            case qml_port.get_keyValue_from_up():  //上
                break;
            case qml_port.get_keyValue_from_down():  //下
                break;
            case qml_port.get_keyValue_from_left():  //左
                if(share_box.focus)
                    b_message_no.focus = true
                else if(b_message_no.focus)
                    b_messgae_yes.focus = true
                else if(b_messgae_yes.focus)
                    b_message_no.focus = true
                yesImage.yesImage_source()
                noImage.noImage_source()
                break;
            case qml_port.get_keyValue_from_right():  //右
                if(share_box.focus)
                    b_messgae_yes.focus = true
                else if(b_messgae_yes.focus)
                    b_message_no.focus = true
                else if(b_message_no.focus)
                    b_messgae_yes.focus = true
                yesImage.yesImage_source()
                noImage.noImage_source()
                break;
            case qml_port.get_keyValue_from_center():  //中
                if(b_messgae_yes.focus) {
                    b_messgae_yes.focus = false
                    yesImage.yesImage_source()
                    share_box.ok_btn_clicked()
                }
                else if(b_message_no.focus) {
                    b_message_no.focus = false
                    noImage.noImage_source()
                    share_box.cancel_btn_clicked()
                }
                break;
        }
        event.accepted = true
    }

    Component.onCompleted: {
        share_box.focus = true
        b_message_no.focus = false
        b_messgae_yes.focus = false
        noImage.source = qml_port.get_img_qml_res_path() + "images/ok_button_n.png"
        yesImage.source = qml_port.get_img_qml_res_path() + "images/ok_button_n.png"

        console.log("MessageBoxEx : width:" + share_box.width + ", height:" + share_box.height);
    }
}


