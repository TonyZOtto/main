# {ottoZcode}/src/useExe.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/ozExe ../../libs/ozExe ../ozExe
windows:LIBS *= -lozExe6
linux:LIBS *= -lozExe
LIBS *= -L$$DESTDIR
message(--------/src/useExe.pri LIBS=$$LIBS DESTDIR==$$DESTDIR LIBDIR==$$LIBDIR INCLUDEPATH==$$INCLUDEPATH )


