import QtQuick 2.0


Rectangle {
    id: treeViewExDelegate
    width: change_model.is_640x480_size() ? 160 : 106
    property alias text: tree_item_text.text
    //property bool b_shooted: ( index >= 0 && index < treeViewExModel.count )? qml_port.get_task_tree_list_node_shoot( treeViewExModel.get(index).v_index ) : false
    color: tree_item_bg_color()
    property int tree_index: v_index
    signal clicked( int n_indx )
    height: tree_select_image_height( index )

    Image {
        id: tree_level_head
        anchors.left: parent.left
        anchors.top: parent.top
        source: get_image_pre_str() + "linemid"+ ".png"
        visible: (get_this_level() > 3 ) ? true : false
    }

    Image {
        id: tree_item_image
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        source: tree_item_img_source()
    }

    Image {
        id: tree_unfold_image
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        source: get_image_pre_str() + "indicate.png";
        visible: qml_port.get_task_select_info( tree_index, n_sel_index );
        onVisibleChanged: {
            var n_row_height = tree_select_image_height();
            tree_select_image.height = n_row_height;
            treeViewExDelegate.height = n_row_height;
        }
    }

    Image {
        id: tree_level_last
        anchors.left: parent.left
        anchors.top: tree_item_image.bottom
        source: get_image_pre_str() + "linemid"+ ".png"
        visible: tree_level_last_img_visible()
    }

    Image {
        id: tree_select_image
        anchors.left: tree_item_image.right
        anchors.leftMargin: 2
        source: ( index >= 0 && index < treeViewExModel.count && n_sel_index == treeViewExModel.get(index).v_index ) ?
                    qml_port.get_img_qml_res_path()  + "images/row_select.png" : ""; //qml_port.get_task_select_pos()
        height: parent.height
        Text {
            renderType: Text.NativeRendering
            id: tree_item_text
            anchors.left: parent.left
            width: parent.width
            wrapMode: Text.Wrap
            verticalAlignment: Text.AlignVCenter
            text: modelData
            color: tree_item_text_color()
            horizontalAlignment: get_this_level() == 0 ? Text.AlignHCenter : Text.AlignLeft

            font.pixelSize: change_model.is_640x480_size() ? 18 : 12
            anchors.verticalCenter: parent.verticalCenter
        }
        MouseArea {
            id: objMouseArea
            anchors.fill: parent

            onClicked: {
                treeViewExDelegate.clicked( index );
                console.log( "TreeViewExDelegate.qml onClicked end" )
            }
        }
    }

    Image {
        id: tree_line_image
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        source: get_image_pre_str() + "verline.png";
        visible: tree_line_img_visible()
    }

    function get_this_level() {
        if( index >= 0 && index < treeViewExModel.count ) {
            return qml_port.get_task_tree_list_node_level( treeViewExModel.get(index).v_index );
        } else {
            return 0;
        }
    }

    function tree_select_image_height( date ) {

        if( typeof(tree_item_text.contentHeight ) == "undefined" ) {
            console.log( "TreeViewExDelegate.qml tree_select_image_height index=", index );
        }
        var b_visible = tree_unfold_image_visible();
        tree_select_image.anchors.right = b_visible ? tree_unfold_image.left:treeViewExDelegate.right;

        var n_line;
        if( change_model.is_640x480_size() ) {
            n_line = tree_item_text.contentHeight / 30;
            return (n_line * 34 ) + 8;
        } else {
            n_line = tree_item_text.contentHeight / 21;
            return (n_line * 28 );
        }
    }

    function tree_item_text_color() {
        if( index < 0 || index >= treeViewExModel.count ) {
            return "black";
        }

        if( n_sel_index == treeViewExModel.get(index).v_index ) { //qml_port.get_task_select_pos()
            return "white";
        } else if( qml_port.get_task_tree_list_node_shoot( treeViewExModel.get(index).v_index ) ) {
            return "green";
        } else {
            return "black";
        }
    }

    function tree_level_last_img_visible() {
        var level = get_this_level();

        if( level < 3 ) {
            return false;
        } else if( level == 3 && ( index >= 0 && index < treeViewExModel.count &&
                                  !qml_port.get_task_select_info( treeViewExModel.get(index).v_index ) ) ) {
            return false;
        } else {
            return true;
        }
    }

    function tree_unfold_image_visible() {
        var b_ret = false;
        if( get_this_level() > 0 && get_this_level() < 4 && index >= 0 && index < treeViewExModel.count ) {
            b_ret = qml_port.get_task_select_info( treeViewExModel.get(index).v_index );
        }

        return b_ret;
    }

    function tree_line_img_visible() {
        if( get_this_level() <= 3  ) {
            return true;
        } else {
            return false;
        }
    }

    function tree_item_bg_color() {
        var level = get_this_level();
        if( 0 == level ) {
            treeViewExDelegate.color = "#084D92";
        } else if( 1 == level ) {
            treeViewExDelegate.color = "#0B66C3";
        } else if( 2 == level ) {
            treeViewExDelegate.color = "#488DD2";
        } else if( 3 == level ) {
            treeViewExDelegate.color = "#86B2E1";
        } else if( 4 == level ) {
            treeViewExDelegate.color = "#C2D8F0";
        }
    }

    function is_last_level() {
        return ( get_this_level() == 4 );
    }

    function tree_item_img_source() {
        var level = get_this_level();
        if( 0 == level || index < 0 || index >= treeViewExModel.count ) {
            return "";
        }

        var s_unfold = qml_port.get_child_has_shoot( treeViewExModel.get(index).v_index ) ? "":"unfold";
        //        if( level == 1 || level == 2 ) {
        //            s_unfold = "";
        //        }
        var tree_item_img_fn = level + ( is_last_level() ? "":s_unfold ) + ( level > 2 ?  "mid" : "" );
        return get_image_pre_str() + tree_item_img_fn + ".png";
    }

    function get_image_pre_str() {
        return qml_port.get_img_qml_res_path()  + "images/level";
    }

    function shooted_update() {
        tree_item_text.color = tree_item_text_color();
    }

    function click_date( pos ) {
        //main_repaint()
        if(  typeof(treeViewExModel.get( index ) ) == "undefined"
                || typeof(tree_list_view) == "undefined" ) {
            return;
        }
        if( pos == treeViewExModel.get(index).v_index ) {
            treeViewExDelegate.clicked( index );
        }
    }


    Component.onCompleted: {
        var n_row_height = tree_select_image_height();
        tree_select_image.height = n_row_height;
        treeViewExDelegate.height = n_row_height;
        //main_repaint()
    }
    Component.onDestruction: {
        //main_repaint()
    }
}

