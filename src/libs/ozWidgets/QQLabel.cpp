#include "QQLabel.h"

QQLabel::QQLabel() {;}
QQLabel::QQLabel(const QString &aText) : QLabel(aText) {;}
QQLabel::QQLabel(const QPixmap &aPixmap, const QString &aText) : QLabel(aText) { setPixmap(aPixmap); }

