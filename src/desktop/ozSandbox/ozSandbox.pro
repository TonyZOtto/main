QT += core
QT += gui
QT += widgets

CONFIG += c++17
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../desktop.pri)

SOURCES += \
    SandboxToolbar.cpp \
    SandboxWidget.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    MainWindow.h \
    SandboxToolbar.h \
    SandboxWidget.h

FORMS += \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    noun-quit-1331221.png \
    noun-quit-1331221.svg

RESOURCES += \
    ozSandbox.qrc
