#include "FrameData.h"


FrameData::FrameData(const Key &key, const Id id,
                     const QString desc)
    : mIdent(key, id, desc) {;}
FrameData::FrameData(const Uid uid, const Key &key,
                     const Id id, const QString desc)
    : mIdent(uid, key, id, desc) {;}

