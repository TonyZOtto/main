QT += core
QT += gui
QT += widgets

CONFIG += c++17
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../desktop.pri)
include(../../useCore.pri)
include(../../useGui.pri)
include(../../useExe.pri)
include(../../useColor.pri)
include(../../usePhoto.pri)

SOURCES += \
    SandboxApplication.cpp \
    SandboxData.cpp \
    SandboxEngine.cpp \
    SandboxMainWindow.cpp \
    SandboxScene.cpp \
    main.cpp

HEADERS += \
    ../../version.h \
    SandboxApplication.h \
    SandboxData.h \
    SandboxEngine.h \
    SandboxMainWindow.h \
    SandboxScene.h

FORMS += \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../../doc/desktop/ozSandbox/Notes.md

RESOURCES += \
    ozSandbox.qrc
