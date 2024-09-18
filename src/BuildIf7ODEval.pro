TEMPLATE = subdirs
 
SUBDIRS +=          \
    ozCore          \
    ozColor         \
    ozImage         \
    ozGui           \
    ozWidgets       \
    If7ODEval       \

ozCore.subdir           = libs/ozCore
ozColor.subdir          = libs/ozColor
ozImage.subdir          = libs/ozImage
ozGui.subdir            = libs/ozGui
ozWidgets.subdir        = libs/ozWidgets
If7ODEval.subdir        = desktop/If7ODEval

ozCore.depends          =
ozColor.depends         =   ozCore
ozImage.depends         =   ozCore          ozColor
ozGui.depends           =   ozCore
ozWidgets.depends       =   ozCore          ozColor ozImage
If7ODEval.depends       =   ozCore    ozGui ozColor ozImage


