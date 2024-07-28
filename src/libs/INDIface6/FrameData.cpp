#include "FrameData.h"


FrameData::FrameData(const Key &key, const Id id,
                     const QString desc)
    : Ident(key, id, desc) {;}
FrameData::FrameData(const Uid uid, const Key &key,
                     const Id id, const QString desc)
    : Ident(uid, key, id, desc) {;}

