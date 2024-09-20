#pragma once

#define MUSTDO(msg)     { qFatal() << Q_FUNC_INFO << "MUSTDO:" << msg; }
#define WEXPECT(bexp)   { if ( ! (bexp)) qWarning()  << Q_FUNC_INFO  << #bexp << "failed"; }
#define EXPECT(bexp)    { if ( ! (bexp)) qCritical() << Q_FUNC_INFO  << #bexp << "failed"; }
#define FEXPECT(bexp)   { if ( ! (bexp)) qFatal()    << Q_FUNC_INFO  << #bexp << "failed"; }

class Debug
{
public:
    Debug();
};
