import QtQuick 2.0

Rectangle {
    id: treeViewExDelegate

    property int screen_width: qml_port.get_screen_width()
    property int screen_height: qml_port.get_screen_height()

    width:qml_port.get_screen_listWidth()
    property alias text: tree_item_text.text
    //property bool b_shooted: ( index >= 0 && index < treeViewExModel.count )? qml_port.get_task_tree_list_node_shoot( treeViewExModel.get(index).v_index ) : false
    color: tree_item_bg_color()
    signal clicked( int n_indx )

    MouseArea {
        id: objMouseArea
        anchors.fill: parent

        onClicked: {
            treeViewExDelegate.clicked( index );
            console.log( "TreeViewExDelegate.qml onClicked end" )
        }
    }

    Image {
        id: tree_level_back
        anchors.fill: parent
        source: tree_item_bg_img()
    }

    Image {
        id: tree_level_head
        anchors.left: parent.left
        anchors.top: parent.top
        //height: ( 32 - get_item_image_height(model.level + ( model.isLastLevel ?( objMouseArea.isSaved ? "" : "" ):objRecursiveColumn.s_state ) + ( model.level > 2 ?  model.last_or_mid: "" ) ) ) / 2
        source: get_image_pre_str() + "linemid"+ ".png"
        //visible: (get_this_level() > 2 ) ? true : false
        visible: false
    }

    Image {
        id: tree_item_image
        anchors.fill: parent
        //anchors.left: parent.left
        //anchors.verticalCenter: parent.verticalCenter
        height: get_img_height()
        //y: ( 32 - get_item_image_height() ) / 2
        source: tree_item_img_source()
        //asynchronous : true

        function get_img_height()
        {
            var level = get_this_level();
            if(level == 4) {
                return parent.height;
            } else {
                return 50
            }
        }
    }

    Image {
        id: tree_unfold_image
        anchors.fill: parent
        //anchors.right: parent.right
        //anchors.verticalCenter: parent.verticalCenter
        //source: get_image_pre_str() + "indicate.png"; //qml_port.get_img_qml_res_path()  + "images/level";
        visible: false
    }

    Image {
        id: tree_level_last
        anchors.left: parent.left
        anchors.top: tree_item_image.bottom
        //y: ( 32 - get_item_image_height() ) / 2 + get_item_image_height(  )
        //height: item_text.height - ( 32 - get_item_image_width( model.level + ( model.isLastLevel ?( objMouseArea.isSaved ? "" : "" ):objRecursiveColumn.s_state ) + ( model.level > 2 ?  model.last_or_mid: "" ) ) ) / 2 - get_item_image_height( model.level + ( model.isLastLevel ?( objMouseArea.isSaved ? "" : "" ):objRecursiveColumn.s_state ) + ( model.level > 2 ?  model.last_or_mid: "" ) )
        source: get_image_pre_str() + "linemid"+ ".png"
        //visible: tree_level_last_img_visible()
        visible: false
        //asynchronous : true
    }

    Image {
        id: tree_select_image
        anchors.left: parent.left
        anchors.leftMargin: get_text_margin()
        source: ( index >= 0 && index < treeViewExModel.count && n_sel_index == treeViewExModel.get(index).v_index )? qml_port.get_img_qml_res_path()  + "images/row_select.png" : ""; //qml_port.get_task_select_pos()
        width: parent.width

        Text {
            renderType : Text.NativeRendering
            id: tree_item_text
            anchors.left: parent.left
            width: get_text_width()
            wrapMode: Text.WordWrap
            //width: unfold_image.visible ? objRow.width - get_item_image_width( model.level + ( model.isLastLevel ?( objMouseArea.isSaved ? "" : "" ):objRecursiveColumn.s_state ) + ( model.level > 2 ?  model.last_or_mid: "" ) ) - 2 - unfold_image.width : objRow.width - get_item_image_width( model.level + ( model.isLastLevel ?( objMouseArea.isSaved ? "" : "" ):objRecursiveColumn.s_state ) + ( model.level > 2 ?  model.last_or_mid: "" ) ) - 2
            verticalAlignment: Text.AlignVCenter
            text: modelData
            //font.bold: set_text_bold()
            color: tree_item_text_color()
            horizontalAlignment: get_this_level() == 0 ? Text.AlignHCenter : Text.AlignLeft
            font.pixelSize: get_text_size()

            function set_text_bold()
            {
                if(analysis_op.exist_history_by_info(qml_port.get_deviceNodes_by_index( treeViewExModel.get(index).v_index )))
                    return true
                else
                    return false
            }

            function get_text_width()
            {
                var level = get_this_level();
                if (level == 1) {
                    return treeViewExDelegate.width - treeViewExDelegate.width / 6.5;
                } else if (level == 2) {
                    return treeViewExDelegate.width - treeViewExDelegate.width / 5;
                } else if (level == 3) {
                    return treeViewExDelegate.width - treeViewExDelegate.width / 3.6;
                } else if (level == 4) {
                    return treeViewExDelegate.width - treeViewExDelegate.width / 10;
                }
            }

            function get_text_size()
            {
                var level = get_this_level();
                if (level == 4)
                    return treeViewExDelegate.width / 10
                else
                    return treeViewExDelegate.width / 8
            }
        }

        function get_text_margin()
        {
            var level = get_this_level();
            if (level == 1) {
                return treeViewExDelegate.width / 6.5;
            } else if (level == 2) {
                return treeViewExDelegate.width / 5;
            } else if (level == 3) {
                return treeViewExDelegate.width / 3.6;
            } else if (level == 4) {
                return treeViewExDelegate.width / 10;
            }
        }
    }

    Image {
        id: tree_line_image
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        //source: get_image_pre_str() + "verline.png"; //qml_port.get_img_qml_res_path()  + "images/level";
        visible: tree_line_img_visible()
    }

    function get_this_level() {
        if( index >= 0 && index < treeViewExModel.count ) {
            return qml_port.get_task_tree_list_node_level( treeViewExModel.get(index).v_index );
        } else {
            return 0;
        }
    }

    function tree_select_image_height() {
        if( typeof(tree_item_text.contentHeight ) == "undefined" ) {
            console.log( "TreeViewExDelegate.qml tree_select_image_height index=", index );
        }
        var b_visible = tree_unfold_image_visible();
        tree_unfold_image.visible = b_visible;
        tree_select_image.anchors.right = b_visible ? tree_unfold_image.left:treeViewExDelegate.right;
        var n_line
        if( change_model.is_640x480_size() ) {
            n_line = tree_item_text.contentHeight / 30;
            return (n_line * 34 );
        } else {
            n_line = tree_item_text.contentHeight / 21;
            return (n_line * 25 );
        }
    }

    function tree_item_text_color() {
        if( index < 0 || index >= treeViewExModel.count ) {
            return "black";
        }
        if( n_sel_index == treeViewExModel.get(index).v_index ) { //qml_port.get_task_select_pos()
            //return "white"
            return "#FFFFFF";
        } else if (qml_port.get_task_tree_list_node_shoot(treeViewExModel.get(index).v_index)) {
            return "green";
        } else if ((v_capture == 1) && index !== 0) {
            //return "#777777"
            return "#444444"
        } else if ((v_capture == 2) && index !== 0) {
            return "#CC3333"
        } else {
            return "#7CA6C9";
        }
    }

    function tree_level_last_img_visible() {
        var level = get_this_level();

        if( level < 2 ) {
            return false;
        } else if( level == 2 && ( index >= 0 && index < treeViewExModel.count && !qml_port.get_task_tree_node_child_visible( treeViewExModel.get(index).v_index ) ) ) {
            return false;
        } else {
            return true;
        }
    }

    function tree_unfold_image_visible() {
        var b_ret = false;
        if( get_this_level() > 0 && get_this_level() < 4 && index >= 0 && index < treeViewExModel.count ) {
            b_ret = qml_port.get_task_tree_node_child_visible( treeViewExModel.get(index).v_index );
            //console.log( "TreeViewExDelegate.qml level=", get_this_level(), " b_ret=", b_ret );
        }

        return b_ret;
    }

    function tree_line_img_visible() {
        if( get_this_level() == 1 ) {
            return true;
        } else {
            return false;
        }
    }

    function tree_item_bg_color() {
        var level = get_this_level();
        if( 0 == level ) {
            //treeViewExDelegate.color = "#FF0000";//"#084D92";
            treeViewExDelegate.color = "transparent"
            console.log( "Text==================================================================",tree_item_text.text);
        } else if( 1 == level ) {
            //treeViewExDelegate.color = "#0B66C3";
            treeViewExDelegate.color = "transparent"
        } else if( 2 == level ) {
            //treeViewExDelegate.color = "#488DD2";
            treeViewExDelegate.color = "transparent"
        } else if( 3 == level ) {
            //treeViewExDelegate.color = "#86B2E1";
            treeViewExDelegate.color = "transparent"
        } else if( 4 == level ) {
            //treeViewExDelegate.color = "#C2D8F0";
            treeViewExDelegate.color = "transparent"
        }
    }

    function tree_item_bg_img() {
        var level = get_this_level();
        if(0 == level) {
            return qml_port.get_img_qml_res_path() + "images/top.png"
        } else if (1 == level) {
            return qml_port.get_img_qml_res_path() + "images/level_bottom.png"
        } else if (2 == level) {
            return qml_port.get_img_qml_res_path() + "images/level_bottom.png"
        } else if (3 == level) {
            return qml_port.get_img_qml_res_path() + "images/level_bottom.png"
        } else if (4 == level) {
            return qml_port.get_img_qml_res_path() + "images/blank.png"
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
        var s_unfold = qml_port.get_task_tree_node_child_visible( treeViewExModel.get(index).v_index )?"unfold":"";
        //var tree_item_img_fn = level + ( is_last_level() ? "":s_unfold ) + ( level > 2 ?  "last" : "" );
        var tree_item_img_fn = level + ( is_last_level() ? "":s_unfold )
        if(level == 4) {
            if(qml_port.is_head_pos(text))
                tree_item_img_fn += "head";
            if(qml_port.is_tail_pos(text))
                tree_item_img_fn += "last";
        }
        return get_image_pre_str() + tree_item_img_fn + ".png";
    }

    function get_image_pre_str() {
        return qml_port.get_img_qml_res_path()  + "images/level";
    }

    function shooted_update() {
        //treeViewExDelegate.b_shooted = ( index >= 0 && index < treeViewExModel.count )? qml_port.get_task_tree_list_node_shoot( treeViewExModel.get(index).v_index ) : false
        tree_item_text.color = tree_item_text_color();
    }

    function click_date( pos ) {
        main_repaint()
        if(  typeof(treeViewExModel.get( index ) ) == "undefined"
                || typeof(tree_list_view) == "undefined" ) {
            return;
        }
        if( pos == treeViewExModel.get(index).v_index ) {
            treeViewExDelegate.clicked( index );
        }
    }

    function get_tree_width()
    {
        if (tree_ex_id.screen_width === 480)
               return 96;
        else if (tree_ex_id.screen_width === 800)
               return 160;
        else if (tree_ex_id.screen_width === 853)
                return 215;

        return 0;
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

