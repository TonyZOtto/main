QT -= gui

TEMPLATE = lib
DEFINES += OZLOG_LIBRARY
CONFIG += c++17
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../libs.pri)

SOURCES += \
    LogCategory.cpp \
    LogContext.cpp \
    LogEngine.cpp \
    LogFileInfo.cpp \
    LogFunctionInfo.cpp \
    LogItem.cpp \
    LogItemObj.cpp \
    LogObject.cpp \
    ozLog.cpp

HEADERS += \
    Log.h \
    LogCategory.h \
    LogContext.h \
    LogEngine.h \
    LogFileInfo.h \
    LogFunctionInfo.h \
    LogItem.h \
    LogItemObj.h \
    LogMacros.h \
    LogObject.h \
    ozLog_global.h \
    ozLog.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
