# file: {repo}/src/useOCV4.pri
INCLUDEPATH *= ../../../3P/OpenCV-v4.10.0D/include
    # typical #include's specify opencv2
    # omit D suffix on release
LIBS *= -L../../../3P/OpenCV-v4.10.0D/x64/mingw/bin

LIBS *= -lopencv_core4100d         # if DEBUG
LIBS *= -lopencv_highgui4100d
LIBS *= -lopencv_imageproc4100d
LIBS *= -lopencv_objdetect4100d
