QT += core
QT += gui
QT += widgets
TEMPLATE = lib
DEFINES += OZEXE_LIBRARY
CONFIG += c++17
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

include(../libs.pri)
include(../../useCore.pri)
include(../../useWidgets.pri)

SOURCES += \
    ApplicationHelper.cpp \
    BaseMainWindow.cpp \
    CommandLine.cpp \
    ConsoleApplication.cpp \
    ErrorManager.cpp \
    GridMainWindow.cpp \
    GuiApplication.cpp \
    IconFactory.cpp \
    MdiMainWindow.cpp \
    Settings.cpp \
    StackedMainPage.cpp \
    StackedMainWindow.cpp \
    WidgetApplication.cpp \
    ozExe.cpp

HEADERS += \
    ApplicationHelper.h \
    BaseMainWindow.h \
    CommandLine.h \
    ConsoleApplication.h \
    ErrorManager.h \
    GridMainWindow.h \
    GuiApplication.h \
    IconFactory.h \
    MdiMainWindow.h \
    Settings.h \
    StackedMainPage.h \
    StackedMainWindow.h \
    WidgetApplication.h \
    ozExe.h \
    ozExe_global.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
