#include "SCRect.h"

SCRect::SCRect() : mSize(-1), mCenter(0, 0) {;}
SCRect::SCRect(const QSize aSize) : mSize(aSize), mCenter(0, 0) {;}
SCRect::SCRect(const QSize aSize, const QPoint aCenter) : mSize(aSize), mCenter(aCenter) {;}


