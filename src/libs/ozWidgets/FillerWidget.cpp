#include "FillerWidget.h"

#include <QPainter>
#include <QPen>
#include <QPaintEvent>
#include <QResizeEvent>

#include <Color.h>

FillerWidget::FillerWidget(QWidget *parent)
    : QLabel{parent}
{
    qInfo() << Q_FUNC_INFO << (parent ? parent->objectName() : "orphan");
    setObjectName("FillerWidget");
    ctor();
}

FillerWidget::FillerWidget(QString text, QWidget *parent)
    : QLabel{parent}
{
    qInfo() << Q_FUNC_INFO << (parent ? parent->objectName() : "orphan");
    setObjectName("FillerWidget: *" + text + "*");
    ctor();
}

FillerWidget::FillerWidget(const QString text, const QColor back, QWidget *parent)
    : QLabel{parent}
    , mBackColor(back)
{
    qInfo() << Q_FUNC_INFO << (parent ? parent->objectName() : "orphan");
    setObjectName("FillerWidget: *" + text + "*");
    ctor();
}

void FillerWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
}

void FillerWidget::resizeEvent(QResizeEvent *event)
{
    qInfo() << Q_FUNC_INFO << event->size() << event->oldSize();
    QWidget::resizeEvent(event);
}

void FillerWidget::updatePixmap(const QSize newSize)
{
    qInfo() << Q_FUNC_INFO << newSize << stack()->count();
    if (mPixmap.size() == newSize)                  return; // /*===*/
    if (newSize.isValid())
        mPixmap = QPixmap(newSize);
//    stack()->removeWidget(this);
    QPen tPen(foreColor());
    QPainter tPainter(&mPixmap);
    tPainter.setPen(tPen);
    tPainter.fillRect(mPixmap.rect(), backColor());
    tPainter.drawText(mPixmap.rect(),
                      Qt::AlignCenter | Qt::TextWordWrap,
                      text());
    tPainter.end();
    setPixmap(mPixmap);
    stack()->insertWidget(0, this);
    qInfo() << Q_FUNC_INFO << "exit" << mPixmap.size() << stack()->count();
}

void FillerWidget::ctor()
{
    mpStack = new QStackedLayout();
    setLayout(stack());
    setUpdatesEnabled(false);
    if ( ! backColor().isValid())
        backColor(QColor("lightskyblue"));
    if ( ! foreColor().isValid())
        foreColor(Color::complement(backColor()));
    mPixmap = QPixmap(size());
    setUpdatesEnabled(true);
    update();
}
