 SUBDIRS += \
	desktop/ozSandbox	\
	libs/ozCore \
	libs/ozGui \
	libs/ozWidgets \
	libs/ozExe \
	
ozSandbox.depends 	ozCore	ozGui	ozWidgets	ozExe
ozGui.depends		ozCore
ozWidegets.depends	ozCore
ozExe.depends		ozCore			ozWidgets
	
