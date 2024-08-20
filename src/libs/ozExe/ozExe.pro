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
    ActionManager.cpp \
    AppSettings.cpp \
    ApplicationHelper.cpp \
    BaseMainWindow.cpp \
    CommandLine.cpp \
    ConsoleApplication.cpp \
    GridMainWindow.cpp \
    GuiApplication.cpp \
    IconFactory.cpp \
    MdiMainWindow.cpp \
    SettingsItem.cpp \
    StackedMainWindow.cpp \
    WidgetApplication.cpp \
    ozExe.cpp

HEADERS += \
    ActionManager.h \
    AppSettings.h \
    ApplicationHelper.h \
    BaseMainWindow.h \
    CommandLine.h \
    ConsoleApplication.h \
    GridMainWindow.h \
    GuiApplication.h \
    IconFactory.h \
    MdiMainWindow.h \
    SettingsItem.h \
    StackedMainWindow.h \
    WidgetApplication.h \
    ozExe.h \
    ozExe_global.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
