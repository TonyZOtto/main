#include "AnyColor.h"

#include <QColor>

AnyColor::AnyColor() : mComponentValueList(Color::$maxComponent) {;}

AnyColor::AnyColor(const QString &aString) { set(aString); }

BYTE AnyColor::byte(const Color::Component cc) const
{
    return 0; // TODO
}

QRgb AnyColor::qrgba32() const
{
    return qRgba(byte(Color::Red), byte(Color::Green),
                 byte(Color::Blue), byte(Color::Opacity));
}

void AnyColor::set(const QString &aString)
{
    const QColor cNamedColor = QColor::fromString(aString);
    if (cNamedColor.isValid())
    {
        set(Color::Opacity, cNamedColor.alphaF());
    }

}

void AnyColor::set(const Color::Component cc, const WORDF wfv)
{
    mComponentValueList.set(cc, wfv);
}
