TEMPLATE = subdirs
 
SUBDIRS +=          \
    ozCore          \
    ozExe           \
    ozGui           \
    ozColor         \
    ozPhoto         \
    ozWidgets       \
    If7ODEval       \

ozCore.subdir           = libs/ozCore
ozExe.subdir            = libs/ozExe
ozGui.subdir            = libs/ozGui
ozColor.subdir          = libs/ozColor
ozPhoto.subdir          = libs/ozPhoto
ozWidgets.subdir        = libs/ozWidgets
If7ODEval.subdir        = desktop/If7ODEval

ozCore.depends          =
ozExe.depends           =   ozCore                  ozWidgets
ozGui.depends           =   ozCore
ozColor.depends         =   ozCore
ozPhoto.depends         =   ozCore                              ozColor
ozWidgets.depends       =   ozCore                              ozColor
If7ODEval.depends       =   ozCore    ozExe ozGui               ozColor ozPhoto


