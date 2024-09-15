#include "Color.h"

Color::Color() {}

QColor Color::complement(const QColor qc)
{
    QColor result(Qt::transparent);
    const QColor::Spec cSpec = qc.spec();
    QColor input = qc.convertTo(QColor::Rgb);
    QColor tNewColor = QColor().convertTo(QColor::Rgb);
    tNewColor.setAlphaF(qc.alphaF());
    tNewColor.setRedF(1.0 - input.redF());
    tNewColor.setGreenF(1.0 - input.greenF());
    tNewColor.setBlueF(1.0 - input.blueF());
    result = tNewColor.convertTo(cSpec);
    return result;
}
