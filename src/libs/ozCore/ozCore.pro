## QT -= gui
QT *= gui
QT *= widgets

TEMPLATE = lib
DEFINES += OZCORE_LIBRARY
CONFIG += c++17
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

include(../libs.pri)
#include(../../useLog.pri)

SOURCES += \
    AText.cpp \
    Angle.cpp \
    Boolean.cpp \
    Key.cpp \
    KeyMap.cpp \
    KeySeg.cpp \
    KeySegList.cpp \
    ObjectHelper.cpp \
    QQDir.cpp \
    QQObject.cpp \
    QQPoint.cpp \
    QQSize.cpp \
    QQStringList.cpp \
    Rational.cpp \
    SCRect.cpp \
    SettingsName.cpp \
    Success.cpp \
    VersionInfo.cpp \
    ozCore.cpp \


HEADERS += \
    AText.h \
    Angle.h \
    Boolean.h \
    DualMap.h \
    Key.h \
    KeyMap.h \
    KeySeg.h \
    KeySegList.h \
    MetaType.h \
    ObjectHelper.h \
    QQDir.h \
    QQObject.h \
    QQPoint.h \
    QQSize.h \
    QQStringList.h \
    Rational.h \
    SCRect.h \
    SettingsName.h \
    Success.h \
    Types.h \
    VersionInfo.h \
    ozCore.h        \
    ozCore_global.h \

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
