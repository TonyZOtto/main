## QT -= gui
QT *= gui
QT *= widgets

TEMPLATE = lib
DEFINES += OZCORE_LIBRARY
CONFIG += c++17
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

include(../libs.pri)

SOURCES += \
    AText.cpp \
    Angle.cpp \
    ApplicationSettings.cpp \
    BaseApplication.cpp \
    CommandLine.cpp \
    ConsoleApplication.cpp \
    ConsoleStdIO.cpp \
    DesktopApplication.cpp \
    Key.cpp \
    KeyMap.cpp \
    KeySeg.cpp \
    KeySegList.cpp \
    ObjectHelper.cpp \
    QQFileInfo.cpp \
    QQObject.cpp \
    QQStringList.cpp \
    Rational.cpp \
    SettingsName.cpp \
    VersionInfo.cpp \
    WidgetApplication.cpp \
    coreapp/ApplicationSettings.cpp \
    coreapp/BaseApplication.cpp \
    coreapp/CommandLine.cpp \
    coreapp/ConsoleApplication.cpp \
    coreapp/ConsoleStdIO.cpp \
    coreapp/DesktopApplication.cpp \
    coreapp/ObjectHelper.cpp \
    coreapp/SettingsName.cpp \
    coreapp/WidgetApplication.cpp \
    filesys/QQFileInfo.cpp \
    ident/Key.cpp \
    ident/KeyMap.cpp \
    ident/KeySeg.cpp \
    ident/KeySegList.cpp \
    ident/VersionInfo.cpp \
    log/Context.cpp \
    log/FunctionInfo.cpp \
    log/LogItem.cpp \
    log/Logger.cpp \
    object/QQObject.cpp \
    ozCore.cpp \
    qcore/QQStringList.cpp \
    types/Angle.cpp \
    types/Rational.cpp


HEADERS += \
    AText.h \
    Angle.h \
    ApplicationSettings.h \
    BaseApplication.h \
    CommandLine.h \
    ConsoleApplication.h \
    ConsoleStdIO.h \
    DesktopApplication.h \
    Key.h \
    KeyMap.h \
    KeySeg.h \
    KeySegList.h \
    ObjectHelper.h \
    QQFileInfo.h \
    QQObject.h \
    QQStringList.h \
    Rational.h \
    SettingsName.h \
    Types.h \
    VersionInfo.h \
    WidgetApplication.h \

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
