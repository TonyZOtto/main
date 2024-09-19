#pragma once
#include "ozCore.h"

#include <QMainWindow>

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
    void resized(const QQSize newSize);

public: // const
    KeyMap configMap() const;
    QQSize mainSize() const;
    QQSize screenSize(const Index kScreen=0) const;

public: // non-const

public: // pointers
    WidgetApplication * app() const;

protected slots:
    virtual void doResize(const QQSize newSize);

protected:
    virtual void resizeEvent(QResizeEvent * event) override;

private:
    WidgetApplication * mpApp=nullptr;
    KeyMap mConfigMap;
    QQSize mMainSize;
};

inline KeyMap BaseMainWindow::configMap() const { return mConfigMap; }
inline QQSize BaseMainWindow::mainSize() const { return mMainSize; }
inline WidgetApplication *BaseMainWindow::app() const { Q_ASSERT(mpApp); return mpApp; }


