import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2

Item {
    property Component styleBtnDefault: comBtnDefault;

    property Component styleCheckBox: comCheckBox;

    //设置
    property Component styleSetting: comSetting;
    property bool b_setting_pressed: false
    property Component styleFuse: comFuse;
    property bool b_fuse_pressed: false;
    property Component styleVi: comVi;
    property bool b_vi_pressed: false;
    //property Component styleUv: comUv;
    //property bool b_uv_pressed: false;
    property Component styleTask: comTask;
    property bool b_task_pressed: false;
    property Component styleColorPanel: comColorPanel;
    property bool b_color_panel_pressed: false;
    property Component styleOpacity: comOpacity;
    property bool b_opacity_pressed: false;
    property Component styleRect: comRect;
    property bool b_rect_pressed: false;
    property Component styleStatus: comStatus;
    property bool b_status_pressed: false;
    property Component styleVideo: comVideo;
    property bool b_video_pressed: false;
    property Component styleFile: comFile;
    property bool b_file_pressed: false
    property Component styleLaser: comLaser;
    property bool b_laser_pressed: false;
    property Component styleAlarm: comAlarm;
    property bool b_alarm_pressed: false;
    property Component styleDenoise: comDenoise;
    property bool b_denoise_pressed: false;
    property Component styleDeleteAnaItem: comDeleteAnaItem;

    //文件
    property Component stylePrePage: comPrePage;
    property Component styleReturn: comReturn;
    property Component styleNextPage: comNextPage;
    property Component styleImportNewTask: comImportNewTask;
    property Component styleTaskSelect: comTaskSelect;
    property Component styleImportTask: comImportTask;
    property Component styleBtnLoad: comBtnLoad;

    //预览
    property Component stylePreView: comPreView;
    property Component styleDelete: comDelete;

    //左右
    property Component styleLeft: comLeft;
    property Component styleRight: comRight;

    //设置
    property Component styleParamSet: comParamSet;
    property bool b_param_set: false;
    property Component styleAlarmSet: comAlarmSet;
    property bool b_alarm_set: false;
    property Component styleSystemSet: comSystemSet;
    property bool b_system_set: false;

    Component {
        id: comBtnDefault;
        ButtonStyle {
            background: Rectangle {
                border.width: control.activeFocus ? 2 : 1;
                border.color: "#888";
                radius: 4;

                color: control.pressed ? "#6B6B6B" :
                                         ( control.hovered ?  "#C6C6C6" :
                                                             ( control.enabled ? "#D0D0D0" : "#555555" ) );
            }
        }
    }

    Component {
        id: comCheckBox;
        CheckBoxStyle {
            indicator: Rectangle {
                    implicitWidth: 35
                    implicitHeight: 35
                    radius: 8
                    border.color: control.activeFocus ? "darkblue" : "gray"
                    //border.width: 1
                    Image {
                        anchors.fill: parent;
                        source: qml_port.get_img_qml_res_path()  +"images/checkbox_normal.png";
                        fillMode: Image.PreserveAspectCrop;
                    }

                    Image {
                        anchors.fill: parent;
                        visible: control.checked;
                        source: qml_port.get_img_qml_res_path()  +"images/checkbox_press.png";
                        fillMode: Image.PreserveAspectCrop;
                    }
            }
        }
    }

    Component {
        id: comSetting

        ButtonStyle {
            background: ItemBtnStyleBackground {
                pressed: b_setting_pressed
                ms_image_btn_hover: "images/setting_normal.png";
                ms_image_btn_press: "images/setting_press.png";
                ms_image_btn_release: "images/setting_normal.png";
                ms_image_btn_disable: "images/setting_disabled.png";
            }
        }
    }

    Component {   //融合
        id: comFuse
        ButtonStyle {
            id: btn_style_fuse
            background: ItemBtnStyleBackground {
                pressed: b_fuse_pressed
                ms_image_btn_hover: "images/fuse_normal.png";
                ms_image_btn_press: "images/fuse_press.png";
                ms_image_btn_release: "images/fuse_normal.png";
                ms_image_btn_disable: "images/fuse_disabled.png";
            }
        }
    }

    Component {
        id: comVi

        ButtonStyle {
            background: ItemBtnStyleBackground {
                pressed: b_vi_pressed
                ms_image_btn_hover: "images/vi_normal.png";
                ms_image_btn_press: "images/vi_press.png";
                ms_image_btn_release: "images/vi_normal.png";
                ms_image_btn_disable: "images/vi_disabled.png";
            }
        }
    }

//    Component {
//        id: comUv

//        ButtonStyle {
//            background: ItemBtnStyleBackground {
//                pressed: b_uv_pressed
//                ms_image_btn_hover: "images/uv_normal.png";
//                ms_image_btn_press: "images/uv_press.png";
//                ms_image_btn_release: "images/uv_normal.png";
//                ms_image_btn_disable: "images/uv_disabled.png";
//            }
//        }
//    }

    Component {
        id: comTask

        ButtonStyle {
            background: ItemBtnStyleBackground {
                pressed: b_task_pressed
                ms_image_btn_hover: "images/task_normal.png";
                ms_image_btn_press: "images/task_press.png";
                ms_image_btn_release: "images/task_normal.png";
                ms_image_btn_disable: "images/task_disabled.png";
            }
        }
    }

    Component {
        id: comColorPanel

        ButtonStyle {
            background: ItemBtnStyleBackground {
                pressed: b_color_panel_pressed
                ms_image_btn_hover: "images/panel_normal.png";
                ms_image_btn_press: "images/panel_press.png";
                ms_image_btn_release: "images/panel_normal.png";
                ms_image_btn_disable: "images/panel_disabled.png";
            }
        }
    }

    Component {
        id: comOpacity

        ButtonStyle {
            background: ItemBtnStyleBackground {
                pressed: b_opacity_pressed
                ms_image_btn_hover: "images/opacity_normal.png";
                ms_image_btn_press: "images/opacity_press.png";
                ms_image_btn_release: "images/opacity_normal.png";
                ms_image_btn_disable: "images/opacity_disabled.png";
            }
        }
    }

    Component {
        id: comRect

        ButtonStyle {
            background: ItemBtnStyleBackground {
                pressed: b_rect_pressed
                ms_image_btn_hover: "images/rect_normal.png";
                ms_image_btn_press: "images/rect_press.png";
                ms_image_btn_release: "images/rect_normal.png";
                ms_image_btn_disable: "images/rect_disabled.png";
            }
        }
    }

    Component {
        id: comStatus

        ButtonStyle {
            background: ItemBtnStyleBackground {
                pressed: b_status_pressed
                ms_image_btn_hover: "images/status_normal.png";
                ms_image_btn_press: "images/status_press.png";
                ms_image_btn_release: "images/status_normal.png";
                ms_image_btn_disable: "images/status_disabled.png";
            }
        }
    }

    Component {
        id: comVideo

        ButtonStyle {
            background: ItemBtnStyleBackground {
                pressed: b_video_pressed
                ms_image_btn_hover: "images/video_normal.png";
                ms_image_btn_press: "images/video_press.png";
                ms_image_btn_release: "images/video_normal.png";
                ms_image_btn_disable: "images/video_disabled.png";
            }
        }
    }

    Component {
        id: comFile

        ButtonStyle {
            background: ItemBtnStyleBackground {
                pressed: b_file_pressed
                ms_image_btn_hover: "images/file_normal.png";
                ms_image_btn_press: "images/file_press.png";
                ms_image_btn_release: "images/file_normal.png";
                ms_image_btn_disable: "images/file_disabled.png";
            }
        }
    }

    Component {
        id: comLaser

        ButtonStyle {
            background: ItemBtnStyleBackground {
                pressed: b_laser_pressed
                ms_image_btn_hover: "images/laser_normal.png";
                ms_image_btn_press: "images/laser_press.png";
                ms_image_btn_release: "images/laser_normal.png";
                ms_image_btn_disable: "images/laser_disabled.png";
            }
        }
    }

    Component {
        id: comAlarm

        ButtonStyle {
            background: ItemBtnStyleBackground {
                pressed: b_alarm_pressed
                ms_image_btn_hover: "images/alarm_normal.png";
                ms_image_btn_press: "images/alarm_press.png";
                ms_image_btn_release: "images/alarm_normal.png";
                ms_image_btn_disable: "images/alarm_disabled.png";
            }
        }
    }

    Component {
        id: comDeleteAnaItem

        ButtonStyle {
            background: ItemBtnStyleBackground {
                ms_image_btn_hover: "images/delete_ana_normal.png";
                ms_image_btn_press: "images/delete_ana_press.png";
                ms_image_btn_release: "images/delete_ana_normal.png";
                ms_image_btn_disable: "images/delete_ana_press.png";
            }
        }
    }

    Component {
        id: comPrePage

        ButtonStyle {
            background: ItemBtnStyleBackground {
                ms_image_btn_hover: qml_port.get_img_qml_res_path()  +"images/pre_page_n.png";
                ms_image_btn_press: qml_port.get_img_qml_res_path()  +"images/pre_page_s.png";
                ms_image_btn_release: qml_port.get_img_qml_res_path()  +"images/pre_page_n.png";
                ms_image_btn_disable: qml_port.get_img_qml_res_path()  +"images/pre_page_d.png";
            }
        }
    }

    Component {
        id: comReturn

        ButtonStyle {
            background: ItemBtnStyleBackground {
                ms_image_btn_hover: qml_port.get_img_qml_res_path()  +"images/back_n.png";
                ms_image_btn_press: qml_port.get_img_qml_res_path()  +"images/back_s.png";
                ms_image_btn_release: qml_port.get_img_qml_res_path()  +"images/back_n.png";
                ms_image_btn_disable: qml_port.get_img_qml_res_path()  +"images/back_d.png";
            }
        }
    }

    Component {
        id: comNextPage

        ButtonStyle {
            background: ItemBtnStyleBackground {
                ms_image_btn_hover: qml_port.get_img_qml_res_path()  +"images/next_page_n.png";
                ms_image_btn_press: qml_port.get_img_qml_res_path()  +"images/next_page_s.png";
                ms_image_btn_release: qml_port.get_img_qml_res_path()  +"images/next_page_n.png";
                ms_image_btn_disable: qml_port.get_img_qml_res_path()  +"images/next_page_d.png";
            }
        }
    }

    Component {
        id: comImportNewTask

        ButtonStyle {
            background: ItemBtnStyleBackground {
                ms_image_btn_hover: qml_port.get_img_qml_res_path()  +"images/download_n.png";
                ms_image_btn_press: qml_port.get_img_qml_res_path()  + "images/download_s.png";
                ms_image_btn_release: qml_port.get_img_qml_res_path()  +"images/download_n.png";
                ms_image_btn_disable: qml_port.get_img_qml_res_path()  +"images/download_d.png";
            }
        }
    }

    Component {
        id: comTaskSelect

        ButtonStyle {
            background: ItemBtnStyleBackground {
                ms_image_btn_hover: qml_port.get_img_qml_res_path()  +"images/task_choose.png";
                ms_image_btn_press: qml_port.get_img_qml_res_path()  +"images/task_choose1.png";
                ms_image_btn_release: qml_port.get_img_qml_res_path()  +"images/task_choose.png";
                ms_image_btn_disable: qml_port.get_img_qml_res_path()  +"images/task_choose2.png";
            }
        }
    }

    Component {
        id: comImportTask

        ButtonStyle {
            background: ItemBtnStyleBackground {
                ms_image_btn_hover: qml_port.get_img_qml_res_path()  +"images/import.png";
                ms_image_btn_press: qml_port.get_img_qml_res_path()  +"images/import_press.png";
                ms_image_btn_release: qml_port.get_img_qml_res_path() +"images/import.png";
                ms_image_btn_disable: qml_port.get_img_qml_res_path() +"images/import_disable.png";
            }
        }
    }

    Component {
        id: comBtnLoad

        ButtonStyle {
            background: ItemBtnStyleBackground {
                ms_image_btn_hover: qml_port.get_img_qml_res_path()  +"images/load_n.png";
                ms_image_btn_press: qml_port.get_img_qml_res_path()  +"images/load_s.png";
                ms_image_btn_release: qml_port.get_img_qml_res_path()  +"images/load_n.png";
                ms_image_btn_disable: qml_port.get_img_qml_res_path()  +"images/load_d.png";
            }
        }
    }

    Component {
        id: comPreView

        ButtonStyle {
            background: ItemBtnStyleBackground {
                ms_image_btn_hover: "images/preview_normal.png";
                ms_image_btn_press: "images/preview_press.png";
                ms_image_btn_release: "images/preview_normal.png";
                ms_image_btn_disable: "images/preview_disabled.png";
            }
        }
    }

    Component {
        id: comDelete

        ButtonStyle {
            background: ItemBtnStyleBackground {
                ms_image_btn_hover: qml_port.get_img_qml_res_path() +"images/task_delete.png";
                ms_image_btn_press: qml_port.get_img_qml_res_path() +"images/task_delete1.png";
                ms_image_btn_release: qml_port.get_img_qml_res_path() +"images/task_delete.png";
                ms_image_btn_disable: qml_port.get_img_qml_res_path() +"images/task_delete2.png";
            }
        }
    }

    Component {
        id: comLeft

        ButtonStyle {
            background: ItemBtnStyleBackground {
                ms_image_btn_hover: "images/btn_left_normal.png";
                ms_image_btn_press: "images/btn_left_press.png";
                ms_image_btn_release: "images/btn_left_normal.png";
                ms_image_btn_disable: "images/btn_left_disable.png";
            }
        }
    }

    Component {
        id: comRight

        ButtonStyle {
            background: ItemBtnStyleBackground {
                ms_image_btn_hover: "images/btn_right_normal.png";
                ms_image_btn_press: "images/btn_right_press.png";
                ms_image_btn_release: "images/btn_right_normal.png";
                ms_image_btn_disable: "images/btn_right_disabled.png";
            }
        }
    }

    Component {
        id: comDenoise

        ButtonStyle {
            background: ItemBtnStyleBackground {
                pressed: b_denoise_pressed
                ms_image_btn_hover: "images/denoise_normal.png";
                ms_image_btn_press: "images/denoise_press.png";
                ms_image_btn_release: "images/denoise_normal.png";
                ms_image_btn_disable: "images/denoise_disabled.png";
            }
        }
    }

    Component {
        id: comParamSet

        ButtonStyle {
            background: ItemBtnStyleBackground {
                pressed: b_param_set
                ms_image_btn_hover: "images/param_set_normal.png";
                ms_image_btn_press: "images/param_set_press.png";
                ms_image_btn_release: "images/param_set_normal.png";
                ms_image_btn_disable: "";
            }
        }
    }

    Component {
        id: comAlarmSet

        ButtonStyle {
            background: ItemBtnStyleBackground {
                pressed: b_alarm_set
                ms_image_btn_hover: "images/alarm_set_normal.png";
                ms_image_btn_press: "images/alarm_set_press.png";
                ms_image_btn_release: "images/alarm_set_normal.png";
                ms_image_btn_disable: "";
            }
        }
    }

    Component {
        id: comSystemSet

        ButtonStyle {
            background: ItemBtnStyleBackground {
                pressed: b_system_set
                ms_image_btn_hover: "images/system_set_normal.png";
                ms_image_btn_press: "images/system_set_press.png";
                ms_image_btn_release: "images/system_set_normal.png";
                ms_image_btn_disable: "";
            }
        }
    }
}

