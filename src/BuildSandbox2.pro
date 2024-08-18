 SUBDIRS += \
	desktop/ozSandbox	\
	libs/ozCore \
	libs/ozGui \
	libs/ozWidegets \
	libs/ozExe \
	
ozSandbox.depends 	ozCore	ozGui	ozWidegets	ozExe
ozGui.depends		ozCore
ozWidegets.depends	ozCore
ozExe.depends		ozCore			ozWidegets
	
