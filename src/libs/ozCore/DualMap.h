#pragma once
/** @file DualMap.h
*	Declaration of NamedEnum class for DDT core library
*
*	@author	Dynamic DeZigns Technology
*/

#include <QtGlobal>

#include <QMap>
#include <QtDebug>

template <class A, class B> class DualMap
{
public:
    DualMap(void) {}
    void clear(void)
    { mapAtoB.clear(), mapBtoA.clear(); }
    bool isEmpty(void) const
    { return mapAtoB.isEmpty() || mapBtoA.isEmpty(); }
    int size(void) const
    { return qMin(mapAtoB.size(), mapBtoA.size()); }
    bool contains(const A & key) const
    { return mapAtoB.contains(key); }
    bool contains(const B & key) const
    { return mapBtoA.contains(key); }
    B at(const A & key) const
    {	return contains(key) ? mapAtoB.value(key) : B(); }
    A at(const B & key) const
    {	return contains(key) ? mapBtoA.value(key) : A(); }
    QList<A> all(const A & key) const
    {
        (void)key;
        return mapAtoB.keys();
    }
    QList<A> all(const B & key) const
    {
        (void)key;
        return mapBtoA.keys();
    }

    bool remove(const A & key)
    {
        if (contains(key))
        {
            B value = at(key);
            mapAtoB.remove(key);
            if (contains(value))
            {
                mapBtoA.remove(value);
                return true;
            }
        }
        return false;
    } // remove(A)

    bool remove(const B & key)
    {
        if (contains(key))
        {
            A value = at(key);
            mapBtoA.remove(key);
            if (contains(value))
            {
                mapAtoB.remove(value);
                return true;
            }
        }
        return false;
    } // remove(A)

    bool insertUnique(const A & a, const B & b)
    {
        if (contains(a) || contains(b))
            return false;
        mapAtoB.insert(a, b);
        mapBtoA.insert(b, a);
        return true;
    }

private:
    QMap<A,B> mapAtoB;
    QMap<B,A> mapBtoA;
}; // class DualMap
