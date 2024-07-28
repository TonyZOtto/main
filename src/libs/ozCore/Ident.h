#pragma once
#include "ozCore.h"

#include <QString>

#include "Key.h"
#include "Types.h"
#include "Uid.h"

class OZCORE_EXPORT Ident
{
    Q_GADGET
public: // ctors
    Ident();
    Ident(const Key k, const Id i=0, const QString d=QString());
    Ident(const Uid u, const Key k, const Id i=0, const QString d=QString());

public: // const
    bool isNull() const;


    // -------------------- Properties ---------------------
private:
    Uid p_uid;
    Key p_key;
    Id p_id;
    QString p_desc;
    Q_PROPERTY(Uid uid READ uid WRITE uid FINAL)
    Q_PROPERTY(Id id READ id WRITE id FINAL)
    Q_PROPERTY(Key key READ key WRITE key FINAL)
    Q_PROPERTY(QString desc READ desc WRITE desc FINAL)
public:
    Uid uid() const;
    void uid(const Uid &new_uid);
    Id id() const;
    void id(Id new_id);
    Key key() const;
    void key(const Key &new_key);
    QString desc() const;
    void desc(const QString &new_desc);
};

inline Uid Ident::uid() const
{
    return p_uid;
}

inline void Ident::uid(const Uid &new_uid)
{
    p_uid = new_uid;
}

inline Id Ident::id() const
{
    return p_id;
}

inline void Ident::id(Id new_id)
{
    p_id = new_id;
}

inline Key Ident::key() const
{
    return p_key;
}

inline void Ident::key(const Key &new_key)
{
    p_key = new_key;
}

inline QString Ident::desc() const
{
    return p_desc;
}

inline void Ident::desc(const QString &new_desc)
{
    p_desc = new_desc;
}

