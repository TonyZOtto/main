#pragma once

#include <QObject>

class IconManager : public QObject
{
    Q_OBJECT
public:
    explicit IconManager(QObject *parent = nullptr);

signals:
};
