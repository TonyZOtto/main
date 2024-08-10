#pragma once

#include <QObject>

#include <QList>

#include <KeyMap.h>
#include <Success.h>

class EngineApplication;
class EngineSettings;

class EngineModule : public QObject
{
    Q_OBJECT
public: // types
    enum Module
    {
        $nullModule = 0,
        Input,
        FaceDet,
        Marker,
        Output,
        $maxModule
    };
    Q_ENUM(Module)

    typedef QList<EngineModule *> List;

public: // ctors
    explicit EngineModule(const Module aModule, EngineApplication *parent = nullptr);

public slots:
    virtual void initialize();
    virtual void connections();
    virtual void configure();
    virtual void setup();

signals:

public: // const
    Module module() const;
    QString moduleName() const;
    virtual Success isValid() const;

public: // non-const

public: // pointers
    EngineApplication * application();
    EngineSettings * settings();

protected: // const
    virtual KeyMap defaltSettings() const;



protected slots:
    void initializeSettings();


private:
    EngineApplication * mpApplication=nullptr;
    Module mModule=$nullModule;
};

inline EngineModule::Module EngineModule::module() const { return mModule; }
inline EngineApplication * EngineModule::application() { Q_ASSERT(mpApplication); return mpApplication; }

