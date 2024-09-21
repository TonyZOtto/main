# {ottoZcode}/src/useImage.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/ozImage ../../libs/ozImage ../ozImage
windows:LIBS *= -lozImage7
linux:LIBS *= -lozImage
LIBS *= -L$$DESTDIR
#message(--------/src/useImage.pri LIBS=$$LIBS DESTDIR==$$DESTDIR LIBDIR==$$LIBDIR INCLUDEPATH==$$INCLUDEPATH )


