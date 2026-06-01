import QtQuick 2.0

Rectangle {
    id: root

    property int screen_width: qml_port.get_screen_width()
    property int screen_height: qml_port.get_screen_height()

    width: parent.width
    height: root.screen_height / 8
    //property alias text: textitem.text
    property int current: n_index
    signal beclicked()
    signal currentItemChange(int currentIndex)
    color: "transparent"

    MouseArea {
        anchors.fill: parent
        visible: true
        z: 1
        onClicked: {
            currentItemChange(index)
        }
    }

    Image {
        anchors.fill: parent
        visible: true
        source: (current == index)?qml_port.get_img_qml_res_path() + "images/select_pkg.png":""
    }

    Text {
        renderType : Text.NativeRendering
        id: textitem
        color: "#7CA6C9"
        //font.bold: true
        font.pixelSize: root.screen_width / 35
        text: title
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 5
    }
    Rectangle{
        id : task_choose_box
        width: root.screen_width / 13
        height: root.screen_height / 14
        x: root.screen_width * 0.7
        z: 1
        anchors.verticalCenter: parent.verticalCenter
        color: "transparent"
        BorderImage{
            id: task_choose_box_img
            visible: true
            width: parent.width
            height: parent.height
            source: qml_port.get_img_qml_res_path() + ( get_this_selected() ? "images/switch_on.png" : "images/switch_off.png" )
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                multipleSelect_type();
            }
            onPressed: {
                currentItemChange(index)
            }
            onReleased: {
            }
        }

    }

    Rectangle {
        anchors.left: parent.left
        anchors.bottom:tasktype_delegate_rect.top
        height: 1
        width: parent.width
        visible:  true
        color: "#797979"
    }
    Rectangle {
        id: tasktype_delegate_rect
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        height: 1
        width: parent.width
        visible:  true
        color: "#E4E4E4"
    }

    MouseArea {
        id: mouse_area
        anchors.fill: parent
        onClicked: {

        }
        onPressed: {

        }
        onReleased: {

        }
    }

    Component.onCompleted: {
    }

    function multipleSelect_type () {
        //console.log( "multipleSelect_type device zone index=", index )
        qml_port.task_type_clicked( index );
        //updata task_area;
        modify_selectall_btn_status();
        if ( get_this_selected() ) {
            task_choose_box_img.source = qml_port.get_img_qml_res_path() + "images/switch_on.png";
            //console.log("fasle")
        } else {
            task_choose_box_img.source = qml_port.get_img_qml_res_path() + "images/switch_off.png";
        }
        set_ok_btn_status();
    }

    Connections {
        target: task_type
        onSelectAllDeviceType: {
            if ( get_this_selected() ) {
                task_choose_box_img.source = qml_port.get_img_qml_res_path() + "images/switch_on.png";
            }else {
                task_choose_box_img.source = qml_port.get_img_qml_res_path() + "images/switch_off.png";
            }
        }
    }


    function get_this_selected() {
        var b_ret = qml_port.get_task_type_selected( index );
        //console.log( "device zone index=", index, " b_selected=", b_ret )
        return b_ret;
    }
}
