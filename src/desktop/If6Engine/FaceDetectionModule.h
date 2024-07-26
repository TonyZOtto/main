#pragma once

#include "EngineModule.h"

class FaceDetectionModule : public EngineModule
{
    Q_OBJECT
public:
    explicit FaceDetectionModule(QObject *parent = nullptr);

public slots:
    virtual void initialize();

signals:

public: // const
    virtual Success isValid() const;
    virtual KeyMap defaltSettings() const;


private:
};
