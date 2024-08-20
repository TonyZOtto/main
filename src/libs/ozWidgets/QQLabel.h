#pragma once
#include "ozWidgets.h"

#include <QLabel>

#include <QPixmap>
#include <QString>

class OZWIDGETS_EXPORT QQLabel : public QLabel
{
    Q_OBJECT
public:
    QQLabel();
    QQLabel(const QString &aText);
    QQLabel(const QPixmap &aPixmap, const QString &aText=QString());
};
