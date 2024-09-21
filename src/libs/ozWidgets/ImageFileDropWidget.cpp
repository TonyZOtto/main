#include "ImageFileDropWidget.h"

#include <QDropEvent>
#include <QDragEnterEvent>
#include <QGridLayout>
#include <QLabel>
#include <QMimeData>

#include <ApplicationHelper.h>
#include <SupportedFormats.h>

ImageFileDropWidget::ImageFileDropWidget(QWidget *parent)
    : QWidget{parent}
{
    qInfo() << Q_FUNC_INFO;
    setObjectName("ImageFileDropWidget");
}

void ImageFileDropWidget::initialize()
{
    mpReadFormats = new SupportedFormats(SupportedFormats::Read);
}

void ImageFileDropWidget::configure()
{
    //const QString cReadFormats = APPH->
}

void ImageFileDropWidget::setup()
{
    qInfo() << Q_FUNC_INFO;
    QLabel * pLabel = new QLabel("Drop Image Files Here");
    pLabel->setFrameShape(QFrame::Panel);
    QGridLayout * pGridLayout = new QGridLayout();
    pGridLayout->addWidget(pLabel, 0, 0, Qt::AlignCenter | Qt::AlignHCenter);
    setLayout(pGridLayout);
}

SupportedFormats *ImageFileDropWidget::readFormats()
{
    if ( ! mpReadFormats)
        mpReadFormats = new SupportedFormats(SupportedFormats::Read);
    return mpReadFormats;
}

void ImageFileDropWidget::dragEnterEvent(QDragEnterEvent *e)
{
    const QMimeData * cpMData = e->mimeData();
    if (cpMData->hasUrls())
        e->acceptProposedAction();
}

void ImageFileDropWidget::dropEvent(QDropEvent *e)
{
    const QMimeData * cpMData = e->mimeData();
    QList<QUrl> mUrlList = cpMData->urls();
    foreach (const QUrl cUrl, mUrlList)
    {
        ;
    }
}
#if 0
void MainWindow::dragEnterEvent(QDragEnterEvent *e)
{
     {

    }
}

void MainWindow::dropEvent(QDropEvent *e)
{
    foreach (const QUrl &url, e->mimeData()->urls()) {
        QString fileName = url.toLocalFile();
        ui->listWidget->addItem(fileName);
    }
#endif

