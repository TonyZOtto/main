#pragma once

#include <QThread>

class BaseEngineTask : public QThread
{
    Q_OBJECT
public:
    BaseEngineTask();
};
