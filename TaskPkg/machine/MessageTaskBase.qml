import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.2

Rectangle {
        id: task_messag
        property bool show_list: false;      //框中有两个 对话框   这两个bool类型度值控制这两个 对话框哪个显示  外部setProperty函数来更改这两个的值
        property bool show_list_ret: false;
        property int screen_width: qml_port.get_screen_width();
        property int screen_height: qml_port.get_screen_height();

        width: task_messag.screen_width / 2.2
        height: task_messag.screen_height / 2.5
        visible: true
        focus: true
        //radius: change_model.is_640x480_size() ? 12: 6

        signal messageOKEvent()
        signal messageCannelEvent()
        signal messageReturnOKEvent()
        signal messageReturnCannelEvent()

        MouseArea{
            anchors.fill: parent
            onClicked: {
               console.log("rect_task_list onVisibleChanged", change_model.is_640x480_size());
            }
            onPressed: {
            }
            onReleased: {
            }
        }

        function init_dlg() {
            message_box_ex.init_dlg()
        }

        MessageBoxEx {
            id: message_box_ex
            anchors.centerIn: parent
            //radius: 12
            visible: show_list
            focus: show_list
            //text: qsTr("恢复上次拍摄设备？")
            Text {
                id: text_id
                color: "#7CA6C9"
                font.pixelSize: task_messag.width / 12
                anchors.left: parent.left
                anchors.leftMargin: parent.width / 8
                anchors.top: parent.top
                anchors.topMargin: parent.height / 10
                text: qsTr("恢复上次拍摄设备？")
            }
            onOk_btn_clicked: {
                var n_flag = qml_port.get_restore_last_shoot_status_flag();   //已拍摄的设备树位置信息是否存在   空返回0  存在返回1
                if(n_flag === 1)  //存在
                {
                    qml_port.set_restore_last_shoot_status_flag(2);
                }else{ //不存在
                    qml_port.restore_last_shoot_status(true);
                    //task_messag.visible = false;
                    qml_port.set_restore_last_shoot_status_flag(0);
                    messageOKEvent(); //关闭选择窗口  InitTreeView（）
                }
            }
            onCancel_btn_clicked: {
                var n_flag = qml_port.get_restore_last_shoot_status_flag();  //已拍摄的设备树位置信息是否存在   空返回0  存在返回1
                qml_port.set_restore_last_shoot_status_flag(0);
                if(n_flag === 1)//存在
                {
                    //task_messag.visible = false;
                }else{ //不存在
                    qml_port.restore_last_shoot_status(false);
                    //task_messag.visible = false;
                }
                messageCannelEvent(); ////初始化TaskSelect界面  SlotInitTaskSelect（）
            }
        }

        MessageBoxEx {      //我看外部代码 这个对话框始终没有调用，不知道什么情况下才调用
            id: message_box_over
            anchors.centerIn: parent
            radius: 12
            visible: show_list_ret
            text: qsTr("is return?")
            onOk_btn_clicked:  {
                messageReturnOKEvent()
                qml_port.change_to_general_model_slot();
            }
            onCancel_btn_clicked:  {
                messageReturnCannelEvent()
            }
        }

        MessageTaskBox {
            id: task_message_b
            anchors.verticalCenter: parent.verticalCenter
            visible: false
        }
}
