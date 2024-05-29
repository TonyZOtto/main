#pragma once

#include <QObject>
#include <QToolBar>

class SandboxToolbar : public QToolBar
{
    Q_OBJECT
public:
    explicit SandboxToolbar(QWidget *parent = nullptr);
};
