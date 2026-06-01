import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Layouts 1.0
import QtQuick.Window 2.0

//最初度界面
Rectangle {  //整个宽
    id: rect_task_list
    //anchors.fill: parent

    property bool show_list: true;
    property int screen_width: qml_port.get_screen_width();
    property int screen_height: qml_port.get_screen_height();

    width: rect_task_list.screen_width
    height: rect_task_list.screen_height
    visible: true;  //可视
    focus: show_list
    color: "transparent"  //颜色可改变
    z: 10

    property int gn_title_bar_width: width/3     //使用这个变量    宽为整个界面的三分之一
    property int gn_title_bar_height: height/4   //使用这个变量  高为整个界面的四分之一        作业包选择用来这个变量

    property int gn_show_rows: 5     //作业包的数量最多为五
    property int gn_current_index: -1
    property int gn_current_page: 1
    property int gn_total_page: 1
    property int gn_total_count: 0
    property bool btn_select_st: false
    property bool btn_delete_st: false
    property bool dlg_findPage_st: false
    property bool dlg_fingXml_st: value
    property bool dlg_taskType_st: false
    property string gs_current_folder_name: ""

    signal start_sel_taskTree()
    signal sig_return_main_wnd()     //任务包选择返回信号
    signal delete_select_task_type_form()
    signal delete_select_find_page_form()
    signal stp_show_close_screen_msgbox()
    signal restore_main_form();

    signal key_up()
    signal key_down()
    signal key_left()
    signal key_right()
    signal key_ok()
    signal type_key_up()
    signal type_key_down()
    signal type_key_left()
    signal type_key_right()
    signal type_key_ok()
    signal select_xml()

    Connections {
        target: qml_port
        onSignal_reset_dlg : {

        }
    }

    Image {
        id: back_img
        anchors.fill: parent      //填充整个矩形
        width: parent
        height: parent
        source: qml_port.get_img_qml_res_path() + "images/setting_background.png"    //作业包选择图片
        visible: true
    }

    ItemAllStyle {
        id: item_all_style
    }


    Rectangle {//整个界面按钮
        id: rect_folder_window
        anchors.fill: parent
        color: "transparent"
        Rectangle {   //顶部作业包选择图片
            id: rect_title_bar
            color: "transparent"
            width: parent.width
            height: gn_title_bar_height      //高为整个界面的四分之一
            //border.width: 2

            Text {
                anchors.centerIn: parent
                text: qsTr("作业包选择")
                color: "#7CA6C9"
                font.pixelSize: rect_task_list.screen_width / 15
            }
        }

        //中间的作业包
        ListModel{
            id: task_select_model
        }

        Component {
            id: task_select_delegate
            Rectangle {
                id: list_cell
                width: parent.width
                height: gn_title_bar_height*0.5  //高度为总高度度八分之一
                color: "transparent"
                property int cell_index: index_v

                signal delete_select_task_type_form();
                signal delete_select_task_pack_form();

                MouseArea {
                    anchors.fill: parent
                    anchors.rightMargin: 200
                    onClicked: {
                        console.log("#### [TaskSelectList] [task_select_delegate] : index_v = " + cell_index);
                        gn_current_index = cell_index
                        folder_list_view.focus = true
                    }
                }

                Image {
                    id: task_back_img
                    anchors.fill: parent
                    source: (gn_current_index == cell_index)?qml_port.get_img_qml_res_path()  + "images/select_pkg.png":""
                }

                Row {
                    anchors.fill: parent
                    anchors.leftMargin: 20
                    anchors.rightMargin: 20
                    spacing: parent.width - row_name.width - row_preview_delete.width - 40
                    Row {
                        id: row_name
                        anchors.verticalCenter: parent.verticalCenter
                        width: image_task.width + text_task_name.width + 10
                        spacing: 10  //间隔为10
                        Image { //最前面压缩包度图片
                            id: image_task
                            source: qml_port.get_img_qml_res_path() + "images/task_pkg.png"
                        }

                        Text {
                            id: text_task_name
                            height: parent.height
                            verticalAlignment: Text.AlignVCenter //文本垂直居中
                            font.pixelSize: rect_task_list.screen_width / 30
                            text: name
                            color: "#7CA6C9"
                        }
                    }
                    Row {
                        id: row_preview_delete
                        anchors.verticalCenter: parent.verticalCenter
                        spacing: 20   //两个按钮间隔20

                        Rectangle {
                            width: rect_task_list.screen_width / 12
                            height: rect_task_list.screen_height / 12
                            color: "transparent"
                            anchors.verticalCenter: parent.verticalCenter
                            Image {
                                id: img_select
                                anchors.fill: parent
                                source: qml_port.get_img_qml_res_path() + (((gn_current_index == cell_index)&&btn_select_st)?"images/button_st_s.png":"images/button_st_n.png")
                            }
                            Text {
                                anchors.centerIn: parent
                                color: "#7CA6C9"
                                font.pixelSize: rect_task_list.screen_width / 30
                                text: qsTr("选择")
                            }
                            MouseArea {
                                anchors.fill: parent
                                onClicked: {
                                    create_taskType()
                                }
                                onPressed: {
                                    btn_select_st = true
                                    gn_current_index = cell_index
                                }
                                onReleased: {
                                    btn_select_st = false
                                }
                            }
                        }

                        Rectangle {
                            width: rect_task_list.screen_width / 12
                            height: rect_task_list.screen_height / 12
                            color: "transparent"
                            anchors.verticalCenter: parent.verticalCenter
                            Image {
                                id: img_delete
                                anchors.fill: parent
                                source: qml_port.get_img_qml_res_path() + (((gn_current_index == cell_index)&&btn_delete_st)?"images/button_st_s.png":"images/button_st_n.png")
                            }
                            Text {
                                anchors.centerIn: parent
                                color: "#7CA6C9"
                                font.pixelSize: rect_task_list.screen_width / 30
                                text: qsTr("删除")
                            }
                            MouseArea {
                                anchors.fill: parent
                                onClicked: {
                                    /*
                                    gs_current_folder_name = text_task_name.text   //这个变量等于任务包度名字
                                    wnd_delte_folder.visible = true  //删除按钮框可视
                                    rect_folder_window.enabled = false  //主界面 不使能
                                    */
                                    delete_task()
                                }
                                onPressed: {
                                    btn_delete_st = true
                                    gn_current_index = cell_index
                                }
                                onReleased: {
                                    btn_delete_st = false
                                }
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

                Connections {
                    target: qml_port
                    onTask_loaded : {
                        console.log("\r\n\r\n#### [TaskSelectList] [onTask_loaded] : running . . .\r\n\r\n");
                        //rect_task_list.delete_select_task_type_form();
                        //list_cell.delete_select_task_pack_form();
                        handle_task_loaded_sig()
                    }
                }
            }
        }

        ListView {
            id: folder_list_view
            anchors.top: rect_title_bar.bottom
            width: parent.width
            height: gn_title_bar_height*2.5
            delegate: task_select_delegate
            model: task_select_model
            interactive: false
            //focus: true
        }
        Rectangle {    //底部按钮
            id: rect_operator_btn
            anchors.top: folder_list_view.bottom
            width: parent.width
            height: gn_title_bar_height*0.5   //高为目录标题的一半  目录又是界面的四分之一     高就为界面的八分之一
            color: "transparent"
            Row {
                anchors.fill: parent
                anchors.leftMargin: (parent.width - btn_pre.width*3 - btn_import_new_task.width - 3 * 50 )/2
                anchors.topMargin: 0   //顶部距离为10
                anchors.rightMargin: (parent.width - btn_pre.width*3 - btn_import_new_task.width - 3 * 50 )/2
                anchors.bottomMargin: 10  //底部距离为10
                spacing: 15     //间隔50

                Rectangle {     //返回图标按钮
                    id: btn_return
                    width: rect_task_list.screen_width / 12
                    height: rect_task_list.screen_height / 7
                    //style: item_all_style.styleReturn
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
                            rect_task_list.focus = true
                            update_btn();
                            btn_return_img.source = qml_port.get_img_qml_res_path() + "images/back_s.png"
                        }
                        onReleased: {
                            update_btn();
                        }
                        onClicked: {
                            console.log("#### [TaskSelectList] [btn_return] : clicked ！！！")
                            gn_current_index = -1
                            sig_return_main_wnd()      //发送任务包选择返回信号
                        }
                    }
                }

                Rectangle {     //左切图标按钮
                    id: btn_pre
                    width: rect_task_list.screen_width / 12
                    height: rect_task_list.screen_height / 7
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
                            update_btn();
                        }
                        onClicked: {
                            console.log("#### [TaskSelectList] [btn_pre] : clicked ！！！");
                            if( gn_current_page > 1 && gn_current_page <= gn_total_page ) {
                                gn_current_page -= 1
                                gn_current_index = -1
                                update_select_task_list()
                            }
                        }
                    }
                }

                Rectangle {
                    width: rect_task_list.screen_width / 12
                    height: rect_task_list.screen_height / 7
                    color: "transparent"
                    Text {
                        font.pixelSize: rect_task_list.screen_width / 20
                        anchors.centerIn: parent
                        color: "#7CA6C9"
                        text: qsTr(gn_current_page + "/" + gn_total_page)
                    }
                }

                Rectangle {    //右切图标按钮
                    id: btn_next
                    width: rect_task_list.screen_width / 12
                    height: rect_task_list.screen_height / 7
                    //style: item_all_style.styleNextPage
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
                            console.log("#### [TaskSelectList] [btn_next] : clicked ！！！");
                            if( gn_current_page < gn_total_page ) { //当前页数是否小于总页数
                                console.log("#### [TaskSelectList] : gn_current_page < gn_total_page")
                                gn_current_page += 1
                                gn_current_index = -1
                                update_select_task_list()
                            }
                        }
                    }
                }

                Rectangle {
                    id: btn_import_new_xml
                    width: rect_task_list.screen_width / 12
                    height: rect_task_list.screen_height / 7
                    color: "transparent"
                    enabled: true
                    Image {
                        id: btn_import_new_xml_img
                        anchors.fill: parent
                        source: btn_import_new_xml_img_source()
                        function btn_import_new_xml_img_source() {
                            if(btn_import_new_xml.enabled) {
                                if(btn_import_new_xml.focus) {
                                    btn_import_new_xml_img.source = qml_port.get_img_qml_res_path() + "images/file_s.png"
                                } else {
                                    btn_import_new_xml_img.source = qml_port.get_img_qml_res_path() + "images/file_n.png"
                                }
                            } else {
                                btn_import_new_xml_img.source = qml_port.get_img_qml_res_path() + "images/file_d.png"
                            }
                        }
                    }
                    MouseArea {
                        anchors.fill: parent
                        onPressed: {
                            console.log("#### [TaskSelectList] [btn_import_new_xml] : onPressed ！！！");
                            rect_task_list.focus = true
                            update_btn();
                            btn_import_new_xml_img.source = qml_port.get_img_qml_res_path() + "images/file_s.png"
                        }
                        onReleased: {
                            console.log("#### [TaskSelectList] [btn_import_new_xml] : onReleased ！！！");
                            update_btn();
                        }
                        onClicked: {
                            console.log("#### [TaskSelectList] [btn_import_new_xml] : onClicked ！！！");
                            btn_import_new_xml.open_findXmlPage()
                        }
                    }
                    function open_findXmlPage() {
                        if( qml_port.is_inserted_sd() ) {
                            xml_list.init_xml_list()
                            var component = Qt.createComponent( "FindTaskXml.qml" );
                            var obj = null;
                            if ( component.status === Component.Ready ) {
                                obj = component.createObject( rect_task_list, {"x": 0, "y": 0} );
                                if ( obj == null ) {
                                } else {
                                    dlg_fingXml_st = true
                                    obj.return_selected_from_findXml.connect( select_from_findXml )
                                    obj.return_return_from_findxml.connect( return_from_findXml )
                                    rect_task_list.key_up.connect(obj.get_btn_up)
                                    rect_task_list.key_down.connect(obj.get_btn_down)
                                    rect_task_list.key_left.connect(obj.get_btn_left)
                                    rect_task_list.key_right.connect(obj.get_btn_right)
                                    rect_task_list.key_ok.connect(obj.get_btn_center)

                                }
                            }
                        } else {
                            rect_task_list.enabled = false
                            var component1 = Qt.createComponent( "./MessageDialog.qml" )
                            var obj1 = null;
                            if ( component1.status === Component.Ready ) {    //组成部分就绪-组件已加载，可用于创建实例。
                                obj1 = component1.createObject( rect_task_list, {"x": 250, "y": 190} )   //如果对象创建失败，则返回null
                                if ( obj1 == null ) {
                                    console.log( "Fail creating ", fn, " object" )
                                } else {
                                    obj1.information( qsTr( "请插入SD卡" ) )
                                    obj1.return_main_page.connect( close_err_message )
                                }
                            }
                        }
                    }
                }

                Rectangle {  //导入新的作业包按钮
                    id: btn_import_new_task
                    width: rect_task_list.screen_width / 12
                    height: rect_task_list.screen_height / 7
                    //style: item_all_style.styleImportNewTask
                    color: "transparent"
                    enabled: true
                    Image {
                        id: btn_import_new_task_img
                        anchors.fill: parent
                        source: btn_import_new_task_img_source()
                        function btn_import_new_task_img_source() {
                            if(btn_import_new_task.enabled) {
                                if(btn_import_new_task.focus) {
                                    btn_import_new_task_img.source = qml_port.get_img_qml_res_path() + "images/download_s.png"
                                } else {
                                    btn_import_new_task_img.source = qml_port.get_img_qml_res_path() + "images/download_n.png"
                                }
                            } else {
                                btn_import_new_task_img.source = qml_port.get_img_qml_res_path() + "images/download_d.png"
                            }
                        }
                    }
                    MouseArea {
                        anchors.fill: parent
                        onPressed: {
                            console.log("#### [TaskSelectList] [btn_import_new_task] : onPressed ！！！");
                            rect_task_list.focus = true
                            update_btn();
                            btn_import_new_task_img.source = qml_port.get_img_qml_res_path() + "images/download_s.png"
                        }
                        onReleased: {
                            console.log("#### [TaskSelectList] [btn_import_new_task] : onReleased ！！！");
                            update_btn();
                        }
                        onClicked: {
                            console.log("#### [TaskSelectList] [btn_import_new_task] : onClicked ！！！");
                            btn_import_new_task.open_findTaskPage()
                        }
                    }
                    function open_findTaskPage() {
                        gn_current_index = -1
                        if( qml_port.is_inserted_sd() ) {
                            console.log("import task")
                            file_list.init_find_task_selected_list( file_list.get_import_task_file_count() )
                            var component = Qt.createComponent( "FindTaskPage.qml" );   //创建了这个界面
                            var obj = null;
                            console.log("btn_import_new_task"+component.errorString() )
                            if ( component.status === Component.Ready ) { //组成部分就绪-组件已加载，可用于创建实例。
                                obj = component.createObject( rect_task_list, {"x": 0, "y": 0} );  //如果对象创建失败，则返回null
                                if ( obj == null ) {
                                } else {
                                    obj.fresh_selected_task.connect( fresh_this_form );
                                    //Keys.enabled = false;
                                    //rect_task_list.focus = false
                                    dlg_findPage_st = true
                                    obj.return_selected_from_fingPage.connect( return_from_fingPage )
                                    rect_task_list.key_up.connect(obj.get_key_up)
                                    rect_task_list.key_down.connect(obj.get_key_down)
                                    rect_task_list.key_left.connect(obj.get_key_left)
                                    rect_task_list.key_right.connect(obj.get_key_right)
                                    rect_task_list.key_ok.connect(obj.get_key_ok)
                                    rect_task_list.delete_select_find_page_form.connect(obj.return_back_selected_page)
                                }
                            }
                        } else {
                            rect_task_list.enabled = false
                            var component1 = Qt.createComponent( "./MessageDialog.qml" )
                            var obj1 = null;
                            if ( component1.status === Component.Ready ) {    //组成部分就绪-组件已加载，可用于创建实例。
                                obj1 = component1.createObject( rect_task_list, {"x": 250, "y": 190} )   //如果对象创建失败，则返回null
                                if ( obj1 == null ) {
                                    console.log( "Fail creating ", fn, " object" )
                                } else {
                                    obj1.information( qsTr( "请插入SD卡" ) )
                                    obj1.return_main_page.connect( close_err_message )
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    function return_from_fingPage()
    {
        console.log("#### [TaskSelectList] [return_from_fingPage] : RUN . . .")
    }

    function return_from_findXml()
    {
        dlg_fingXml_st = false
        qml_port.fresh_select_pkg()
        init_task_select_list()
        Keys.enabled = true;
        console.log("#### [TaskSelectList] [return_from_findXml] : RUN . . .")
    }

    function select_from_findXml()
    {
        dlg_fingXml_st = false
        qml_port.fresh_select_pkg()
        init_task_select_list()
        Keys.enabled = true;
        console.log("#### [TaskSelectList] [return_from_findXml] : RUN . . .")

        select_xml()
        sig_return_main_wnd()

    }

    function return_select() {
        rect_task_list.focus = true
        rect_task_list.enabled = true
    }

    function close_err_message() {
        rect_task_list.focus = true
        rect_task_list.enabled = true
    }

    /* @ description : 初始化任务选择列表 */
    function init_task_select_list() {
        rect_task_list.focus = true
        rect_task_list.forceActiveFocus()
        Keys.enabled = true

        console.log("\r\n\r\n#### [TaskSelectList] [init_task_select_list] : running . . .\r\n");
        rect_task_list.delete_select_task_type_form();
        folder_list.get_task_select_list()
        task_select_model.clear()
        gn_total_count = folder_list.get_task_select_count()

        if( gn_total_count > 0 )
            gn_current_page = 1
        gn_total_page = gn_total_count/gn_show_rows + (gn_total_count%gn_show_rows>0?1:0)
        console.log( "init_folder_list------------ " + gn_total_count + gn_total_page + gn_current_page )

        update_task_select_model()
    }

    function reset_dlg()
    {
        console.log("\r\n\r\n#### [TaskSelectList] [reset_dlg] : running . . .\r\n\r\n");
        rect_task_list.delete_select_task_type_form();
    }

    /* description : 更新作业包选择界面 */
    function update_select_task_list() {
        /* 总数量 */
        gn_total_count = folder_list.get_task_select_count()
        /* 当页数 */
        gn_total_page = gn_total_count/gn_show_rows + (gn_total_count%gn_show_rows>0?1:0)
        update_task_select_model()
    }

    /* description : 更新作业列表容器容器 */
    function update_task_select_model() {
        task_select_model.clear()
        if( gn_current_page < gn_total_page ) {
            for( var i = (gn_current_page-1)*gn_show_rows; i < gn_current_page*gn_show_rows; ++i ) {
                task_select_model.append( {"name": folder_list.get_task_select_name( i ), "index_v": i%gn_show_rows } )
                console.log("#### [TaskSelectList] : task_name = " + folder_list.get_task_select_name( i ))
            }
            if( gn_current_page == 1 ) {
                btn_pre.enabled = false
            } else {
                btn_pre.enabled = true
            }

            btn_next.enabled = true
        } else if( gn_current_page == gn_total_page ) {
            for( var j = (gn_current_page-1)*gn_show_rows; j < gn_total_count; ++j ) {
                task_select_model.append( {"name": folder_list.get_task_select_name( j ), "index_v": j%gn_show_rows } )
                console.log("#### [TaskSelectList] : task_name = " + folder_list.get_task_select_name( i ))
            }
            if( gn_current_page == 1 ) {
                btn_pre.enabled = false
            } else {
                btn_pre.enabled = true
            }
            btn_next.enabled = false
        } else {
            for( var n = 0; n < gn_total_count; ++n) {
                task_select_model.append( {"name": folder_list.get_task_select_name( n ), "index_v": n%gn_show_rows } )
            }
            btn_pre.enabled = false
            btn_next.enabled = false
        }

        dlg_fingXml_st = false
        dlg_findPage_st = false
        rect_task_list.focus = true
        gn_current_index = -1
        btn_select_st = false
        btn_delete_st = false
        update_btn();
    }

    function fresh_this_form() {
        qml_port.fresh_select_pkg()
        init_task_select_list()
        //yes_delete.agin_set_updown_disable();
        Keys.enabled = true;
        //rect_task_list.focus = true;
    }

    Rectangle{ //按下删除所选择度任务包时 弹出度确认和取消对话框
        id: wnd_delte_folder
        anchors.centerIn: parent
        width: rect_task_list.screen_width / 2.5
        height: rect_task_list.screen_height / 2.5
        visible: false
        z: 20    //保证 它出现在最上面
        color: "#7CA6C9"

        Image {
            width: parent.width - 6
            height: parent.height - 6
            anchors.centerIn: parent
            source: qml_port.get_img_qml_res_path() + "images/setting_background.png"
        }

        Column {
            anchors.fill: parent
            anchors.leftMargin: parent.width/40
            anchors.rightMargin: parent.width/40
            anchors.topMargin: parent.height/40
            anchors.bottomMargin: parent.height/40
            spacing: parent.height / 5

            Text{
                id: text_delete_folder
                //anchors.centerIn: parent
                anchors.top: parent.top
                anchors.topMargin: parent.height / 4
                anchors.left: parent.left
                anchors.leftMargin: parent.width / 10
                color: "#7CA6C9"
                font.pixelSize: rect_task_list.screen_width / 29
                text: qsTr("删除选中的任务包？")
            }

            Row {
                x: (parent.width - btn_sure.width - btn_cancel.width - 30) / 2
                y: parent.height / 2
                spacing: 30
                Rectangle {
                    id: btn_sure
                    width: rect_task_list.screen_width / 8
                    height: rect_task_list.screen_height / 12
                    color: "transparent"
                    Text {
                        anchors.centerIn: parent
                        color: "#7CA6C9"
                        font.pixelSize: rect_task_list.screen_width / 35
                        text: qsTr("确定")
                    }
                    Image {
                        id: btn_sure_img
                        anchors.fill: parent
                        source: qml_port.get_img_qml_res_path() + (btn_sure.focus?"images/ok_button_s.png":"images/ok_button_n.png")
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            btn_sure_disp()
                        }
                        onPressed: {
                            btn_sure.focus = true
                        }
                        onReleased: {
                            wnd_delte_folder.focus = true
                        }
                    }
                }

                Rectangle {
                    id: btn_cancel
                    width: rect_task_list.screen_width / 8
                    height: rect_task_list.screen_height / 12
                    color: "transparent"
                    Text {
                        anchors.centerIn: parent
                        color: "#7CA6C9"
                        font.pixelSize: rect_task_list.screen_width / 35
                        text: qsTr("取消")
                    }
                    Image {
                        id: btn_cancel_img
                        anchors.fill: parent
                        source: qml_port.get_img_qml_res_path() + (btn_cancel.focus?"images/ok_button_s.png":"images/ok_button_n.png")
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            btn_cancel_disp()
                        }
                        onPressed: {
                            btn_cancel.focus = true
                        }
                        onReleased: {
                            wnd_delte_folder.focus = true
                        }
                    }
                }
            }
        }
    }

    function handle_ok_btn_click() {
        pop_task_loading_msg();  //最终蒋id为 task_ok_timer的timer启动
    }

    function handle_return_btn_click() {
        dlg_taskType_st = false
        rect_task_list.focus = true;
        update_btn();
    }

    function handle_task_loaded_sig() {
        rect_task_list.return_main_form( "ok_btn" );
    }

    function return_main_form( id ) {
        //Keys.enabled = false;
        //rect_task_list.focus = false;
        rect_task_list.restore_main_form();
        //rect_task_list.visible = false
        //qml_port.restore_video();
        //rect_task_list.destroy(); //20
    }

    function pop_task_loading_msg() {//最终蒋id为 task_ok_timer的timer启动
        qml_port.emit_start_parse_task_pack();
    }

    Keys.enabled: true
    Keys.onReleased: {
        console.log("#### [TaskSelectList] [Keys] : running . . .");
        switch(event.key) {
           case qml_port.get_keyValue_from_up():  //上
                console.log("#### [TaskSelectList] [Keys] : UP ！！！！！");
                if(dlg_findPage_st) {
                    console.log("#### [TaskSelectList] [Keys] : dlg_findPage_st --> " + dlg_findPage_st)
                    key_up()
                } else if (dlg_fingXml_st) {
                    console.log("#### [TaskSelectList] [Keys] : dlg_findXml_st --> " + dlg_fingXml_st)
                    key_up()
                } else if(dlg_taskType_st) {
                    console.log("#### [TaskSelectList] [Keys] : dlg_taskType_st --> " + dlg_taskType_st)
                    type_key_up()
                } else {
                    if(rect_task_list.focus) {
                        btn_return.focus = true
                    } else if(btn_return.focus ||
                           btn_pre.focus ||
                           btn_next.focus ||
                           btn_import_new_task.focus) {
                        if(task_select_model.count > 0) {
                            folder_list_view.focus = true
                            gn_current_index = task_select_model.count - 1
                        }
                    } else if(folder_list_view.focus) {
                        --gn_current_index
                        btn_select_st = false
                        btn_delete_st = false
                        if(gn_current_index < 0) {
                            btn_return.focus = true
                        }
                    }
                    console.log("#### [TaskSelectList] [Keys] : " + gn_current_index)
                    update_btn();
               }
               break;
           case qml_port.get_keyValue_from_down():  //下
               console.log("#### [TaskSelectList] [Keys] : DOWN ！！！！！");
               if(dlg_findPage_st) {
                   console.log("#### [TaskSelectList] [Keys] : dlg_findPage_st --> " + dlg_findPage_st)
                   key_down()
               } else if (dlg_fingXml_st) {
                   console.log("#### [TaskSelectList] [Keys] : dlg_findXml_st --> " + dlg_fingXml_st)
                   key_down()
               } else if(dlg_taskType_st) {
                   console.log("#### [TaskSelectList] [Keys] : dlg_taskType_st --> " + dlg_taskType_st)
                   type_key_down()
               } else {
                    if(rect_task_list.focus) {
                        if(task_select_model.count > 0) {
                            folder_list_view.focus = true
                            gn_current_index = 0
                        } else {
                            btn_return.focus = true
                        }
                    } else if(folder_list_view.focus) {
                        gn_current_index++
                        btn_select_st = false
                        btn_delete_st = false
                        if(gn_current_index >= task_select_model.count) {
                            btn_return.focus = true
                        }
                    } else if(btn_return.focus ||
                             btn_pre.focus ||
                             btn_next.focus ||
                             btn_import_new_task.focus) {
                        if(task_select_model.count > 0) {
                            folder_list_view.focus = true
                            gn_current_index = 0
                        }
                    }
                    update_btn();
               }
               break;
           case qml_port.get_keyValue_from_left():  //左
               console.log("#### [TaskSelectList] [Keys] : LEFT ！！！！！");
               if(dlg_findPage_st) {
                   console.log("#### [TaskSelectList] [Keys] : dlg_findPage_st --> " + dlg_findPage_st)
                   key_left()
               } else if (dlg_fingXml_st) {
                   console.log("#### [TaskSelectList] [Keys] : dlg_findXml_st --> " + dlg_fingXml_st)
                   key_left()
               } else if(dlg_taskType_st) {
                   console.log("#### [TaskSelectList] [Keys] : dlg_taskType_st --> " + dlg_taskType_st)
                   type_key_left()
               } else {
                    if(wnd_delte_folder.visible) {
                        if(! btn_cancel.focus) {
                            btn_cancel.focus = true
                        } else {
                            btn_sure.focus = true
                        }
                    } else if(rect_task_list.focus) {
                        btn_import_new_task.focus = true
                    } else if(btn_import_new_task.focus) {
                        if (btn_import_new_xml.enabled)
                            btn_import_new_xml.focus = true
                        else if(btn_next.enabled)
                            btn_next.focus = true
                        else if(btn_pre.enabled)
                            btn_pre.focus = true
                        else
                            btn_return.focus = true
                    } else if (btn_import_new_xml.focus) {
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
                        btn_import_new_task.focus = true
                    } else if(folder_list_view.focus) {
                        if(!btn_delete_st) {
                            btn_delete_st = true
                            btn_select_st = false
                        } else {
                            btn_select_st = true
                            btn_delete_st = false
                        }
                    }
                    update_btn();
               }
               break;
           case qml_port.get_keyValue_from_right():  //右
               console.log("#### [TaskSelectList] [Keys] : RIGHT ！！！！！");
               if(dlg_findPage_st) {
                   console.log("#### [TaskSelectList] [Keys] : dlg_findPage_st --> " + dlg_findPage_st)
                   key_right()
               } else if (dlg_fingXml_st) {
                   console.log("#### [TaskSelectList] [Keys] : dlg_findXml_st --> " + dlg_fingXml_st)
                   key_right()
               } else if(dlg_taskType_st) {
                   console.log("#### [TaskSelectList] [Keys] : dlg_taskType_st --> " + dlg_taskType_st)
                   type_key_right()
               } else {
                    if(wnd_delte_folder.visible) {
                        if(! btn_sure.focus) {
                            btn_sure.focus = true
                        } else {
                            btn_cancel.focus = true
                        }
                    } else if(rect_task_list.focus) {
                        btn_return.focus = true
                    } else if(btn_return.focus) {
                        if(btn_pre.enabled)
                            btn_pre.focus = true
                        else if(btn_next.enabled)
                            btn_next.focus = true
                        else if (btn_import_new_xml.enabled)
                            btn_import_new_xml.focus = true
                        else
                            btn_import_new_task.focus = true
                    } else if(btn_pre.focus) {
                        if(btn_next.enabled)
                            btn_next.focus = true
                        else if (btn_import_new_xml.enabled)
                            btn_import_new_xml.focus = true
                        else
                            btn_import_new_task.focus = true
                    } else if(btn_next.focus) {
                        btn_import_new_xml.focus = true
                    } else if (btn_import_new_xml.focus) {
                        btn_import_new_task.focus = true
                    } else if(btn_import_new_task.focus) {
                        btn_return.focus = true
                    } else if(folder_list_view.focus) {
                        if(!btn_select_st) {
                            btn_delete_st = false
                            btn_select_st = true
                        } else {
                            btn_select_st = false
                            btn_delete_st = true
                        }
                    }
                    update_btn();
               }
               break;
           case qml_port.get_keyValue_from_center():  //中
               console.log("#### [TaskSelectList] [Keys] : CENTRE ！！！！！");
               if(dlg_findPage_st) {
                   console.log("#### [TaskSelectList] [Keys] : dlg_findPage_st --> " + dlg_findPage_st)
                   key_ok()
               } else if (dlg_fingXml_st) {
                   console.log("#### [TaskSelectList] [Keys] : dlg_findXml_st --> " + dlg_fingXml_st)
                   key_ok()
               } else if(dlg_taskType_st) {
                   console.log("#### [TaskSelectList] [Keys] : dlg_taskType_st --> " + dlg_taskType_st)
                   type_key_ok()
               } else {
                    if(wnd_delte_folder.visible) {
                        if(btn_sure.focus) {
                            btn_sure_disp()
                        } else if(btn_cancel.focus) {
                            btn_cancel_disp()
                        }
                    } else if(btn_return.focus) {
                        sig_return_main_wnd()
                    } else if (btn_pre.focus) {
                        if( gn_current_page > 1 && gn_current_page <= gn_total_page ) {
                            gn_current_page -= 1
                            update_select_task_list()
                        }
                    } else if (btn_next.focus) {
                        if( gn_current_page < gn_total_page ) { //当前页数是否小于总页数
                            console.log("#### [TaskSelectList] : gn_current_page < gn_total_page")
                            gn_current_page += 1
                            update_select_task_list()
                        }
                    } else if (btn_import_new_task.focus) {
                        btn_import_new_task.open_findTaskPage()
                    } else if (folder_list_view.focus) {
                        if (btn_select_st) {
                            create_taskType();
                        } else if (btn_delete_st) {
                            delete_task()
                        } else {
                            btn_select_st = true
                        }
                    } else if (btn_import_new_xml.focus) {
                        btn_import_new_xml.open_findXmlPage()
                    }
               }
               break;
        }
        event.accepted = true
    }

    function update_btn() {
        btn_return_img.btn_return_img_source()
        btn_pre_img.btn_pre_img_source()
        btn_next_img.btn_next_img_source()
        btn_import_new_task_img.btn_import_new_task_img_source()
        btn_import_new_xml_img.btn_import_new_xml_img_source()
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

    Connections {
        target: qml_port
        onStart_parse_task_pack_sig: {
            task_message_b.open_task_msg_box( true );
            task_message_b.visible = true;
            task_ok_timer.start();
        }
    }

    Connections {
        target: qml_port
        onSignal_reset_dlg: {
            console.log("\r\n#### [TaskType] [onSignal_reset_dlg] : running . . .\r\n");
            task_message_b.open_task_msg_box( false );
            task_type.visible = false;
            handle_return_btn_click();
        }
    }

    MessageTaskBox{             //缺少qml文件不存在
        id: task_message_b
        anchors.verticalCenter: parent.verticalCenter
        visible: false
    }

    function create_taskType() {
        start_sel_taskTree()

        qml_port.set_taskpack_cell_byname(task_select_model.get(gn_current_index).name)
        gn_current_index = -1

        qml_port.set_device_tree_expand_way(1)
        qml_port.is_task_type_selectded()

        handle_ok_btn_click()

        /*
        var component = Qt.createComponent( "TaskType.qml" );  //创建了这个界面
        var obj = null;
        console.log( "TaskType.qml component.status=", component.status );
        if(component.status == Component.Ready) {
            obj = component.createObject( rect_task_list, {"x": 0, "y": 0} );
            if ( obj == null ) {
                console.log( "Fail creating TaskType.qml object" );
            } else {
                dlg_taskType_st = true
                obj.ok_btn_click_sig.connect( handle_ok_btn_click )
                obj.return_btn_click_sig.connect(handle_return_btn_click)
                rect_task_list.delete_select_task_type_form.connect(obj.task_return_select_taskpack_page)
                rect_task_list.type_key_up.connect(obj.type_get_key_up)
                rect_task_list.type_key_down.connect(obj.type_get_key_down)
                rect_task_list.type_key_left.connect(obj.type_get_key_left)
                rect_task_list.type_key_right.connect(obj.type_get_key_right)
                rect_task_list.type_key_ok.connect(obj.type_get_key_ok)
            }
        }*/
    }

    function delete_task() {
        gs_current_folder_name = task_select_model.get(gn_current_index).name
        wnd_delte_folder.visible = true  //删除按钮框可视
        wnd_delte_folder.focus = true
        rect_folder_window.enabled = false  //主界面 不使能
    }

    function btn_sure_disp()
    {
        rect_folder_window.enabled = true
        wnd_delte_folder.visible = false
        rect_task_list.focus = true

        var v_count = folder_list.get_task_select_count()
        var n_pos = folder_list.get_task_select_pos( gs_current_folder_name )
        var b_suc = folder_list.delete_task_select( gs_current_folder_name )
        if( !b_suc ) {
            console.log( "wnd_delete_folder delete task select: " + gs_current_folder_name + " failed")
        }

        gn_total_page = gn_total_count/gn_show_rows + (gn_total_count%gn_show_rows>0?1:0)
        if( n_pos === v_count && n_pos%gn_show_rows == 1 && gn_total_page > 1 ) {
            gn_current_page -= 1
        }

        gs_current_folder_name = ""
        update_select_task_list()
    }

    function btn_cancel_disp()
    {
        wnd_delte_folder.visible = false
        rect_folder_window.enabled = true
        rect_task_list.focus = true
        gn_current_index = -1
        btn_select_st = false
        btn_delete_st = false
        update_btn();
    }

    Connections {
        target: qml_port
        onSignal_back_last_pkg: {
            if(dlg_findPage_st)
                rect_task_list.delete_select_find_page_form()
            else if(dlg_taskType_st)
                rect_task_list.delete_select_task_type_form()
            else
                sig_return_main_wnd()
        }
    }
}



