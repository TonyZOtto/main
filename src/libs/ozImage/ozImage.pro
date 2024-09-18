QT += gui
QT += widgets
TEMPLATE = lib
DEFINES += OZIMAGE_LIBRARY
CONFIG += c++17
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

include(../libs.pri)
include(../../useCore.pri)
include(../../useColor.pri)

SOURCES += \
    BaseImage.cpp \
    BasePixel32.cpp \
    BasePixelBehavior.cpp \
    ColorImage.cpp \
    Grey16Image.cpp \
    GreyImage.cpp \
    Image.cpp \
    IndexedImage.cpp \
    PixmapStack.cpp \
    SupportedFormats.cpp \
    ThumbImage.cpp \
    ozImage.cpp \

HEADERS += \
    BaseImage.h \
    BasePixel32.h \
    BasePixelBehavior.h \
    ColorImage.h \
    Grey16Image.h \
    GreyImage.h \
    Image.h \
    IndexedImage.h \
    PixmapStack.h \
    SupportedFormats.h \
    ThumbImage.h \
    ozImage.h \
    ozImage_global.h \

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
