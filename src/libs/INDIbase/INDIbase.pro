QT += gui
TEMPLATE = lib
DEFINES += INDIBASE_LIBRARY
CONFIG += c++17
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

include(../libs.pri)

SOURCES += \
    INDIbase.cpp

HEADERS += \
    INDIbase_global.h \
    INDIbase.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
