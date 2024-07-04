#pragma once

#include <QSharedDataPointer>

class SandboxDataData;

class SandboxData
{
public:
    SandboxData();
    SandboxData(const SandboxData &);
    SandboxData &operator=(const SandboxData &);
    ~SandboxData();

private:
    QSharedDataPointer<SandboxDataData> data;
};
