QT += gui

TEMPLATE = lib
DEFINES += OZCOLOR_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Color.cpp \
    Pixel32.cpp \
    RgbColor.cpp \
    Rgba32Table.cpp \
    ozColor.cpp

HEADERS += \
    Color.h \
    Pixel32.h \
    RgbColor.h \
    Rgba32Table.h \
    ozColor_global.h \
    ozColor.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
