#pragma once

#include <QObject>

class SandboxScene;

class SandboxEngine : public QObject
{
    Q_OBJECT
public: // ctors
    explicit SandboxEngine(SandboxScene * pScene, QObject *parent = nullptr);

public slots:

signals:

public: // ctors

public: // const

public: // non-const

private slots:

private:

private:
    SandboxScene * mpScene=nullptr;
};
