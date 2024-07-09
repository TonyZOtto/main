#pragma once

#include <QByteArray>
#include <QList>
class QImage;

#include "Types.h"

class ByteHistogram
{
public: // types
    typedef QList<Count> CountList;
    typedef QList<BYTE> SampleList;

public: // ctors
    ByteHistogram();

public: // const
    Count sampleCount() const;
    SampleList sampleList() const;
    CountList countList() const;
    Count at(const BYTE aSample) const;
    CountList ktileList(const BYTE aWidth) const;
    SampleList distribution(const Count aCountPerBin) const;
    operator [] (const BYTE aSample) const { return at(aSample); }

public: // non-const
    void add(const BYTE aSample);
    void add(const BYTE *pData, Count nData);
    void add(const QByteArray aSampleList);
    void add(const QImage aIndexedQImage);
    void clear();
    void clearSampleList();

private:
    Count mSampleCount;
    SampleList mSamples;
    CountList mBinCounts;
};
