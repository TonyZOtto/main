# {ottoZcode}/src/useWidgets.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/ozWidgets ../../libs/ozWidgets ../ozWidgets
windows:LIBS *= -lozWidgets6
linux:LIBS *= -lozWidgets
LIBS *= -L$$DESTDIR
message(--------/src/useWidgets.pri LIBS=$$LIBS DESTDIR==$$DESTDIR LIBDIR==$$LIBDIR INCLUDEPATH==$$INCLUDEPATH )


