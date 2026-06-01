INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

SOURCES += machine/change-model.cpp \
    machine/databaseop.cpp \
    machine/device-list.cpp \
    machine/file-list.cpp \
    machine/folder-list.cpp \
    machine/formula.cpp \
    machine/general-mode-dlg.cpp \
    machine/import-task-thread.cpp \
    machine/module.cpp \
    machine/qml-port.cpp \
    machine/select-task-dlg.cpp \
    machine/setting-help.cpp \
    machine/yfjsonaccess.cpp \
    machine/setting_conf.cpp \
    machine/xml-list.cpp

HEADERS += machine/change-model.h \
    machine/config.h \
    machine/databaseop.h \
    machine/device-list.h \
    machine/file-list.h \
    machine/folder-list.h \
    machine/formula.h \
    machine/general-mode-dlg.h \
    machine/import-task-thread.h \
    machine/module.h \
    machine/qml-port.h \
    machine/select-task-dlg.h \
    machine/setting-help.h \
    machine/yfjsonaccess.h \
    machine/setting_conf.h \
    machine/xml-list.h

INCLUDEPATH += $$PWD/../

DISTFILES += \
    $$PWD/MessageInteraction.qml

