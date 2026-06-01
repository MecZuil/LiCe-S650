import QtQuick 2.1

Rectangle {
    id: tree_ex_id
    width: change_model.is_640x480_size() ? 215 : 106
    height: change_model.is_640x480_size() ? 420 : 272

    property int index : 0
    property bool bshow_list: false;
    property int n_sel_index: -1
    property int sign_number: change_model.is_640x480_size() ? 5 : 5
    property int list_size: 0
    property int i_time: 0
    visible: bshow_list
    signal showGridView();
    signal click_by_id(var pos);
    property int currect_level_number: -1;

    Rectangle{
        id: up_level_rect
        height: up_level_text.contentHeight / 30 * 34 + 8;
        width: change_model.is_640x480_size() ? 215 : 106
        visible:  true
        //        property int currect_index: qml_port.get_up_level_index( currect_level_number );
        //        property var s_unfold: qml_port.get_up_level_unflod( currect_level_number );
        Image {
            anchors.fill: parent
            source: qml_port.get_img_qml_res_path()  + "images/" + "level_bkimage.png";
        }
        Text {
            renderType : Text.NativeRendering
            width: parent.width
            id: up_level_text;
            text: qml_port.get_cur_level_name( currect_level_number );
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: change_model.is_640x480_size() ? 18 : 12
            wrapMode: Text.WrapAnywhere
            elide: Text.ElideRight
            maximumLineCount: 2
        }
        //        MouseArea {
        //            id: up_level_mouse_area
        //            anchors.fill: parent;
        //            onPressed: {
        //                create_tree_ex( 0, up_level_rect.currect_index, 0);
        //            }
        //        }
    }
    ListModel {
        id: treeViewExModel
    }

    ListView {
        id : tree_list_view
        width: change_model.is_640x480_size() ? 215 : 106
        height: change_model.is_640x480_size() ? ( 390 - up_level_rect.height - down_level_rect.height  + (up_level_rect.visible ? 0 : up_level_rect.height ) + (down_level_rect.visible ? 0 : down_level_rect.height ) ) :
                                                 ( 252 - up_level_rect.height - down_level_rect.height  + (up_level_rect.visible ? 0 : up_level_rect.height ) + (down_level_rect.visible ? 0 : down_level_rect.height ) )
        anchors.top: up_level_rect.bottom
        model: treeViewExModel
        clip: true
        onDragEnded: {
            qml_port.update_sync_sgl();

        }
        Component.onCompleted: {
            currentIndex = count - 1
            contentY = tree_list_view.count * 30
        }

        delegate: LevelTreeViewExDelegate {
            id: tree_view_ex_delegate;
            text: ( index >= 0 && index < treeViewExModel.count ) ? treeViewExModel.get( index ).title:""
            onClicked: {
                //main_repaint()
                if( typeof(treeViewExModel.get( n_indx ).v_index) == "undefined"
                        || typeof(tree_list_view) == "undefined" ) {
                    return;
                }
                console.log( "LevelTreeViewEx.qml onClicked n_indx=", treeViewExModel.get( n_indx ).v_index )
                var ret = qml_port.tree_node_clicked( treeViewExModel.get( n_indx ).v_index );
                if( ret == 0 ) {
                    tree_ex_id.n_sel_index = qml_port.get_task_select_pos();
//                    if( !qml_port.is_shoot_save_not() ) {
//                        title_lab.set_img_title( parameterManager.is_device_name_show(), false );
//                    }  else {
//                        title_lab.set_img_title( true, false );
//                    }
//                    if( b_shoot ) {
//                        qml_port.ir_get_image_name();
//                     console.log("onCapture_image----",qml_port.get_current_img_name())
                    title_show(qml_port.get_current_img_name())
//                    console.log("ononon",title_visible_state())
//                    }

//                    if( change_model.is_show_anas_and_outline() ) {
//                        if( i_switch_type !== 2 ) {
//                            img_item.set_status_type( 2 )
//                            img_item.status_change_to_user();
//                            img_item.save_handle_info()
//                            //qml_port.show_current_node_ana();
//                        }
//                    }
                } else if( ret == 1 ) {
                    create_tree_ex( n_indx, treeViewExModel.get( n_indx ).v_index, qml_port.get_click_child_num() );
                }
            }
            Connections {
                target: tree_ex_id
                ignoreUnknownSignals: true
                onClick_by_id: {
                    tree_view_ex_delegate.click_date( pos );
                }
            }
        }
    }


    Rectangle{
        id: down_level_rect
        height: down_level_text.contentHeight / 30 * 34 + 8;
        width: change_model.is_640x480_size() ? 215 : 106
        anchors.top: tree_list_view.bottom
        visible:  down_level_text.text !== ""
        property int currect_index: qml_port.get_down_level_index( currect_level_number );
        property var s_unfold: qml_port.get_down_level_unflod( currect_level_number );

        Image {
            anchors.fill: parent
            source: qml_port.get_img_qml_res_path()  + "images/" + "level_bkimage.png";
        }
        Image{
            id: down_level_image;
            width: change_model.is_640x480_size() ? 22 : 15
            height: change_model.is_640x480_size() ? 21 : 15
            source: qml_port.get_img_qml_res_path()  + "images/" + "down_level.png";
            anchors.verticalCenter: parent.verticalCenter
        }
        Text {
            renderType : Text.NativeRendering
            id: down_level_text;
            text: qml_port.get_down_level_name( currect_level_number );
            anchors.left: down_level_image.right
            anchors.leftMargin: change_model.is_640x480_size() ? 5 : 3
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: change_model.is_640x480_size() ? 18 : 12
            width: parent.width - down_level_text.x
            wrapMode: Text.WrapAnywhere
            elide: Text.ElideRight
            maximumLineCount: 2
        }

        MouseArea {
            id: down_level_mouse_area
            anchors.fill: parent;
            onPressed: {
                create_tree_ex( 0, down_level_rect.currect_index, 0);
            }
        }
    }
    Rectangle{
        id: down_function
        height: change_model.is_640x480_size() ? 30 : 20
        width: change_model.is_640x480_size() ? 215 : 106
        anchors.bottom: parent.bottom
        property int currect_index: qml_port.get_back_level_index( currect_level_number );
        property var s_unfold: qml_port.get_back_level_unflod( currect_level_number );
        Rectangle {
            id: back_rect;
            height: change_model.is_640x480_size() ? 30 : 20
            width: ( currect_level_number == 0 ) ? 0 : ( change_model.is_640x480_size() ? 80 : 53 )

            Image{
                anchors.fill: parent
                source: qml_port.get_img_qml_res_path()  + "images/" + "buttom_image.png";
            }
            Text{
                renderType : Text.NativeRendering
                text: qsTr( "back" )
                anchors.centerIn: parent;
                anchors.leftMargin: change_model.is_640x480_size() ? 5 : 3
                font.pixelSize: change_model.is_640x480_size() ? 18 : 12
            }
            MouseArea {
                id: back_mouse_area
                anchors.fill: parent;
                onPressed: {
//                    if( main_page.b_shoot ) {
//                        return;
//                    }
                    create_tree_ex( 0, down_function.currect_index, 0);
                }
            }
        }
        Rectangle {
            id: return_rect;
            height: change_model.is_640x480_size() ? 30 : 20
            width: change_model.is_640x480_size() ? ( 215 - back_rect.width ) : ( 106 - back_rect.width );
            anchors.left: back_rect.right
            Image{
                anchors.fill: parent
                height: change_model.is_640x480_size() ? 30 : 20
                width: change_model.is_640x480_size() ? ( 215 - back_rect.width ) : ( 106 - back_rect.width );
                source: qml_port.get_img_qml_res_path()  + "images/" + "buttom_image.png";
            }

            Text{
                renderType : Text.NativeRendering
                text: qsTr( "return" )
                anchors.centerIn: parent;
                font.pixelSize: change_model.is_640x480_size() ? 18 : 12
            }
            MouseArea {
                id: return_mouse_area
                anchors.fill: parent;
                onPressed: {
//                    if( main_page.b_shoot ) {
//                        return;
//                    }
                    device_return_slot()
                }
            }
        }
    }


    function set_current_device( path, bUnfold ) {

        console.log( "LevelTreeViewEx.qml set_current_device select_pos=", tree_ex_id.n_sel_index,
                    qml_port.get_task_select_pos(), currect_level_number, " bUnfold=", bUnfold )

        if( !bUnfold ) {
            create_tree_ex( 0, qml_port.get_cur_level_index( qml_port.get_task_select_pos() ), 0 );
        } else {
            if( path.toString().length > 0 ) {
                console.log( "path.toString().length >= 0" )
                if( qml_port.has_path_father( path, currect_level_number ) ) {
                    if( qml_port.is_same_voltage_level( path, currect_level_number ) ) {
                        create_tree_ex( 0, qml_port.get_cur_level_index( qml_port.get_task_select_pos() ), 0 );
                    } else {
                        create_tree_ex( -1, 0, 0 );
                    }
                }
            } else {
                console.log( "path.toString().length <= 0" )
            }
        }

        if( tree_ex_id.n_sel_index != qml_port.get_task_select_pos() ) {
            var pos = 0;
            for( var i = 0; i<treeViewExModel.count; ++i ) {
                if( treeViewExModel.get( i ).v_index == qml_port.get_task_select_pos() ){
                    pos = i;
                }
            }

            console.log( "LevelTreeViewEx.qml set_current_device pos=2222", pos, sign_number )
            if( pos < sign_number ) {
                //tree_list_view.positionViewAtIndex( 0, ListView.Beginning )
                tree_list_view.contentY = 0;
                tree_list_view.y = 0;
                tree_list_view.positionViewAtBeginning();
                console.log( "~~~~~~~~~~~~~~~~~~~~~~~LevelTreeViewEx.qml tree_list_view.atYBeginning ", tree_list_view.atYBeginning, tree_list_view.contentY, tree_list_view.height )
            } else {
                tree_list_view.positionViewAtIndex( pos - 1, ListView.Beginning )
            }

            tree_ex_id.n_sel_index = qml_port.get_task_select_pos();
        }
        title_show(qml_port.get_current_img_name())
        //title_lab.set_img_title( parameterManager.is_device_name_show(), false );
    }
    function title_show(title) {
        up_level_text.visible = true
        up_level_text.text = title
    }
    function device_save_change() {
        console.log( "LevelTreeViewEx.qml device_save_change() select_pos=", qml_port.get_task_select_pos() )
        //objModel.deviceSaveChange()
        if( qml_port.get_child_visible_change() ) {
            console.log( "LevelTreeViewEx.qml device_save_change() create_tree_ex_by_save_shoot()" )
            tree_list_view.enabled = false;
            create_tree_ex_by_save_shoot();
            tree_list_view.enabled = true;
        } else {
            var objs = tree_list_view.children;
            var sel_pos = qml_port.get_task_select_pos();

            for( var i=0; i<objs.length; ++i ) {
                if( sel_pos == treeViewExModel.get( i ).v_index ) {
                    objs[i].shooted_update();
                    console.log( "i~~~~~~~~~~~~~~", i );
                    break;
                }
            }
        }
    }
    function device_click_by_id( pos, list_path ) {
        console.log( "~~~~~~~~~~~~~~~~~~~~~~~~~~~", pos, tree_ex_id.n_sel_index, list_path );
        set_current_device( "", true );
        click_by_id( pos );
    }

    function create_tree_ex_by_save_shoot() {

        var pos = 0;
        for( var i = 0; i<treeViewExModel.count; ++i ) {
            if( treeViewExModel.get( i ).v_index  == qml_port.get_task_select_pos() ){
                pos = i;
            }
        }
        console.log( "LevelTreeViewEx.qml set_current_device pos=2223~~~~~~", pos, sign_number, tree_list_view.contentY )
        if( pos < sign_number ) {
            tree_list_view.positionViewAtIndex( 0, ListView.Beginning )
        } else {
            var index_of1 = tree_list_view.indexAt( 0, tree_list_view.contentY );
            var index_of2 = tree_list_view.indexAt( 0,  tree_list_view.height + tree_list_view.contentY );
            if( index_of2 -1 < pos ) {
                console.log( "~~~~~~~~~~~~~~~~~~~~~~~LevelTreeViewEx.qml tree_list_view.atYBeginning ", index_of1, index_of2, pos);
                tree_list_view.positionViewAtIndex( pos, ListView.Beginning )
            }
        }
        tree_ex_id.n_sel_index = qml_port.get_task_select_pos();
    }

    function create_tree_ex( n_start_indx, selct_index, n_num ) { // n_num add or delete,  selct_index device id, n_start_indx tree id

        console.log( "n_start_indx~~~~~~~~~`", n_start_indx, selct_index, n_num );
        if( n_start_indx === -1 ){
            var list_count = qml_port.get_task_tree_list_count();
            var sel_pos = qml_port.get_task_select_pos();
            treeViewExModel.clear();
            console.log("create_tree_ex list_count:",list_count, "sel_pos",sel_pos)
            for( var i = 1; i<list_count; ++i ) {
                if( qml_port.get_task_tree_list_node_level( i ) == 1 ) {
                    treeViewExModel.append( {"title" :qml_port.get_task_tree_list_str( i ), "v_index": i } );
                }
            }
            currect_level_number = 0;
        } else {
            var level = qml_port.get_task_tree_list_node_level( selct_index );
            if( level !== 3 ) {
                var list_count = qml_port.get_task_child_level( selct_index );
                treeViewExModel.clear();
                for( var i = 0; i < list_count; ++i ) {
                    treeViewExModel.append( {"title" :qml_port.get_task_tree_list_str( qml_port.get_task_child_leve_data_id( i ) ), "v_index": qml_port.get_task_child_leve_data_id( i ) } );
                    console.log( "append:", qml_port.get_task_tree_list_str( qml_port.get_task_child_leve_data_id( i ) ) );
                    if( qml_port.get_task_tree_node_child_visible( qml_port.get_task_child_leve_data_id( i ) ) === false &&
                            qml_port.get_task_tree_list_node_level( qml_port.get_task_child_leve_data_id( i ) ) == 3 ) {
                        i = i + qml_port.get_task_tree_list_node_number( qml_port.get_task_child_leve_data_id( i ) );
                    }
                }
                currect_level_number = selct_index;
                create_tree_ex_by_save_shoot();
            } else {
                if( n_num < 0 ) {
                    n_num = 0 - n_num;
                    if( treeViewExModel.count > n_start_indx + n_num ) {
                        treeViewExModel.remove( n_start_indx + 1, n_num );
                        //treeViewExModel.remove( n_start_indx, n_num  ); //delete click node
                        console.log( "remove !!!!!!!!!!!", n_start_indx, n_num );
                    }
                } else {
                    var list_count = qml_port.get_task_child_level( selct_index );

                    for( var i = 0; i < list_count; ++i ) {
                        treeViewExModel.insert( n_start_indx + i + 1, {"title" :qml_port.get_task_tree_list_str( qml_port.get_task_child_leve_data_id( i ) ), "v_index": qml_port.get_task_child_leve_data_id( i ) } );
                    }
                }
            }
        }
        console.log( "currect_level_number~~~~~~~~~~`", currect_level_number );
    }

    function create_ready() {
        create_tree_ex( -1, 0, 0 );
        console.log( "LevelTreeViewEx.qml create_ready treeViewExModel.count=", treeViewExModel.count );
        if( treeViewExModel.count > 0 ) {
            show_level_tree_view();
            bshow_list = true;
        }
        console.log("tree_ex_id.visible",bshow_list, tree_ex_id.visible)
        //img_item.set_status_type( 2 )
        //img_item.status_change_to_user();
    }

    function tree_clear() {
        //mp_map_series.visible = false;
        treeViewExModel.clear();
        bshow_list = false;
        currect_level_number = -1;
        //title_lab.set_img_title( false, false );
        tree_ex_id.showGridView();

        //if( i_switch_type !== 2) {
            //img_item.set_status_type( 2 )
            //img_item.status_change_to_user();
        //}
    }

    function set_current_item( nodeid ) {
        //qml_port.set_task_select_pos( nodeid )
    }
    function in_task_level() {
        if( qml_port.get_task_tree_list_node_level( currect_level_number ) >= 2 ) {
            return false;
        } else {
            return true;
        }
    }

    Component.onCompleted: {
        console.log( "LevelViewEx.qml Component.onCompleted" );
        create_ready();
    }
}


