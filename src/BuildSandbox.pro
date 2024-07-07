TEMPLATE = subdirs
 
SUBDIRS =           \
        ozCore      \
        ozExe       \
        ozGui       \
        ozPhoto     \
        ozWidgets   \
        ozSandbox   \

ozCore.subdir       = libs/ozCore
ozExe.subdir        = libs/ozExe
ozGui.subdir        = libs/ozGui
ozPhoto.subdir      = libs/ozPhoto
ozWidgets.subdir    = libs/ozWidgets
ozSandbox.subdir    = desktop/ozSandbox

ozCore.depends      =
ozExe.depends       =   ozCore
ozGui.depends       =
ozPhoto.depends     =
ozWidgets.depends   =
ozSandbox.depends   =   ozCore  ozExe           ozPhoto


