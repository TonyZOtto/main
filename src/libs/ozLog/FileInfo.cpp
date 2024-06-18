#include "FileInfo.h"

#include <QDir>

FileInfo::FileInfo() {;}
FileInfo::FileInfo(const QString &fpath) : QFileInfo(fpath) {;}

bool FileInfo::isNull() const
{
    return fileName().isEmpty();
}

bool FileInfo::isSuffix(const QString &sfx) const
{
    return suffix().compare(sfx, Qt::CaseInsensitive);
}

QStringList FileInfo::infoStrings(int verbosity) const
{
    QStringList result;
    const QString cPath = path();
    const QDir cDir(cPath);
    if (verbosity < 0) verbosity = 2;

    if (isFile())
        result << QString("File:               %1").arg(fileName());

    if (cDir.isRelative())
        result << QString("Relative Directory: %1").arg(cDir.path());
    if ((verbosity > 1 && cDir.isAbsolute()) || verbosity >= 3)
        result << QString("Absolute Directory: %1").arg(cDir.path());
    if (verbosity > 0)
        result << QString("Flags:              %1").arg(flagString());
    if (verbosity > 1)
        result << QString("NOT Flags:          %1").arg(flagString(false));
    if (verbosity > 0)
        result << QString("Permissions:        %1").arg(permissionsString());
    return result;
}

QString FileInfo::permissionsString() const
{
    QString result;
    return result;
}

QString FileInfo::flagString(const bool isSet) const
{
    QString result;
    QStringList tNames;
    if (isSet == isRelative()) tNames << "Relative";
    if (isSet == isAbsolute()) tNames << "Absolute";
    if (isSet == isDir()) tNames << "Dir";
    if (isSet == isFile()) tNames << "File";
    if (isSet == isExecutable()) tNames << "Executable";
    if (isSet == isHidden()) tNames << "Hidden";
    if (isSet == isNativePath()) tNames << "NativePath";
    if (isSet == isReadable()) tNames << "Readable";
    if (isSet == isWritable()) tNames << "Writable";
    if (isSet == exists()) tNames << "Exists";
    if (isSet == isRoot()) tNames << "Root";
    if (isSet == isSymLink()) tNames << "SymLink";
    if (isSet == isSymbolicLink()) tNames << "SymbolicLink";
    result = tNames.join(' ');
    return result;
}
