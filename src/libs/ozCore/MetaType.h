#pragma once

#include <QMetaType>

class MetaType
{
public: // QMetaType
    MetaType() = default;
    ~MetaType() = default;
    MetaType(const MetaType &) = default;
    MetaType &operator=(const MetaType &) = default;
};

Q_DECLARE_METATYPE(MetaType);
