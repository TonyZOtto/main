QT *= gui
QT *= widgets
QT *= statemachine
TEMPLATE = lib
DEFINES += OZCORE_LIBRARY
CONFIG += c++17
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

include(../libs.pri)
#include(../../useLog.pri)

SOURCES += \
    AText.cpp \
    Angle.cpp \
    ApplicationHelper.cpp \
    BaseErrorItem.cpp \
    Boolean.cpp \
    ByteHistogram.cpp \
    Ident.cpp \
    IdentMap.cpp \
    Key.cpp \
    KeyMap.cpp \
    KeySeg.cpp \
    KeySegList.cpp \
    MachineHelper.cpp \
    MillisecondTime.cpp \
    ObjectHelper.cpp \
    QQBitArray.cpp \
    QQDir.cpp \
    QQObject.cpp \
    QQPoint.cpp \
    QQRect.cpp \
    QQSize.cpp \
    QQStringList.cpp \
    Rational.cpp \
    RationalList.cpp \
    SCRect.cpp \
    SettingsName.cpp \
    State.cpp \
    StateMachine.cpp \
    Success.cpp \
    Uid.cpp \
    Url.cpp \
    Value.cpp \
    Variable.cpp \
    VariableSet.cpp \
    VersionInfo.cpp \
#    VersionInfoGadget.cpp \
    ozCore.cpp \


HEADERS += \
    AText.h \
    Angle.h \
    ApplicationHelper.h \
    BaseErrorItem.h \
    Boolean.h \
    ByteHistogram.h \
    DataProperty.h \
    DualMap.h \
    Ident.h \
    IdentMap.h \
    Key.h \
    KeyMap.h \
    KeyMapT.h \
    KeySeg.h \
    KeySegList.h \
    MachineHelper.h \
    MatrixT.h \
    MetaType.h \
    MillisecondTime.h \
    ObjectHelper.h \
    QQBitArray.h \
    QQDir.h \
    QQObject.h \
    QQPoint.h \
    QQRect.h \
    QQSize.h \
    QQStringList.h \
    Rational.h \
    RationalList.h \
    SCRect.h \
    SettingsName.h \
    State.h \
    StateMachine.h \
    Success.h \
    Types.h \
    Uid.h \
    Url.h \
    Value.h \
    Variable.h \
    VariableProperty.h \
    VariableSet.h \
    VersionInfo.h \
    ozCore.h        \
    ozCore_global.h \

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
