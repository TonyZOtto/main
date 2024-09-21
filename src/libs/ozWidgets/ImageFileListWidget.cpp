#include "ImageFileListWidget.h"

#include <QGridLayout>
#include <QLabel>


ImageFileListWidget::ImageFileListWidget(QWidget *parent)
    : QWidget{parent}
{
}

void ImageFileListWidget::initialize()
{

}

void ImageFileListWidget::configure()
{

}

void ImageFileListWidget::setup()
{
    QLabel * pLabel = new QLabel("ImageFileListWidget");
    pLabel->setFrameShape(QFrame::Panel);
    QGridLayout * pGridLayout = new QGridLayout();
    pGridLayout->addWidget(pLabel, 0, 0, Qt::AlignCenter | Qt::AlignHCenter);
    setLayout(pGridLayout);
}
