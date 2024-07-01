#pragma once
#include "ozExe.h"

#include <QObject>

class OZEXE_EXPORT ApplicationSettings : public QObject
{
    Q_OBJECT
public:
    explicit ApplicationSettings(QObject *parent = nullptr);

signals:
};
