#pragma once
#include "ozExe.h"

#include <QMainWindow>

class WidgetApplication;

class OZEXE_EXPORT BaseMainWindow : public QMainWindow
{
    Q_OBJECT
public: // ctor
    explicit BaseMainWindow(WidgetApplication *wapp);

public slots:

signals:

public: // const

public: // non-const

public: // pointers
    WidgetApplication * app() const;

private:
    WidgetApplication * mpApp=nullptr;
};

inline WidgetApplication *BaseMainWindow::app() const { Q_ASSERT(mpApp); return mpApp; }


