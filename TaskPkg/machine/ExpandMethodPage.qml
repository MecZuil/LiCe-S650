import QtQuick 2.0

Rectangle {
    id: expand_method

    property int screen_width: qml_port.get_screen_width()
    property int screen_height: qml_port.get_screen_height()

    x: expand_method.screen_width/4
    y: expand_method.screen_height/4
    width: expand_method.screen_width/2
    height: expand_method.screen_height/2
    visible: false
    color: "#7CA6C9"
    property int lightIndex: -1

    signal expand_way_changed( int n_way )

    Rectangle {
        anchors.centerIn: parent
        width: parent.width - 6
        height: parent.height - 6
        Image {
            id: expand_method_back
            anchors.fill: parent
            source: qml_port.get_img_qml_res_path() + "images/setting_background.png"
        }
        Text {
            renderType : Text.NativeRendering
            id: expand_title
            anchors.top: parent.top
            anchors.topMargin: change_model.is_640x480_size() ? 16:10
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: change_model.is_640x480_size() ? 25:20
            color: "#7CA6C9"
            text: qsTr( "请选择展开方式" ) //qsTr("Please choose expand method")
        }
        GridView {
            id: expand_list
            height: change_model.is_640x480_size() ? 140 : 112
            width: change_model.is_640x480_size() ? 350 : 265
            anchors.top: expand_title.bottom
            anchors.topMargin: 8
            clip: true
            model: expand_model
            interactive: false
            cellWidth: change_model.is_640x480_size() ? 340 : 250
            cellHeight: change_model.is_640x480_size() ? 40 : 30
            currentIndex: 0
            x: change_model.is_640x480_size() ? 20 : 5
            delegate:
                Rectangle {
                    id : signal_expand_tect;
                    width: expand_list.cellWidth;
                    height: expand_list.cellHeight
                    visible: true
                    color: "transparent"
                    property int light: lIndex
                    Image {
                        anchors.fill: parent
                        source: (light == index)?(qml_port.get_img_qml_res_path() + "images/select_pkg.png"):""
                    }
                    Image {
                        id: expand_type
                        width: parent.height * 1.3
                        height: parent.height * 0.75
                        source: qml_port.get_img_qml_res_path() +
                            ( expand_list.currentIndex == index ? "images/switch_on.png":"images/switch_off.png" )
                        anchors.verticalCenter: parent.verticalCenter;
                        anchors.left: parent.left
                        anchors.leftMargin: change_model.is_640x480_size() ? 5 : 3
                    MouseArea {
                        id: expand_mouse_area
                        anchors.fill: parent;
                        onPressed: {
                            expand_list.currentIndex = index;
                            }
                        }
                    }
                    Text {
                        renderType : Text.NativeRendering
                        id: expand_txt;
                        anchors.left: expand_type.right
                        anchors.leftMargin: change_model.is_640x480_size() ? 5 : 3
                        text: expand_info
                        font.pixelSize: change_model.is_640x480_size() ? 22 : 18
                        anchors.verticalCenter: parent.verticalCenter
                        color: "#7CA6C9"
                    }
                }
            Component.onCompleted: {
                expand_list.currentIndex = 0;
            }
        }
        ListModel {
            id: expand_model
            ListElement {
                //expand_info: qsTr( "按级别分层展开" ) //qsTr( "unfold level" )
                expand_info: qsTr( "按设备区展开" ) //qsTr( "device area" )
                lIndex: -1
            }
            ListElement {
                //expand_info: qsTr( "按设备区展开" ) //qsTr( "device area" )
                expand_info: qsTr( "按设备展开" ) //qsTr( "device" )
                lIndex: -1
            }
            ListElement {
                //expand_info: qsTr( "按设备展开" ) //qsTr( "device" )
                expand_info: qsTr( "按级别分层展开" ) //qsTr( "unfold level" )
                lIndex: -1
            }
        }
        Rectangle {
            id: method_return_btn
            anchors.left: parent.left
            anchors.leftMargin: change_model.is_640x480_size() ? 120:65
            anchors.bottom: parent.bottom
            anchors.bottomMargin: change_model.is_640x480_size() ? 10:10
            width: change_model.is_640x480_size() ? 60:70
            height: change_model.is_640x480_size() ? 60:70
            color: "transparent"
            Image {
                id: method_return
                visible: true
                source: qml_port.get_img_qml_res_path() + (method_return_btn.focus?"images/back_s.png":"images/back_n.png")
                anchors.fill: parent
            }
            MouseArea {
                id: method_return_area
                anchors.fill: parent
                onPressed: {
                    method_return_btn.focus = true
                }
                onReleased: {
                    method_return_btn.focus = false
                }
                onClicked: {
                    task_list_rect.enabled = true;
                    task_type_header.enabled = true;
                    task_type_foot.enabled = true;
                    expand_method.visible = false
                }
            }
        }
        Rectangle {
            id: method_ensure_btn
            anchors.left: method_return_btn.right
            anchors.leftMargin: change_model.is_640x480_size() ? 15:40
            anchors.bottom: parent.bottom
            anchors.bottomMargin: change_model.is_640x480_size() ? 10:10
            width: change_model.is_640x480_size() ? 60:70
            height: change_model.is_640x480_size() ? 60:70
            color: "transparent"
            Image {
                id: method_ensure
                visible: true
                source:  qml_port.get_img_qml_res_path() + (method_ensure_btn.focus?"images/load_s.png":"images/load_n.png")
                anchors.fill: parent
            }

            MouseArea {
                id: method_ensure_area
                anchors.fill: parent
                onPressed: {
                    method_ensure_btn.focus = true
                }
                onReleased: {
                    method_ensure_btn.focus = false
                }
                onClicked: {
                    task_list_rect.enabled = true;
                    task_type_header.enabled = true;
                    task_type_foot.enabled = true;
                    expand_method.visible = false

                    console.log("#### [ExpandMethodPage] [method_ensure_area] : expand_list.currentIndex = " + expand_list.currentIndex);
                    //expand_method.expand_way_changed( expand_list.currentIndex );// 0 level //0:device area, 1: device
                    if(expand_list.currentIndex == 0)   //0:area 1:device 2: level
                        expand_method.expand_way_changed( 1 )
                    else if(expand_list.currentIndex == 1)
                        expand_method.expand_way_changed( 2 )
                    else if(expand_list.currentIndex == 2)
                        expand_method.expand_way_changed( 0 )
                }
            }
        }
    }

    function key_up() {
        console.log("#### [ExpandMethodPage] [key_up] : running . . .")
        if(!expand_list.focus && !method_return_btn.focus && !method_ensure_btn.focus) {
            method_ensure_btn.focus = true
        } else if(method_return_btn.focus || method_ensure_btn.focus) {
            expand_list.focus = true
            for(var i = 0; i < 3; i++)
                expand_model.set(i, {"lIndex" : lightIndex = 2})
        } else if(expand_list.focus) {
            --lightIndex
            for(var j = 0; j < 3; j++)
                expand_model.set(j, {"lIndex" : lightIndex})
            if(lightIndex < 0)
                method_ensure_btn.focus = true
        }
    }

    function key_down() {
        console.log("#### [ExpandMethodPage] [key_down] : running . . .")
        if(!expand_list.focus && !method_return_btn.focus && !method_ensure_btn.focus) {
            expand_list.focus = true
            for(var i = 0; i < 3; i++)
                expand_model.set(i, {"lIndex" : lightIndex = 0})
        } else if(method_return_btn.focus || method_ensure_btn.focus) {
            expand_list.focus = true
            for(var m = 0; m < 3; m++)
                expand_model.set(i, {"lIndex" : lightIndex = 0})
        } else if(expand_list.focus) {
            ++lightIndex
            for(var j = 0; j < 3; j++)
                expand_model.set(j, {"lIndex" : lightIndex})
            if(lightIndex >= 3)
                method_ensure_btn.focus = true
        }
    }

    function key_left() {
        console.log("#### [ExpandMethodPage] [key_left] : running . . .")
        if(!expand_list.focus && !method_return_btn.focus && !method_ensure_btn.focus) {
            method_ensure_btn.focus = true
        } else if(method_return_btn.focus)
            method_ensure_btn.focus = true
        else if(method_ensure_btn.focus)
            method_return_btn.focus = true
    }

    function key_right() {
        console.log("#### [ExpandMethodPage] [key_right] : running . . .")
        if(!expand_list.focus && !method_return_btn.focus && !method_ensure_btn.focus) {
            method_return_btn.focus = true
        } else if(method_return_btn.focus)
            method_ensure_btn.focus = true
        else if(method_ensure_btn.focus)
            method_return_btn.focus = true
    }

    function key_ok() {
        console.log("#### [ExpandMethodPage] [key_ok] : running . . .")
        if(method_return_btn.focus) {
            task_list_rect.enabled = true;
            task_type_header.enabled = true;
            task_type_foot.enabled = true;
            expand_method.visible = false
        } else if(method_ensure_btn.focus) {
            task_list_rect.enabled = true;
            task_type_header.enabled = true;
            task_type_foot.enabled = true;
            expand_method.visible = false
            expand_method.expand_way_changed( expand_list.currentIndex )
        } else if(expand_list.focus) {
            if(expand_method.lightIndex >= 0 && expand_method.lightIndex < expand_list.count)
                expand_list.currentIndex = expand_method.lightIndex
        }
    }
}


