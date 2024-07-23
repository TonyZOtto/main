#include "QQRect.h"

QQRect::QQRect() {}
QQRect::QQRect(const QQSize aSize) : QRect(QPoint(0,0), aSize) {;}
