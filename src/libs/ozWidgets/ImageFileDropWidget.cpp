#include "ImageFileDropWidget.h"

#include <QGridLayout>
#include <QLabel>

ImageFileDropWidget::ImageFileDropWidget(QWidget *parent)
    : QWidget{parent}
{
    qInfo() << Q_FUNC_INFO;
    setObjectName("ImageFileDropWidget");
}

void ImageFileDropWidget::setup()
{
    qInfo() << Q_FUNC_INFO;
    QLabel * pLabel = new QLabel("Drop Image Files Here");
    QGridLayout * pGridLayout = new QGridLayout();
    pGridLayout->addWidget(pLabel, 0, 0, Qt::AlignCenter | Qt::AlignHCenter);
    setLayout(pGridLayout);
}
