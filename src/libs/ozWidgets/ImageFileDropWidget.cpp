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
    const QString cReadFormats = APPH->
}

void ImageFileDropWidget::setup()
{
    qInfo() << Q_FUNC_INFO;
    QLabel * pLabel = new QLabel("Drop Image Files Here");
    QGridLayout * pGridLayout = new QGridLayout();
    pGridLayout->addWidget(pLabel, 0, 0, Qt::AlignCenter | Qt::AlignHCenter);
    setLayout(pGridLayout);
}

SupportedFormats *ImageFileDropWidget::readFormats()
{
    if ( ! mpReadFormats)
    {
        mpReadFormats = new SupportedFormats();
    }
}

void ImageFileDropWidget::dragEnterEvent(QDragEnterEvent *e)
{
    QMimeData * pMData = e->mimeData();
    if (pMData->hasUrls())
        e->acceptProposedAction();
}

void ImageFileDropWidget::dropEvent(QDropEvent *e)
{
    QMimeData * pMData = e->mimeData();
    QList<QUrl> mUrlList = pMData->urls();
    foreach (const cUrl, mUrlList)
    {

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

