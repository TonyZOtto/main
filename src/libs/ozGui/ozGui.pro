QT += gui
TEMPLATE = lib
DEFINES += OZGUI_LIBRARY
CONFIG += c++17
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../libs.pri)
include(../../useCore.pri)

SOURCES += \
    ActionManager.cpp \
    IconManager.cpp \
    QQColor.cpp \
    ozGui.cpp

HEADERS += \
    ActionManager.h \
    IconManager.h \
    QQColor.h \
    ozGui_global.h \
    ozGui.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
