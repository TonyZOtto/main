#include "ImageFileListWidget.h"

#include <FillerWidget.h>

ImageFileListWidget::ImageFileListWidget(QWidget *parent)
    : QWidget{parent}
{
    setLayout(FillerWidget("ImageFileListWidget", this).stack());
}

void ImageFileListWidget::initialize()
{

}

void ImageFileListWidget::configure()
{

}

void ImageFileListWidget::setup()
{

}
