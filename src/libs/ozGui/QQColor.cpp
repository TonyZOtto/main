#include "QQColor.h"

#include <QtDebug>

QQColor::QQColor() {;}
QQColor::QQColor(int r, int g, int b, int a)  : QColor(r, g, b, a) {;}
QQColor::QQColor(Qt::GlobalColor color)  : QColor(color) {;}

QQColor QQColor::subtracted(const QQColor rhs) const
{
    QQColor result;
    switch (result.spec())
    {
    case Rgb:   result = QQColor(red() - rhs.red(),
                                  green() - rhs.green(),
                                  blue() - rhs.blue(),
                                  alpha());                 break;
    default:    qWarning() << "Unhandled spec()" << spec(); break;
    }
    return result;
}

QQColor QQColor::subtract(const QQColor rhs)
{
    QQColor result = subtracted(rhs);
    *this = result;
    return result;
}
