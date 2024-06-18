#pragma once
#include "ozLog.h"

#include <QObject>

class OZLOG_EXPORT Logger : public QObject
{
    Q_OBJECT
public:
    explicit Logger(QObject *parent = nullptr);

signals:
};
