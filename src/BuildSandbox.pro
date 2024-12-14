TEMPLATE = subdirs
 
SUBDIRS +=          \
    ozCore          \
    ozGui           \
    ozColor         \
    ozImage         \
    ozWidgets       \
    ozSandbox       \

ozCore.subdir           = libs/ozCore
ozGui.subdir            = libs/ozGui
ozColor.subdir          = libs/ozColor
ozImage.subdir          = libs/ozImage
ozWidgets.subdir        = libs/ozWidgets
ozSandbox.subdir        = desktop/ozSandbox

ozCore.depends          =
ozGui.depends           =   ozCore
ozColor.depends         =   ozCore
ozImage.depends         =   ozCore            ozColor
ozWidgets.depends       =   ozCore                    ozImage
ozSandbox.depends       =   ozCore    ozGui   ozColor ozImage


