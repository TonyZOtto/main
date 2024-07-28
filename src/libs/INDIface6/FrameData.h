#pragma once
#include "INDIface6.h"

#include <QMetaType>

#include <Ident.h>
#include <KeyMap.h>

#include <BasePhoto.h>

#include "INDIframe.h"

class INDIFACE6_EXPORT FrameData
{
public: // ctors
    FrameData(const Key &key, const Id id=0, const QString desc=QString());
    FrameData(const Uid uid, const Key &key, const Id id=0, const QString desc=QString());

public: // const
    Ident ident() const;
    bool contains(const Key &key) const;
    bool contains(const INDIframe::Class &cls) const;
    QVariant get(const Key &key);
    BasePhoto photo(const INDIframe::Class &cls) const;

public: // non-const
    void set(const Key &key, const QVariant &value);
    void photo(const INDIframe::Class &cls, const BasePhoto &photo);

public: // pointers
    Ident & ident();

private:
    Ident mIdent;
    KeyMap mData;
    QMap<INDIframe::Class, BasePhoto> mClassPhotoMap;


public: // QMetaType
    FrameData() = default;
    ~FrameData() = default;
    FrameData(const FrameData &) = default;
    FrameData &operator=(const FrameData &) = default;
};

inline Ident FrameData::ident() const  { return mIdent; }
inline Ident &FrameData::ident() { return mIdent; }

Q_DECLARE_METATYPE(FrameData);
