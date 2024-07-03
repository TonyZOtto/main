#pragma once
#include "ozCore.h"

#include <QDir>

#include "Boolean.h"

class OZCORE_EXPORT QQDir : public QDir
{
public:
    QQDir() {;}
    QQDir(const QString &path);
    QQDir(const QDir &other);

public: // const
    bool isNull() const;
    bool notExists() const;
    QDir toQDir() const;


public: // non-const
    void nullify();

private:
    Boolean mNull;
};
