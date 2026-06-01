import QtQuick 2.0

Rectangle {
    id: root

    property int screen_width: qml_port.get_screen_width()
    property int screen_height: qml_port.get_screen_height()

    width: parent.width
    height: root.screen_height / 8
    property alias text: textitem.text
    property int current: n_index
    signal currentItemChange(int currentIndex)
    signal beclicked()
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
        font.pixelSize: root.screen_width / 34
        text: title
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 5
    }

    Rectangle{             
        id : task_devise_box
        width:  root.screen_width / 13
        height: root.screen_height / 13
        x: root.screen_width * 0.6
        z: 1
        anchors.verticalCenter: parent.verticalCenter
        color: "transparent"
        BorderImage{
            id: task_devise_box_img
            visible: true
            width: parent.width
            height: parent.height
            source: qml_port.get_img_qml_res_path() + ( get_this_content_selected() ? "images/switch_on.png" : "images/switch_off.png" )
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                multipleSelect_devise();
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
        anchors.bottom: task_devise_rect.top
        height: 1
        width: parent.width
        visible:  true
        color: "#797979"
    }
    Rectangle {
        id: task_devise_rect
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


    function multipleSelect_devise () {
        qml_port.task_area_clicked( index );
        modify_selectall_btn_status();
        if ( get_this_content_selected() ) {
            task_devise_box_img.source = qml_port.get_img_qml_res_path() + "images/switch_on.png"
        } else {
            task_devise_box_img.source = qml_port.get_img_qml_res_path() + "images/switch_off.png"
        }
        set_ok_btn_status();
    }

    Connections {
        target: task_type
        onSelectAllarea: {
            if ( get_this_content_selected() ) {
                task_devise_box_img.source = qml_port.get_img_qml_res_path() + "images/switch_on.png";
            }else {
                task_devise_box_img.source = qml_port.get_img_qml_res_path() + "images/switch_off.png";
            }
        }
    }

    function get_this_content_selected() {
        return qml_port.get_task_area_selected( index );
    }
}
