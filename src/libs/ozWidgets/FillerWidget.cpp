#include "FillerWidget.h"

#include <QPainter>
#include <QPen>

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
    updatePixmap();
    QWidget::paintEvent(event);
}

void FillerWidget::resizeEvent(QResizeEvent *event)
{
    updatePixmap();
    QWidget::resizeEvent(event);
}

void FillerWidget::updatePixmap(const QSize newSize)
{
    if (newSize.isValid())
        mPixmap = QPixmap(newSize);
    stack()->removeWidget(this);
    QPen tPen(foreColor());
    QPainter tPainter(&mPixmap);
    tPainter.setPen(tPen);
    tPainter.fillRect(mPixmap.rect(), backColor());
    tPainter.drawText(mPixmap.rect(),
                      Qt::AlignCenter | Qt::TextWordWrap,
                      text());
    tPainter.end();
    setPixmap(mPixmap);
    stack()->addWidget(this);
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
    mPixmap.fill(backColor());
    setPixmap(mPixmap);
    setUpdatesEnabled(true);
    update();
}
