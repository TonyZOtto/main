#pragma once
#include "ozExe.h"

#include <QObject>
#include <QString>
#include <QStringList>

class OZEXE_EXPORT ConsoleStdIO : public QObject
{
    Q_OBJECT
public:
    explicit ConsoleStdIO(QObject *parent = nullptr);

public slots:
    void writeline(const QString &s);
    void writelines(const QStringList &sl, const QString prefix=QString());
    void errorline(const QString &s);

signals:
    void written(const FILE * fh, const QString &s);

private:
};
