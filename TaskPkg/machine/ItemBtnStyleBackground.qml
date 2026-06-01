import QtQuick 2.0
import QtQuick.Controls 1.2

Rectangle {
    id: btn_style
    anchors.fill: parent
    property string ms_image_btn_press: ""
    property string ms_image_btn_hover: ""
    property string ms_image_btn_release: ""
    property string ms_image_btn_disable: ""
    property bool pressed: false

    //radius: 8
    color: "transparent"

    Image {
        id: btn_img
        anchors.centerIn: parent
        source: control.enabled?( pressed?ms_image_btn_press:control.pressed ? ms_image_btn_press : (control.hovered?ms_image_btn_hover: ms_image_btn_release ) ) :  ms_image_btn_disable
    }
}

