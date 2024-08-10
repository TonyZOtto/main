QT += core
QT += gui
QT += widgets
QT += statemachine
CONFIG += c++17
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

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
    InputModuleMachine.cpp \
    LiveInputMachine.cpp \
    MarkerModule.cpp \
    OutputModule.cpp \
    StoredInputMachine.cpp \
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
    InputModuleMachine.h \
    LiveInputMachine.h \
    MarkerModule.h \
    OutputModule.h \
    StoredInputMachine.h \
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
