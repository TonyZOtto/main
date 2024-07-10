# {ottoZcode}/src/useGui.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/ozGui ../../libs/ozGui ../ozGui
windows:LIBS *= -lozGui2
linux:LIBS *= -lozGui
LIBS *= -L$$DESTDIR
message(--------/src/useGui.pri LIBS=$$LIBS DESTDIR==$$DESTDIR LIBDIR==$$LIBDIR INCLUDEPATH==$$INCLUDEPATH )


