QT       += core
QT       += gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../../version.pri)
include(../desktop.pri)
include(../../useCore.pri)
include(../../useExe.pri)

SOURCES += \
    BaseEngineTask.cpp \
    BaseEngineThread.cpp \
    EngineApplication.cpp \
    EngineModule.cpp \
    EngineSettings.cpp \
    FaceDetModule.cpp \
    InputModule.cpp \
    MarkerModule.cpp \
    OutputModule.cpp \
    main.cpp \
    EngineMainWindow.cpp

HEADERS += \
    BaseEngineTask.h \
    BaseEngineThread.h \
    EngineApplication.h \
    EngineMainWindow.h \
    EngineModule.h \
    EngineSettings.h \
    FaceDetModule.h \
    InputModule.h \
    MarkerModule.h \
    OutputModule.h \
    version.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../../doc/desktop/INDIface/Settings2.txt \
    ../../version.pri \
    INDIonly64.ico

RESOURCES += \
    If6Engine.qrc
