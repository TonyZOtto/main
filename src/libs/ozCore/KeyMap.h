#ifndef KEYMAP_H
#define KEYMAP_H

#include <QMap>
#include <QVariant>

#include "Key.h"

class KeyMap : public QMap<Key, QVariant>
{
public:
    KeyMap();


};

#endif // KEYMAP_H
