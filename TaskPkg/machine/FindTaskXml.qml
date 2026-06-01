import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Layouts 1.0
import QtQuick.Window 2.0


Rectangle {
    id: find_xml_dlg

    property int screen_width : qml_port.get_screen_width()
    property int screen_height : qml_port.get_screen_height()

    x: 0
    y: 0
    width: find_xml_dlg.screen_width
    height: find_xml_dlg.screen_height
    color: "transparent"
    focus:  true

    property int gn_title_bar_height: height/4
    property int gn_current_page: xml_list.get_current_page()
    property int gn_total_page: xml_list.get_total_page()
    property int gn_show_rows: 5
    property int gn_current_index: -1
    property int gn_select_index: -1
    property bool btn_delete_st: false

    property string gs_current_folder_name: ""

    signal return_selected_from_findXml();
    signal return_return_from_findxml();

    MouseArea {
        anchors.fill: parent
        onClicked: {
        }
    }

    /* 背景图片 */
    Image {
        id: back_img
        anchors.fill: parent
        width: parent.width
        height: parent.height
        source: qml_port.get_img_qml_res_path() + "images/setting_background.png"
        visible: true
    }

    /* @ description : 更新model容器列表 */
    function update_xml_List_model() {
        xml_find_model.clear();
        for (var i = 0; i < xml_list.get_current_page_xml_count(); i++) {
            xml_find_model.append({"m_name":xml_list.get_currentPage_xml_by_index(i), "m_index":i})
        }
    }

    Rectangle {
        id: find_xml_window
        anchors.fill: parent
        color: "transparent"

        /* 标题栏 */
        Rectangle {
            id: find_xml_bar
            color: "transparent"
            width: parent.width
            height: gn_title_bar_height

            Text {
                id: title_text
                anchors.centerIn: parent
                text: qsTr("SD卡中发现XML")
                color: "#7CA6C9"
                font.pixelSize: find_xml_dlg.screen_width / 15
            }
        }

        /* 内容列表 */
        ListModel {
            id: xml_find_model
        }

        Component {
            id: xml_find_delegate
            Rectangle {
                id: delegate_cell
                width: parent.width
                height: gn_title_bar_height * 0.5
                color: "transparent"
                property int n_index: 1

                Image {
                    anchors.fill: parent
                    source: (m_index==gn_current_index)?qml_port.get_img_qml_res_path()+"images/select_pkg.png":""
                }
                MouseArea {
                    anchors.fill: parent
                    anchors.rightMargin: 200
                    onClicked: {
                        gn_current_index = m_index
                        xml_list_view.focus = true
                    }
                }

                Row {
                    anchors.fill: parent
                    anchors.leftMargin: 20
                    anchors.rightMargin: 20
                    spacing: parent.width - row_name.width - find_xml_dlg.screen_width/4
                    //spacing: 5

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
                            text: m_name
                            font.pixelSize: find_xml_dlg.screen_width / 30
                            color: "#7CA6C9"
                        }
                    }

                    Row {
                        id: row_button
                        anchors.right: parent.right
                        anchors.rightMargin: find_xml_dlg.screen_width / 30
                        anchors.verticalCenter: parent.verticalCenter
                        width: find_xml_dlg.screen_width / 7
                        spacing: 10

                        Rectangle {
                            id: select_btn
                            width: find_xml_dlg.screen_width / 14
                            height: find_xml_dlg.screen_height / 15
                            visible: true
                            radius: 6
                            color: "transparent"
                            BorderImage {
                                id: back_sel
                                visible: true
                                anchors.fill: parent
                                source:  qml_port.get_img_qml_res_path() + (gn_select_index==((gn_current_page-1)*5+m_index) ? "images/switch_on.png" : "images/switch_off.png")
                            }

                            MouseArea {
                                id: btn_model_select
                                anchors.fill: parent
                                onClicked: {
                                    gn_current_index = m_index
                                    xml_list_view.focus = true
                                    if (gn_select_index == (gn_current_page-1) * 5 + m_index)
                                        gn_select_index = -1
                                    else
                                        gn_select_index = (gn_current_page-1) * 5 + m_index

                                    if (gn_select_index >= 0) {
                                        btn_select.enabled = true
                                    } else {
                                        btn_select.enabled = false
                                    }
                                    update_btn_source()
                                }
                            }
                        }

                        Rectangle {
                            id: delete_btn
                            width: find_xml_dlg.screen_width / 12
                            height: find_xml_dlg.screen_height / 14
                            visible: true
                            radius: 6
                            color: "transparent"
                            Image {
                                id: back_del
                                visible: true
                                anchors.fill: parent
                                source: qml_port.get_img_qml_res_path() + (((gn_current_index == m_index)&&btn_delete_st)?"images/button_st_s.png":"images/button_st_n.png")
                            }
                            Text {
                                anchors.centerIn: parent
                                color: "#7CA6C9"
                                font.pixelSize: find_xml_dlg.screen_width / 30
                                text: qsTr("删除")
                            }
                            MouseArea {
                                id: btn_model_delete
                                anchors.fill: parent
                                onClicked: {
                                    delete_xml();
                                }
                                onPressed: {
                                    btn_delete_st = true
                                    gn_current_index = m_index
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
            }
        }

        ListView {
            id: xml_list_view
            anchors.top: find_xml_bar.bottom
            width: parent.width
            height: gn_title_bar_height*2.5
            delegate: xml_find_delegate
            model: xml_find_model
            interactive: false
            focus: true

            Component.onCompleted: {
                console.log("FindTaskXml.qml : xml_list_view init ok ... ...");
                update_xml_List_model();
            }
        }

        /* 底部按钮 */
        Rectangle {
            id: rect_operator_btn
            anchors.top: xml_list_view.bottom
            width: parent.width
            height: gn_title_bar_height*0.5
            color: "transparent"
            Row {
                anchors.fill: parent
                anchors.leftMargin: (parent.width - btn_pre.width*3 - btn_select.width - 3 * 50 )/2
                anchors.rightMargin: (parent.width - btn_pre.width*3 - btn_select.width - 3 * 50 )/2
                anchors.bottomMargin: 10
                spacing: 15

                /* 返回按钮 */
                Rectangle {
                    id: btn_return
                    width: find_xml_dlg.screen_width / 12
                    height: find_xml_dlg.screen_height / 7
                    enabled: true
                    focus: false
                    color: "transparent"
                    Image {
                        id: btn_return_img
                        anchors.fill: parent
                        source: qml_port.get_img_qml_res_path() + "images/back_d.png"
                    }
                    MouseArea {
                        anchors.fill: parent
                        onPressed: {
                            btn_return.focus = true
                            update_btn_source()
                        }
                        onReleased: {
                            btn_return.focus = false
                            update_btn_source()

                            return_return_from_findxml()
                            find_xml_dlg.destroy()
                        }
                        onClicked: {
                        }
                    }
                }

                /* 上一页按钮 */
                Rectangle {
                    id: btn_pre
                    width: find_xml_dlg.screen_width / 12
                    height: find_xml_dlg.screen_height / 7
                    enabled: true
                    focus: false
                    color: "transparent"
                    Image {
                        id: btn_pre_img
                        anchors.fill: parent
                        source: qml_port.get_img_qml_res_path() + "images/pre_page_d.png"
                    }
                    MouseArea {
                        anchors.fill: parent
                        onPressed: {
                            btn_pre.focus = true
                            update_btn_source()
                        }
                        onReleased: {
                            gn_current_index = -1
                            xml_list.jump_to_pre_page()
                            update_xml_List_model()

                            gn_current_page = xml_list.get_current_page()
                            gn_total_page = xml_list.get_total_page()
                            if (gn_current_page == gn_total_page) {
                                btn_next.enabled = false
                            } else {
                                btn_next.enabled = true
                            }
                            if (gn_current_page == 1) {
                                btn_pre.enabled = false
                            } else {
                                btn_pre.enabled = true
                            }
                            btn_pre.focus = false
                            update_btn_source()

                            xml_list_view.focus = true
                        }
                        onClicked: {
                        }
                    }
                }

                /* 页码显示 */
                Rectangle {
                    id: label_page
                    width: find_xml_dlg.screen_width / 12
                    height: find_xml_dlg.screen_height / 7
                    anchors.topMargin: 30
                    color: "transparent"
                    Text {
                        id: label_page_text
                        font.pixelSize: find_xml_dlg.screen_width / 20
                        anchors.centerIn: parent
                        color: "#7CA6C9"
                        text: qsTr(gn_current_page + "/" + gn_total_page)
                    }
                }

                /* 下一页按钮 */
                Rectangle {
                    id: btn_next
                    width: find_xml_dlg.screen_width / 12
                    height: find_xml_dlg.screen_height / 7
                    enabled: true
                    focus: false
                    color: "transparent"
                    Image {
                        id: btn_next_img
                        anchors.fill: parent
                        source: qml_port.get_img_qml_res_path() + "images/next_page_d.png"
                    }
                    MouseArea {
                        anchors.fill: parent
                        onPressed: {
                            btn_next.focus = true
                            update_btn_source()
                        }
                        onReleased: {
                            gn_current_index = -1
                            xml_list.jump_to_next_page()
                            update_xml_List_model()

                            gn_current_page = xml_list.get_current_page()
                            gn_total_page = xml_list.get_total_page()
                            if (gn_current_page == gn_total_page) {
                                btn_next.enabled = false
                            } else {
                                btn_next.enabled = true
                            }
                            if (gn_current_page == 1) {
                                btn_pre.enabled = false
                            } else {
                                btn_pre.enabled = true
                            }
                            btn_next.focus = false
                            update_btn_source()

                            xml_list_view.focus = true
                        }
                        onClicked: {
                        }
                    }
                }

                /* 选择按钮 */
                Rectangle {
                    id: btn_select
                    width: find_xml_dlg.screen_width / 12
                    height: find_xml_dlg.screen_height / 7
                    enabled: false
                    focus: false
                    color: "transparent"
                    Image {
                        id: btn_select_img
                        anchors.fill: parent
                        source: qml_port.get_img_qml_res_path() + "images/load_d.png"
                    }
                    MouseArea {
                        anchors.fill: parent
                        onPressed: {
                            btn_select.focus = true
                            update_btn_source()
                        }
                        onReleased: {
                            btn_select.focus = false
                            update_btn_source()

                            xml_list.set_select_xml_index(gn_select_index)
                            return_selected_from_findXml()
                            find_xml_dlg.destroy()
                        }
                        onClicked: {
                        }
                    }
                }
            }

            Component.onCompleted: {
                gn_current_page = xml_list.get_current_page()
                gn_total_page = xml_list.get_total_page()
                if (gn_current_page == gn_total_page) {
                    btn_next.enabled = false
                } else {
                    btn_next.enabled = true
                }
                if (gn_current_page == 1) {
                    btn_pre.enabled = false
                } else {
                    btn_pre.enabled = true
                }
                btn_pre.focus = false

                update_btn_source()
            }
        }
    }

    /* @ description : 删除确认弹窗 */
    Rectangle {
        id : wnd_delete_folder
        anchors.centerIn: parent
        width: find_xml_dlg.screen_width / 2.5
        height: find_xml_dlg.screen_height / 2.5
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
                anchors.top: parent.top
                anchors.topMargin: parent.height / 4
                anchors.left: parent.left
                anchors.leftMargin: parent.width / 10
                color: "#7CA6C9"
                font.pixelSize: find_xml_dlg.screen_width / 29
                text: qsTr("删除选中的文件？")
            }

            Row {
                x: (parent.width - btn_sure.width - btn_cannel.width - 30) / 2
                y: parent.height / 2
                spacing: 30
                Rectangle {
                    id: btn_sure
                    width: find_xml_dlg.screen_width / 8
                    height: find_xml_dlg.screen_height / 12
                    color: "transparent"
                    Text {
                        anchors.centerIn: parent
                        color: "#7CA6C9"
                        font.pixelSize: find_xml_dlg.screen_width / 35
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
                            delete_xml_sure()
                        }
                        onPressed: {
                            btn_sure.focus = true
                        }
                        onReleased: {
                            wnd_delete_folder.focus = true
                        }
                    }
                }
                Rectangle {
                    id: btn_cannel
                    width: find_xml_dlg.screen_width / 8
                    height: find_xml_dlg.screen_height / 12
                    color: "transparent"
                    Text {
                        anchors.centerIn: parent
                        color: "#7CA6C9"
                        font.pixelSize: find_xml_dlg.screen_width / 35
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
                            delete_xml_cannel()
                        }
                        onPressed: {
                            btn_cannel.focus = true
                        }
                        onReleased: {
                            wnd_delete_folder.focus = true
                        }
                    }
                }
            }
        }
    }

    /* @ description: 按键资源图片更新 */
    function update_btn_source() {
        update_btn_return_source()
        update_btn_pre_source()
        update_btn_next_source()
        update_btn_select_source()
    }

    /* @ description : 返回按键资源图片更新 */
    function update_btn_return_source() {
        if (btn_return.enabled == true) {
            if (btn_return.focus == true) {
                btn_return_img.source = qml_port.get_img_qml_res_path() + "images/back_s.png"
            } else {
                btn_return_img.source = qml_port.get_img_qml_res_path() + "images/back_n.png"
            }
        } else {
            btn_return_img.source = qml_port.get_img_qml_res_path() + "images/back_d.png"
        }
    }

    /* @ description : 上一页按键资源图片更新 */
    function update_btn_pre_source() {
        if (btn_pre.enabled == true) {
            if (btn_pre.focus == true) {
                btn_pre_img.source = qml_port.get_img_qml_res_path() + "images/pre_page_s.png"
            } else {
                btn_pre_img.source = qml_port.get_img_qml_res_path() + "images/pre_page_n.png"
            }
        } else {
            btn_pre_img.source = qml_port.get_img_qml_res_path() + "images/pre_page_d.png"
        }
    }

    /* @ description : 下一页按键资源图片更新 */
    function update_btn_next_source() {
        if (btn_next.enabled == true) {
            if (btn_next.focus == true) {
                btn_next_img.source = qml_port.get_img_qml_res_path() + "images/next_page_s.png"
            } else {
                btn_next_img.source = qml_port.get_img_qml_res_path() + "images/next_page_n.png"
            }
        } else {
            btn_next_img.source = qml_port.get_img_qml_res_path() + "images/next_page_d.png"
        }
    }

    /* @ description : 选择按键资源图片更新 */
    function update_btn_select_source() {
        if (btn_select.enabled == true) {
            if (btn_select.focus == true) {
                btn_select_img.source = qml_port.get_img_qml_res_path() + "images/load_s.png"
            } else {
                btn_select_img.source = qml_port.get_img_qml_res_path() + "images/load_n.png"
            }
        } else {
            btn_select_img.source = qml_port.get_img_qml_res_path() + "images/load_d.png"
        }
    }

    /* @ description : 删除xml文件 */
    function delete_xml() {
        wnd_delete_folder.visible = true
        wnd_delete_folder.focus = true
        find_xml_window.enabled = false
    }

    function delete_xml_sure() {
        console.log("delete_xml_sure excute")
        xml_list.del_xml_by_index((gn_current_page-1)*5+gn_current_index)
        gn_current_page = xml_list.get_current_page()
        gn_total_page = xml_list.get_total_page()
        if ((gn_current_page-1)*5+gn_current_index === gn_select_index) {
            gn_select_index = -1
            xml_list.set_select_xml_index(gn_select_index)
            btn_select.enabled = false;
        } else if ((gn_current_page-1)*5+gn_current_index <= gn_select_index) {
            gn_select_index = gn_select_index-1
            xml_list.set_select_xml_index(gn_select_index)
        }
        gn_current_page = xml_list.get_current_page()
        gn_total_page = xml_list.get_total_page()
        gn_current_index = -1;

        find_xml_dlg.focus = true
        wnd_delete_folder.visible = false
        find_xml_window.enabled = true
        update_btn_source();
        update_xml_List_model();
    }

    function delete_xml_cannel() {
        console.log("delete_xml_cannel excute")
        find_xml_dlg.focus = true
        wnd_delete_folder.visible = false
        find_xml_window.enabled = true
        gn_current_index = -1;
        update_btn_source();
    }

    /* @ description : 上键响应函数 */
    function get_btn_up() {
        console.log("---------------------------> get_btn_up")
        if (xml_list_view.focus) {
            if (gn_current_index > 0) {
                gn_current_index--
            } else {
                btn_return.focus = true
            }
        } else if (btn_return.focus) {
            xml_list_view.focus = true
            if (xml_list_view.count > 0 && gn_current_index < 0)
                gn_current_index = xml_list_view.count-1
        } else if (btn_pre.focus) {
            xml_list_view.focus = true
            if (xml_list_view.count > 0 && gn_current_index < 0)
                gn_current_index = xml_list_view.count-1
        } else if (btn_next.focus) {
            xml_list_view.focus = true
            if (xml_list_view.count > 0 && gn_current_index < 0)
                gn_current_index = xml_list_view.count-1
        } else if (btn_select.focus) {
            xml_list_view.focus = true
            if (xml_list_view.count > 0 && gn_current_index < 0)
                gn_current_index = xml_list_view.count-1
        } else {
            btn_return.focus = true
        }

        update_btn_source()
    }

    /* @ description : 下键响应函数 */
    function get_btn_down() {
        console.log("---------------------------> get_btn_down")
        if (xml_list_view.focus) {
            if (gn_current_index < xml_list_view.count - 1) {
                gn_current_index++
            } else {
                btn_return.focus = true
            }
        } else if (btn_return.focus) {
            xml_list_view.focus = true
            if (xml_list_view.count > 0 && gn_current_index < 0)
                gn_current_index = 0
        } else if (btn_pre.focus) {
            xml_list_view.focus = true
            if (xml_list_view.count > 0 && gn_current_index < 0)
                gn_current_index = 0
        } else if (btn_next.focus) {
            xml_list_view.focus = true
            if (xml_list_view.count > 0 && gn_current_index < 0)
                gn_current_index = 0
        } else if (btn_select.focus) {
            xml_list_view.focus = true
            if (xml_list_view.count > 0 && gn_current_index < 0)
                gn_current_index = 0
        } else {
            if (xml_list_view.count > 0 && gn_current_index < 0) {
                xml_list_view.focus = true
                gn_current_index = 0
            } else {
                btn_return.focus = true
            }
        }

        update_btn_source()
    }

    /* @ description : 左键响应函数 */
    function get_btn_left() {
        console.log("---------------------------> get_btn_left")
        if (xml_list_view.focus) {
        } else if (btn_return.focus) {
            if (btn_select.enabled)
                btn_select.focus = true
            else if (btn_next.enabled)
                btn_next.focus = true
            else if (btn_pre.enabled)
                btn_pre.focus = true
        } else if (btn_pre.focus) {
            btn_return.focus = true
        } else if (btn_next.focus) {
            if (btn_pre.enabled)
                btn_pre.focus = true
            else
                btn_return.focus = true
        } else if (btn_select.focus) {
            if (btn_next.enabled)
                btn_next.focus = true
            else if (btn_pre.enabled)
                btn_pre.focus = true
            else
                btn_return.focus = true
        } else {
            if (btn_select.enabled)
                btn_select.focus = true
            else if (btn_next.enabled)
                btn_next.focus = true
            else if (btn_pre.enabled)
                btn_pre.focus = true
            else
                btn_return.focus = true
        }

        update_btn_source()
    }

    /* @ description : 右键响应函数 */
    function get_btn_right() {
        console.log("---------------------------> get_btn_right")
        if (xml_list_view.focus) {
        } else if (btn_return.focus) {
            if (btn_pre.enabled)
                btn_pre.focus = true
            else if (btn_next.enabled)
                btn_next.focus = true
            else if (btn_select.enabled)
                btn_select.focus = true
        } else if (btn_pre.focus) {
            if (btn_next.enabled)
                btn_next.focus = true
            else if (btn_select.enabled)
                btn_select.focus = true
            else
                btn_return.focus = true
        } else if (btn_next.focus) {
            if (btn_select.enabled)
                btn_select.focus = true
            else
                btn_return.focus = true
        } else if (btn_select.focus) {
            btn_return.focus = true
        } else {
            btn_return.focus = true
        }

        update_btn_source()
    }

    /* @ description : 中键响应函数 */
    function get_btn_center() {
        console.log("---------------------------> get_btn_center")
        if (xml_list_view.focus) {
            if (gn_current_index >= 0 && gn_current_index < xml_list_view.count) {
                if (gn_select_index == (gn_current_page-1) * 5 + gn_current_index)
                    gn_select_index = -1
                else
                    gn_select_index = (gn_current_page-1) * 5 + gn_current_index

                if (gn_select_index >= 0) {
                    btn_select.enabled = true
                } else {
                    btn_select.enabled = false
                }
                update_btn_source()
            }
        } else if (btn_return.focus) {
            return_return_from_findxml()
            find_xml_dlg.destroy()
        } else if (btn_pre.focus) {
            if (btn_pre.enabled) {
                gn_current_index = -1
                xml_list.jump_to_pre_page()
                update_xml_List_model()

                gn_current_page = xml_list.get_current_page()
                gn_total_page = xml_list.get_total_page()
                if (gn_current_page == gn_total_page) {
                    btn_next.enabled = false
                } else {
                    btn_next.enabled = true
                }
                if (gn_current_page == 1) {
                    btn_pre.enabled = false
                } else {
                    btn_pre.enabled = true
                }
                if (btn_pre.enabled)
                    btn_pre.focus = true
                else
                    xml_list_view.focus = true
                update_btn_source()
            }
        } else if (btn_next.focus) {
            if (btn_next.enabled) {
                gn_current_index = -1
                xml_list.jump_to_next_page()
                update_xml_List_model()

                gn_current_page = xml_list.get_current_page()
                gn_total_page = xml_list.get_total_page()
                if (gn_current_page == gn_total_page) {
                    btn_next.enabled = false
                } else {
                    btn_next.enabled = true
                }
                if (gn_current_page == 1) {
                    btn_pre.enabled = false
                } else {
                    btn_pre.enabled = true
                }
                if (btn_next.enabled)
                    btn_next.focus = true
                else
                    xml_list_view.focus = true
                update_btn_source()
            }
        } else if (btn_select.focus) {
            xml_list.set_select_xml_index(gn_select_index)
            return_selected_from_findXml()
            find_xml_dlg.destroy()
        } else {
        }

        update_btn_source()
    }
}















