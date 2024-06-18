# {Eclipse6}/src/useLog.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/ozLog ../../libs/ozLog ../ozLog
windows:LIBS *= -lozLog2
linux:LIBS *= -lozLog
LIBS *= -L$$DESTDIR
message(--------/src/useLog.pri LIBS=$$LIBS DESTDIR==$$DESTDIR LIBDIR==$$LIBDIR INCLUDEPATH==$$INCLUDEPATH )


