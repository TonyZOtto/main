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
    BaseMainWindow.cpp \
    Boolean.cpp \
    ByteHistogram.cpp \
    CommandLine.cpp \
    ConsoleApplication.cpp \
    ConsoleStdIO.cpp \
    GridMainWindow.cpp \
    GuiApplication.cpp \
    IconFactory.cpp \
    Ident.cpp \
    IdentMap.cpp \
    Key.cpp \
    KeyMap.cpp \
    KeySeg.cpp \
    KeySegList.cpp \
    MachineHelper.cpp \
    MainWindowConfig.cpp \
    MdiMainWindow.cpp \
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
    Settings.cpp \
    SettingsItem.cpp \
    SettingsName.cpp \
    StackedMainPage.cpp \
    StackedMainWindow.cpp \
    State.cpp \
    StateMachine.cpp \
    Success.cpp \
    TriggerItem.cpp \
    TriggerManager.cpp \
    Uid.cpp \
    Url.cpp \
    Value.cpp \
    Variable.cpp \
    VariableSet.cpp \
    VersionInfo.cpp \
#    VersionInfoGadget.cpp \
    WidgetApplication.cpp \
    ozCore.cpp \


HEADERS += \
    AText.h \
    Angle.h \
    ApplicationHelper.h \
    BaseErrorItem.h \
    BaseMainWindow.h \
    Boolean.h \
    ByteHistogram.h \
    CommandLine.h \
    ConsoleApplication.h \
    ConsoleStdIO.h \
    DataProperty.h \
    DualMap.h \
    GridMainWindow.h \
    GuiApplication.h \
    IconFactory.h \
    Ident.h \
    IdentMap.h \
    Key.h \
    KeyMap.h \
    KeyMapT.h \
    KeySeg.h \
    KeySegList.h \
    MachineHelper.h \
    MainWindowConfig.h \
    MatrixT.h \
    MdiMainWindow.h \
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
    Settings.h \
    SettingsItem.h \
    SettingsName.h \
    StackedMainPage.h \
    StackedMainWindow.h \
    State.h \
    StateMachine.h \
    Success.h \
    TriggerItem.h \
    TriggerManager.h \
    Types.h \
    Uid.h \
    Url.h \
    Value.h \
    Variable.h \
    VariableProperty.h \
    VariableSet.h \
    VersionInfo.h \
    WidgetApplication.h \
    ozCore.h        \
    ozCore_global.h \

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
