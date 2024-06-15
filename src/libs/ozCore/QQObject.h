#pragma once

#include <QObject>

class QQObject : public QObject
{
    Q_OBJECT
public:
    explicit QQObject(QObject *parent = nullptr);

signals:
};
