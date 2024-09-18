#pragma once
#include "ozCore.h"

#include "BaseMainWindow.h"

class QMdiArea;

class OZCORE_EXPORT MdiMainWindow : public BaseMainWindow
{
    Q_OBJECT
public:
    MdiMainWindow(WidgetApplication *wapp = nullptr);

public slots:
    void initialize();

signals:
    void initialized();
    void initializeError(const QString errorString);


private:
    QMdiArea * mpMdiArea=nullptr;
};
