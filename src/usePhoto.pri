# {ottoZcode}/src/usePhoto.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/ozPhoto ../../libs/ozPhoto ../ozPhoto
windows:LIBS *= -lozPhoto2
linux:LIBS *= -lozPhoto
LIBS *= -L$$DESTDIR
message(--------/src/usePhoto.pri LIBS=$$LIBS DESTDIR==$$DESTDIR LIBDIR==$$LIBDIR INCLUDEPATH==$$INCLUDEPATH )


