#pragma once

#include "EngineModule.h"

class OutputModule : public EngineModule
{
    Q_OBJECT
public:
    explicit OutputModule(QObject *parent = nullptr);

public slots:
    virtual void initialize();

signals:

public: // const
    virtual Success isValid() const;
    virtual KeyMap defaltSettings() const;


private:

};
