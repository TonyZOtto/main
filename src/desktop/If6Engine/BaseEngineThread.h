#pragma once

#include <QThread>

class BaseEngineThread : public QThread
{
    Q_OBJECT
public:
    explicit BaseEngineThread(QObject *parent = nullptr);
};
