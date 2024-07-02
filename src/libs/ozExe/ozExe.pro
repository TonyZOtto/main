#QT -= gui

TEMPLATE = lib
DEFINES += OZEXE_LIBRARY
CONFIG += c++17
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../libs.pri)
include(../../useLog.pri)
include(../../useCore.pri)

SOURCES += \
    ActionManager.cpp \
    ApplicationSettings.cpp \
    CommandLine.cpp \
#    ConsoleApplication.cpp \
#    ConsoleStdIO.cpp \
#    WidgetApplication.cpp \
    ozExe.cpp

HEADERS += \
    ActionManager.h \
    ApplicationSettings.h \
    CommandLine.h \
#    ConsoleApplication.h \
#    ConsoleStdIO.h \
#    WidgetApplication.h \
    ozExe.h \
    ozExe_global.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
