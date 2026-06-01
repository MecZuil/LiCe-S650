import QtQuick 2.1

Rectangle {
    id: tree_ex_base;
    width: change_model.is_640x480_size() ? 160 : 106
    height: change_model.is_640x480_size() ? 420 : 272
    visible: true

    TreeViewEx {
            id: task_tree
            x: 0
            width: change_model.is_640x480_size() ? 160 : 106
            height: change_model.is_640x480_size() ? 420 : 272
            visible: false
        }

        LevelTreeViewEx {
            id: level_task_tree
            x: 0
            width: change_model.is_640x480_size() ? 160 : 106
            height: change_model.is_640x480_size() ? 420 : 272
            visible: false
        }

        function show_tree_view() {
            //btn_area.visible = false;
            level_task_tree.visible = false;
            task_tree.visible = true;
        }
        function show_level_tree_view() {
            //btn_area.visible = false;
            task_tree.visible = false;
            level_task_tree.visible = true;
        }

}
