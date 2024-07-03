#pragma once
#include "ozCore.h"

#include <QSize>

class OZCORE_EXPORT QQSize : public QSize
{
public:
    QQSize() {;}
    QQSize(const int aDim) : QSize(aDim, aDim) {;}
    int area() const;

};
