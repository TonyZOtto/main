TEMPLATE = subdirs
 
SUBDIRS +=          \
    ozCore          \
    ozExe           \
    ozGui           \
    ozWidgets       \
    ozSandbox       \

ozCore.subdir           = libs/ozCore
ozExe.subdir            = libs/ozExe
ozGui.subdir            = libs/ozGui
ozWidgets.subdir        = libs/ozWidgets
ozSandbox.subdir        = desktop/ozSandbox

ozCore.depends          =
ozExe.depends           = ozCore
ozGui.depends           = # tbd
ozWidgets.depends       = # tbd
ozSandbox.depends       = ozCore    ozExe

