#pragma once

#include <QMainWindow>

class EngineApplication;

class EngineMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    EngineMainWindow(EngineApplication *pApp = nullptr);
    ~EngineMainWindow();

public slots:
    void initialize();

signals:
    void initialized();

public: // const

public: // non-const

public: // pointers
    EngineApplication * application();

private:
    EngineApplication * mpApplication=nullptr;
};

inline EngineApplication *EngineMainWindow::application() { Q_CHECK_PTR(mpApplication); return mpApplication; }
