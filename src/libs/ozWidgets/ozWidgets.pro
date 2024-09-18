QT += widgets
TEMPLATE = lib
DEFINES += OZWIDGETS_LIBRARY
CONFIG += c++17
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#QMAKE_CXXFLAGS_DEBUG *= -E

include(../libs.pri)
include(../../useCore.pri)
include(../../useGui.pri)
include(../../useColor.pri)
include(../../useImage.pri)

SOURCES += \
    BaseGridLayout.cpp \
    BaseStackedLayout.cpp \
    BaseTabBar.cpp \
    BaseToolBar.cpp \
    BaseToolButton.cpp \
    DropWidgetView.cpp \
    FillerWidget.cpp \
    GridStackPage.cpp \
    ImageFileDropWidget.cpp \
    ImageFileListWidget.cpp \
    ImageFileTreeWidget.cpp \
    ImageGalleryConfig.cpp \
    ImageGalleryInternal.cpp \
    ImageGalleryItem.cpp \
    ImageGalleryWidget.cpp \
    QQLabel.cpp \
    TriggerItem.cpp \
    TriggerManager.cpp \
    ozWidgets.cpp\

HEADERS += \
    BaseGridLayout.h \
    BaseStackedLayout.h \
    BaseTabBar.h \
    BaseToolBar.h \
    BaseToolButton.h \
    DropWidgetView.h \
    FillerWidget.h \
    GridStackPage.h \
    ImageFileDropWidget.h \
    ImageFileListWidget.h \
    ImageFileTreeWidget.h \
    ImageGalleryConfig.h \
    ImageGalleryInternal.h \
    ImageGalleryItem.h \
    ImageGalleryWidget.h \
    QQLabel.h \
    TriggerItem.h \
    TriggerManager.h \
    ozWidgets.h \
    ozWidgets_global.h \

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
