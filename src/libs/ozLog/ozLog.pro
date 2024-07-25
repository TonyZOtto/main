QT -= gui

TEMPLATE = lib
DEFINES += OZLOG_LIBRARY
CONFIG += c++17
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../libs.pri)

SOURCES += \
    Context.cpp \
    FileInfo.cpp \
    FunctionInfo.cpp \
    LogItem.cpp \
    LogObject.cpp \
    Logger.cpp \
    ozLog.cpp

HEADERS += \
    Context.h \
    FileInfo.h \
    FunctionInfo.h \
    Log.h \
    LogItem.h \
    LogMacros.h \
    LogObject.h \
    Logger.h \
    ozLog_global.h \
    ozLog.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
