import QtQuick 2.0
import QtCharts 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Layouts 1.0
import QtQuick.Window 2.0

Rectangle {
    id: rect_analysis_window

    property int screen_width: qml_port.get_screen_width();
    property int screen_height: qml_port.get_screen_height();

    width: rect_analysis_window.screen_width
    height: rect_analysis_window.screen_height
    visible: true
    color: "transparent"
    focus: true

    property int n_current_index: -1
    property int n_part_index: -1

    signal sig_return_tree_wnd()

    /* 背景 */
    Image {
        anchors.fill: parent
        source: qml_port.get_img_qml_res_path() + "images/setting_background.png"
        visible: true
    }

    Text {
        id: tt
        color: "blue"
        font.family: "Arial"
        font.bold: false
        font.italic: false
        font.pixelSize: rect_analysis_window.screen_width/140
    }
    Text {
        id: dd
        color: "blue"
        font.family: "Arial"
        font.bold: false
        font.italic: false
        font.pixelSize: rect_analysis_window.screen_width/54
    }

    /* 折线图 */
    ChartView {
        id: myChartView
        title : "历史数据分析"
        titleColor: "#7CA6C9"
        titleFont.bold: true
        //titleFont.pointSize: 80
        titleFont.pointSize: rect_analysis_window.screen_width/42
        antialiasing: true
        backgroundColor: "#11DDDDDD"
        animationOptions: ChartView.SeriesAnimations
        anchors.top: parent.top
        anchors.left: parent.left
        width: parent.width
        height: parent.height - rect_analysis_window.screen_height/4
        legend.font: dd.font

        ValueAxis {
            id: myAxisX
            min: 1
            max: 20
            tickCount: 20
            labelsColor: "#FFFFFF"
            //labelsFont.pointSize: 35
            labelsFont.pointSize: rect_analysis_window.screen_width / 80
            labelsFont.bold: true
            labelFormat: "%d"
        }
        ValueAxis {
            id: myAxisY
            min: 0.00
            max: 50.00
            tickCount: 6
            labelsColor: "#FFFFFF"
            //labelsFont.pointSize: 35
            labelsFont.pointSize: rect_analysis_window.screen_width / 80
            labelsFont.bold: true
            labelFormat: "%.2f"
        }
        LineSeries {
            id: lineSeries_1
            name: "LineSeries"
            pointLabelsColor: "#FFFFFF"
            axisX: myAxisX
            axisY: myAxisY
            color: "#FF2222"
            width: 2
            visible: false
            pointLabelsVisible: false
            pointLabelsFont: tt.font
        }

        LineSeries {
            id: lineSeries_2
            name: "LineSeries"
            pointLabelsColor: "#FFFFFF"
            axisX: myAxisX
            axisY: myAxisY
            color: "#22FF22"
            width: 2
            visible: false
            pointLabelsVisible: false
            pointLabelsFont: tt.font
        }
        LineSeries {
            id: lineSeries_3
            name: "LineSeries"
            pointLabelsColor: "#FFFFFF"
            axisX: myAxisX
            axisY: myAxisY
            color: "#2222FF"
            width: 2
            visible: false
            pointLabelsVisible: false
            pointLabelsFont: tt.font
        }
        LineSeries {
            id: lineSeries_4
            name: "LineSeries"
            pointLabelsColor: "#FFFFFF"
            axisX: myAxisX
            axisY: myAxisY
            color: "#F2F222"
            width: 2
            visible: false
            pointLabelsVisible: false
            pointLabelsFont: tt.font
        }
        LineSeries {
            id: lineSeries_5
            name: "LineSeries"
            pointLabelsColor: "#FFFFFF"
            axisX: myAxisX
            axisY: myAxisY
            color: "#F222F2"
            width: 2
            visible: false
            pointLabelsVisible: false
            pointLabelsFont: tt.font
        }
        LineSeries {
            id: lineSeries_6
            name: "LineSeries"
            pointLabelsColor: "#FFFFFF"
            axisX: myAxisX
            axisY: myAxisY
            color: "#FFFFF2"
            width: 2
            visible: false
            pointLabelsVisible: false
            pointLabelsFont: tt.font
        }
        LineSeries {
            id: lineSeries_7
            name: "LineSeries"
            pointLabelsColor: "#FFFFFF"
            axisX: myAxisX
            axisY: myAxisY
            color: "#2FFFFF"
            width: 2
            visible: false
            pointLabelsVisible: false
            pointLabelsFont: tt.font
        }
        LineSeries {
            id: lineSeries_8
            name: "LineSeries"
            pointLabelsColor: "#FFFFFF"
            axisX: myAxisX
            axisY: myAxisY
            color: "#222222"
            width: 2
            visible: false
            pointLabelsVisible: false
            pointLabelsFont: tt.font
        }
        LineSeries {
            id: lineSeries_9
            name: "LineSeries"
            pointLabelsColor: "#FFFFFF"
            axisX: myAxisX
            axisY: myAxisY
            color: "#DDDDDD"
            width: 2
            visible: false
            pointLabelsVisible: false
            pointLabelsFont: tt.font
        }
        LineSeries {
            id: lineSeries_10
            name: "LineSeries"
            pointLabelsColor: "#FFFFFF"
            axisX: myAxisX
            axisY: myAxisY
            color: "#D2D22D"
            width: 2
            visible: false
            pointLabelsVisible: false
            pointLabelsFont: tt.font
        }
    }

    ListModel {
        id: analysis_choose_model
    }
    ListModel {
        id: analysis_part_model
    }

    Component {
        id: analysis_choose_delegate
        Rectangle {
            id: list_cell
            width: rect_analysis_window.screen_width / 4
            height: rect_analysis_window.screen_height / 10
            color: "transparent"
            property int cell_index: current_index
            Rectangle {
                id: list_cell_part
                anchors.top: parent.top
                anchors.topMargin: rect_analysis_window.screen_width / 200
                anchors.left: parent.left
                width: list_cell.width
                height: list_cell.height
                color: "#11DDDDDD"
                Image {
                    id: background_highlight
                    anchors.fill: parent
                    source: (n_current_index == cell_index)?qml_port.get_img_qml_res_path()  + "images/row_select.png":""
                }
                Image {
                    id: analysis_choose_img
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.topMargin: parent.height * 0.2
                    height: parent.height * 0.6
                    width: parent.width * 0.26
                    source: qml_port.get_img_qml_res_path() + (n_status?"images/switch_on.png":"images/switch_off.png")
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            reset_list_focus()
                            n_status = ! n_status
                            if(n_status) {
                                var tmpIndex = -1
                                for(var i = 0; i < analysis_choose_model.count; i++)
                                    if(analysis_choose_model.get(i).n_status)
                                        tmpIndex++
                                if(tmpIndex >= 10) {
                                    tmpIndex = 9
                                    for(var j = 0; j < analysis_choose_model.count; j++) {
                                        if(analysis_choose_model.get(j).n_status && analysis_choose_model.get(j).n_index < 10) {
                                            if(analysis_choose_model.get(j).n_index <= 0)
                                                analysis_choose_model.set(j, {"n_index": 100, "n_status": false})
                                            else
                                                analysis_choose_model.set(j, {"n_index": analysis_choose_model.get(j).n_index - 1})
                                        }
                                    }
                                }
                                n_index = tmpIndex
                            } else {
                                for(var m = 0; m < analysis_choose_model.count; m++) {
                                    if(analysis_choose_model.get(m).n_status &&
                                            analysis_choose_model.get(m).n_index > n_index &&
                                            analysis_choose_model.get(m).n_index !== 100)
                                        analysis_choose_model.set(m, {"n_index": analysis_choose_model.get(m).n_index - 1})
                                }
                                n_index = 100
                            }

                            update_chart()
                            update_temp()
                        }
                    }
                }
                Text {
                    id: analysis_choose_name
                    anchors.left: analysis_choose_img.right
                    anchors.leftMargin: parent.width * 0.02
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: parent.height * 0.1
                    height: parent.height * 0.8
                    width: parent.width * 0.31
                    text: n_title
                    color: "#7CA6C9"
                    font.pixelSize: parent.height * 0.6
                    visible: true
                }
                Text {
                    id: analysis_choose_temp
                    anchors.left: analysis_choose_name.right
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: parent.height * 0.1
                    height: parent.height * 0.8
                    width: parent.width * 0.31
                    text: n_temp
                    color: n_color
                    font.pixelSize: parent.height * 0.6
                    visible: true
                }
            }
        }
    }

    Component {
        id: analysis_part_delegate
        Rectangle {
            id: list_part_cell
            width: rect_analysis_window.screen_width / 8
            height: rect_analysis_window.screen_height / 8
            color: "transparent"
            property int cell_index: cur_index
            Rectangle {
                id: btn_part
                anchors.bottom: list_part_cell.bottom
                anchors.bottomMargin: parent.height * 0.05
                anchors.left: list_part_cell.left
                anchors.leftMargin: parent.width * 0.05
                height: list_part_cell.height * 0.9
                width: list_part_cell.width * 0.9
                color: part_status?"#5555BBFF":"transparent"
                Text {
                    id: btn_part_text
                    anchors.centerIn: btn_part
                    color: "#7CA6C9"
                    font.pixelSize: parent.height * 0.7
                    text: part_text
                }
                Image {
                    id: btn_part_img
                    anchors.fill: btn_part
                    source: qml_port.get_img_qml_res_path() + (cell_index == rect_analysis_window.n_part_index?"images/ok_button_s.png":"images/ok_button_n.png")
                }
                MouseArea {
                    anchors.fill: btn_part
                    onPressed: {
                    }
                    onClicked: {
                        reset_list_focus()
                        clicked_btn_part( cell_index )
                    }
                }
            }
        }
    }

    ListView {
        id: analysis_choose_list
        anchors.top: myChartView.bottom
        anchors.left: parent.left
        anchors.leftMargin: parent.width * 0.02
        width: parent.width * 0.96
        height: parent.height * 0.1
        delegate: analysis_choose_delegate
        model: analysis_choose_model
        orientation: ListView.Horizontal
        clip: true
    }

    ListView {
        id: analysis_part_list
        anchors.bottom: parent.bottom
        anchors.bottomMargin: parent.height / 40
        anchors.left: parent.left
        anchors.leftMargin: parent.width / 40
        width: parent.width * 0.6
        height: parent.height * 0.1
        delegate: analysis_part_delegate
        model: analysis_part_model
        orientation: ListView.Horizontal
        clip: true
    }

    /* 底部按键 */
    Rectangle {
        id: part_btn
        anchors.bottom: parent.bottom
        anchors.bottomMargin: parent.height / 40
        anchors.right: parent.right
        anchors.rightMargin: parent.width / 40
        width: parent.width * 0.4
        height: parent.height * 0.1
        color: "transparent"

        Rectangle {
            id: module_y_change
            anchors.right: btn_return.left
            anchors.rightMargin: parent.width / 40
            height: parent.height
            width: parent.width * 0.7
            color: "transparent"
            visible: true
            Rectangle {
                id: pre_x
                anchors.right: current_x.left
                width: parent.height * 1.1
                height: parent.height
                color: "transparent"
                Image {
                    id: pre_x_img
                    anchors.fill: parent
                    source: qml_port.get_img_qml_res_path() + "images/pre_page_d.png"
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        if(!analysis_op.get_pre_btn_status())
                            return;

                        reset_list_focus()
                        rect_analysis_window.focus = true
                        clicked_btn_pre()
                    }
                    onPressed: {
                        if(!analysis_op.get_pre_btn_status())
                            return;
                        pre_x.focus = true
                    }
                }
                Image {
                    id: pre_X_focus_img
                    anchors.fill: parent
                    source: qml_port.get_img_qml_res_path() + "images/button_st_s.png"
                    visible: pre_x.focus
                }
            }
            Rectangle {
                id: current_x
                anchors.right: next_x.left
                height: parent.height
                width: parent.height
                color: "transparent"
                Text {
                    id: text_y
                    anchors.centerIn: parent
                    color: "#7CA6C9"
                    font.pixelSize: parent.height * 0.7
                    text: qsTr("0")
                }
            }
            Rectangle {
                id: next_x
                anchors.right: parent.right
                anchors.rightMargin: parent.width / 40
                width: parent.height * 1.1
                height: parent.height
                color: "transparent"
                Image {
                    id: next_x_img
                    anchors.fill: parent
                    source: qml_port.get_img_qml_res_path() + "images/next_page_d.png"
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        if(!analysis_op.get_next_btn_status())
                            return

                        reset_list_focus()
                        rect_analysis_window.focus = true
                        clicked_btn_next()
                    }
                    onPressed: {
                        if(!analysis_op.get_next_btn_status())
                            return
                        next_x.focus = true
                    }
                }
                Image {
                    id: next_x_focus_img
                    anchors.fill: parent
                    source: qml_port.get_img_qml_res_path() + "images/button_st_s.png"
                    visible: next_x.focus
                }
            }
        }
        Rectangle {
            id: btn_return
            anchors.right: parent.right
            height: parent.height
            width: parent.height
            color: "transparent"
            visible: true
            Image {
                id: btn_return_img
                anchors.fill: parent
                source: qml_port.get_img_qml_res_path() + "images/back_b_n.png"
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    rect_analysis_window.focus = true
                    clicked_btn_return()
                }
                onPressed: {
                    btn_return.focus = true
                }
            }
            Image {
                id: btn_return_focus_img
                anchors.fill: parent
                source: qml_port.get_img_qml_res_path() + "images/button_st_s.png"
                visible: btn_return.focus
            }
        }
    }

    Component.onCompleted: {
        analysis_op.reset_current_index(myAxisX.min)
        text_y.text = analysis_op.get_current_index()
        init_part()
        init_maxY()
        init_minY()
        init_lineSeries()
        update_chart()
        update_temp()
        update_btn_source()
    }

    function init_maxY()
    {
        myAxisY.max = analysis_op.get_maxTemp()
    }

    function init_minY()
    {
        myAxisY.min = analysis_op.get_minTemp()
    }

    function init_part()
    {
        console.log("#### [AnalysisChart] [init_part] : get_historyData_count = " + analysis_op.get_historyData_count())

        analysis_part_model.clear()
        for(var i = 0; i < (analysis_op.get_historyData_count() / 20); i++) {
            if (i != 0)
                analysis_part_model.append({"cur_index": i, "part_status": false, "part_text": qsTr((i*20+1) + "-" + (i*20+20))})
            else
                analysis_part_model.append({"cur_index": i, "part_status": true, "part_text": qsTr((i*20+1) + "-" + (i*20+20))})
        }
    }

    function init_lineSeries()
    {
        analysis_choose_model.clear()
        for(var i = 0; i < analysis_op.get_unit_count(); i++) {
            if(i < 10) {
                analysis_choose_model.append({"n_title":analysis_op.get_unit_name(i), "n_status":true, "n_index":i, "n_temp":"", "n_color":"#7CA6C9", "current_index": i})
            } else {
                analysis_choose_model.append({"n_title":analysis_op.get_unit_name(i), "n_status":false, "n_index":100, "n_temp":"", "n_color":"#7CA6C9", "current_index": i})
            }
        }

        lineSeries_1.clear();   lineSeries_6.clear();
        lineSeries_2.clear();   lineSeries_7.clear();
        lineSeries_3.clear();   lineSeries_8.clear();
        lineSeries_4.clear();   lineSeries_9.clear();
        lineSeries_5.clear();   lineSeries_10.clear();
        lineSeries_1.visible = false;    lineSeries_2.visible = false;
        lineSeries_3.visible = false;    lineSeries_4.visible = false;
        lineSeries_5.visible = false;    lineSeries_6.visible = false;
        lineSeries_7.visible = false;    lineSeries_8.visible = false;
        lineSeries_9.visible = false;    lineSeries_10.visible = false;
        switch (analysis_choose_model.count) {
        case 0:
            break
        case 1:
            lineSeries_1.visible = true;
            lineSeries_1.name = analysis_choose_model.get(0).n_title
            break;
        case 2:
            lineSeries_1.visible = true;    lineSeries_2.visible = true;
            lineSeries_1.name = analysis_choose_model.get(0).n_title
            lineSeries_2.name = analysis_choose_model.get(1).n_title
            break;
        case 3:
            lineSeries_1.visible = true;    lineSeries_2.visible = true;
            lineSeries_3.visible = true;
            lineSeries_1.name = analysis_choose_model.get(0).n_title
            lineSeries_2.name = analysis_choose_model.get(1).n_title
            lineSeries_3.name = analysis_choose_model.get(2).n_title
            break;
        case 4:
            lineSeries_1.visible = true;    lineSeries_2.visible = true;
            lineSeries_3.visible = true;    lineSeries_4.visible = true;
            lineSeries_1.name = analysis_choose_model.get(0).n_title
            lineSeries_2.name = analysis_choose_model.get(1).n_title
            lineSeries_3.name = analysis_choose_model.get(2).n_title
            lineSeries_4.name = analysis_choose_model.get(3).n_title
            break;
        case 5:
            lineSeries_1.visible = true;    lineSeries_2.visible = true;
            lineSeries_3.visible = true;    lineSeries_4.visible = true;
            lineSeries_5.visible = true;
            lineSeries_1.name = analysis_choose_model.get(0).n_title
            lineSeries_2.name = analysis_choose_model.get(1).n_title
            lineSeries_3.name = analysis_choose_model.get(2).n_title
            lineSeries_4.name = analysis_choose_model.get(3).n_title
            lineSeries_5.name = analysis_choose_model.get(4).n_title
            break;
        case 6:
            lineSeries_1.visible = true;    lineSeries_2.visible = true;
            lineSeries_3.visible = true;    lineSeries_4.visible = true;
            lineSeries_5.visible = true;    lineSeries_6.visible = true;
            lineSeries_1.name = analysis_choose_model.get(0).n_title
            lineSeries_2.name = analysis_choose_model.get(1).n_title
            lineSeries_3.name = analysis_choose_model.get(2).n_title
            lineSeries_4.name = analysis_choose_model.get(3).n_title
            lineSeries_5.name = analysis_choose_model.get(4).n_title
            lineSeries_6.name = analysis_choose_model.get(5).n_title
            break;
        case 7:
            lineSeries_1.visible = true;    lineSeries_2.visible = true;
            lineSeries_3.visible = true;    lineSeries_4.visible = true;
            lineSeries_5.visible = true;    lineSeries_6.visible = true;
            lineSeries_7.visible = true;
            lineSeries_1.name = analysis_choose_model.get(0).n_title
            lineSeries_2.name = analysis_choose_model.get(1).n_title
            lineSeries_3.name = analysis_choose_model.get(2).n_title
            lineSeries_4.name = analysis_choose_model.get(3).n_title
            lineSeries_5.name = analysis_choose_model.get(4).n_title
            lineSeries_6.name = analysis_choose_model.get(5).n_title
            lineSeries_7.name = analysis_choose_model.get(6).n_title
            break;
        case 8:
            lineSeries_1.visible = true;    lineSeries_2.visible = true;
            lineSeries_3.visible = true;    lineSeries_4.visible = true;
            lineSeries_5.visible = true;    lineSeries_6.visible = true;
            lineSeries_7.visible = true;    lineSeries_8.visible = true;
            lineSeries_1.name = analysis_choose_model.get(0).n_title
            lineSeries_2.name = analysis_choose_model.get(1).n_title
            lineSeries_3.name = analysis_choose_model.get(2).n_title
            lineSeries_4.name = analysis_choose_model.get(3).n_title
            lineSeries_5.name = analysis_choose_model.get(4).n_title
            lineSeries_6.name = analysis_choose_model.get(5).n_title
            lineSeries_7.name = analysis_choose_model.get(6).n_title
            lineSeries_8.name = analysis_choose_model.get(7).n_title
            break;
        case 9:
            lineSeries_1.visible = true;    lineSeries_2.visible = true;
            lineSeries_3.visible = true;    lineSeries_4.visible = true;
            lineSeries_5.visible = true;    lineSeries_6.visible = true;
            lineSeries_7.visible = true;    lineSeries_8.visible = true;
            lineSeries_9.visible = true;
            lineSeries_1.name = analysis_choose_model.get(0).n_title
            lineSeries_2.name = analysis_choose_model.get(1).n_title
            lineSeries_3.name = analysis_choose_model.get(2).n_title
            lineSeries_4.name = analysis_choose_model.get(3).n_title
            lineSeries_5.name = analysis_choose_model.get(4).n_title
            lineSeries_6.name = analysis_choose_model.get(5).n_title
            lineSeries_7.name = analysis_choose_model.get(6).n_title
            lineSeries_8.name = analysis_choose_model.get(7).n_title
            lineSeries_9.name = analysis_choose_model.get(8).n_title
            break;
        default:
            lineSeries_1.visible = true;    lineSeries_2.visible = true;
            lineSeries_3.visible = true;    lineSeries_4.visible = true;
            lineSeries_5.visible = true;    lineSeries_6.visible = true;
            lineSeries_7.visible = true;    lineSeries_8.visible = true;
            lineSeries_9.visible = true;    lineSeries_10.visible = true;
            lineSeries_1.name = analysis_choose_model.get(0).n_title
            lineSeries_2.name = analysis_choose_model.get(1).n_title
            lineSeries_3.name = analysis_choose_model.get(2).n_title
            lineSeries_4.name = analysis_choose_model.get(3).n_title
            lineSeries_5.name = analysis_choose_model.get(4).n_title
            lineSeries_6.name = analysis_choose_model.get(5).n_title
            lineSeries_7.name = analysis_choose_model.get(6).n_title
            lineSeries_8.name = analysis_choose_model.get(7).n_title
            lineSeries_9.name = analysis_choose_model.get(8).n_title
            lineSeries_10.name = analysis_choose_model.get(9).n_title
            break;
        }
    }

    function clicked_btn_part( index )
    {
        myAxisX.min = index * 20 + 1
        myAxisX.max = index * 20 + 20
        for(var i = 0; i < analysis_part_model.count; i++) {
            if(i !== index)
                analysis_part_model.set(i, {"part_status":false})
            else
                analysis_part_model.set(i, {"part_status":true})
        }

        analysis_op.reset_current_index(myAxisX.min)
        text_y.text = analysis_op.get_current_index()
        update_temp()
        update_chart()
        update_btn_source()
    }



    function clicked_btn_pre()
    {
        if(!analysis_op.get_pre_btn_status())
            return;

        analysis_op.pre_current_index()
        text_y.text = analysis_op.get_current_index()
        update_temp()
        update_btn_source()
    }

    function clicked_btn_next()
    {
        if(!analysis_op.get_next_btn_status())
            return;

        analysis_op.next_current_index()
        text_y.text = analysis_op.get_current_index()
        update_temp()
        update_btn_source()
    }

    function update_btn_source()
    {
        if(analysis_op.get_pre_btn_status())
            pre_x_img.source = qml_port.get_img_qml_res_path() + "images/pre_page_n.png"
        else
            pre_x_img.source = qml_port.get_img_qml_res_path() + "images/pre_page_d.png"

        if(analysis_op.get_next_btn_status())
            next_x_img.source = qml_port.get_img_qml_res_path() + "images/next_page_n.png"
        else
            next_x_img.source = qml_port.get_img_qml_res_path() + "images/next_page_d.png"
    }

    function clicked_btn_return()
    {
        sig_return_tree_wnd()
    }

    function update_chart()
    {
        console.log("#### [AnalysisChart] [update_chart] : RUN . . .")

        lineSeries_1.clear();   lineSeries_1.visible = false
        lineSeries_2.clear();   lineSeries_2.visible = false
        lineSeries_3.clear();   lineSeries_3.visible = false
        lineSeries_4.clear();   lineSeries_4.visible = false
        lineSeries_5.clear();   lineSeries_5.visible = false
        lineSeries_6.clear();   lineSeries_6.visible = false
        lineSeries_7.clear();   lineSeries_7.visible = false
        lineSeries_8.clear();   lineSeries_8.visible = false
        lineSeries_9.clear();   lineSeries_9.visible = false
        lineSeries_10.clear();  lineSeries_10.visible = false

        var tmp = 0
        for(var devIndex = 0; devIndex < analysis_choose_model.count; devIndex++) {
            if(analysis_choose_model.get(devIndex).n_status) {
                if(tmp === 0) {
                    lineSeries_1.visible = true
                    lineSeries_1.name = analysis_choose_model.get(devIndex).n_title
                } else if(tmp === 1) {
                    lineSeries_2.visible = true
                    lineSeries_2.name = analysis_choose_model.get(devIndex).n_title
                } else if(tmp === 2) {
                    lineSeries_3.visible = true
                    lineSeries_3.name = analysis_choose_model.get(devIndex).n_title
                } else if(tmp === 3) {
                    lineSeries_4.visible = true
                    lineSeries_4.name = analysis_choose_model.get(devIndex).n_title
                } else if(tmp === 4) {
                    lineSeries_5.visible = true
                    lineSeries_5.name = analysis_choose_model.get(devIndex).n_title
                } else if(tmp === 5) {
                    lineSeries_6.visible = true
                    lineSeries_6.name = analysis_choose_model.get(devIndex).n_title
                } else if(tmp === 6) {
                    lineSeries_7.visible = true
                    lineSeries_7.name = analysis_choose_model.get(devIndex).n_title
                } else if(tmp === 7) {
                    lineSeries_8.visible = true
                    lineSeries_8.name = analysis_choose_model.get(devIndex).n_title
                } else if(tmp === 8) {
                    lineSeries_9.visible = true
                    lineSeries_9.name = analysis_choose_model.get(devIndex).n_title
                } else if(tmp === 9) {
                    lineSeries_10.visible = true
                    lineSeries_10.name = analysis_choose_model.get(devIndex).n_title
                }
                tmp++
            }
        }

        for(var xIndex = myAxisX.min; xIndex <= myAxisX.max; xIndex++) {
            for(devIndex = 0; devIndex < analysis_choose_model.count; devIndex++) {
                if(analysis_choose_model.get(devIndex).n_status) {
                    var temp = analysis_op.get_temp_by_index(xIndex - 1, devIndex)
                    if(temp !== -50.00) {
                        if(analysis_choose_model.get(devIndex).n_title === lineSeries_1.name)
                            lineSeries_1.append(xIndex, temp)
                        else if(analysis_choose_model.get(devIndex).n_title === lineSeries_2.name)
                            lineSeries_2.append(xIndex, temp)
                        else if(analysis_choose_model.get(devIndex).n_title === lineSeries_3.name)
                            lineSeries_3.append(xIndex, temp)
                        else if(analysis_choose_model.get(devIndex).n_title === lineSeries_4.name)
                            lineSeries_4.append(xIndex, temp)
                        else if(analysis_choose_model.get(devIndex).n_title === lineSeries_5.name)
                            lineSeries_5.append(xIndex, temp)
                        else if(analysis_choose_model.get(devIndex).n_title === lineSeries_6.name)
                            lineSeries_6.append(xIndex, temp)
                        else if(analysis_choose_model.get(devIndex).n_title === lineSeries_7.name)
                            lineSeries_7.append(xIndex, temp)
                        else if(analysis_choose_model.get(devIndex).n_title === lineSeries_8.name)
                            lineSeries_8.append(xIndex, temp)
                        else if(analysis_choose_model.get(devIndex).n_title === lineSeries_9.name)
                            lineSeries_9.append(xIndex, temp)
                        else if(analysis_choose_model.get(devIndex).n_title === lineSeries_10.name)
                            lineSeries_10.append(xIndex, temp)
                    }
                }
            }
        }
    }

    function update_temp()
    {
        for(var i = 0; i < analysis_choose_model.count; i++) {
            if(analysis_choose_model.get(i).n_status && analysis_op.get_temp_by_index(analysis_op.get_current_index() - 1, i) !== -50.00) {
                var tmpColor = "#7CA6C9";
                if(analysis_choose_model.get(i).n_title === lineSeries_1.name)
                    tmpColor = "#FF2222"
                else if(analysis_choose_model.get(i).n_title === lineSeries_2.name)
                    tmpColor = "#22FF22"
                else if(analysis_choose_model.get(i).n_title === lineSeries_3.name)
                    tmpColor = "#2222FF"
                else if(analysis_choose_model.get(i).n_title === lineSeries_4.name)
                    tmpColor = "#F2F222"
                else if(analysis_choose_model.get(i).n_title === lineSeries_5.name)
                    tmpColor = "#F222F2"
                else if(analysis_choose_model.get(i).n_title === lineSeries_6.name)
                    tmpColor = "#FFFFF2"
                else if(analysis_choose_model.get(i).n_title === lineSeries_7.name)
                    tmpColor = "#2FFFFF"
                else if(analysis_choose_model.get(i).n_title === lineSeries_8.name)
                    tmpColor = "#222222"
                else if(analysis_choose_model.get(i).n_title === lineSeries_9.name)
                    tmpColor = "#DDDDDD"
                else if(analysis_choose_model.get(i).n_title === lineSeries_10.name)
                    tmpColor = "#D2D22D"
                analysis_choose_model.set(i, {"n_temp": analysis_op.get_temp_by_index(analysis_op.get_current_index() - 1, i).toFixed(2), "n_color":tmpColor})
            } else {
                analysis_choose_model.set(i, {"n_temp": "", "n_color":"#7CA6C9"})
            }
        }
    }

    Keys.enabled: true
    Keys.onReleased: {
        console.log("#### [AnalysisChart] [Keys.onReleased] : running  . . . " + event.key)
        switch(event.key) {
        case qml_port.get_keyValue_from_up():
            console.log("#### [AnalysisChart] [Keys.onReleased] : UP . . .")
            key_up()
            break;
        case qml_port.get_keyValue_from_down():
            console.log("#### [AnalysisChart] [Keys.onReleased] : DOWN . . .")
            key_down()
            break;
        case qml_port.get_keyValue_from_left():
            console.log("#### [AnalysisChart] [Keys.onReleased] : LEFT . . .")
            key_left()
            break;
        case qml_port.get_keyValue_from_right():
            console.log("#### [AnalysisChart] [Keys.onReleased] : RIGHT . . .")
            key_right()
            break;
        case qml_port.get_keyValue_from_center():
            console.log("#### [AnalysisChart] [Keys.onReleased] : OK . . .")
            key_ok()
            break;
        }
    }

    function key_up()
    {
        if(!analysis_part_list.focus && !btn_return.focus &&
                !pre_x.focus && !next_x.focus) {
            if (analysis_part_model.count > 0) {
                analysis_part_list.focus = true
                for(var i = 0; i < analysis_part_model.count; i++) {
                    if(analysis_part_model.get(i).part_status) {
                        rect_analysis_window.n_part_index = analysis_part_model.get(i).cur_index
                        analysis_part_list.positionViewAtIndex(i, ListView.Center)
                    }
                }
            } else if (analysis_op.get_pre_btn_status()) {
                pre_x.focus = true
            } else if (analysis_op.get_next_btn_status()) {
                next_x.focus = true
            } else {
                btn_return.focus = true
            }
            n_current_index = -1
        } else if (analysis_part_list.focus || pre_x.focus || next_x.focus || btn_return.focus) {
            if(analysis_choose_model.count > 0) {
                analysis_choose_list.focus = true
                n_current_index = 0
                analysis_choose_list.positionViewAtIndex(n_current_index, ListView.Center)
                rect_analysis_window.n_part_index = -1
            }
        }
    }

    function key_down()
    {
        rect_analysis_window.n_part_index = -1
        if(!analysis_choose_list.focus && analysis_choose_model.count > 0) {
            analysis_choose_list.focus = true
            n_current_index = 0
            analysis_choose_list.positionViewAtIndex(n_current_index, ListView.Center)
            rect_analysis_window.n_part_index = -1
        } else if (!analysis_part_list.focus || !pre_x.focus || !next_x.focus || !btn_return.focus) {
            if (analysis_part_model.count > 0) {
                analysis_part_list.focus = true
                for(var i = 0; i < analysis_part_model.count; i++) {
                    if(analysis_part_model.get(i).part_status) {
                        rect_analysis_window.n_part_index = analysis_part_model.get(i).cur_index
                        analysis_part_list.positionViewAtIndex(i, ListView.Center)
                    }
                }
            } else if (analysis_op.get_pre_btn_status()) {
                pre_x.focus = true
            } else if (analysis_op.get_next_btn_status()) {
                next_x.focus = true
            } else {
                btn_return.focus = true
            }
            n_current_index = -1
        }
    }

    function key_left()
    {
        var i = 0
        if(!analysis_choose_list.focus && !analysis_part_list.focus &&
                !pre_x.focus && !next_x.focus && !btn_return.focus) {
            btn_return.focus = true
        } else if (btn_return.focus) {
            if(analysis_op.get_next_btn_status())
                next_x.focus = true
            else if (analysis_op.get_pre_btn_status())
                pre_x.focus = true
            else if (analysis_part_model.count > 0) {
                analysis_part_list.focus = true
                for(i = 0; i < analysis_part_model.count; i++) {
                    if(analysis_part_model.get(i).part_status) {
                        rect_analysis_window.n_part_index = analysis_part_model.get(i).cur_index
                        analysis_part_list.positionViewAtIndex(i, ListView.Center)
                    }
                }
            }
        } else if (next_x.focus) {
            if (analysis_op.get_pre_btn_status())
                pre_x.focus = true
            else if (analysis_part_model.count > 0) {
                analysis_part_list.focus = true
                for(i = 0; i < analysis_part_model.count; i++) {
                    if(analysis_part_model.get(i).part_status) {
                        rect_analysis_window.n_part_index = analysis_part_model.get(i).cur_index
                        analysis_part_list.positionViewAtIndex(i, ListView.Center)
                    }
                }
            } else
                btn_return.focus = true
        } else if (pre_x.focus) {
            if (analysis_part_model.count > 0) {
                analysis_part_list.focus = true
                for(i = 0; i < analysis_part_model.count; i++) {
                    if(analysis_part_model.get(i).part_status) {
                        rect_analysis_window.n_part_index = analysis_part_model.get(i).cur_index
                        analysis_part_list.positionViewAtIndex(i, ListView.Center)
                    }
                }
            } else
                btn_return.focus = true
        } else if (analysis_part_list.focus) {
            if(rect_analysis_window.n_part_index > 0) {
                rect_analysis_window.n_part_index--
                analysis_part_list.positionViewAtIndex(rect_analysis_window.n_part_index, ListView.Center)
            } else if (rect_analysis_window.n_part_index == 0) {
                rect_analysis_window.n_part_index--
                btn_return.focus = true
            }
        } else if (analysis_choose_list.focus) {
            n_current_index--;
            if(n_current_index < 0)
                n_current_index = analysis_choose_model.count - 1
            analysis_choose_list.positionViewAtIndex(n_current_index, ListView.Center)
        }
    }

    function key_right()
    {
        var i = 0
        if(!analysis_choose_list.focus && !analysis_part_list.focus &&
                !pre_x.focus && !next_x.focus) {
            if(analysis_part_model.count > 0) {
                analysis_part_list.focus = true
                for(i = 0; i < analysis_part_model.count; i++) {
                    if(analysis_part_model.get(i).part_status) {
                        rect_analysis_window.n_part_index = analysis_part_model.get(i).cur_index
                        analysis_part_list.positionViewAtIndex(i, ListView.Center)
                    }
                }
            } else
                btn_return.focus = true
        } else if (pre_x.focus) {
            if(analysis_op.get_next_btn_status())
                next_x.focus = true
            else
                btn_return.focus = true
        } else if (next_x.focus) {
            btn_return.focus = true
        } else if (analysis_choose_list.focus) {
            n_current_index++;
            if(n_current_index >= analysis_choose_model.count)
                n_current_index = 0
            analysis_choose_list.positionViewAtIndex(n_current_index, ListView.Center)
        } else if (analysis_part_list.focus) {
            if(rect_analysis_window.n_part_index <  analysis_part_model.count - 1) {
                rect_analysis_window.n_part_index++
                analysis_part_list.positionViewAtIndex(rect_analysis_window.n_part_index, ListView.Center)
            } else if (rect_analysis_window.n_part_index >= analysis_part_model.count - 1) {
                rect_analysis_window.n_part_index = -1
                if(analysis_op.get_pre_btn_status())
                    pre_x.focus = true
                else if(analysis_op.get_next_btn_status())
                    next_x.focus = true
                else
                    btn_return.focus = true
            }
        }
    }

    function key_ok()
    {
        if(analysis_choose_list.focus) {
            var tmpStatus = !analysis_choose_model.get(n_current_index).n_status
            analysis_choose_model.set(n_current_index, {"n_status":tmpStatus})
            if(tmpStatus) {
                var tmpIndex = -1
                for(var i = 0; i < analysis_choose_model.count; i++)
                    if(analysis_choose_model.get(i).n_status)
                        tmpIndex++
                if(tmpIndex >= 10) {
                    tmpIndex = 9
                    for(var j = 0; j < analysis_choose_model.count; j++) {
                        if(analysis_choose_model.get(j).n_status && analysis_choose_model.get(j).n_index < 10) {
                            if(analysis_choose_model.get(j).n_index <= 0)
                                analysis_choose_model.set(j, {"n_index": 100, "n_status": false})
                            else
                                analysis_choose_model.set(j, {"n_index": analysis_choose_model.get(j).n_index - 1})
                        }
                    }
                }
                analysis_choose_model.set(n_current_index, {"n_index":tmpIndex})
            } else {
                for(var m = 0; m < analysis_choose_model.count; m++) {
                    if(analysis_choose_model.get(m).n_status &&
                            analysis_choose_model.get(m).n_index > analysis_choose_model.get(n_current_index).n_index &&
                            analysis_choose_model.get(m).n_index !== 100)
                        analysis_choose_model.set(m, {"n_index": analysis_choose_model.get(m).n_index - 1})
                }
                analysis_choose_model.set(n_current_index, {"n_index":100})
            }
            update_chart()
            update_temp()
        } else if (analysis_part_list.focus) {
            clicked_btn_part(n_part_index)
        } else if (pre_x.focus) {
            clicked_btn_pre()
        } else if (next_x.focus) {
            clicked_btn_next()
        } else if (btn_return.focus) {
            clicked_btn_return()
        }
    }

    function reset_list_focus()
    {
        rect_analysis_window.focus = true
        n_current_index = -1
        n_part_index = -1
    }

    function update_focus_img() {

    }
}






























