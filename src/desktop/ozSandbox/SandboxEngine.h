#pragma once

#include <QObject>

class SandboxScene;

class SandboxEngine : public QObject
{
    Q_OBJECT
public: // ctors
    explicit SandboxEngine(SandboxScene * pScene, QObject *parent = nullptr);


public slots:
    void initialize(void);
    void configure(void) {;}
    void setup(void) {;}
    void objconnect(void) {;}
    void start(void) {;}

signals:
    void initialized(void);
    void configured(void);
    void setuped(void);
    void objconnected(void);
    void started(void);


public: // ctors

public: // const

public: // non-const

private slots:

private:

private:
    SandboxScene * mpScene=nullptr;
};
