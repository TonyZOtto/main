#pragma once

#include <QObject>

#include <QColor>

#include <QQSize.h>

class ImageGalleryConfig : public QObject
{
    Q_OBJECT
public:
    explicit ImageGalleryConfig(QObject *parent = nullptr);

signals:

    // properties
public:
    QQSize ThumbPixelSize() const;
    void ThumbPixelSize(const QQSize &new_ThumbPixelSize);
    QColor BackColor() const;
    void BackColor(const QColor &new_BackColor);
    QColor BlankColor() const;
    void BlankColor(const QColor &new_BlankColor);
    int ScrollOrientationValue() const;
    void ScrollOrientationValue(int new_ScrollOrientationValue);

    QQSize ViewPixelSize() const;
    void ViewPixelSize(const QQSize &new_ViewPixelSize);

signals:
    void changed_ThumbPixelSize();
    void changed_BackColor();
    void changed_BlankColor();
    void changed_ScrollOrientationValue();

    void changed_ViewPixelSize();

private:
    QQSize      pThumbPixelSize;
    QQSize      pViewPixelSize;
    QColor      pBackColor;
    QColor      pBlankColor;
    int         pScrollOrientationValue;
    Q_PROPERTY(QQSize ThumbPixelSize READ ThumbPixelSize WRITE ThumbPixelSize NOTIFY changed_ThumbPixelSize FINAL)
    Q_PROPERTY(QColor BackColor READ BackColor WRITE BackColor NOTIFY changed_BackColor FINAL)
    Q_PROPERTY(QColor BlankColor READ BlankColor WRITE BlankColor NOTIFY changed_BlankColor FINAL)
    Q_PROPERTY(int ScrollOrientationValue READ ScrollOrientationValue WRITE ScrollOrientationValue NOTIFY changed_ScrollOrientationValue FINAL)
    Q_PROPERTY(QQSize ViewPixelSize READ ViewPixelSize WRITE ViewPixelSize NOTIFY changed_ViewPixelSize FINAL)
};

inline QQSize ImageGalleryConfig::ThumbPixelSize() const
{
    return pThumbPixelSize;
}

inline void ImageGalleryConfig::ThumbPixelSize(const QQSize &new_ThumbPixelSize)
{
    if (pThumbPixelSize == new_ThumbPixelSize)
        return;
    pThumbPixelSize = new_ThumbPixelSize;
    emit changed_ThumbPixelSize();
}

inline QColor ImageGalleryConfig::BackColor() const
{
    return pBackColor;
}

inline void ImageGalleryConfig::BackColor(const QColor &new_BackColor)
{
    if (pBackColor == new_BackColor)
        return;
    pBackColor = new_BackColor;
    emit changed_BackColor();
}

inline QColor ImageGalleryConfig::BlankColor() const
{
    return pBlankColor;
}

inline void ImageGalleryConfig::BlankColor(const QColor &new_BlankColor)
{
    if (pBlankColor == new_BlankColor)
        return;
    pBlankColor = new_BlankColor;
    emit changed_BlankColor();
}

inline int ImageGalleryConfig::ScrollOrientationValue() const
{
    return pScrollOrientationValue;
}

inline void ImageGalleryConfig::ScrollOrientationValue(int new_ScrollOrientationValue)
{
    if (pScrollOrientationValue == new_ScrollOrientationValue)
        return;
    pScrollOrientationValue = new_ScrollOrientationValue;
    emit changed_ScrollOrientationValue();
}

inline QQSize ImageGalleryConfig::ViewPixelSize() const
{
    return pViewPixelSize;
}

inline void ImageGalleryConfig::ViewPixelSize(const QQSize &new_ViewPixelSize)
{
    if (pViewPixelSize == new_ViewPixelSize)
        return;
    pViewPixelSize = new_ViewPixelSize;
    emit changed_ViewPixelSize();
}
