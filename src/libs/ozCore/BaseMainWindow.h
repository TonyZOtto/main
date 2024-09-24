#pragma once
#include "ozCore.h"

#include <QMainWindow>

#include <QWidget>

#include <KeyMap.h>
#include <QQSize.h>
#include <Types.h>


class WidgetApplication;

class OZCORE_EXPORT BaseMainWindow : public QMainWindow
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
    KeyMap configMap() const;

public: // non-const

public: // pointers
    WidgetApplication * app() const;
    QWidget * centralWidget() const;

protected slots:

protected:

private:
    WidgetApplication * mpApp=nullptr;
    QWidget * mpCentralWidget=nullptr;
    KeyMap mConfigMap;
};

inline KeyMap BaseMainWindow::configMap() const { return mConfigMap; }
inline WidgetApplication *BaseMainWindow::app() const { Q_ASSERT(mpApp); return mpApp; }
inline QWidget *BaseMainWindow::centralWidget() const { Q_ASSERT(mpCentralWidget); return mpCentralWidget; }


