// {ottoZcpde}/src/desktop/If6Engine/version.h Version #define's overrides for INDIface v6 Engine
#pragma once

#define VER_APPNAME         "If6Engine"

#undef VER_ORGNAME
#undef VER_PRODUCT
#undef VER_COPYRIGHT
#undef VER_LEGAL

#ifdef QT_NO_DEBUG
#define VER_ORGNAME         "EclipseIR"
#else
#define VER_ORGNAME         "EclipseRD"
#endif
#define VER_PRODUCT         "INDIface6"
#define VER_COPYRIGHT           "Copyright (c) 2007-2024, Eclipse Identity Recognition Corporation. " \
                            "All rights reserved worldwide. " 
#define VER_LEGAL           "INDIface(tm), IfSearch(tm), EclipseIR(tm), SearchPoint(tm), and MatchPoint(tm) " \
                            "are trademarks of Eclipse Identity Recognition Corporation. " \
                            "See LEGAL.txt for more information."


