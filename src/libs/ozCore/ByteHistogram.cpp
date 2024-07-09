#include "ByteHistogram.h"

#include <QImage>

ByteHistogram::ByteHistogram()
{
    mBinCounts = CountList(256);
}

Count ByteHistogram::at(const BYTE aSample) const
{
    return mBinCounts[aSample];
}

ByteHistogram::SampleList ByteHistogram::distribution(const Count aCountPerBin) const
{
    SampleList result;
    Count tBinCount = 0;
    for (Index ix = 0; ix < 256; ++ix)
    {
        tBinCount += at(ix);
        if (tBinCount > aCountPerBin)
        {
            result.append(ix);
            tBinCount = 0;
        }
    }
    return result;
}

void ByteHistogram::add(const BYTE aSample)
{
    mSamples.append(aSample),
    ++mSampleCount,
    mBinCounts[aSample]++;
}

void ByteHistogram::add(const BYTE *pData, Count nData)
{
    while (nData--) add(*pData++);
}

void ByteHistogram::add(const QImage aIndexedQImage)
{
    if (1 != aIndexedQImage.depth())
        return;
    const Index nData = aIndexedQImage.sizeInBytes();
    if (nData != (aIndexedQImage.height()
                       * aIndexedQImage.bytesPerLine()))
        return;
    const BYTE * pData = aIndexedQImage.constBits();
    add(pData, nData);
}

void ByteHistogram::clear()
{
    mSampleCount = 0;
    clearSampleList();
    mBinCounts.fill(0);
}

void ByteHistogram::clearSampleList()
{
    mSamples.clear();
}
