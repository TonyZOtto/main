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
    qcore/QQStringList.cpp

HEADERS += \
    ../../include/ConsoleApplication \
    ../../include/ConsoleStdIO \
    ../../include/FileInfo \
    ../../include/GadgetHelper \
    ../../include/QQStringList \
    ../../include/Types \
    AText.h \
    Types.h \
    coreapp/ApplicationSettings.h \
    coreapp/BaseApplication.h \
    coreapp/CommandLine.h \
    coreapp/ConsoleApplication.h \
    coreapp/ConsoleStdIO.h \
    coreapp/DesktopApplication.h \
    coreapp/ObjectHelper.h \
    coreapp/SettingsName.h \
    coreapp/WidgetApplication.h \
    filesys/QQFileInfo.h \
    ident/Key.h \
    ident/KeyMap.h \
    ident/KeySeg.h \
    ident/KeySegList.h \
    ident/VersionInfo.h \
    log/Context.h \
    log/FunctionInfo.h \
    log/Log.h \
    log/LogItem.h \
    log/LogMacros.h \
    log/Logger.h \
    object/QQObject.h \
    ozCore_global.h \
    ozCore.h \
    qcore/QQStringList.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
