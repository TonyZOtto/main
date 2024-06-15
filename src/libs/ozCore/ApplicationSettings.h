#pragma once
#include "../ozCore.h"

#include <QObject>

class OZCORE_EXPORT ApplicationSettings : public QObject
{
    Q_OBJECT
public:
    explicit ApplicationSettings(QObject *parent = nullptr);

signals:
};
