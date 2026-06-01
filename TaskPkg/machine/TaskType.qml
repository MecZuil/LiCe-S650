import QtQuick 2.0
import QtQuick.Controls 1.1


Rectangle {
    id : task_type

    property int screen_width: qml_port.get_screen_width()
    property int screen_height: qml_port.get_screen_height()

    width: task_type.screen_width
    height: task_type.screen_height
    color: "transparent"
    focus: true
    signal selectAllarea();
    signal selectAllDeviceType();
    property int index: 0
    property int lastIndex: 0
    property bool task_type_click: false
    property int currentTab : 0 //qml_port.get_curr_tab_show()
    signal ok_btn_click_sig()
    signal return_btn_click_sig()
    signal load_sig();

    property bool devicestype_up_status: false
    property bool devicestype_down_status: true
    property bool devicearea_up_status: false
    property bool devicearea_down_status: true

    Image {
        anchors.fill: parent
        source: qml_port.get_img_qml_res_path() + "images/setting_background.png"
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

    Rectangle {
        id: task_list_rect
        width: task_type.screen_width
        height: task_type.screen_height * 0.75
        anchors.left: parent.left
        anchors.top: task_type_header.bottom
        color: "transparent"

        ListView{       //设备类型
            id: task_list_date_true
            property int  show_index: 0
            property bool set_device_area_down_status: true
            anchors.fill: task_list_rect
            clip: true
            width: task_type.screen_width
            height: task_type.screen_height * 0.3
            visible: false
            //focus: true
            model:ListModel{ id: task_list_date }
            delegate: TasktypeDelegate {
                id: task_type_delegate;
                onCurrentItemChange : {
                    update_current_index(currentIndex)
                    task_list_rect.focus = true
                }
            }
            Component.onCompleted:  {
                task_list_date_true.init_devie_type_model()
                modify_selectall_btn_status();
                if ( task_list_date_true.count <= 5 ) {
                    set_device_area_down_status = false
                }
            }
            function init_devie_type_model() {
                task_list_date.clear();
                console.log("init_devie_type_model -----------------------111111", qml_port.get_task_type_number())
                for( var v_index = 0; v_index < qml_port.get_task_type_number(); v_index++ ) {
                    var s_txt = qml_port.get_task_type_text( v_index );
                    console.log("init_devie_type_model -----------------------222222", s_txt)
                    task_list_date.append( {"title" :s_txt, "n_index": index} );
                }
                task_list_date_true.show_index = 0
                task_btn_down.set_upDown_status()
                update_btn()
            }
        }

        ListView{       //设备区
            id: task_list_date_devise
            property int  show_index: 0
            anchors.fill: task_list_rect
            clip: true
            width: task_type.screen_width
            height: task_type.screen_height * 0.3
            visible: true
            //focus: true
            model:ListModel{ id: task_list_devise }
            delegate: TaskContentDelegate{
                id: task_area_delegate;
                onCurrentItemChange : {
                    update_current_index(currentIndex)
                    task_list_rect.focus = true
                }
            }
            Component.onCompleted:  {
                task_list_date_devise.init_device_area_model()
            }

            function init_device_area_model() {
                task_list_devise.clear();
                console.log("init_device_area_model -----------------------111111", qml_port.get_task_area_number())
                for( var v_index = 0; v_index < qml_port.get_task_area_number(); v_index++ ) {
                    var s_txt = qml_port.get_task_area_text( v_index );
                    task_list_devise.append( {"title": s_txt, "n_index": index} );
                }
                task_list_date_devise.show_index = 0;
                task_btn_down.set_upDown_status()
                update_btn()
            }
        }
    }

    function update_current_index(tmp_index) {
        task_type.index = tmp_index
        if(task_list_date_devise.visible) {
            if(task_list_date_devise.count > 0) {
                task_list_date_devise.show_index = task_type.index
                task_list_devise.set(task_type.lastIndex, {"n_index": tmp_index})
                task_list_devise.set(task_type.index, {"n_index": task_type.index})
            }
        }
        if(task_list_date_true.visible) {
            if(task_list_date_true.count > 0) {
                task_list_date_true.show_index = task_type.index
                task_list_date.set(task_type.lastIndex, {"n_index": tmp_index})
                task_list_date.set(task_type.index, {"n_index": task_type.index})
            }
        }
        task_type.lastIndex = task_type.index
        task_btn_down.set_upDown_status()
        update_btn()
    }

    Rectangle{//area
        id: task_type_header
        width: task_type.screen_width
        height: task_type.screen_height / 4
        anchors.left: parent.left
        anchors.top: parent.top
        color: "transparent"
        Rectangle {//area    左边设备区图片
            id: task_type_img
            width: task_type.screen_width / 2 - 5
            height: task_type.screen_height / 4
            anchors.left: parent.left
            anchors.leftMargin: 1
            anchors.top: parent.top
            color: "transparent"
            Image {
                id: task_type_back
                anchors.fill: parent
                source: qml_port.get_img_qml_res_path() + (task_list_date_devise.visible?"images/title_devicearea_s.png":"images/title_devicearea_n.png");
            }
            Image {
                id: task_type_front
                anchors.fill: parent
                source: task_type_img.focus?(qml_port.get_img_qml_res_path()+"images/button_st_s.png"):"";
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    task_type.focus = true
                    task_type.update()
                    task_type_img.deviceArea_clicked()
                }
            }

            function deviceArea_clicked() {
                if(task_list_devise.count > 0) {
                    task_list_date.set(index, {"n_index": 0})
                    task_list_date.set(0, {"n_index": 0})
                    task_list_devise.set(index, {"n_index": 0})
                    task_list_devise.set(0, {"n_index": 0})
                }
                task_list_date_devise.positionViewAtBeginning(0)
                task_list_date_devise.show_index = 0
                task_type.index = 0
                task_type.lastIndex = 0
                task_list_date_devise.visible = true
                task_list_date_true.visible = false
                task_btn_down.set_upDown_status();
                task_type_click = false;
                modify_selectall_btn_status();
                update_btn()
            }
        }

        Rectangle {   //右边设备类型图片
            id: task_device_type
            width: task_type.screen_width / 2 - 5
            height: task_type.screen_height / 4
            anchors.left: task_type_img.right
            anchors.top: parent.top
            color: "transparent"
            Image {
                id: task_device_type_back
                anchors.fill: parent
                source: qml_port.get_img_qml_res_path() + (task_list_date_true.visible?"images/title_devicelist_s.png":"images/title_devicelist_n.png")
            }
            Image {
                id: task_device_type_front
                anchors.fill: parent
                source: task_device_type.focus?(qml_port.get_img_qml_res_path()+"images/button_st_s.png"):"";
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    task_type.focus = true
                    task_type.update()
                    task_device_type.deviceType_clicked()
                }
            }

            function deviceType_clicked() {
                if( task_type_click ) {
                    return;
                }
                if(task_list_date.count > 0) {
                    task_list_devise.set(index, {"n_index": 0})
                    task_list_devise.set(0, {"n_index": 0})
                    task_list_date.set(index, {"n_index": 0})
                    task_list_date.set(0, {"n_index": 0})
                }
                task_list_date_true.positionViewAtBeginning(0);
                task_list_date_true.show_index = 0
                task_type.index = 0
                task_type.lastIndex = 0
                task_list_date_devise.visible = false
                task_list_date_true.visible = true
                task_list_date_true.init_devie_type_model();
                task_btn_up.task_page_up()
                task_btn_down.set_upDown_status()
                task_type_click = true;
                modify_selectall_btn_status();
                update_btn()
            }
        }
    }

    Timer{
        id: task_ok_timer
        interval: 100
        repeat: false
        running: false
        triggeredOnStart: false
        onTriggered: {
            qml_port.regist_success_slot();
        }
    }

    ExpandMethodPage {
        id: expand_way_msg
        visible: false
        onExpand_way_changed: {
            console.log("#### [TaskType] [expand_way_msg] : onExpand_way_changed ");
            expand_way_msg.visible = false;
            qml_port.set_device_tree_expand_way( n_way )
            ok_btn_click();
        }
    }

    Connections {
        target: qml_port
        onStart_parse_task_pack_sig: {
            task_message_b.open_task_msg_box( true );
            task_message_b.visible = true;
            task_ok_timer.start();
        }
    }

    MessageTaskBox{             //缺少qml文件不存在
        id: task_message_b
        anchors.verticalCenter: parent.verticalCenter
        visible: false
    }

    Rectangle{
        id: task_type_foot
        width: task_type.screen_width
        height: task_type.screen_height / 8
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        color: "transparent"

        Rectangle{  //上一页
            id: task_btn_up
            x : task_type.screen_width / 7
            width: task_type.screen_width / 15
            height: task_type.screen_width / 15
            anchors.verticalCenter: parent.verticalCenter
            property bool type_up_temp: true
            property bool area_up_temp: true
            enabled: false
            color: "transparent"
            BorderImage {
                anchors.fill: parent
                id: task_btn_up_front
                visible: true
                width: parent.width
                height: parent.height
                source: update_pre_source()
                function update_pre_source() {
                    if(task_btn_up.enabled) {
                        if(task_btn_up.focus)
                            task_btn_up_front.source = qml_port.get_img_qml_res_path() + "images/pre_page_s.png"
                        else
                            task_btn_up_front.source = qml_port.get_img_qml_res_path() + "images/pre_page_n.png"
                    } else {
                        task_btn_up_front.source = qml_port.get_img_qml_res_path() + "images/pre_page_d.png"
                    }
                }
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    task_btn_up.task_page_up()
                    task_btn_down.set_upDown_status ();
                    update_btn()
                }
                onPressed: {
                    task_type.focus = true
                    task_type.update_btn()
                    task_btn_up_front.source = qml_port.get_img_qml_res_path() + "images/pre_page_s.png"
                }
                onReleased: {
                    task_type.update_btn()
                }
            }
            function task_page_up() {
                if ( task_list_date_true.visible ) {
                    task_list_date_true.positionViewAtIndex( ( task_list_date_true.show_index - 5 - task_list_date_true.show_index % 5 >= 0  )
                                                            ? task_list_date_true.show_index = task_list_date_true.show_index - 5 - task_list_date_true.show_index % 5 : 0  , ListView.Beginning )
                    task_type.index = task_list_date_true.show_index
                }
                if ( task_list_date_devise.visible ) {
                    task_list_date_devise.positionViewAtIndex( ( task_list_date_devise.show_index - 5 - task_list_date_devise.show_index % 5 >= 0  )
                                                              ? task_list_date_devise.show_index = task_list_date_devise.show_index - 5 - task_list_date_devise.show_index % 5 : 0  , ListView.Beginning )
                    task_type.index = task_list_date_devise.show_index
                }
                update_current_index(task_type.index)
            }
        }

        Rectangle{      //下一页
            id: task_btn_down
            x : task_type.screen_width / 2.4
            width: task_type.screen_width / 15
            height: task_type.screen_width / 15
            anchors.verticalCenter: parent.verticalCenter
            property bool area_down_temp: true
            property bool type_down_temp: true
            enabled: task_list_date_devise.count > 5
            color: "transparent"
            BorderImage{
                id: task_btn_down_front
                anchors.fill: parent
                visible: true
                width: parent.width
                height: parent.height
                source: update_next_source()
                function update_next_source() {
                    if(task_btn_down.enabled) {
                        if(task_btn_down.focus)
                            task_btn_down_front.source = qml_port.get_img_qml_res_path() + "images/next_page_s.png"
                        else
                            task_btn_down_front.source = qml_port.get_img_qml_res_path() + "images/next_page_n.png"
                    } else {
                        task_btn_down_front.source = qml_port.get_img_qml_res_path() + "images/next_page_d.png"
                    }
                }
            }

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    task_btn_down.task_page_down()
                    task_btn_down.set_upDown_status();
                    update_btn()
                }
                onPressed: {
                    task_type.focus = true
                    task_type.update_btn()
                    task_btn_down_front.source = qml_port.get_img_qml_res_path() + "images/next_page_s.png"
                }
                onReleased: {
                    task_type.update_btn()
                    task_btn_down_front.source = qml_port.get_img_qml_res_path() + "images/next_page_n.png"
                }
            }

            function set_upDown_status() {
                devicearea_down_status = false
                devicearea_up_status = false
                if(index >= 5)
                    devicearea_up_status = true
                if ( task_list_date_true.visible ) {//area up
                    if(task_list_date_true.count - 5 > index) {
                        devicearea_down_status = true
                    }
                } else if ( task_list_date_devise.visible ) {
                    if(task_list_date_devise.count - 5 > index) {
                        devicearea_down_status = true
                    }
                }

                set_upDown_enable( devicearea_up_status, devicearea_down_status )
            }

            function set_upDown_enable( upEnabled, downEnabled ) {
                task_btn_down.enabled = downEnabled;
                task_btn_up.enabled = upEnabled;
                update_btn()
            }

            function task_page_down( ) {
                if ( task_list_date_true.visible == true ) {
                    task_list_date_true.positionViewAtIndex( ( task_list_date_true.show_index + 5 - task_list_date_true.show_index % 5 <= task_list_date_true.count - 1 )
                                                            ? task_list_date_true.show_index = task_list_date_true.show_index + 5 - task_list_date_true.show_index % 5 : task_list_date_true.show_index , ListView.Beginning );
                    task_type.index = task_list_date_true.show_index
                }
                if ( task_list_date_devise.visible == true) {
                    task_list_date_devise.positionViewAtIndex( ( task_list_date_devise.show_index + 5 - task_list_date_devise.show_index % 5 <= task_list_date_devise.count - 1 )
                                                              ? task_list_date_devise.show_index = task_list_date_devise.show_index + 5 - task_list_date_devise.show_index % 5 : task_list_date_devise.show_index , ListView.Beginning );
                    task_type.index = task_list_date_devise.show_index
                }
                update_current_index(task_type.index)
            }
        }

        Rectangle{      //返回键
            id: task_btn_return
            x : task_type.screen_width / 3.4
            width: task_type.screen_width / 15
            height: task_type.screen_width / 15
            anchors.verticalCenter: parent.verticalCenter
            color: "transparent"
            BorderImage{
                id: task_return_image
                anchors.fill: parent
                visible: true
                width: parent.width
                height: parent.height
                source: qml_port.get_img_qml_res_path() + "images/back_n.png"
                function update_return_source() {
                    if(task_btn_return.focus)
                        task_return_image.source = qml_port.get_img_qml_res_path() + "images/back_s.png"
                    else
                        task_return_image.source = qml_port.get_img_qml_res_path() + "images/back_n.png"
                }
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    task_return_select_taskpack_page()
                }
                onPressed: {
                    task_type.focus = true
                    task_type.update_btn()
                    task_return_image.source = qml_port.get_img_qml_res_path() + "images/back_s.png";
                }
                onReleased: {
                    task_type.focus = true
                    task_type.update_btn()
                    task_return_image.source = qml_port.get_img_qml_res_path() + "images/back_n.png";
                }
            }
        }

        Rectangle{
            id: task_btn_ok
            x : task_type.screen_width / 1.8
            width: task_type.screen_width / 15
            height: task_type.screen_width / 15
            anchors.verticalCenter: parent.verticalCenter
            color: "transparent"
            BorderImage{
                id: task_ok_image
                anchors.fill: parent
                visible: true
                width: parent.width
                height: parent.height
                source: update_ok_source()

                function update_ok_source() {
                    if(task_btn_ok.enabled) {
                        if(task_btn_ok.focus)
                            task_ok_image.source = qml_port.get_img_qml_res_path() + "images/load_s.png"
                        else
                            task_ok_image.source = qml_port.get_img_qml_res_path() + "images/load_n.png"
                    } else {
                        task_ok_image.source = qml_port.get_img_qml_res_path() + "images/load_d.png"
                    }
                }
            }

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    if( qml_port.is_task_type_selectded() ) {
                    } else {
                        task_list_rect.enabled = false;
                        task_type_header.enabled = false;
                        task_type_foot.enabled = false;
                        expand_way_msg.visible = true;
                        expand_way_msg.focus = true
                    }
                }
                onPressed: {
                    task_type.focus = true
                    task_btn_down.set_upDown_status()
                    task_type.update_btn()
                    task_ok_image.source = qml_port.get_img_qml_res_path() + "images/load_s.png"
                }
                onReleased: {
                    task_type.focus = true
                    task_btn_down.set_upDown_status()
                    task_type.update_btn()
                    task_ok_image.source = qml_port.get_img_qml_res_path() + "images/load_n.png"
                }
            }
            Component.onCompleted: {
                set_ok_btn_status();
            }
        }

        Rectangle{
            id: task_btn_choose
            x : task_type.screen_width / 1.4
            width: task_type.screen_width / 15
            height: task_type.screen_width / 15
            anchors.verticalCenter: parent.verticalCenter
            color: "transparent"
            BorderImage{
                id: task_choose_image
                anchors.fill: parent
                width: parent.width
                height: parent.height
                source: update_choose_source()

                function update_choose_source() {
                    var n_count = task_type_click ? task_list_date.count : task_list_devise.count;
                    if( n_count == 0 ) {
                        task_choose_image.source = qml_port.get_img_qml_res_path() + "images/all_d.png"
                    } else {
                        if( task_type_click ) {
                            if( qml_port.is_task_type_select_all() ) {
                                if(task_btn_choose.focus)
                                    task_choose_image.source = qml_port.get_img_qml_res_path() + "images/all_2_s.png"
                                else
                                    task_choose_image.source = qml_port.get_img_qml_res_path() + "images/all_2_n.png"
                            } else {
                                if(task_btn_choose.focus)
                                    task_choose_image.source = qml_port.get_img_qml_res_path() + "images/all_s.png"
                                else
                                    task_choose_image.source = qml_port.get_img_qml_res_path() + "images/all_n.png"
                            }
                        } else {
                            if( qml_port.is_task_area_select_all() ) {
                                if(task_btn_choose.focus)
                                    task_choose_image.source = qml_port.get_img_qml_res_path() + "images/all_2_s.png"
                                else
                                    task_choose_image.source = qml_port.get_img_qml_res_path() + "images/all_2_n.png"
                            } else {
                                if(task_btn_choose.focus)
                                    task_choose_image.source = qml_port.get_img_qml_res_path() + "images/all_s.png"
                                else
                                    task_choose_image.source = qml_port.get_img_qml_res_path() + "images/all_n.png"
                            }
                        }
                    }
                }
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    task_btn_choose.choose_clicked()
                }
                onPressed: {
                }
                onReleased: {
                }
            }

            function choose_clicked() {
                if ( task_type_click ) {
                    if( !qml_port.is_task_type_select_all() )
                        qml_port.select_all_task_type_clicked();
                    else
                        qml_port.select_no_task_type_clicked();
                    selectAllDeviceType();
                } else if( !task_type_click ) {
                    if( !qml_port.is_task_area_select_all() )
                        qml_port.select_all_task_area_clicked();
                    else
                        qml_port.select_no_task_area_clicked();
                    selectAllarea();
                }
                set_ok_btn_status();
                modify_selectall_btn_status();
            }
        }
    }

    function task_return_select_taskpack_page() {
        console.log("\r\n#### [TaskType] [task_return_select_taskpack_page] : running . . .\r\n");
        task_message_b.open_task_msg_box( false );
        task_type.focus = false;
        return_btn_click_sig();
        task_type.destroy();
    }

    Connections {
        target: qml_port
        onSignal_reset_dlg: {
            console.log("\r\n#### [TaskType] [onSignal_reset_dlg] : running . . .\r\n");
            task_message_b.open_task_msg_box( false );
            task_type.visible = false;
            return_btn_click_sig();
            task_type.destroy();
        }
    }

    function ok_btn_click() {
        ok_btn_click_sig();
    }

    function modify_selectall_btn_status() {
        var n_count = task_type_click ? task_list_date.count : task_list_devise.count;
        if( n_count == 0 ) {
            task_choose_image.source = qml_port.get_img_qml_res_path() + "images/all_d.png"
        } else {
            if( task_type_click ) {
                if( qml_port.is_task_type_select_all() ) {
                    task_choose_image.source = qml_port.get_img_qml_res_path() + "images/all_2_n.png"
                } else {
                    task_choose_image.source = qml_port.get_img_qml_res_path() + "images/all_n.png"
                }
            } else {
                if( qml_port.is_task_area_select_all() ) {
                    task_choose_image.source = qml_port.get_img_qml_res_path() + "images/all_2_n.png"
                } else {
                    task_choose_image.source = qml_port.get_img_qml_res_path() + "images/all_n.png"
                }
            }
        }
    }

    function set_ok_btn_status() {
        if( qml_port.is_task_type_selectded( ) ) {
            task_btn_ok.enabled = false;
            task_ok_image.source = qml_port.get_img_qml_res_path() + "images/load_d.png"
        } else {
            task_btn_ok.enabled = true;
            task_ok_image.source = qml_port.get_img_qml_res_path() + "images/load_n.png"
        }
    }


    function type_get_key_up() {
        console.log("#### [TaskType] [key_up] : running . . .")
        if(expand_way_msg.visible) {
            expand_way_msg.key_up()
            return
        }
        if(!task_list_rect.focus && !task_type_img.focus && !task_device_type.focus && !task_btn_up.focus &&
                !task_btn_down.focus && !task_btn_return.focus && !task_btn_ok.focus && !task_btn_choose.focus) {
            task_btn_return.focus = true
        } else if(task_btn_down.focus || task_btn_return.focus || task_btn_up.focus ||
                  task_btn_ok.focus || task_btn_choose.focus) {
           if(task_list_date.count > 0) {
               task_list_rect.focus = true
               if((index + 1) % 5 == 0) {
                   if(task_list_date_true.visible)
                       task_list_date_true.positionViewAtIndex(index, ListView.End)
                   else if(task_list_date_devise.visible)
                       task_list_date_devise.positionViewAtIndex(index, ListView.End)
               }
           } else {
               task_type_img.focus = true
           }
        } else if(task_list_rect.focus) {
            if(index > 0) {
                update_current_index(--index)
                if((index + 1) % 5 == 0) {
                    if(task_list_date_true.visible)
                        task_list_date_true.positionViewAtIndex(index, ListView.End)
                    else if(task_list_date_devise.visible)
                        task_list_date_devise.positionViewAtIndex(index, ListView.End)
                }
            } else {
                task_type_img.focus = true
            }
        } else if(task_type_img.focus || task_device_type.focus) {
            task_btn_return.focus = true
        }
        task_btn_down.set_upDown_status()
        update_btn()
    }

    function type_get_key_down() {
        console.log("#### [TaskType] [key_down] : running . . .")
        if(expand_way_msg.visible) {
            expand_way_msg.key_down()
            return
        }
        if(!task_list_rect.focus && !task_type_img.focus && !task_device_type.focus && !task_btn_up.focus &&
                !task_btn_down.focus && !task_btn_return.focus && !task_btn_ok.focus && !task_btn_choose.focus) {
            task_type_img.focus = true
        } else if(task_btn_down.focus || task_btn_return.focus || task_btn_up.focus ||
                  task_btn_ok.focus || task_btn_choose.focus) {
            task_type_img.focus = true
        } else if(task_type_img.focus || task_device_type.focus) {
            if(task_list_date.count > 0) {
                task_list_rect.focus = true
                if(index % 5 == 0) {
                    if(task_list_date_true.visible)
                        task_list_date_true.positionViewAtIndex(index, ListView.Beginning)
                    else if(task_list_date_devise.visible)
                        task_list_date_devise.positionViewAtIndex(index, ListView.Beginning)
                }
            } else {
                task_btn_return.focus = true
            }
        } else if(task_list_rect.focus) {
            if((task_list_date_true.visible && index < task_list_date.count - 1) ||
                    (task_list_date_devise.visible && index < task_list_devise.count - 1)) {
                update_current_index(++index)
                if(index % 5 == 0) {
                    if(task_list_date_true.visible)
                        task_list_date_true.positionViewAtIndex(index, ListView.Beginning)
                    else if(task_list_date_devise.visible)
                        task_list_date_devise.positionViewAtIndex(index, ListView.Beginning)
                }
            } else {
                task_btn_return.focus = true
            }
        }
        task_btn_down.set_upDown_status()
        update_btn()
    }

    function type_get_key_left() {
        console.log("#### [TaskType] [key_left] : running . . .")
        if(expand_way_msg.visible) {
            expand_way_msg.key_left()
            return
        }
        if(!task_list_rect.focus && !task_type_img.focus && !task_device_type.focus && !task_btn_up.focus &&
                !task_btn_down.focus && !task_btn_return.focus && !task_btn_ok.focus && !task_btn_choose.focus) {
            if(task_btn_choose.enabled)
                task_btn_choose.focus = true
            else if(task_btn_ok.enabled)
                task_btn_ok.focus = true
            else if(task_btn_down.enabled)
                task_btn_down.focus = true
            else
                task_btn_return.focus = true
        } else if(task_btn_choose.focus) {
            if(task_btn_ok.enabled)
                task_btn_ok.focus = true
            else if(task_btn_down.enabled)
                task_btn_down.focus = true
            else
                task_btn_return.focus = true
        } else if(task_btn_ok.focus) {
            if(task_btn_down.enabled)
                task_btn_down.focus = true
            else
                task_btn_return.focus = true
        } else if(task_btn_down.focus) {
            task_btn_return.focus = true
        } else if(task_btn_return.focus) {
            if(task_btn_up.enabled)
                task_btn_up.focus = true
            else if(task_btn_choose.enabled)
                task_btn_choose.focus = true
            else if(task_btn_ok.enabled)
                task_btn_ok.focus = true
            else if(task_btn_down.enabled)
                task_btn_down.focus = true
        } else if(task_btn_up.focus) {
            if(task_btn_choose.enabled)
                task_btn_choose.focus = true
            else if(task_btn_ok.enabled)
                task_btn_ok.focus = true
            else if(task_btn_down.enabled)
                task_btn_down.focus = true
            else
                task_btn_return.focus = true
        }else if(task_list_rect.focus) {
            if(task_list_date_true.visible)
                task_type_img.focus = true
            else if(task_list_date_devise.visible)
                task_device_type.focus = true
        } else if(task_device_type.focus) {
            task_type_img.focus = true
        } else if(task_type_img.focus) {
            task_device_type.focus = true
        }
        task_btn_down.set_upDown_status()
        update_btn()
    }

    function type_get_key_right() {
        console.log("#### [TaskType] [key_right] : running . . .")
        if(expand_way_msg.visible) {
            expand_way_msg.key_right()
            return
        }
        if(!task_list_rect.focus && !task_type_img.focus && !task_device_type.focus && !task_btn_up.focus &&
                !task_btn_down.focus && !task_btn_return.focus && !task_btn_ok.focus && !task_btn_choose.focus) {
            if(task_btn_up.enabled)
                task_btn_up.focus = true
            else
                task_btn_return.focus = true
        } else if(task_btn_up.focus) {
            task_btn_return.focus = true
        } else if(task_btn_return.focus) {
            if(task_btn_down.enabled)
                task_btn_down.focus = true
            else if(task_btn_ok.enabled)
                task_btn_ok.focus = true
            else if(task_btn_choose.enabled)
                task_btn_choose.focus = true
            else if(task_btn_up.enabled)
                task_btn_ok.focus = true
        } else if(task_btn_down.focus) {
            if(task_btn_ok.enabled)
                task_btn_ok.focus = true
            else if(task_btn_choose.enabled)
                task_btn_choose.focus = true
            else if(task_btn_up.enabled)
                task_btn_ok.focus = true
            else
                task_btn_return.focus = true
        } else if(task_btn_ok.focus) {
            if(task_btn_choose.enabled)
                task_btn_choose.focus = true
            else if(task_btn_up.enabled)
                task_btn_ok.focus = true
            else
                task_btn_return.focus = true
        } else if(task_btn_choose.focus) {
            if(task_btn_up.enabled)
                task_btn_up.focus = true
            else
                task_btn_return.focus = true
        } else if(task_list_rect.focus) {
            if(task_list_date_true.visible)
                task_type_img.focus = true
            else if(task_list_date_devise.visible)
                task_device_type.focus = true
        } else if(task_device_type.focus) {
            task_type_img.focus = true
        } else if(task_type_img.focus) {
            task_device_type.focus = true
        }

        task_btn_down.set_upDown_status()
        update_btn()
    }

    function type_get_key_ok() {
        console.log("#### [TaskType] [key_ok] : running . . .")
        if(expand_way_msg.visible) {
            expand_way_msg.key_ok()
            return
        }
        if(task_list_rect.focus) {
            if(task_list_date_true.visible) {
                qml_port.task_type_clicked(index)
                selectAllDeviceType()
            } else if(task_list_date_devise.visible) {
                qml_port.task_area_clicked(index)
                selectAllarea()
            }
            modify_selectall_btn_status()
            set_ok_btn_status()
        } else if(task_type_img.focus) {
            task_type_img.deviceArea_clicked()
        } else if(task_device_type.focus) {
            task_device_type.deviceType_clicked()
        } else if(task_btn_up.focus) {
            task_btn_up.task_page_up()
            task_btn_down.set_upDown_status ();
        } else if(task_btn_down.focus) {
            task_btn_down.task_page_down()
            task_btn_down.set_upDown_status();
        } else if(task_btn_return.focus) {
            task_return_select_taskpack_page()
        } else if(task_btn_ok.focus) {
            if( qml_port.is_task_type_selectded() ) {
            } else {
                task_btn_ok.focus = false;
                task_btn_down.set_upDown_status()
                update_btn();
                task_list_rect.enabled = false;
                task_type_header.enabled = false;
                task_type_foot.enabled = false;
                expand_way_msg.visible = true;
                expand_way_msg.focus = true
                return
            }
        } else if(task_btn_choose.focus) {
            task_btn_choose.choose_clicked()
        }

        if(!task_btn_up.enabled && task_btn_up.focus)
            task_type.focus = true
        if(!task_btn_down.enabled && task_btn_down.focus)
             task_type.focus = true
        task_btn_down.set_upDown_status()
        update_btn()
    }

    function update_btn() {
        task_btn_up_front.update_pre_source()
        task_btn_down_front.update_next_source()
        task_return_image.update_return_source()
        task_ok_image.update_ok_source()
        task_choose_image.update_choose_source()
    }

    function close_expand_dlg() {
        console.log("#### [TaskType] [close_expand_dlg] : RUN . . .")
        task_return_select_taskpack_page()
        /*
        task_message_b.open_task_msg_box( false );
        task_type.enabled = true
        task_list_rect.enabled = true;
        task_type_header.enabled = true;
        task_type_foot.enabled = true;
        task_type.focus = true
        */

    }

    Connections {
        target: qml_port
        onSignal_close_expand_dlg: {
            //close_expand_dlg();
        }
    }

    Connections {
        target: qml_port
        onSignal_init_sel: {
        }
    }
}


