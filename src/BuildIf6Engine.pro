TEMPLATE = subdirs
 
SUBDIRS +=          \
    ozCore          \
    ozGui           \
    ozExe           \
    ozColor         \
    ozPhoto         \
    ozWidgets       \
	INDIbase6		\
	INDIface6		\
    If6Engine       \

ozCore.subdir           = libs/ozCore
ozGui.subdir            = libs/ozGui
ozExe.subdir            = libs/ozExe
ozColor.subdir          = libs/ozColor
ozPhoto.subdir          = libs/ozPhoto
INDIbase6.subdir        = libs/INDIbase6
INDIface6.subdir        = libs/INDIface6
ozWidgets.subdir        = libs/ozWidgets
If6Engine.subdir        = desktop/If6Engine

ozCore.depends          =
ozGui.depends           =   ozCore
ozExe.depends           =   ozCore			ozGui
ozColor.depends         =   ozCore
ozPhoto.depends         =   ozCore                  ozColor
ozWidgets.depends       = 	ozCore			ozGui
If6Engine.depends       =   ozCore    ozExe ozGui   ozColor ozPhoto	INDIface6	INDIbase6

