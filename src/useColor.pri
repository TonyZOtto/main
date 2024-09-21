# {ottoZcode}/src/useColor.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/ozColor ../../libs/ozColor ../ozColor
windows:LIBS *= -lozColor7
linux:LIBS *= -lozColor
LIBS *= -L$$DESTDIR
#message(--------/src/useColor.pri LIBS=$$LIBS DESTDIR==$$DESTDIR LIBDIR==$$LIBDIR INCLUDEPATH==$$INCLUDEPATH )
