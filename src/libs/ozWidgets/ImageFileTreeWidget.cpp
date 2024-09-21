#include "ImageFileTreeWidget.h"

#include <QGridLayout>
#include <QLabel>

ImageFileTreeWidget::ImageFileTreeWidget(QWidget *parent)
    : QWidget{parent}
{
    setObjectName("ImageFileTreeWidget");
}

void ImageFileTreeWidget::initialize()
{

}

void ImageFileTreeWidget::configure()
{

}

void ImageFileTreeWidget::setup()
{
    QLabel * pLabel = new QLabel("ImageFileTreeWidget");
    pLabel->setFrameShape(QFrame::Panel);
    QGridLayout * pGridLayout = new QGridLayout();
    pGridLayout->addWidget(pLabel, 0, 0, Qt::AlignCenter | Qt::AlignHCenter);
    setLayout(pGridLayout);
}
