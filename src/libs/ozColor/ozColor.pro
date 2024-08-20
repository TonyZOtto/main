QT += gui
TEMPLATE = lib
DEFINES += OZCOLOR_LIBRARY
CONFIG += c++17
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

include(../libs.pri)
include(../../useCore.pri)

SOURCES += \
    AnyColor.cpp \
    BrightnessContrast.cpp \
    Color.cpp \
    Pixel32.cpp \
    RationalColorList.cpp \
    RgbColor.cpp \
    Rgba32Table.cpp \
    ozColor.cpp

HEADERS += \
    AnyColor.h \
    BrightnessContrast.h \
    Color.h \
    Pixel32.h \
    RationalColorList.h \
    RgbColor.h \
    Rgba32Table.h \
    ozColor_global.h \
    ozColor.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
