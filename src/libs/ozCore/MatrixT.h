#pragma once

#include <QList>

#include "QQPoint.h"
#include "QQSize.h"
#include "Types.h"

template <typename T> class MatrixT
{
public: // ctors
    MatrixT() {;}
    MatrixT(const QQSize sz, const T &fillT=T()) { fill(sz, fillT); }

public: // const
    T get(const QQPoint pt) const { return mTList.at(pt.x(), pt.y()); }
    T get(const int x, const int y) const
    { const Index cix = index(x, y);
        return isValid(cix) ? mTList.value(cix) : T(); }
    QQSize size() const { return mSize; }

public: // non-const
    void set(const QQPoint pt, const T &t)
    { set(pt.x(), pt.y(), t); }
    void set(const int x, const int y, const T &t)
    { const Index cix = index(x, y);
        if (isValid(cix)) mTList[cix] = t; }
    void fill(const QQSize sz, const T &t)
    { mSize = sz; mTList.fill(t, mSize.area()); }

private:
    Count area() const { return mSize.area(); }
    Index index(const int x, const int y) const
    { return x + size().width() * y; }
    Index index(const QQPoint pt) const
    { return index(pt.x(), pt.y()); }
    bool isValid(const Index ix) const
    { return ix >= 0 && ix < area(); }
    bool isValid(const int x, const int y) const
    { const Index ix = index(x, y); return isValid(ix); }
    bool isValid(const QQPoint pt) const
    { return isValid(pt.x(), pt.y()); }

private:
    QQSize mSize;
    QList<T> mTList;
};
