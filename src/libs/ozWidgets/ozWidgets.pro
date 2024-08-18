QT += widgets
TEMPLATE = lib
DEFINES += OZWIDGETS_LIBRARY
CONFIG += c++17
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include("../libs.pri")

SOURCES += \
    BaseGridLayout.cpp \
    ozWidgets.cpp

HEADERS += \
    BaseGridLayout.h \
    ozWidgets.h \
    ozWidgets_global.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
