TEMPLATE = subdirs
 
SUBDIRS +=          \
    ozCore          \
    ozExe           \
    ozGui           \
    ozColor         \
    ozPhoto         \
    ozWidgets       \
    ozSandbox       \

ozCore.subdir           = libs/ozCore
ozExe.subdir            = libs/ozExe
ozGui.subdir            = libs/ozGui
ozColor.subdir          = libs/ozColor
ozPhoto.subdir          = libs/ozPhoto
ozWidgets.subdir        = libs/ozWidgets
ozSandbox.subdir        = desktop/ozSandbox

ozCore.depends          =
ozExe.depends           =   ozCore
ozGui.depends           =   ozCore
ozColor.depends         =   ozCore
ozPhoto.depends         =   ozCore                  ozColor
ozWidgets.depends       = # tbd
ozSandbox.depends       =   ozCore    ozExe ozGui   ozColor ozPhoto

