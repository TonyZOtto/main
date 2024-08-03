TEMPLATE = subdirs
 
SUBDIRS +=          \
    QtCV            \
    ozLog           \
    ozCore          \
    ozQtCV          \
    ozGui           \
    ozExe           \
    ozColor         \
    ozPhoto         \
    ozWidgets       \
#    INDIface        \
#    INDIbase        \
    If6Engine       \

QtCV.subdir             = libs/QtCV
ozLog.subdir            = libs/ozLog
ozCore.subdir           = libs/ozCore
ozQtCV.subdir           = libs/ozQtCV
ozGui.subdir            = libs/ozGui
ozExe.subdir            = libs/ozExe
ozColor.subdir          = libs/ozColor
ozPhoto.subdir          = libs/ozPhoto
#INDIface.subdir         = libs/INDIface
#INDIbase.subdir         = libs/INDIbase
ozWidgets.subdir        = libs/ozWidgets
If6Engine.subdir        = desktop/If6Engine

QtCV.depends            =
ozLog.depends           =
ozCore.depends          =           ozLog
ozQtCV.depends          =           ozLog   ozCore
ozGui.depends           =                   ozCore
ozExe.depends           =                   ozCore          ozGui
ozColor.depends         =                   ozCore
ozPhoto.depends         =                   ozCore                          ozColor
#INDIface.subdir         =
#INDIbase.subdir         =
ozWidgets.depends       =                   ozCore          ozGui
#If6Engine.depends       =   QtCV    ozLog   ozCore  ozQtCV  ozGui   ozExe   ozColor ozPhoto INDIface    INDIbase    ozWidgets
If6Engine.depends       =   QtCV    ozLog   ozCore  ozQtCV  ozGui   ozExe   ozColor ozPhoto ozWidgets

