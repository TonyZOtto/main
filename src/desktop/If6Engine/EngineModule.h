#pragma once

#include <QObject>

#include <QList>

#include <KeyMap.h>
#include <Success.h>

class EngineModule : public QObject
{
    Q_OBJECT
public: // types
    enum Module
    {
        $nullModule = 0,
        Input,
        FaceDetection,
        Output,
        $maxModule
    };
    Q_ENUM(Module)

    typedef QList<EngineModule *> List;

public: // ctors
    explicit EngineModule(const Module aModule, QObject *parent = nullptr);


public slots:
    virtual void initialize();

signals:

public: // const
    Module module() const;
    QString moduleName() const;
    virtual Success isValid() const;

protected: // const
    virtual KeyMap defaltSettings() const;

protected slots:
    void initializeSettings();


private:
    Module mModule=$nullModule;
};

inline EngineModule::Module EngineModule::module() const { return mModule; }

