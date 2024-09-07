#pragma once
#include "ozExe.h"

#include <QMainWindow>

#include <QQSize.h>
#include <Value.h>


class WidgetApplication;

class OZEXE_EXPORT BaseMainWindow : public QMainWindow
{
    Q_OBJECT
public: // ctor
    explicit BaseMainWindow(WidgetApplication *wapp);

public slots:
    virtual void initialize();
    virtual void configure();
    virtual void setup();

signals:
    void initialized();
    void configured();
    void setuped();
    void startupError(const QString errorString);

public: // const

public: // non-const
    QQSize mainSize(const bool live=false);

public: // pointers
    WidgetApplication * app() const;

private:
    WidgetApplication * mpApp=nullptr;
    QQSize mMainSize;
    Value mMainUnderSizeValue;
};

inline WidgetApplication *BaseMainWindow::app() const { Q_ASSERT(mpApp); return mpApp; }


