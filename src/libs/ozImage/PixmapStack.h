#pragma once

#include <QColor>
#include <QStack>
#include <QPixmap>

#include <BaseImage.h>
#include <QQSize.h>
#include <Types.h>

class PixmapStack
{
public: // types
    enum StackPos { $null = -1, BackColor, BackImage, User };

public:
    PixmapStack();
    PixmapStack(const QQSize aImageSize,
                const Qt::AspectRatioMode aQARM=Qt::IgnoreAspectRatio);

public: // const
    Count count() const;
    Count rawCount() const;
    QQSize imageSize() const;
    Qt::AspectRatioMode qARM() const;
    bool isValid() const;
    bool isEmpty() const;
    bool notEmpty() const { return ! isEmpty(); }
    QColor backColor() const;
    QPixmap back() const;
    QPixmap at(const Index ix) const;
    QPixmap rawAt(const Index ix) const;
    QPixmap operator [] (const Index ix) const { return at(ix); }
    BaseImage at(const Index ix, const Image::Type aType) const;
    QPixmap resolve() const;
    BaseImage resolve(const Image::Type aType) const;

public: // non-const
    void set(const QQSize aImageSize);
    void set(const Qt::AspectRatioMode aQARM);
    void set(const QQSize aImageSize,
             const Qt::AspectRatioMode aQARM);
    void resize(const QQSize aImageSize,
                const Qt::AspectRatioMode aQARM=Qt::IgnoreAspectRatio);
    void back(const QColor aColor);
    void back(const QPixmap aPixmap);
    void back(const BaseImage aPhoto);
    void push(const QColor aColor);
    void push(const QPixmap aPixmap);
    void push(const BaseImage aPhoto);
    QPixmap pop();

private:
    bool isValidIndex(const Index ix) const;


private:
    QQSize mImageSize;
    Qt::AspectRatioMode mQARM=Qt::IgnoreAspectRatio;
    QColor mBackColor;
    QStack<QPixmap> mStack;
};

inline QQSize PixmapStack::imageSize() const { return mImageSize; }
inline Qt::AspectRatioMode PixmapStack::qARM() const { return mQARM; }
inline QColor PixmapStack::backColor() const { return mBackColor; }
inline void PixmapStack::set(const QQSize aImageSize) { mImageSize = aImageSize; }
inline void PixmapStack::set(const Qt::AspectRatioMode aQARM) { mQARM = aQARM; }
