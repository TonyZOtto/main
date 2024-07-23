QT += gui \
    widgets
TEMPLATE = lib
DEFINES += OZPHOTO_LIBRARY
CONFIG += c++17
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../libs.pri)
include(../../useCore.pri)
include(../../useColor.pri)

SOURCES += \
    BasePhoto.cpp \
    BasePixel32.cpp \
    BasePixelBehavior.cpp \
    ColorPhoto.cpp \
    Grey16Photo.cpp \
    GreyPhoto.cpp \
    IndexPhoto.cpp \
    Photo.cpp \
    PhotoGallery.cpp \
    PixmapStack.cpp \
    ozPhoto.cpp

HEADERS += \
    BasePhoto.h \
    BasePixel32.h \
    BasePixelBehavior.h \
    ColorPhoto.h \
    Grey16Photo.h \
    GreyPhoto.h \
    IndexPhoto.h \
    Photo.h \
    PhotoGallery.h \
    PixmapStack.h \
    ozPhoto_global.h \
    ozPhoto.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
