QT       += core
QT       += gui
QT       += widgets
CONFIG += c++17
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

include(../desktop.pri)
include(../../useCore.pri)
include(../../useExe.pri)
include(../../useColor.pri)
include(../../usePhoto.pri)
include(../../useWidgets.pri)

SOURCES += \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    MainWindow.h \
    version.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
