#pragma once

#include <QString>

#include "OutputLogUrl.h"

class OutputLogUrlList : public OutputLogUrl::List
{
public:
    OutputLogUrlList(const QString &aString);

public: // static
    static QChar hinge();
    static void hinge(const QChar aChar);

private: // static
    static QChar smHinge;
};

inline QChar OutputLogUrlList::hinge()
{
    return smHinge;
}

inline void OutputLogUrlList::hinge(const QChar aChar)
{
    smHinge = aChar;
}
