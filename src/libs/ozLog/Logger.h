#pragma once
#include "../ozCore.h"

#include <QObject>

class OZCORE_EXPORT Logger : public QObject
{
    Q_OBJECT
public:
    explicit Logger(QObject *parent = nullptr);

signals:
};
