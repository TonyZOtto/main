#pragma once
#include "ozExe.h"

#include <QApplication>
#include <QObject>

class ApplicationHelper;

class OZEXE_EXPORT WidgetApplication : public QApplication
{
    Q_OBJECT
public: // ctors
    WidgetApplication(int &argc, char **argv);

public:
    ApplicationHelper * helper();


private:
    ApplicationHelper * mpHelper=nullptr;
};

inline ApplicationHelper *WidgetApplication::helper() { Q_ASSERT(mpHelper); return mpHelper; }

