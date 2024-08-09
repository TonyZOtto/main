# {Eclipse6}/src/DESTDIR.pri
message(========/src/DESTDIR.pri)

OURDEST = "{bindir}/{bldcfg}{osbits}-Qt{qtmajor}{cvmajor}-{ver}"
message(OURDEST = $$OURDEST)
message(VER_STRING = $$VER_STRING)

include(version.pri)
include(BINDIR.pri)
include(BLDCFG.pri)
include(OSBITS.pri)
include(CVMAJOR.pri)

OURDEST = $$replace(OURDEST, "{bindir}", $$BINDIR)
OURDEST = $$replace(OURDEST, "{bldcfg}", $$BLDCFG)
OURDEST = $$replace(OURDEST, "{osbits}", $$OSBITS)
OURDEST = $$replace(OURDEST, "{qtmajor}", $$QT_MAJOR_VERSION)
OURDEST = $$replace(OURDEST, "{cvmajor}", $$CVMAJOR)
OURDEST = $$replace(OURDEST, "{ver}", $$VER_STRING)
message(OURDEST = $$OURDEST)

DESTDIR = $$OURDEST
message(DESTDIR = $$DESTDIR)
