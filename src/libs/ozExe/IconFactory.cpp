#include "IconFactory.h"

#include <QFileInfo>

#include <Success.h>

IconFactory::IconFactory(QObject *parent)
    : QObject{parent}
{
    setObjectName("ozExe:IconFactory");
}

void IconFactory::createIcon(const Key &aIconKey, const QQSize aSize)
{
    Q_UNUSED(aIconKey); Q_UNUSED(aSize);
    Q_ASSERT(!"MUSTDO"); // MUSTDO create(key)
}

bool IconFactory::baseDir(const QDir &aBaseDir)
{
    Success success;
    mBaseDir.nullify();
    QQDir tBaseDir = aBaseDir;
    if (tBaseDir.isNull())
    {
        success = false;
    }
    else if (tBaseDir.notExists())
    {
        success.expect(tBaseDir.mkpath("."));
        if (success.test()) success.expect(tBaseDir.cd("."));
        QFileInfo tBaseFI(tBaseDir.toQDir(), "");
        if (success.test()) success.expect(tBaseFI.isWritable());
    }
    if (success)
        mBaseDir = tBaseDir;
    return success;
}
