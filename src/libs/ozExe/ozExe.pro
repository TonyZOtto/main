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
    ErrorManager.cpp \
    GridMainWindow.cpp \
    GuiApplication.cpp \
    IconFactory.cpp \
    MdiMainWindow.cpp \
    SettingsItem.cpp \
    StackedMainPage.cpp \
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
    ErrorManager.h \
    GridMainWindow.h \
    GuiApplication.h \
    IconFactory.h \
    MdiMainWindow.h \
    SettingsItem.h \
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
