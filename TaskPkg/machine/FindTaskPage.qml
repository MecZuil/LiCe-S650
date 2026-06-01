import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Layouts 1.0
import QtQuick.Window 2.0


Rectangle {
    id: find_task_dlg

    property int screen_width : qml_port.get_screen_width()
    property int screen_height : qml_port.get_screen_height()

    x: 0
    y: 0
    width: find_task_dlg.screen_width
    height: find_task_dlg.screen_height
    color: "transparent"
    focus: true
    //FocusScope: true

    property int gn_title_bar_height: height/4
    property int gn_show_rows: 5
    property int gn_current_page: 1
    property int gn_current_index: -1
    property int gn_total_page: 1
    property int gn_total_count: 0
    property string gs_current_folder_name: ""
    property int n_sd_status: 0
    property bool gn_current_st: false

    signal fresh_selected_task();
    signal return_selected_from_fingPage();

    MouseArea {
        anchors.fill: parent
        onClicked: {
        }
    }

    Image {
        id: back_img
        anchors.fill: parent
        width: parent
        height: parent
        source: qml_port.get_img_qml_res_path() + "images/setting_background.png"    //作业包选择图片
        visible: true
    }

    function init_list_model() {
        gn_current_page = 1
        gn_total_page = 1
        gn_total_count =  0
        gn_total_count = file_list.get_import_task_file_count()
        if( gn_total_count > 0 ) gn_current_page = 1
        gn_total_page = gn_total_count/gn_show_rows + (gn_total_count%gn_show_rows>0?1:0)

        update_task_select_model()
    }

    function update_select_task_list() {
        gn_total_count = file_list.get_import_task_file_count()
        gn_total_page = gn_total_count/gn_show_rows + (gn_total_count%gn_show_rows>0?1:0)
        update_task_select_model()
    }

    function update_task_select_model() {
        task_find_model.clear()
        console.log("FindTaskPage.qml update_task_select_model-----------1111111111", gn_current_page, gn_total_page);
        if( gn_current_page < gn_total_page ) {
            for( var i = (gn_current_page-1)*gn_show_rows; i < gn_current_page*gn_show_rows; ++i ) {
                task_find_model.append( {"name":file_list.get_import_task_file_name( i ), "value_index": i%5, "select_btn_st":file_list.get_find_task_btn_status( i % gn_show_rows, gn_current_page, gn_show_rows)} )
            }
            if( gn_current_page == 1 ) {
                btn_pre.enabled = false
            } else {
                btn_pre.enabled = true
            }

            btn_next.enabled = true
        } else if( gn_current_page == gn_total_page ) {
            for( var j = (gn_current_page-1)*gn_show_rows; j < gn_total_count; ++j ) {
                task_find_model.append( {"name": file_list.get_import_task_file_name( j ), "value_index": j%5, "select_btn_st":file_list.get_find_task_btn_status( j % gn_show_rows, gn_current_page, gn_show_rows) } )
            }
            if( gn_current_page == 1 ) {
                btn_pre.enabled = false
            } else {
                btn_pre.enabled = true
            }

            btn_next.enabled = false
        } else {
            console.log("update_task_select_model ----------- 0000", file_list.get_import_task_file_count());
            for(var n = 0; n < file_list.get_import_task_file_count(); ++n ){
                console.log("update_task_select_model ----------- ", file_list.get_import_task_file_name( n ));
                task_find_model.append( {"name": QStringfile_list.get_import_task_file_name( n ), "value_index": n%5, "select_btn_st":file_list.get_find_task_btn_status( n % gn_show_rows, gn_current_page, gn_show_rows) } )
            }
            btn_pre.enabled = false
            btn_next.enabled = false
        }
        task_list_view.focus = true
        update_btn()
    }

    Rectangle {
        id: fild_task_window
        anchors.fill: parent
        color: "transparent"

        /*************************************
          * 标题栏
          */
        Rectangle {
            id: find_task_bar
            color: "transparent"
            width: parent.width
            height: gn_title_bar_height   //高度为总高度度四分之一
            //border.width: 1

            Text {
                id: title_text
                anchors.centerIn: parent
                text: qsTr("SD卡中发现作业包")
                color: "#7CA6C9"
                font.pixelSize: find_task_dlg.screen_width/15
            }
        }

        /*******************************
          * 内容列表
          */
        ListModel{
            id: task_find_model
        }

        Component {
            id: task_find_delegate
            Rectangle {
                id: delegate_cell
                width: parent.width
                height: gn_title_bar_height*0.5
                color: "transparent"
                property int n_index: value_index
                property bool b_selected: select_btn_st

                Image {
                    anchors.fill: parent
                    source: (n_index == gn_current_index)?qml_port.get_img_qml_res_path()  + "images/select_pkg.png":""
                }
                MouseArea {
                    anchors.fill: parent
                    anchors.rightMargin: 200
                    onClicked: {
                        gn_current_index = n_index
                        task_list_view.focus = true
                    }
                }

                Row {
                    anchors.fill: parent
                    anchors.leftMargin: 20
                    anchors.rightMargin: 20
                    spacing: parent.width - row_name.width - find_task_dlg.screen_width/4

                    Row {
                        id: row_name
                        anchors.verticalCenter: parent.verticalCenter
                        width: image_task.width + text_task_name.width + 10
                        spacing: 10
                        Image {
                            id: image_task
                            source: qml_port.get_img_qml_res_path() + "images/task_pkg.png"
                        }

                        Text {
                            id: text_task_name
                            height: parent.height
                            verticalAlignment: Text.AlignVCenter
                            text: name
                            font.pixelSize: find_task_dlg.screen_width / 30
                            color: "#7CA6C9"
                        }
                    }

                    Rectangle {
                        id: select_btn
                        anchors.right: parent.right
                        anchors.rightMargin: find_task_dlg.screen_width / 24
                        anchors.verticalCenter: parent.verticalCenter
                        width: find_task_dlg.screen_width / 14
                        height: find_task_dlg.screen_height / 15
                        visible: true
                        radius: 6
                        color: "transparent"
                        BorderImage {
                            id: back
                            visible: true
                            anchors.fill: parent
                            source:  qml_port.get_img_qml_res_path() + (delegate_cell.b_selected ? "images/switch_on.png" : "images/switch_off.png")
                        }

                        MouseArea{
                            id: btn_area
                            anchors.fill: parent
                            onClicked: {
                                gn_current_index = n_index
                                delegate_cell.b_selected = !file_list.get_find_task_btn_status(index, gn_current_page, gn_show_rows)
                                file_list.set_find_task_btn_status( index, gn_current_page, gn_show_rows, delegate_cell.b_selected );
                                btn_import_new_task.enabled = file_list.has_select_import_task()
                                update_btn()
                                update_task_select_model()
                            }
                        }
                    }
                }
                Rectangle {
                    anchors.left: parent.left
                    anchors.bottom: parent.bottom
                    height: 1
                    width: parent.width
                    visible:  true
                    color: "#E4E4E4"
                }
            }
        }

        ListView {
            id: task_list_view
            anchors.top: find_task_bar.bottom
            width: parent.width
            height: gn_title_bar_height*2.5
            delegate: task_find_delegate
            model: task_find_model
            interactive: false
            focus: true

            Component.onCompleted: {
                console.log("FindTaskPage.qml --------------------1111111111")
                file_list.get_import_task_file_list()
                find_task_dlg.init_list_model()
                file_list.init_find_task_selected_list( file_list.get_import_task_file_count() );
            }

            Timer {
                id: detect_sd_timer
                interval: 500
                running: true
                repeat: true
                onTriggered: {
                    var n_inserted = qml_port.is_inserted_sd()?2:1                    
                    if( find_task_dlg.n_sd_status == 0 ) {                     
                        find_task_dlg.n_sd_status = n_inserted;
                    } else {
                        if( n_inserted !== find_task_dlg.n_sd_status ) {
                            find_task_dlg.n_sd_status = n_inserted;
                            btn_import_new_task.enabled = false;

                            file_list.get_import_task_file_list()
                            find_task_dlg.init_list_model()
                            file_list.clear_find_task_selected_list( );
                            file_list.init_find_task_selected_list( file_list.get_import_task_file_count() );                       
                            update_btn()
                        }
                    }
                }
            }
        }

        Rectangle {//按钮
            id: rect_operator_btn
            anchors.top: task_list_view.bottom
            width: parent.width
            height: gn_title_bar_height*0.5
            color: "transparent"
            Row {
                anchors.fill: parent
                anchors.leftMargin: (parent.width - btn_pre.width*3 - btn_import_new_task.width - 3 * 50 )/2
                anchors.rightMargin: (parent.width - btn_pre.width*3 - btn_import_new_task.width - 3 * 50 )/2
                anchors.bottomMargin: 10
                spacing: 15
                ItemAllStyle {
                        id: item_all_style
                    }

                Rectangle {     //返回图标按钮
                    id: btn_return
                    width: find_task_dlg.screen_width / 12
                    height: find_task_dlg.screen_height / 7
                    color: "transparent"
                    Image {
                        id: btn_return_img
                        anchors.fill: parent
                        source: btn_return_img_source()
                        function btn_return_img_source() {
                            if(btn_return.enabled) {
                                if(btn_return.focus) {
                                    btn_return_img.source = qml_port.get_img_qml_res_path() + "images/back_s.png"
                                } else {
                                    btn_return_img.source = qml_port.get_img_qml_res_path() + "images/back_n.png"
                                }
                            } else {
                                btn_return_img.source = qml_port.get_img_qml_res_path() + "images/back_d.png"
                            }
                        }
                    }
                    MouseArea {
                        anchors.fill: parent
                        onPressed: {
                            return_selected_from_fingPage()
                            rect_task_list.focus = true
                            update_btn();
                            btn_return_img.source = qml_port.get_img_qml_res_path() + "images/back_s.png"
                        }
                        onReleased: {
                            update_btn();
                        }
                        onClicked: {
                            find_task_dlg.fresh_selected_task();
                            find_task_dlg.destroy()
                        }
                    }
                }

                Rectangle {     //左切图标按钮
                    id: btn_pre
                    width: find_task_dlg.screen_width / 12
                    height: find_task_dlg.screen_height / 7
                    //style: item_all_style.stylePrePage
                    color: "transparent"
                    enabled: true
                    Image {
                        id: btn_pre_img
                        anchors.fill: parent
                        source: btn_pre_img_source()
                        function btn_pre_img_source() {
                            if(btn_pre.enabled) {
                                if(btn_pre.focus) {
                                    btn_pre_img.source = qml_port.get_img_qml_res_path() + "images/pre_page_s.png"
                                } else {
                                    btn_pre_img.source = qml_port.get_img_qml_res_path() + "images/pre_page_n.png"
                                }
                            } else {
                                btn_pre_img.source = qml_port.get_img_qml_res_path() + "images/pre_page_d.png"
                            }
                        }
                    }
                    MouseArea {
                        anchors.fill: parent
                        onPressed: {
                            rect_task_list.focus = true
                            update_btn();
                            btn_pre_img.source = qml_port.get_img_qml_res_path() + "images/pre_page_s.png"
                        }
                        onReleased: {
                            update_btn()
                        }
                        onClicked: {
                            console.log("#### [TaskSelectList] [btn_pre] : clicked ！！！");
                            btn_pre.btn_pre_disp()
                        }
                    }

                    function btn_pre_disp()
                    {
                        if( gn_current_page > 1 && gn_current_page <= gn_total_page ) {
                            gn_current_page -= 1
                            gn_current_index = -1
                            update_select_task_list()
                        }
                    }
                }

                Rectangle {
                    width: find_task_dlg.screen_width / 12
                    height: find_task_dlg.screen_height / 7
                    anchors.topMargin: 30
                    color: "transparent"
                    Text {
                        font.pixelSize: find_task_dlg.screen_width / 20
                        anchors.centerIn: parent
                        color: "#7CA6C9"
                        text: qsTr(gn_current_page + "/" + gn_total_page)
                    }
                }

                Rectangle {    //右切图标按钮
                    id: btn_next
                    width: find_task_dlg.screen_width / 12
                    height: find_task_dlg.screen_height / 7
                    color: "transparent"
                    enabled: true
                    Image {
                        id: btn_next_img
                        anchors.fill: parent
                        source: btn_next_img_source()
                        function btn_next_img_source() {
                            if(btn_next.enabled) {
                                if(btn_next.focus) {
                                    btn_next_img.source = qml_port.get_img_qml_res_path() + "images/next_page_s.png"
                                } else {
                                    btn_next_img.source = qml_port.get_img_qml_res_path() + "images/next_page_n.png"
                                }
                            } else {
                                btn_next_img.source = qml_port.get_img_qml_res_path() + "images/next_page_d.png"
                            }
                        }
                    }
                    MouseArea {
                        anchors.fill: parent
                        onPressed: {
                            rect_task_list.focus = true
                            update_btn();
                            btn_next_img.source = qml_port.get_img_qml_res_path() + "images/next_page_s.png"
                        }
                        onReleased: {
                            update_btn();
                        }
                        onClicked: {
                            btn_next.btn_next_disp()
                        }
                    }

                    function btn_next_disp() {
                        if( gn_current_page < gn_total_page ) {
                            gn_current_index = -1
                            gn_current_page += 1
                            update_select_task_list()
                        }
                    }
                }

                Rectangle {
                    id: btn_import_new_task
                    width: find_task_dlg.screen_width / 12
                    height: find_task_dlg.screen_height / 7
                    color: "transparent"
                    enabled: false
                    Image {
                        id: btn_import_new_task_img
                        anchors.fill: parent
                        source: btn_import_new_task_source()
                        function btn_import_new_task_source() {
                            if(btn_import_new_task.enabled) {
                                if(btn_import_new_task.focus) {
                                    btn_import_new_task_img.source = qml_port.get_img_qml_res_path() + "images/load_s.png"
                                } else {
                                    btn_import_new_task_img.source = qml_port.get_img_qml_res_path() + "images/load_n.png"
                                }
                            } else {
                                btn_import_new_task_img.source = qml_port.get_img_qml_res_path() + "images/load_d.png"
                            }
                        }
                    }
                    MouseArea {
                        anchors.fill: parent
                        onPressed: {
                            return_selected_from_fingPage()
                            rect_task_list.focus = true
                            update_btn();
                            btn_import_new_task_img.source = qml_port.get_img_qml_res_path() + "images/load_s.png"
                        }
                        onReleased: {
                            update_btn();
                        }
                        onClicked: {
                            btn_import_new_task.btn_import_disp()
                        }
                    }

                    function btn_import_disp() {
                        package_progress.visible = true//显示导入进度
                        find_task_dlg.set_enable_status( false )//禁止当前页面的所有按钮
                        page_num.text = file_list.get_task_progress_num()
                        progress_bar.minimumValue = 0;
                        progress_bar.maximumValue = file_list.get_progress_max_value();
                        file_list.import_task();
                        file_list.clear_find_task_selected_list( );
                    }
                }
            }
        }
    }

    function set_enable_status( b_enable ) {
        btn_pre.enabled = b_enable
        btn_return.enabled = b_enable
        btn_next.enabled = b_enable
        btn_import_new_task.enabled = b_enable
        task_list_view.enabled = b_enable
    }

    Rectangle {     //显示导入进度
        id: package_progress
        x: find_task_dlg.screen_width / 3
        y: find_task_dlg.screen_height / 3
        width: find_task_dlg.screen_width / 3
        height: find_task_dlg.screen_height / 3
        visible: false
        color: "#7CA6C9"

        Image {
            id: frame_back
            width: parent.width - 6
            height: parent.height - 6
            anchors.centerIn: parent
            source: qml_port.get_img_qml_res_path()  + "images/setting_background.png"
        }
        Text {
            renderType : Text.NativeRendering
            id: import_title
            anchors.top: parent.top
            anchors.topMargin: parent.height / 2
            anchors.horizontalCenter: parent.horizontalCenter
            color: "#7CA6C9"
            font.pixelSize: find_task_dlg.screen_width / 30
            text: "导入进度"
        }
        ProgressBar {
            id: progress_bar
            width: parent.width * 0.8
            anchors.left: parent.left
            anchors.leftMargin: parent.width * 0.1
            anchors.top: parent.top
            anchors.topMargin: parent.height / 12
            anchors.horizontalCenter: parent.horizontalCenter
            value: 0.5

            style: ProgressBarStyle {
                background: Rectangle {
                    radius: 12
                    color: "lightgray"
                    border.color: "gray"
                    border.width: 1
                    implicitWidth: find_task_dlg.screen_width/3
                    implicitHeight: 14
                }
                progress: Rectangle {
                    radius: 12
                    color: "blue"
                    border.color: "blue"
                }
            }

        }
        Text {
            renderType : Text.NativeRendering
            id: page_num
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 9
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: find_task_dlg.screen_width / 32
            color: "#7CA6C9"
        }
    }

    Connections {
        target: file_list
        onChangeValue: {
            progress_bar.value = n_progress_value;
        }
        onImportFinished: {
            //find_task_dlg.b_import_task = false
            //find_task_dlg.set_enable_status( true )
            find_task_dlg.fresh_selected_task();
            find_task_dlg.destroy();
        }
        onTask_bag_progress_num: {
            page_num.text = s_task_progress_num;
        }
    }

    function update_btn() {
        btn_return_img.btn_return_img_source()
        btn_pre_img.btn_pre_img_source()
        btn_next_img.btn_next_img_source()
        btn_import_new_task_img.btn_import_new_task_source()
    }

    function get_key_up() {
        console.log("#### [FindTaskPage] [Keys] : UP . . .")
        if(!btn_return.focus && !btn_pre.focus && !btn_next.focus && !btn_import_new_task.focus && !task_list_view.focus) {
            btn_return.focus = true
        } else if (btn_return.focus || btn_pre.focus || btn_next.focus || btn_import_new_task.focus) {
            if(task_find_model.count > 0) {
                task_list_view.focus = true
                gn_current_index = task_find_model.count - 1
            }
        } else if (task_list_view.focus) {
            --gn_current_index
            if(gn_current_index < 0)
                btn_return.focus = true
        }
        update_btn()
    }

    function get_key_down() {
        console.log("#### [FindTaskPage] [Keys] : DOWN . . .")
        if(!btn_return.focus && !btn_pre.focus && !btn_next.focus && !btn_import_new_task.focus && !task_list_view.focus) {
            if(task_find_model.count > 0) {
                gn_current_index = 0
                task_list_view.focus = true
            } else {
                btn_return.focus = true
            }
        } else if (task_list_view.focus) {
            ++gn_current_index
            if(gn_current_index >= task_find_model.count)
                btn_return.focus = true
        } else if (btn_return.focus || btn_pre.focus || btn_next.focus || btn_import_new_task.focus) {
            if(task_find_model.count > 0) {
                gn_current_index = 0
                task_list_view.focus = true
            }
        }
        update_btn()
    }

    function get_key_left() {
        console.log("#### [FindTaskPage] [Keys] : LEFT . . .")
        if(!btn_return.focus && !btn_pre.focus && !btn_next.focus && !btn_import_new_task.focus && !task_list_view.focus) {
            if(btn_import_new_task.enabled)
                btn_import_new_task.focus = true
            else if(btn_next.enabled)
                btn_next.focus = true
            else if(btn_pre.enabled)
                btn_pre.focus = true
            else
                btn_return.focus = true
        } else if(btn_import_new_task.focus) {
            if(btn_next.enabled)
                btn_next.focus = true
            else if(btn_pre.enabled)
                btn_pre.focus = true
            else
                btn_return.focus = true
        } else if(btn_next.focus) {
            if(btn_pre.enabled)
                btn_pre.focus = true
            else
                btn_return.focus = true
        } else if(btn_pre.focus) {
            btn_return.focus = true
        } else if(btn_return.focus) {
            if(btn_import_new_task.enabled)
                btn_import_new_task.focus = true
            else if(btn_next.enabled)
                btn_next.focus = true
            else if(btn_pre.enabled)
                btn_pre.focus = true
        }
        update_btn()
    }

    function get_key_right() {
        console.log("#### [FindTaskPage] [Keys] : RIGHT . . .")
        if(!btn_return.focus && !btn_pre.focus && !btn_next.focus && !btn_import_new_task.focus && !task_list_view.focus) {
            btn_return.focus = true
        } else if(btn_return.focus) {
            if(btn_pre.enabled)
                btn_pre.focus = true
            else if(btn_next.enabled)
                btn_next.focus = true
            else if(btn_import_new_task.enabled)
                btn_import_new_task.focus = true
        } else if(btn_pre.focus) {
            if(btn_next.enabled)
                btn_next.focus = true
            else if(btn_import_new_task.enabled)
                btn_import_new_task.focus = true
            else
                btn_return.focus = true
        } else if(btn_next.focus) {
            if(btn_import_new_task.enabled)
                btn_import_new_task.focus = true
            else
                btn_return.focus = true
        } else if(btn_import_new_task.focus) {
            btn_return.focus = true
        }

        update_btn()
    }

    function get_key_ok() {
        console.log("#### [FindTaskPage] [Keys] : OK . . .")
        if(btn_return.focus) {
            find_task_dlg.fresh_selected_task();
            find_task_dlg.destroy()
        } else if(btn_pre.focus) {
            btn_pre.btn_pre_disp()
        } else if(btn_next.focus) {
            btn_next.btn_next_disp()
        } else if(btn_import_new_task.focus) {
            btn_import_new_task.btn_import_disp()
        } else if(task_list_view.focus) {
            gn_current_st = file_list.get_find_task_btn_status(gn_current_index % gn_show_rows, gn_current_page, gn_show_rows)
            gn_current_st = !gn_current_st
            console.log("#### [FindTaskPage] [Keys] : gn_current_st = " + gn_current_st )
            file_list.set_find_task_btn_status( gn_current_index , gn_current_page, gn_show_rows, gn_current_st )
            task_find_model.set(gn_current_index, {"select_btn_st" : gn_current_st})
            btn_import_new_task.enabled = file_list.has_select_import_task()
            update_btn()
        }
    }

    function return_back_selected_page() {
        find_task_dlg.fresh_selected_task();
        find_task_dlg.destroy()
    }
}





