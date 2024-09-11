#pragma once
#include "ozWidgets.h"

#include <QSharedDataPointer>

#include <KeyMap.h>
#include <QQSize.h>
#include <Types.h>

class ImageGalleryConfigData;
// TODO REDO as Q_GADGET with named translate to KeyMap
class OZWIDGETS_EXPORT ImageGalleryConfig
{
public: // our ctors
    ImageGalleryConfig(const QString &aTitle);
    ImageGalleryConfig(const KeyMap &aMap);
    ImageGalleryConfig(const QQSize thumbSize,
                       const QString &aTitle=QString());
    ImageGalleryConfig(const Index thumbSizeIndex,
                       const QString &aTitle=QString());

public: // const
    QString title() const;
    QQSize cellSize() const;



public: // non-const
    void set(const KeyMap &aMap);
    void set(const Key &aKey, const QVariant &aValue);

private: // non-const
    void calculate();


private: // static
    static QQSize::List smTypicalThumbSizes;

private:
    QQSize mCellSize;

public:  // QSharedDataPointer
    ImageGalleryConfig();
    ImageGalleryConfig(const ImageGalleryConfig &);
    ImageGalleryConfig &operator=(const ImageGalleryConfig &);
    ~ImageGalleryConfig();
private:
    QSharedDataPointer<ImageGalleryConfigData> data;
};

inline QQSize ImageGalleryConfig::cellSize() const { return mCellSize; }
