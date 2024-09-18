#pragma once
#include "ozCore.h"

#include <QMainWindow>

#include <QQSize.h>
#include <Value.h>


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

protected slots:
    virtual void doResize();

signals:
    void initialized();
    void configured();
    void setuped();
    void startupError(const QString errorString);
    void resized(const QQSize newSize);

public: // const
    QQSize mainSize() const;
    QQSize screenSize() const;

public: // non-const
//    QQSize maximizedSize(const bool live=false);

public: // pointers
    WidgetApplication * app() const;

protected:
    virtual void resizeEvent(QResizeEvent * event) override;

private:
    WidgetApplication * mpApp=nullptr;
    QQSize mMainSize;
    static QQSize smScreenSize;
};

inline QQSize BaseMainWindow::mainSize() const { return mMainSize; }
inline WidgetApplication *BaseMainWindow::app() const { Q_ASSERT(mpApp); return mpApp; }


