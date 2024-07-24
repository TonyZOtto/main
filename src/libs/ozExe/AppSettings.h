#pragma once
#include "ozExe.h"

#include <QObject>

class QSettings;

class OZEXE_EXPORT AppSettings : public QObject
{
    Q_OBJECT
public: // types

public: // ctors
    explicit AppSettings(QObject *parent = nullptr);

public slots:

signals:

public: // const

public: // non-const

public: // pointers

private:
    QSettings * mpSettings=nullptr;
};
