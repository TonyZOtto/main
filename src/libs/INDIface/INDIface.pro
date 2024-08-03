QT += gui
TEMPLATE = lib
DEFINES += INDIFACE_LIBRARY
CONFIG += c++17
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

include(../libs.pri)

SOURCES += \
    INDIface.cpp

HEADERS += \
    INDIface_global.h \
    INDIface.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
