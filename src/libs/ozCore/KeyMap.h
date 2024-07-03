#include "ozCore.h"

#include <QMap>
#include <QVariant>

#include "Key.h"

class OZCORE_EXPORT KeyMap : public QMap<Key, QVariant>
{
public:
    KeyMap();


};


