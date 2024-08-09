# {Eclipse6}/src/BLDCFG.pri
CONFIG(release, debug|release):BLDCFG = "Rel"
CONFIG(debug,   debug|release):BLDCFG = "Dbg"
message(............/src/BLDCFG.pri = $$BLDCFG)


