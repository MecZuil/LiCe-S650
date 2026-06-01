import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.2
import QtQuick.Window 2.0


Rectangle {
    id: tree_ex_id
    width: change_model.is_640x480_size() ? 160 : 106
    height: change_model.is_640x480_size() ? 480 : 272
    x:0
    y:0
    visible: bshow_list
    focus: bshow_list
    property int index : 0
    property bool bshow_list: true
    property int n_sel_index: -1
    property int sign_number: change_model.is_640x480_size() ? 5 : 5
    property int list_size: 0
    property int i_time: 0
    signal showGridView();
    signal click_by_id(var pos);
    signal treeViewReturn();

    Image {
        x: 0
        y: 0
        width: parent.width * 4
        height: parent.height
        source: qml_port.get_img_qml_res_path() + "images/setting_background.png"
    }

    ListModel {
        id: treeViewExModel
    }

    ListView {
        id : tree_list_view
        model: treeViewExModel
        width: change_model.is_640x480_size() ? 160 : 106
        height: parent.height - down_function.height;
        anchors.top: parent.top
        clip: true
        onDragStarted: {
        }
        onDragEnded: {
            qml_port.update_sync_sgl();
        }

        Component.onCompleted: {
            //currentIndex = count - 1
            currentIndex = qml_port.get_task_select_pos();
            console.log("#### [TreeViewEx] [tree_list_view] : The tree List view is loaded successfully, currentIndex = %d", currentIndex);
        }

        delegate: TreeViewExDelegate {
            id: tree_view_ex_delegate;
            text: ( index >= 0 && index < treeViewExModel.count ) ? treeViewExModel.get( index ).title:""
            onClicked: {
                if(  typeof(treeViewExModel.get( n_indx ).v_index) == "undefined"
                        || typeof(tree_list_view) == "undefined" ) {
                    return;
                }
                tree_ex_id.n_sel_index = treeViewExModel.get( n_indx ).v_index
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
                    tree_list_view.enabled = true;
                }
                console.log( "\r\n\r\nTreeViewEx.qml onClicked n_indx=", treeViewExModel.get( n_indx ).v_index, ret, n_indx )
            }
            Connections {
                target: tree_ex_id
                ignoreUnknownSignals: true
                onClick_by_id: {
                    tree_view_ex_delegate.click_date( pos );
                }
            }
        }

        /* 该函数造成延迟 ！！！*/
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

    /* 返回按键 */
    Rectangle{
        id: down_function
        height: change_model.is_640x480_size() ? 40 : 20
        width: change_model.is_640x480_size() ? 160 : 106
        anchors.top: tree_list_view.bottom
        Rectangle {
            id: return_rect;
            height: change_model.is_640x480_size() ? 40 : 20
            width: change_model.is_640x480_size() ? 160 : 106
            Image{
                anchors.fill: parent
                source: qml_port.get_img_qml_res_path()  + "images/bottom.png";
            }

            Image{
                id: return_image;
                anchors.fill: parent
                source: qml_port.get_img_qml_res_path() + "images/bottom_return.png";
            }
            Image {
                anchors.fill: parent
                source: return_rect.focus?(qml_port.get_img_qml_res_path() + "images/levelindicate.png"):""
            }
            Text{
                renderType : Text.NativeRendering
                text: qsTr( "return" )
                anchors.left: return_image.right
                anchors.leftMargin: change_model.is_640x480_size() ? 5 : 3
                font.pixelSize: change_model.is_640x480_size() ? 18 : 12
                visible: false
            }
            MouseArea {
                id: return_mouse_area
                anchors.fill: parent;
                /*
                onPressed: {
                    //if( main_page.b_shoot ) {
                        //return;
                    //}
                    treeViewReturn();
                }*/
                onDoubleClicked: {
                    treeViewReturn();
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
            console.log( "tree cur_path~~~~~~~ ", cur_path, "path~~~~~~~~~~~~`", path );

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
                console.log( "cur_path~~~~~~~ ", cur_path, "path~~~~~~~~~~~~`", path );
                if( cur_path.length >= path_len && cur_path.substring( 0, path_len ) == path ) {
                    flag = true;
                }
                ++k;
                if( k > insert_pos && flag ) {
                    console.log( "TreeViewEx.qml create_tree_ex_by_save_shoot real add cur_path=", cur_path )
                    treeViewExModel.insert( insert_pos, {"title" :qml_port.get_task_tree_list_str(i), "v_index": i } );
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
            tree_list_view.positionViewAtIndex( pos - 1, ListView.Beginning )
        }
        tree_ex_id.n_sel_index = qml_port.get_task_select_pos();
    }

    /* 函数 创建树 */
    function create_tree_ex( n_start_indx, n_num ) {
        console.log("------------------------------>>>>>>>>>>>>  " + n_start_indx + "   " + n_num)

        if(n_num < 0) {            //收起
            qml_port.add_packup_cell(treeViewExModel.get(n_start_indx).v_index)
        } else if(n_num > 0) {     //展开
            qml_port.dec_packup_cell(treeViewExModel.get(n_start_indx).v_index)
        }


        if( n_num == 0 ) {
            if( treeViewExModel.count > n_start_indx + 1 ) {
                treeViewExModel.remove( n_start_indx + 1, treeViewExModel.count-n_start_indx-1 );
            }
        }
        else if( n_num < 0 ) {
            n_num = 0 - n_num;
            if( treeViewExModel.count > n_start_indx + n_num ) {
                //treeViewExModel.remove( n_start_indx + 1, n_num );
                treeViewExModel.remove( n_start_indx, n_num + 1 );
                console.log( "remove !!!!!!!!!!!", n_start_indx );
            }
            n_start_indx = n_start_indx - 1;
            n_num = 1; //only readd the click node
        }
        else {
            treeViewExModel.remove( n_start_indx, 1 );
            n_start_indx = n_start_indx - 1;
            n_num = n_num + 1;
        }

        var list_count = qml_port.get_task_tree_list_count();
        var sel_pos = qml_port.get_task_select_pos();
        var j = 0, pos = 0, k = 0, n_count = 0;
        console.log( "  遍历所有的节点  n_start_indx= ", n_start_indx,"sel_pos= ", sel_pos,"n_num= ", n_num );

        for( var i=0; i<list_count; ++i ) {
            if( qml_port.get_task_tree_node_visible( i ) ) {
                ++k;
                if( k > n_start_indx + 1 ) {
                    if( n_num > 0 ) {
                        treeViewExModel.insert( k - 1, {"title" :qml_port.get_task_tree_list_str(i), "v_index": i } );
                        ++n_count;
                        if( n_count == n_num ) {
                            return ;
                        }
                    } else {
                        treeViewExModel.append( {"title" :qml_port.get_task_tree_list_str(i), "v_index": i } );
                    }
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
        case 0x1000037:
            console.log("#### [TreeViewEx] [Keys] : UP . . .");
            if(!tree_list_view.focus && !return_rect.focus) {
                return_rect.focus = true
            } else if(return_rect.focus) {
                tree_list_view.focus = true
                tree_list_view.positionViewAtIndex((tree_ex_id.n_sel_index - qml_port.get_packup_count(tree_ex_id.n_sel_index)), ListView.Center)
            } else if(tree_list_view.focus) {
                if(tree_ex_id.n_sel_index <= 0)
                    return
                tree_ex_id.n_sel_index = qml_port.get_pre_index(tree_ex_id.n_sel_index)
                tree_list_view.positionViewAtIndex((tree_ex_id.n_sel_index - qml_port.get_packup_count(tree_ex_id.n_sel_index)), ListView.Center)
                console.log("....................  " + tree_ex_id.n_sel_index + "    " + qml_port.get_packup_count(tree_ex_id.n_sel_index))
                if(qml_port.get_task_tree_list_node_level(tree_ex_id.n_sel_index) == 4) {
                    tree_list_view.modelChange(tree_ex_id.n_sel_index - qml_port.get_packup_count(tree_ex_id.n_sel_index))
                }
            }
            break;
        case 0x1000038:
            console.log("#### [TreeViewEx] [Keys] : DOWN . . .");
            if(!tree_list_view.focus && !return_rect.focus) {
                tree_list_view.positionViewAtIndex((tree_ex_id.n_sel_index - qml_port.get_packup_count(tree_ex_id.n_sel_index)), ListView.Center)
                tree_list_view.focus = true
            } else if(tree_list_view.focus) {
                if((tree_ex_id.n_sel_index - qml_port.get_packup_count(tree_ex_id.n_sel_index)) >= (treeViewExModel.count - 1)) {
                    return_rect.focus = true
                    return
                }
                tree_ex_id.n_sel_index = qml_port.get_next_index(tree_ex_id.n_sel_index)
                tree_list_view.positionViewAtIndex((tree_ex_id.n_sel_index - qml_port.get_packup_count(tree_ex_id.n_sel_index)), ListView.Center)
                console.log("....................  " + tree_ex_id.n_sel_index + "  " + qml_port.get_packup_count(tree_ex_id.n_sel_index))
                if(qml_port.get_task_tree_list_node_level(tree_ex_id.n_sel_index) == 4) {
                    tree_list_view.modelChange(tree_ex_id.n_sel_index - qml_port.get_packup_count(tree_ex_id.n_sel_index))
                }
            }
            break;
        case 0x1000004:
            console.log("#### [TreeViewEx] [Keys] : OK . . .");
            if(return_rect.focus) {
                treeViewReturn();
            } else if(tree_list_view.focus) {
                if(tree_ex_id.n_sel_index > 0 && tree_ex_id.n_sel_index < treeViewExModel.count)
                   tree_list_view.modelChange(tree_ex_id.n_sel_index - qml_port.get_packup_count(tree_ex_id.n_sel_index))
            }
            break;
        }
    }

    /* 创建完成响应函数 */
    Component.onCompleted: {
        create_ready();
    }
}

