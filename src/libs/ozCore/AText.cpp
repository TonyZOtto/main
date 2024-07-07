#include "AText.h"


QString AText::toString() const
{
    return QString(*this);
}

char AText::takeFirstChar()
{
    char result = 0;
    if ( ! isEmpty()) result = *(first(1)).data();
    removeFirst();
    return result;
}

void AText::set(const AText aText)
{
    *this = aText;
}

void AText::setRight(const AText &aText)
{
    const Count cLeft = qMax(count() - aText.count(), 0);
    set(left(cLeft) + aText);
}

void AText::setUpper()
{
    const AText cUpper = toUpper();
    set(cUpper);
}

// static
QStringList AText::toStringList(const List atl)
{
    QStringList result;
    foreach (AText at, atl)
        result << at.toString();
    return result;
}
