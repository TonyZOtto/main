#pragma once
#include "ozCore.h"

#include "BaseMainWindow.h"

class QGridLayout;

class OZCORE_EXPORT GridMainWindow : public BaseMainWindow
{
    Q_OBJECT
public:
    GridMainWindow(WidgetApplication *wapp);
    GridMainWindow(QGridLayout * pGrid,
                   WidgetApplication *wapp);
public slots:
    void initialize();

signals:
    void initialized();
    void initializeError(const QString errorString);


private:
    QGridLayout * mpGridLayout=nullptr;
};
