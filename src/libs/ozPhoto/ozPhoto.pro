QT += gui
TEMPLATE = lib
DEFINES += OZPHOTO_LIBRARY
CONFIG += c++17
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../libs.pri)
include(../../useCore.pri)

SOURCES += \
    BasePhoto.cpp \
    BasePixel32.cpp \
    BasePixelBehavior.cpp \
    ColorPhoto.cpp \
    GreyPhoto.cpp \
    IndexPhoto.cpp \
    ozPhoto.cpp

HEADERS += \
    BasePhoto.h \
    BasePixel32.h \
    BasePixelBehavior.h \
    ColorPhoto.h \
    GreyPhoto.h \
    IndexPhoto.h \
    ozPhoto_global.h \
    ozPhoto.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
