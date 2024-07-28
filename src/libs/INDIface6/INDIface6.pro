QT += gui

TEMPLATE = lib
DEFINES += INDIFACE6_LIBRARY
CONFIG += c++17
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../libs.pri)
include(../../useCore.pri)
include(../../usePhoto.pri)

SOURCES += \
    FrameData.cpp \
    INDIface6.cpp \
    INDIframe.cpp

HEADERS += \
    FrameData.h \
    INDIface6_global.h \
    INDIface6.h \
    INDIframe.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
