#pragma once
#include "ozWidgets.h"

#include <QLabel>

#include <QColor>
#include <QPixmap>
#include <QStackedLayout>
#include <QString>

class OZWIDGETS_EXPORT FillerWidget : public QLabel
{
    Q_OBJECT
public: // ctors
    explicit FillerWidget(QWidget *parent = nullptr);
    FillerWidget(const QString text, QWidget *parent = nullptr);
    FillerWidget(const QString text, const QColor back, QWidget *parent = nullptr);

public slots:

public: // ctors

public: // const

public: // non-const

public: // pointers
    QStackedLayout * stack();

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void resizeEvent(QResizeEvent *event);

protected slots:
    void updatePixmap(const QSize newSize=QSize());

private:
    void ctor();

private:
    QStackedLayout * mpStack=nullptr;

    // properties
public:
    QString text() const;
    void text(const QString &new_text);
    QColor foreColor() const;
    void foreColor(const QColor &new_foreColor);
    QColor backColor() const;
    void backColor(const QColor &new_backColor);
    QPixmap pixmap() const;
signals:
    void changed_text();
    void changed_foreColor();
    void changed_backColor();
private:
    QString mText;
    QColor mForeColor;
    QColor mBackColor;
    QPixmap mPixmap;
    Q_PROPERTY(QString text READ text WRITE text NOTIFY changed_text FINAL)
    Q_PROPERTY(QColor foreColor READ foreColor WRITE foreColor NOTIFY changed_foreColor FINAL)
    Q_PROPERTY(QColor backColor READ backColor WRITE backColor NOTIFY changed_backColor FINAL)
};

inline QStackedLayout *FillerWidget::stack() { Q_ASSERT(mpStack); return mpStack; }

inline QString FillerWidget::text() const
{
    return mText;
}

inline void FillerWidget::text(const QString &new_text)
{
    if (mText == new_text)
        return;
    mText = new_text;
    emit changed_text();
}

inline QColor FillerWidget::foreColor() const
{
    return mForeColor;
}

inline void FillerWidget::foreColor(const QColor &new_foreColor)
{
    if (mForeColor == new_foreColor)
        return;
    mForeColor = new_foreColor;
    emit changed_foreColor();
}

inline QColor FillerWidget::backColor() const
{
    return mBackColor;
}

inline void FillerWidget::backColor(const QColor &new_backColor)
{
    if (mBackColor == new_backColor)
        return;
    mBackColor = new_backColor;
    emit changed_backColor();
}

inline QPixmap FillerWidget::pixmap() const
{
    return mPixmap;
}
