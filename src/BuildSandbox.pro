TEMPLATE = subdirs
 
SUBDIRS +=          \
    ozCore          \
    ozExe           \
    ozGui           \
    ozColor         \
    ozImage         \
    ozWidgets       \
    ozSandbox       \

ozCore.subdir           = libs/ozCore
ozExe.subdir            = libs/ozExe
ozGui.subdir            = libs/ozGui
ozColor.subdir          = libs/ozColor
ozImage.subdir          = libs/ozImage
ozWidgets.subdir        = libs/ozWidgets
ozSandbox.subdir        = desktop/ozSandbox

ozCore.depends          =
ozExe.depends           =   ozCore
ozGui.depends           =   ozCore
ozColor.depends         =   ozCore
ozImage.depends         =   ozCore                  ozColor
ozWidgets.depends       = 	ozCore							ozImage
ozSandbox.depends       =   ozCore    ozExe ozGui   ozColor ozImage


