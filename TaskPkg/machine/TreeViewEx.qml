import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.2
import QtQuick.Window 2.0


Rectangle {
    id: tree_ex_id

    property int screen_width: qml_port.get_screen_width()
    property int screen_height: qml_port.get_screen_height()

    width: qml_port.get_screen_listWidth()
    //width: screen_width
    height: tree_ex_id.screen_height
    x:0
    y:0
    visible: bshow_list
    focus: bshow_list
    property int index : 0
    property bool bshow_list: true
    property int n_sel_index: 4
    property int sign_number: 5
    property int list_size: 0
    property int i_time: 0
    property int device_id: 0
    signal showGridView();
    signal click_by_id(var pos);
    signal treeViewReturn();
    signal histortShow();
    signal createFinish();
    signal reset_curSelFlag();

    signal sig_interaction_show();

    color: "transparent"

    Image {
        x: 0
        y: 0
        //width: parent.width * 4
        width: qml_port.get_screen_listWidth()
        height: parent.height
        source: qml_port.get_img_qml_res_path() + "images/setting_background.png"
    }

    ListModel {
        id: treeViewExModel
    }

    ListView {
        id : tree_list_view
        model: treeViewExModel
        width: qml_port.get_screen_listWidth()
        height: parent.height - down_function.height;
        anchors.top: parent.top
        clip: true
        onDragStarted: {
            set_hidden_menu(false)
        }
        onDragEnded: {
            qml_port.update_sync_sgl();
        }

        Component.onCompleted: {
            currentIndex = qml_port.get_task_select_pos();
            console.log("#### [TreeViewEx] [tree_list_view] : The tree List view is loaded successfully, currentIndex = %d", currentIndex);

            //createFinish()
            console.log("<TreeViewEx.qml> <tree_list_view> : end . . .\r\n");
        }

        delegate: TreeViewExDelegate {
            id: tree_view_ex_delegate;
            text: ( index >= 0 && index < treeViewExModel.count ) ? treeViewExModel.get( index ).title:""
            onClicked: {
                if(  typeof(treeViewExModel.get( n_indx ).v_index) == "undefined"
                        || typeof(tree_list_view) == "undefined" ) {
                    return;
                }
                set_hidden_menu(false)
                tree_ex_id.n_sel_index = treeViewExModel.get( n_indx ).v_index
                if(tree_ex_id.n_sel_index == 0)
                    return;
                var ret = qml_port.tree_node_clicked( treeViewExModel.get( n_indx ).v_index );
                if( ret == 0 ) {
                    tree_ex_id.n_sel_index = qml_port.get_task_select_pos();
                    title_show(qml_port.get_current_img_name())
                    qml_port.setCurrentImgName()
                } else if( ret == 1 ) {/*
                    tree_list_view.enabled = false;
                    create_tree_ex( n_indx, qml_port.get_click_child_num() );
                    tree_list_view.enabled = true;*/
                }
                if(qml_port.get_task_tree_list_node_level(tree_ex_id.n_sel_index) < 4) {
                    tree_list_view.enabled = false;
                    create_tree_ex( n_indx, qml_port.get_click_child_num() );
                    //create_tree_ex(-1, 0)
                    tree_list_view.enabled = true;
                }

                /*
                console.log("\r\n\r\n\r\n")
                if(analysis_op.exist_history_by_info(qml_port.get_deviceNodes_by_index( tree_ex_id.n_sel_index )))
                    console.log("==============================================")
                else
                    console.log("----------------------------------------------")
                console.log("\r\n\r\n\r\n")
                */
                if(qml_port.get_task_tree_list_node_level(treeViewExModel.get( n_indx ).v_index) == 4)
                    device_id = treeViewExModel.get( n_indx ).v_index

                console.log( "TreeViewEx.qml onClicked n_indx=", treeViewExModel.get( n_indx ).v_index, ret, n_indx )
            }
            Connections {
                target: tree_ex_id
                ignoreUnknownSignals: true
                onClick_by_id: {
                    tree_view_ex_delegate.click_date( pos );
                }
            }
        }

        function modelChange(tmpIndex) {
            console.log("#### [TreeViewEx] [modelChange] : " + tmpIndex)
            if(  typeof(treeViewExModel.get( tmpIndex ).v_index) == "undefined"
                    || typeof(tree_list_view) == "undefined" ) {
                return;
            }
            var ret = qml_port.tree_node_clicked( treeViewExModel.get( tmpIndex ).v_index );
            if( ret == 0 ) {
                tree_ex_id.n_sel_index = qml_port.get_task_select_pos();
                title_show(qml_port.get_current_img_name())
                qml_port.setCurrentImgName()
            } else if( ret == 1 ) {/*
                tree_list_view.enabled = false;
                create_tree_ex( tmpIndex, qml_port.get_click_child_num() );
                tree_list_view.enabled = true;*/
            }
            if(qml_port.get_task_tree_list_node_level(tree_ex_id.n_sel_index) < 4) {
                tree_list_view.enabled = false;
                create_tree_ex( tmpIndex, qml_port.get_click_child_num() );
                tree_list_view.enabled = true;
            }
        }
    }

    /* 底部按键 */
    Rectangle{
        id: down_function
        height: tree_ex_id.screen_height / 10
        width: qml_port.get_screen_listWidth()
        anchors.top: tree_list_view.bottom
        Rectangle {
            id: return_rect;
            x: 0
            y: 0
            height: down_function.height
            width: down_function.width / 2
            Image{
                anchors.fill: parent
                source: qml_port.get_img_qml_res_path()  + "images/bottom.png";
            }
            Image{
                id: return_image;
                anchors.centerIn: parent
                source: qml_port.get_img_qml_res_path() + "images/tree_back.png";
            }
            Image {
                anchors.fill: parent
                source: return_rect.focus?(qml_port.get_img_qml_res_path() + "images/levelindicate.png"):""
            }
            MouseArea {
                id: return_mouse_area
                anchors.fill: parent;
                onClicked: {
                    treeViewReturn();
                }
                onPressed: {
                    return_rect.focus = true
                    set_hidden_menu(false)
                }
                onReleased: {
                    tree_list_view.focus = true
                }
            }
        }

        Rectangle {
            id: pull_rect;
            x: down_function.width / 2
            y: 0
            height: down_function.height
            width: down_function.width / 2
            Image{
                anchors.fill: parent
                source: qml_port.get_img_qml_res_path()  + "images/bottom.png";
            }
            Image{
                id: pull_image;
                anchors.centerIn: parent
                source: qml_port.get_img_qml_res_path() + (hidden_menu_rect.visible?"images/tree_down.png":"images/tree_up.png");
            }
            Image {
                anchors.fill: parent
                source: pull_rect.focus?(qml_port.get_img_qml_res_path() + "images/levelindicate.png"):""
            }
            MouseArea {
                id: pull_mouse_area
                anchors.fill: parent;
                onClicked: {
                    //histortShow();
                    if(hidden_menu_rect.visible)
                        set_hidden_menu(false)
                    else
                        set_hidden_menu(true)
                }
                onPressed: {
                    pull_rect.focus = true
                }
                onReleased: {
                    tree_list_view.focus = true
                }
            }
        }
    }

    function set_hidden_menu( status )
    {
        hidden_menu_rect.visible = status
    }

    Rectangle {
        id: hidden_menu_rect
        anchors.bottom: down_function.top
        height: down_function.height * 3
        width: down_function.width
        visible: false
        Rectangle {
            id: reset_rect
            width: parent.width
            height: parent.height / 3
            anchors.bottom: parent.bottom
            visible: hidden_menu_rect.visible
            Image{
                anchors.fill: parent
                source: qml_port.get_img_qml_res_path()  + "images/bottom.png";
            }
            Image{
                id: reset_image;
                anchors.centerIn: parent
                source: qml_port.get_img_qml_res_path() + "images/tree_refresh.png";
            }
            Image {
                anchors.fill: parent
                source: reset_rect.focus?(qml_port.get_img_qml_res_path() + "images/levelindicate.png"):""
            }
            MouseArea {
                id: reset_mouse_area
                anchors.fill: parent;
                onClicked: {
                    sig_interaction_show()
                    //reset_rect.reset_capture_flag()
                    set_hidden_menu(false)
                }
                onPressed: {
                    reset_rect.focus = true
                }
                onReleased: {
                    tree_list_view.focus = true
                }
            }

            function reset_capture_flag()
            {
                console.log("reset_capture_flag --->")
                analysis_op.reset_capture_flag()
                for(var i = 0; i < treeViewExModel.count; i++) {
                    if(treeViewExModel.get(i).v_capture > 0)
                        treeViewExModel.set(i, {"v_capture": 0})
                }
            }
        }
        Rectangle {
            id: history_rect
            width: parent.width
            height: parent.height / 3
            anchors.bottom: reset_rect.top
            visible: hidden_menu_rect.visible
            Image{
                anchors.fill: parent
                source: qml_port.get_img_qml_res_path()  + "images/bottom.png";
            }
            Image{
                id: history_image;
                anchors.centerIn: parent
                source: qml_port.get_img_qml_res_path() + "images/tree_analysis.png";
            }
            Image {
                anchors.fill: parent
                source: history_rect.focus?(qml_port.get_img_qml_res_path() + "images/levelindicate.png"):""
            }
            MouseArea {
                id: history_mouse_area
                anchors.fill: parent;
                onClicked: {
                    set_hidden_menu(false)
                    histortShow();
                }
                onPressed: {
                    history_rect.focus = true
                }
                onReleased: {
                    tree_list_view.focus = true
                }
            }
        }
        Rectangle {
            id: delete_rect
            width: parent.width
            height:  parent.height / 3
            anchors.bottom: history_rect.top
            visible: hidden_menu_rect.visible
            Image {
                anchors.fill: parent
                source: qml_port.get_img_qml_res_path() + "images/bottom.png";
            }
            Image {
                id: delete_image;
                anchors.centerIn: parent
                source: qml_port.get_img_qml_res_path() + "images/delete.png";
            }
            Image {
                anchors.fill: parent
                source: delete_rect.focus?(qml_port.get_img_qml_res_path() + "images/levelindicate.png"):""
            }
            MouseArea {
                id: delete_mouse_area
                anchors.fill: parent
                onClicked: {
                    set_hidden_menu(false)
                    delete_rect.delete_img_batch()
                }
                onPressed: {
                    delete_rect.focus = true
                }
                onReleased: {
                    tree_list_view.focus = true
                }
            }

            function delete_img_batch() {
                qml_port.delete_img_by_index()
                reset_curSelFlag();

                device_id = tree_ex_id.n_sel_index
                treeViewExModel.set(transition_index(tree_ex_id.device_id), { "v_capture": 0 })
                var curIndex = tree_ex_id.device_id
                var tmpIndex = tree_ex_id.device_id

                for(var i = 0; i < 3; i++) {
                    tmpIndex = qml_port.get_father_index(curIndex)
                    for(var j = transition_index(tmpIndex) + 1; j < treeViewExModel.count; j++) {
                        if(qml_port.get_task_tree_list_node_level(treeViewExModel.get(j).v_index) <=
                                qml_port.get_task_tree_list_node_level(tmpIndex))
                            break
                        if(treeViewExModel.get(j).v_capture === 1) {
                            return
                        }
                    }
                    curIndex = tmpIndex
                    treeViewExModel.set(transition_index(tmpIndex), { "v_capture": 0 })
                }
            }
        }
    }

    Rectangle {
        id: img_title_rect
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        width: img_title.width+15
        height: img_title.height+15
        radius: 3
        visible: false
        color: "transparent"
        BorderImage {
            id: capture_title_img
            source: qml_port.get_img_qml_res_path()  +"images/imgTitleBg.png"
            anchors.fill: parent
            anchors.margins: 1
        }
        Text {
            id: img_title
            anchors.centerIn: parent
            text: qsTr("text")
            color: "white"
            font.pixelSize: 22
            visible: true
        }
    }

    function set_current_device( path, bUnfold ) {

        console.log( "TreeViewEx.qml set_current_device select_pos=", tree_ex_id.n_sel_index, qml_port.get_task_select_pos(), " bUnfold=", bUnfold )
        if( tree_ex_id.n_sel_index != qml_port.get_task_select_pos() ) {
            var list_count = qml_port.get_task_tree_list_count();
            var sel_pos = qml_port.get_task_select_pos();
            var j = 0, pos = 0;

            for( var i=0; i<list_count; ++i ) {
                if( qml_port.get_task_tree_node_visible( i ) ) {
                    if( sel_pos == i ) {
                        pos = j;
                    } else {
                        ++j;
                    }
                }
                if( !qml_port.get_task_tree_node_child_visible( i ) && qml_port.get_task_tree_list_node_number( i ) > 0 ) {
                    var level = qml_port.get_task_tree_list_node_level( i );

                    do {
                        i = i + qml_port.get_task_tree_list_node_number( i ) + 1;
                    } while( qml_port.get_task_tree_list_node_level( i ) > level );
                    --i;
                }
            }

            console.log( "TreeViewEx.qml set_current_device pos=2222", pos, sign_number )
            if( pos < sign_number ) {
                //tree_list_view.positionViewAtIndex( 0, ListView.Beginning )
                tree_list_view.contentY = 0;
                tree_list_view.y = 0;
                tree_list_view.positionViewAtBeginning();
            } else {
                //tree_list_view.positionViewAtIndex( pos - 1 - qml_port.get_packup_count(), ListView.Beginning )
                tree_list_view.positionViewAtIndex( pos - 1, ListView.Beginning )
            }

            tree_ex_id.n_sel_index = qml_port.get_task_select_pos();
        }
        title_show(qml_port.get_current_img_name())
//        title_lab.set_img_title( parameterManager.is_device_name_show(), false );
    }

    function title_show(title) {
        img_title_rect.visible = false;
        img_title.text = title
    }

    function device_save_change() {
        //objModel.deviceSaveChange()
        if( qml_port.get_child_visible_change() ) {
            tree_list_view.enabled = false;
            //create_tree_ex( -1, 0 );
            create_tree_ex_by_save_shoot();
            tree_list_view.enabled = true;
        } else {
            var objs = tree_list_view.children;
            var sel_pos = qml_port.get_task_select_pos();

            for( var i=0; i<objs.length; ++i ) {
                if( sel_pos == treeViewExModel.get( i ).v_index ) {
                    objs[i].shooted_update();
                    break;
                }
            }
        }
    }

    function device_click_by_id( pos, list_path ) {
        set_current_device( "", true );
        click_by_id( pos );
    }

    function create_tree_ex_by_save_shoot() {
        var path = qml_port.get_child_visible_change_path() + '/';
        console.log( "TreeViewEx.qml create_tree_ex_by_save_shoot path=", path )
        var path_len = path.length;
        var insert_pos = -1;
        for( var i=0; i<treeViewExModel.count; ++i ) {
            var curr_path = qml_port.get_task_tree_list_path( treeViewExModel.get( i ).v_index ) + '/';

            if( curr_path.length >= path_len && curr_path.substring( 0, path_len ) == path ) {
                console.log( "TreeViewEx.qml create_tree_ex_by_save_shoot remove curr_path=", curr_path )
                if( insert_pos == -1 ) {
                    insert_pos = i;
                }
                treeViewExModel.remove( i, 1 );
                --i;
            }
        }
        if( insert_pos == -1 ) {
            insert_pos = treeViewExModel.count;
        }

        console.log( "TreeViewEx.qml create_tree_ex_by_save_shoot insert_pos=", insert_pos,
                    " treeViewExModel.count=", treeViewExModel.count )

        var list_count = qml_port.get_task_tree_list_count();
        var sel_pos = qml_port.get_task_select_pos();
        var j = 0, pos = 0, k = 0;

        for( var i=0; i<list_count; ++i ) {
            if( qml_port.get_task_tree_node_visible( i ) ) {
                var cur_path = qml_port.get_task_tree_list_path( i ) + '/';
                var flag = false;
                if( cur_path.length >= path_len && cur_path.substring( 0, path_len ) == path ) {
                    flag = true;
                }
                ++k;
                if( k > insert_pos && flag ) {
                    console.log( "TreeViewEx.qml create_tree_ex_by_save_shoot real add cur_path=", cur_path )
                    treeViewExModel.insert( insert_pos, {"title" :qml_port.get_task_tree_list_str(i), "v_index": i, "v_capture": reset_delegate_capture(i) } );
                    ++insert_pos;
                }

                if( sel_pos == i ) {
                    pos = j;
                } else {
                    ++j;
                }
            }
            if( !qml_port.get_task_tree_node_child_visible( i ) && qml_port.get_task_tree_list_node_number( i ) > 0 ) {
                var level = qml_port.get_task_tree_list_node_level( i );

                do {
                    i = i + qml_port.get_task_tree_list_node_number( i ) + 1;
                } while( qml_port.get_task_tree_list_node_level( i ) > level );
                --i;
            }
        }

        console.log( "TreeViewEx.qml set_current_device pos=2223", pos, sign_number )
        if( pos < sign_number ) {
            tree_list_view.positionViewAtIndex( 0, ListView.Beginning )
        } else {
            //tree_list_view.positionViewAtIndex( pos - 1, ListView.Beginning )
            tree_list_view.positionViewAtIndex( pos - 1 - qml_port.get_packup_count(), ListView.Beginning )
        }
        tree_ex_id.n_sel_index = qml_port.get_task_select_pos();
    }

    /* 函数 创建树  该函数卡顿严重,尽量减少调用次数 */
    function create_tree_ex( n_start_indx, n_num ) {
        //console.log("------------------------------>>>>>>>>>>>>  " + n_start_indx + "   " + n_num)
        //移除全部
        if( n_num == 0 ) {
            if( treeViewExModel.count > n_start_indx + 1 ) {
                treeViewExModel.remove( n_start_indx + 1, treeViewExModel.count-n_start_indx-1 );
            }
        }
        //收起
        else if( n_num < 0 ) {
            n_num = 0 - n_num;
            if( treeViewExModel.count > n_start_indx + n_num ) {    //移除收起的节点
                treeViewExModel.remove( n_start_indx, n_num + 1 );
                //console.log( "remove !!!!!!!!!!!", n_start_indx );
            }
            n_start_indx = n_start_indx - 1;
            n_num = 1; //only readd the click node
        }
        //展开
        else {
            treeViewExModel.remove( n_start_indx, 1 );  //移除该部分首节点
            n_start_indx = n_start_indx - 1;
            n_num = n_num + 1;
        }

        var list_count = qml_port.get_task_tree_list_count();   //列表长度，节点的数量
        var sel_pos = qml_port.get_task_select_pos();           //当前位置
        var j = 0, pos = 0, k = 0, n_count = 0;
        console.log( "  遍历所有的节点  n_start_indx= ", n_start_indx,"sel_pos= ", sel_pos,"list_count= ", list_count );
        //遍历节点
        //该循环造成卡顿
        for( var i=0; i<list_count; ++i ) {
            //console.log("---> title:", qml_port.get_task_tree_list_str(i))
            if( qml_port.get_task_tree_node_visible( i ) ) {    //判断节点可以性（是否收起）
                ++k;
                if( k > n_start_indx + 1 ) {
                    if( n_num > 0 ) {
                        //树控件缺陷
                        treeViewExModel.insert( k - 1, {"title" :qml_port.get_task_tree_list_str(i), "v_index": i, "v_capture": reset_delegate_capture(i) } );
                        ++n_count;
                        if( n_count == n_num ) {
                            return ;
                        }
                    } else {
                        treeViewExModel.append( {"title" :qml_port.get_task_tree_list_str(i), "v_index": i, "v_capture": reset_delegate_capture(i) } );
                    }
                }

                if( sel_pos == i ) {
                    pos = j;
                } else {
                    ++j;
                }
            }
            //console.log("---> visible:", qml_port.get_task_tree_node_child_visible(i),
            //            ", level:", qml_port.get_task_tree_list_node_level(i),
            //            ", node:", qml_port.get_task_tree_list_node_number(i));
            if( !qml_port.get_task_tree_node_child_visible( i ) && qml_port.get_task_tree_list_node_number( i ) > 0 ) {
                var level = qml_port.get_task_tree_list_node_level( i );
                do {
                    i = i + qml_port.get_task_tree_list_node_number( i ) + 1;
                } while( qml_port.get_task_tree_list_node_level( i ) > level );
                --i;
            }
        }

        console.log( "TreeViewEx.qml set_current_device pos=2221", pos, sign_number )
        if( pos < sign_number ) {
            tree_list_view.positionViewAtIndex( 0, ListView.Beginning )
        } else {
            tree_list_view.positionViewAtIndex( pos - 1, ListView.Beginning )
        }

        tree_ex_id.n_sel_index = qml_port.get_task_select_pos() ;
        console.log( "TreeViewEx.qml create_tree_ex end treeViewExModel.count=", treeViewExModel.count, tree_list_view.contentY );
    }

    /* 函数 创建准备 */
    function create_ready() {
        create_tree_ex( -1, 0 );

        if( treeViewExModel.count > 0 ) {
            show_tree_view();
            bshow_list = true;
        }
    }

    function tree_clear() {
        //mp_map_series.visible = false;
        treeViewExModel.clear();
        bshow_list = false;
        //title_lab.set_img_title( false, false );
        tree_ex_id.showGridView();
    }

    function set_current_item( nodeid ) {
        //qml_port.set_task_select_pos( nodeid )
    }

    function init_focus()
    {
        tree_list_view.focus = true
    }

    Keys.enabled: true
    Keys.onReleased: {
        switch(event.key) {
        case qml_port.get_keyValue_from_up():
            console.log("#### [TreeViewEx] [Keys] : UP . . .")
            if(!hidden_menu_rect.visible) {
                tree_ex_id.list_focus_up()
            } else {
                if (delete_rect.focus)
                    pull_rect.focus = true
                else if(history_rect.focus)
                    delete_rect.focus = true
                else if (reset_rect.focus)
                    history_rect.focus = true
                else
                    reset_rect.focus = true
            }
            break;
        case qml_port.get_keyValue_from_down():
            console.log("#### [TreeViewEx] [Keys] : DOWN . . .")
            if(!hidden_menu_rect.visible) {
                if(tree_ex_id.n_sel_index >= treeViewExModel.get(treeViewExModel.count - 1).v_index) {
                    if(!return_rect.focus && !pull_rect.focus)
                        return_rect.focus = true
                    return
                }
                tree_ex_id.list_focus_down()
            } else {
                if (delete_rect.focus)
                    history_rect.focus = true
                if(history_rect.focus)
                    reset_rect.focus = true
                else if (reset_rect.focus)
                    pull_rect.focus = true
                else
                    delete_rect.focus = true
            }
            break;
        case qml_port.get_keyValue_from_left():
            console.log("#### [TreeViewEx] [Keys] : LEFT . . .")
            if(!return_rect.focus && !pull_rect.focus && !hidden_menu_rect.visible) {
                pull_rect.focus = true
            } else if (return_rect.focus) {
                pull_rect.focus = true
            } else if (pull_rect.focus) {
                return_rect.focus = true
            }
            break;
        case qml_port.get_keyValue_from_right():
            console.log("#### [TreeViewEx] [Keys] : RIGHT . . .")
            if(!return_rect.focus && !pull_rect.focus && !hidden_menu_rect.visible) {
                return_rect.focus = true
            } else if (return_rect.focus) {
                pull_rect.focus = true
            } else if (pull_rect.focus) {
                return_rect.focus = true
            }
            break;
        case qml_port.get_keyValue_from_center():
            console.log("#### [TreeViewEx] [Keys] : OK . . .")
            if(!return_rect.focus && !pull_rect.focus && !delete_rect.focus &&
               !reset_rect.focus && !history_rect.focus) {
                if(tree_ex_id.n_sel_index > 0 && tree_ex_id.n_sel_index < qml_port.get_task_tree_list_count())
                   tree_list_view.modelChange(tree_ex_id.n_sel_index - qml_port.get_packup_count(tree_ex_id.n_sel_index))
            } else if (return_rect.focus) {
                treeViewReturn();
            } else if (pull_rect.focus) {
                if(hidden_menu_rect.visible)
                    set_hidden_menu(false)
                else
                    set_hidden_menu(true)

            } else if (reset_rect.focus) {
                sig_interaction_show()
                //reset_rect.reset_capture_flag()
                set_hidden_menu(false)
            } else if (history_rect.focus) {
                set_hidden_menu(false)
                histortShow();
            } else if (delete_rect.focus) {
                set_hidden_menu(false)
                delete_rect.delete_img_batch()
            }
            break;
        }
    }

    function list_focus_up()
    {
        tree_list_view.focus = true
        if(tree_ex_id.n_sel_index <= 0)
            return
        tree_ex_id.n_sel_index = qml_port.get_pre_index(tree_ex_id.n_sel_index)
        tree_list_view.positionViewAtIndex((tree_ex_id.n_sel_index - qml_port.get_packup_count(tree_ex_id.n_sel_index)), ListView.Center)
        if(qml_port.get_task_tree_list_node_level(tree_ex_id.n_sel_index) == 4) {
            tree_list_view.modelChange(tree_ex_id.n_sel_index - qml_port.get_packup_count(tree_ex_id.n_sel_index))
        }
    }

    function list_focus_down()
    {
        tree_list_view.focus = true
        tree_ex_id.n_sel_index = qml_port.get_next_index(tree_ex_id.n_sel_index)
        tree_list_view.positionViewAtIndex((tree_ex_id.n_sel_index - qml_port.get_packup_count(tree_ex_id.n_sel_index)), ListView.Center)
        if(qml_port.get_task_tree_list_node_level(tree_ex_id.n_sel_index) == 4) {
            tree_list_view.modelChange(tree_ex_id.n_sel_index - qml_port.get_packup_count(tree_ex_id.n_sel_index))
        }
    }

    Connections {
        target: qml_port
        onSignal_cap_start : {
            //console.log("#### [TreeViewEx] [onSignal_cap_start] : running . . .>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>")
            tree_list_view.enabled = false
            return_rect.enabled = false
            hidden_menu_rect.enabled = false
        }
    }

    Connections {
        target: qml_port
        onSignal_cap_stop : {
            //console.log("#### [TreeViewEx] [onSignal_cap_stop] : running . . .>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>")
            tree_list_view.enabled = true
            return_rect.enabled = true
            tree_ex_id.focus = true
            hidden_menu_rect.enabled = true
            Keys.enabled = true
        }
    }

    Connections {
        target: qml_port
        onSignal_reset_flag : {
            reset_rect.reset_capture_flag()
        }
    }

    function focus_jump_down()
    {
        console.log("<TreeViewEx> <focus_jump_down> : RUN . . .")
        if(!hidden_menu_rect.visible) {
            if(tree_ex_id.n_sel_index >= treeViewExModel.get(treeViewExModel.count - 1).v_index) {
                console.log("<TreeViewEx> <focus_jump_down> : tree_ex_id.n_sel_index >= treeViewExModel ! ! !")
                return
            }

            tree_list_view.focus = true
            for( var i = 0; i < 4; i++) {
                tree_ex_id.n_sel_index = qml_port.get_next_index(tree_ex_id.n_sel_index)
                if (qml_port.get_task_tree_list_node_level(tree_ex_id.n_sel_index) === 4)
                    break;
                if (qml_port.get_task_tree_list_node_level(tree_ex_id.n_sel_index) < 4) {
                    if (! qml_port.get_task_tree_node_child_visible(tree_ex_id.n_sel_index))
                        tree_list_view.modelChange(tree_ex_id.n_sel_index - qml_port.get_packup_count(tree_ex_id.n_sel_index))
                }
            }

            console.log("<TreeViewEx> <focus_jump_down> : tree_ex_id.n_sel_index = " + tree_ex_id.n_sel_index)

            tree_list_view.positionViewAtIndex((tree_ex_id.n_sel_index - qml_port.get_packup_count(tree_ex_id.n_sel_index)), ListView.Center)
            if(qml_port.get_task_tree_list_node_level(tree_ex_id.n_sel_index) === 4) {
                tree_list_view.modelChange(tree_ex_id.n_sel_index - qml_port.get_packup_count(tree_ex_id.n_sel_index))
            }
        }
    }


    Connections {
        target: qml_port
        onSignal_capture_to_tree : {
            device_id = tree_ex_id.n_sel_index
            treeViewExModel.set(transition_index(tree_ex_id.device_id), { "v_capture": 1 })
            var curIndex = tree_ex_id.device_id
            var tmpIndex = tree_ex_id.device_id

            focus_jump_down()

            for(var i = 0; i < 3; i++) {
                tmpIndex = qml_port.get_father_index(curIndex)
                for(var j = transition_index(tmpIndex) + 1; j < treeViewExModel.count; j++) {
                    if(qml_port.get_task_tree_list_node_level(treeViewExModel.get(j).v_index) <=
                            qml_port.get_task_tree_list_node_level(tmpIndex))
                        break
                    if(treeViewExModel.get(j).v_capture === 0) {
                        return
                    }
                }
                curIndex = tmpIndex
                treeViewExModel.set(transition_index(tmpIndex), { "v_capture": 1 })
            }
            //create_ready()
        }
    }

    Connections {
        target: qml_port
        onSignal_doDump_by_index : {
            console.log("<TreeViewEx> <onSignal_doDump_by_index> : index = " + index + "; dump = " + b_dump + "\r\n")
            if (index > treeViewExModel.get(treeViewExModel.count - 1).v_index) {
                console.log("<TreeViewEx> <onSignal_doDump_by_index> : index > treeViewExModel " + treeViewExModel.get(treeViewExModel.count - 1).v_index + " ! ! !")
                return
            }

            tree_ex_id.n_sel_index = index;
            if ((! qml_port.get_task_tree_node_child_visible(index)) || qml_port.get_task_tree_list_node_level(index) === 4) {
                tree_list_view.modelChange(tree_ex_id.n_sel_index - qml_port.get_packup_count(tree_ex_id.n_sel_index))
            }

            if (b_dump) {
                tree_list_view.positionViewAtIndex((tree_ex_id.n_sel_index - qml_port.get_packup_count(tree_ex_id.n_sel_index)), ListView.Center)
            }
        }
    }

    function transition_index( index )
    {
        for(var i = index; i > 0; i--) {
            if(i >= treeViewExModel.count)
                continue
            if(index === treeViewExModel.get(i).v_index) {
                return i
            }
        }
    }

    /* 创建完成响应函数 */
    Component.onCompleted: {
        console.log("<TreeViewEx> <Component.onCompleted> : RUNNING . . .\r\n")
        create_ready();
    }

    function reset_delegate_capture( index ) {
        return analysis_op.exist_history_by_info(qml_port.get_deviceNodes_by_index( index ))
    }
}

