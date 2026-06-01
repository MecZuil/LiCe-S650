#-------------------------------------------------
#
# Project created by QtCreator 2017-06-28T09:38:48
#
#-------------------------------------------------

QT       += core gui xml sql multimedia multimediawidgets
QT       += quickwidgets qml quick widgets printsupport
QT       += sql multimedia script

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = n_H384i
TEMPLATE = app

linux-oe-g++{
    INCLUDEPATH += /home/knight/MyCrossCompiling/modules/lib/imx6/gstreamer/include
    INCLUDEPATH += /home/knight/MyCrossCompiling/modules/lib/imx6/gstreamer/include/gstreamer-1.0
    INCLUDEPATH += /home/knight/MyCrossCompiling/modules/lib/imx6/gstreamer/lib
    INCLUDEPATH += /home/knight/MyCrossCompiling/modules/lib/imx6/gstreamer/lib/gstreamer-1.0
    INCLUDEPATH += /home/knight/MyCrossCompiling/modules/lib/imx6/gstreamer/lib/gstreamer-1.0/include
    INCLUDEPATH += /home/knight/MyCrossCompiling/modules/lib/imx6/glib-2.0
    INCLUDEPATH += /home/knight/MyCrossCompiling/modules/lib/imx6/glib-2.0/include
    INCLUDEPATH += /opt/fsl-imx-x11/4.1.15-1.2.0/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi/usr/lib/glib-2.0/include
    LIBS += -lasound  -lglib-2.0 -lgobject-2.0 -lgmodule-2.0 -lgthread-2.0 -lsqlite3 -lxml2 -lz
    LIBS += -lavcodec -lavdevice -lavfilter -lavformat -lavutil -lpostproc -lswscale -lswresample
    LIBS += -L/home/knight/MyCrossCompiling/modules/lib/imx6/orc/lib -lorc-0.4
    LIBS += -L/home/knight/MyCrossCompiling/modules/lib/imx6/gstreamer/lib -lgstvideo-1.0 -lgstbase-1.0 -lgstvideo-1.0 -lgstreamer-1.0
    LIBS += -L/opt/fsl-imx-fb/4.1.15-1.1.1/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi/usr/lib -lpthread
}




SOURCES += main.cpp\
        mainwidget.cpp \
    hp_button.cpp \
    hpsetting.cpp \
    hptabwidgetstyle.cpp \
    hpdomainapi.cpp \
    hpdomainthread.cpp \
    hpprotocolpkg.cpp \
    hpmode.cpp \
    hpsebiao.cpp \
    hpcpumem.cpp \
    hp_cpudrawwidget.cpp \
    hp_display.cpp \
    hpresize.cpp \
    hpdeledit.cpp \
    hphidemenu.cpp \
    hpplredit.cpp \
    hp_qslider.cpp \
    hppreview.cpp \
    hpxmlreader.cpp \
    hptempunitconvert.cpp \
    hp_defaultdialog.cpp \
    hp_formatdialog.cpp \
    hp_camera_cap.cpp \
    hp_camera_video.cpp \
    hp_sdinfo.cpp \
    hp_dialog.cpp \
    hp_qspinbox.cpp \
    hp_adjust_cmd.cpp \
    hp_rdj_type_spinbox.cpp \
    hp_mode_hzh_adjust.cpp \
    hp_mode_rdj_adjust.cpp \
    hp_text_input.cpp \
    hp_ble_search.cpp \
    frmnum.cpp \
    hp_media_player.cpp \
    hp_main_task.cpp \
    hp_sd_space_warning.cpp \
    hp_twice_analysis.cpp \
    hp_poweroff_dialog.cpp \
    hp_handfution.cpp \
    hphide_biaoding.cpp \
    hphide_dialog.cpp \
    hphide_dialog_lo.cpp \
    hphide_dialog_save.cpp \
    hp_usb_insert.cpp \
    hp_poweroff_warn.cpp \
    hp_avi_mode.cpp \
    hp_twice_pic.cpp \
    hp_twice_kjg.cpp \
    hpsetting_adjust.cpp \
    hp_ble_dialog.cpp \
    hp_pic_dialog.cpp \
    hp_qdoublespinboxset.cpp \
    hp_qspinboxset.cpp \
    hp_isotherm.cpp \
    hp_wifi_search.cpp \
    hp_wifi_search_dialog.cpp \
    hp_autoupload.cpp \
    hp_autoupload_dialog.cpp \
    hp_hir_player.cpp \
    hp_download.cpp \
    hp_style_scrollarea.cpp \
    hp_gstreamer_player.cpp \
    hp_ffmpeg_player.cpp \
    hp_ffmpeg_audio.cpp \
    mylabel.cpp \
    hp_common_dialog_cancel.cpp \
    hp_common_dialog_select.cpp \
    hp_sis_content.cpp \
    hp_mulhom_edit.cpp \
    hp_picture_mode.cpp \
    hp_wait_warn.cpp \
    cJSON.c \
    hp_pms.cpp \
    hp_style_listwidget.cpp \
    hp_panorama.cpp \
    hphide_laser.cpp \
    hp_panorama_dialog.cpp \
    frminput.cpp \
    hp_panorama_tips_dialog.cpp \
    hp_bel_search_old.cpp \
    hp_ble_at.cpp \
    hp_calbration.cpp \
    hp_sort.cpp \
    hp_media_player_gplay.cpp \
    hp_hotkey.cpp \
    hp_polygon.cpp \
    hp_transmission.cpp \
    hp_bt1036.cpp \
    hp_createpdf.cpp \
    mymalloc.cpp \
    pms_protocol_pkg.cpp \
    crc.cpp \
    mycstdlib.cpp \
    serial.cpp \
    hp_main_task_1.cpp \
    hp_main_task_2.cpp \
    hp_main_task_3.cpp \
    hpmylabel.cpp \
    hp_transmissionsearch.cpp

HEADERS  += mainwidget.h \
    hp_button.h \
    hpsetting.h \
    hptabwidgetstyle.h \
    hi384_protocol.h \
    hpdomainapi.h \
    hpdomainthread.h \
    hpprotocolpkg.h \
    hpmode.h \
    hpsebiao.h \
    hpcpumem.h \
    hp_cpudrawwidget.h \
    hp_display.h \
    hpresize.h \
    hpdeledit.h \
    hphidemenu.h \
    hpplredit.h \
    hp_qslider.h \
    hppreview.h \
    hpxmlreader.h \
    hptempunitconvert.h \
    hp_defaultdialog.h \
    hp_formatdialog.h \
    hp_camera_cap.h \
    hp_camera_video.h \
    hp_sdinfo.h \
    hp_file.h \
    hp_dialog.h \
    hp_qspinbox.h \
    hp_adjust_cmd.h \
    hp_rdj_type_spinbox.h \
    hp_mode_hzh_adjust.h \
    hp_mode_rdj_adjust.h \
    hp_text_input.h \
    hp_ble_search.h \
    frminput.h \
    frmnum.h \
    hp_media_player.h \
    hp_main_task.h \
    hp_sd_space_warning.h \
    hp_twice_analysis.h \
    hp_poweroff_dialog.h \
    hp_handfution.h \
    hphide_biaoding.h \
    hphide_dialog.h \
    hphide_dialog_lo.h \
    hphide_dialog_save.h \
    hp_usb_insert.h \
    hp_poweroff_warn.h \
    hp_avi_mode.h \
    hp_twice_pic.h \
    hp_twice_kjg.h \
    hpsetting_adjust.h \
    hp_ble_dialog.h \
    hp_pic_dialog.h \
    hp_qdoublespinboxset.h \
    hp_qspinboxset.h \
    hp_isotherm.h \
    hp_wifi_search.h \
    hp_wifi_search_dialog.h \
    hp_autoupload.h \
    hp_autoupload_dialog.h \
    hp_hir_player.h \
    hp_download.h \
    hp_style_scrollarea.h \
    hp_gstreamer_player.h \
    hp_ffmpeg_player.h \
    hp_ffmpeg_audio.h \
    mylabel.h \
    hp_common_dialog_cancel.h \
    hp_common_dialog_select.h \
    hp_sis_content.h \
    hp_mulhom_edit.h \
    hp_picture_mode.h \
    hp_wait_warn.h \
    cJSON.h \
    hp_pms.h \
    hp_style_listwidget.h \
    hp_panorama.h \
    hphide_laser.h \
    hp_panorama_dialog.h \
    hp_panorama_tips_dialog.h \
    hp_bel_search_old.h \
    hp_ble_at.h \
    hp_calbration.h \
    hp_sort.h \
    hp_media_player_gplay.h \
    hp_hotkey.h \
    hp_polygon.h \
    hp_bt1036.h \
    hp_transmission.h \
    hp_createpdf.h \
    pms_protocol_pkg.h \
    crc.h \
    debug.h \
    mycstdlib.h \
    mymalloc.h \
    serial.h \
    hp_main_task_1.h \
    hp_main_task_2.h \
    hp_main_task_3.h \
    hpmylabel.h \
    hp_transmissionsearch.h

FORMS    += mainwidget.ui \
    hpsetting.ui \
    hpmode.ui \
    hpsebiao.ui \
    hpcpumem.ui \
    hpresize.ui \
    hpdeledit.ui \
    hphidemenu.ui \
    hpplredit.ui \
    hppreview.ui \
    hp_defaultdialog.ui \
    hp_formatdialog.ui \
    hp_camera_cap.ui \
    hp_camera_video.ui \
    hp_dialog.ui \
    hp_adjust_cmd.ui \
    hp_mode_hzh_adjust.ui \
    hp_mode_rdj_adjust.ui \
    hp_text_input.ui \
    hp_ble_search.ui \
    frminput.ui \
    frmnum.ui \
    hp_media_player.ui \
    hp_main_task.ui \
    hp_sd_space_warning.ui \
    hp_twice_analysis.ui \
    hp_poweroff_dialog.ui \
    hp_handfution.ui \
    hphide_biaoding.ui \
    hphide_dialog.ui \
    hphide_dialog_lo.ui \
    hphide_dialog_save.ui \
    hp_usb_insert.ui \
    hp_poweroff_warn.ui \
    hp_avi_mode.ui \
    hp_twice_pic.ui \
    hp_twice_kjg.ui \
    hpsetting_adjust.ui \
    hp_ble_dialog.ui \
    hp_pic_dialog.ui \
    hp_isotherm.ui \
    hp_wifi_search.ui \
    hp_wifi_search_dialog.ui \
    hp_autoupload.ui \
    hp_autoupload_dialog.ui \
    hp_hir_player.ui \
    hp_download.ui \
    hp_gstreamer_player.ui \
    hp_common_dialog_cancel.ui \
    hp_common_dialog_select.ui \
    hp_sis_content.ui \
    hp_mulhom_edit.ui \
    hp_picture_mode.ui \
    hp_wait_warn.ui \
    hp_pms.ui \
    hp_panorama.ui \
    hphide_laser.ui \
    hp_panorama_dialog.ui \
    hp_panorama_tips_dialog.ui \
    hp_bel_search_old.ui \
    hp_calbration.ui \
    hp_media_player_gplay.ui \
    hp_hotkey.ui \
    hp_createpdf.ui \
    hp_main_task_1.ui \
    hp_main_task_2.ui \
    hp_main_task_3.ui \
    hp_transmissionsearch.ui

RESOURCES += \
    hp_res.qrc

LIBS +=  \
        -lavcodec \
        -lavdevice \
        -lavfilter \
        -lavformat \
        -lavutil \
        -lpostproc \
        -lswscale \
        -lswresample

INCLUDEPATH += /home/knight/fsl-release-bsp/build_imx6q_fb/tmp/sysroots/imx6qsabresd/usr/include/libxml2
LIBS        += -L/home/knight/fsl-release-bsp/build_imx6q_fb/tmp/sysroots/imx6qsabresd/usr/lib -lxml2 -lz -lxml2 -lz
INCLUDEPATH += /home/knight/fsl-release-bsp/build_imx6q_fb/tmp/sysroots/imx6qsabresd/usr/include/
INCLUDEPATH += /home/knight/fsl-release-bsp/build_imx6q_fb/tmp/sysroots/imx6qsabresd/usr/include/gstreamer-1.0
INCLUDEPATH += /home/knight/fsl-release-bsp/build_imx6q_fb/tmp/sysroots/imx6qsabresd/usr/lib/gstreamer-1.0/include/
INCLUDEPATH += /home/knight/fsl-release-bsp/build_imx6q_fb/tmp/sysroots/imx6qsabresd/usr/include/gstreamer-1.0
INCLUDEPATH += /home/knight/fsl-release-bsp/build_imx6q_fb/tmp/sysroots/imx6qsabresd/usr/include/gstreamer-1.0/include
INCLUDEPATH += /home/knight/fsl-release-bsp/build_imx6q_fb/tmp/sysroots/imx6qsabresd/usr/include/glib-2.0/
INCLUDEPATH += /opt/fsl-imx-x11/4.1.15-1.2.0/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi/usr/lib/glib-2.0/include
LIBS        += -L/home/knight/fsl-release-bsp/build_imx6q_fb/tmp/sysroots/imx6qsabresd/usr/lib -lorc-0.4
LIBS        += -L/opt/fsl-imx-x11/4.1.15-1.2.0/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi/usr/lib -lasound -lglib-2.0 -lgobject-2.0 -lgmodule-2.0 -lgthread-2.0 -lsqlite3
LIBS        += -L/home/knight/fsl-release-bsp/build_imx6q_fb/tmp/sysroots/imx6qsabresd/usr/lib -lgstvideo-1.0 -lgstbase-1.0 -lgstreamer-1.0
LIBS        += -L/home/knight/fsl-release-bsp/build_imx6q_fb/tmp/sysroots/imx6qsabresd/usr/lib/gstreamer-1.0 -lgstvideo-1.0
LIBS        += -L/opt/fsl-imx-fb/4.1.15-1.1.1/sysroots/cortexa9hf-vfp-neon-poky-linux-gnueabi/usr/lib -lpthread


# 直接把路径写死在 LFLAGS 里，注意 -Wl 和逗号之间没有空格
#LIBS += /home/knight/MyCrossCompiling/modules/lib/imx6/opencv/V4.5.1/lib/libopencv_*.so

# 同时保留这个，确保链接器在处理“间接依赖”时有底气
#QMAKE_LFLAGS += -Wl,-rpath-link,/home/knight/MyCrossCompiling/modules/lib/imx6/opencv/V4.5.1/lib

#TRANSLATIONS = hp_zh_CN.ts hp_zh_EN.ts hp_zh_TW.ts hp_zh_GE.ts
TRANSLATIONS = hp_zh_CN.ts hp_zh_EN.ts hp_zh_TW.ts hp_zh_RU.ts hp_zh_MA.ts hp_zh_ES.ts
unix:!macx: LIBS += -lasound

DISTFILES +=

INCLUDEPATH += $$PWD/../TaskPkg/
LIBS += -L/$$PWD/../TaskPkg/build/ -lTaskPkg
