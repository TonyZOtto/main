#include "DropWidgetView.h"

#include <QDropEvent>
#include <QFileInfo>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMimeData>
#include <QString>
#include <QUrl>

DropWidgetView::DropWidgetView(QWidget *parent)
    : QGraphicsView(parent), mpScene(new QGraphicsScene(this))
{
    Q_ASSERT(mpScene);
    setObjectName("DropWidgetView:QGraphicsView");
    mpScene->setObjectName("DropWidgetView:QGraphicsScene");
    setAcceptDrops(true);
    setScene(mpScene);
    viewport()->installEventFilter(this);
}

void DropWidgetView::dropEvent(QDropEvent * pEvent)
{
    if (pEvent->source() == this) return;

    mDroppedFileInfos.clear();
    mDroppedPixmaps.clear();
    QDropEvent * pDropEvent = static_cast<QDropEvent *>(pEvent);
    if (pDropEvent->mimeData()->hasUrls())
    {
        const QList<QUrl> cUrls = pDropEvent->mimeData()->urls();
        foreach (const QUrl cUrl, cUrls)
        {
            if (cUrl.isValid() && cUrl.isLocalFile())
            {
                const QString cUrlFilePath = cUrl.toLocalFile();
                const QFileInfo cUrlFileInfo = QFileInfo(cUrlFilePath);
                const QPixmap cUrlFilePixmap = QPixmap(cUrlFileInfo.filePath());
                mDroppedFileInfos.append(cUrlFileInfo);
                mDroppedPixmaps.append(cUrlFilePixmap);

                if (mpScene->items().count()) mpScene->clear();
                QGraphicsPixmapItem * pQGPI = new QGraphicsPixmapItem(cUrlFilePixmap);
                mpScene->setSceneRect(cUrlFilePixmap.rect());
                fitInView(cUrlFilePixmap.rect(), Qt::KeepAspectRatioByExpanding);
                mpScene->addItem(pQGPI);
                pDropEvent->acceptProposedAction();
            }
        }
    }
}
