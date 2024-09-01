#pragma once
#include "ozWidgets.h"

#include <QGraphicsView>

#include <QFileInfoList>
#include <QList>
#include <QPixmap>

class QDropEvent;
class QGraphicsScene;

class OZWIDGETS_EXPORT DropWidgetView : public QGraphicsView
{
    Q_OBJECT
public:
    DropWidgetView(QWidget *parent = nullptr);

protected:
    void dropEvent(QDropEvent *pEvent);

private:
    QGraphicsScene * mpScene=nullptr;
    QFileInfoList mDroppedFileInfos;
    QList<QPixmap> mDroppedPixmaps;
};
