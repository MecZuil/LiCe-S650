#-------------------------------------------------
#
# Project created by QtCreator 2022-04-14T10:17:42
#
#-------------------------------------------------

QT       += core gui xml multimedia
QT       += quickwidgets qml quick widgets printsupport
QT       += sql script

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#linux-oe-g++{
#    LIBS      += -lasound  -lglib-2.0 -lgobject-2.0 -lgmodule-2.0 -lgthread-2.0 -lsqlite3 -lxml2 -lz
#    LIBS      += -lavcodec -lavutil -lavformat
#}

TARGET = TaskPkg
TEMPLATE = lib
CONFIG += plugin

SOURCES += \
    hp_taskpkg.cpp \
    hp_task_formula.cpp


HEADERS += \
    hp_taskpkg.h \
    hp_statement.h \
    hp_task_formula.h \
    hi384_protocol.h \
    hp_file.h


include($$PWD/machine/machine.pri)
include($$PWD/quazip/quazip.pri)
include($$PWD/analysis/analy.pri)

unix {
    target.path = /usr/lib
    INSTALLS += target
}

RESOURCES += \
    qml.qrc \
    hp_Task_res.qrc

FORMS +=
