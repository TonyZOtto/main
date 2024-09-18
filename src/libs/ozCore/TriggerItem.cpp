#include "TriggerItem.h"

class TriggerItemData : public QSharedData
{
public: // types
    enum Flag
    {
        $null = 0,
        Checkable       = 0x00000001,
        Visible         = 0x00000002,
        Enabled         = 0x00000004,
        Flat            = 0x00000008,
        IsChecked       = 0x80000000,
        IsDown          = 0x40000000,
        IsFocus         = 0x20000000,
    };
    Q_DECLARE_FLAGS(Flags, Flag)

public: // data
    Key dkey;
    QString dtext;
    QString dtitle;
    Flags dflags;
    QString dtoolTip;
    QString dstatisTip;
    QString dwhatsThis;
    QIcon dicon;
    QSize diconSize;
    QFont dfont;
    QColor dforeColor;
    QColor dbackColor;
    QAction * dpAction;
    QLabel * dpLabel;
    QPushButton * dpPushButton;
    QToolButton * dpToolButton;
    QMenu * dpMenuContains;
    QKeySequence dshortcut;
    Qt::ToolButtonStyle dToolButtonStyle;
    Qt::ArrowType darrowType;

public: // ctor
    TriggerItemData()
        : dflags($null)
        , dpAction(nullptr)
        , dpLabel(nullptr)
        , dpPushButton(nullptr)
        , dpToolButton(nullptr)
        , dToolButtonStyle(Qt::ToolButtonTextBesideIcon)
        , darrowType(Qt::NoArrow)
    {;}
};

Q_DECLARE_OPERATORS_FOR_FLAGS(TriggerItemData::Flags)

// our ctors
TriggerItem::TriggerItem(const Key &aKey, const QString &text)
    : data(new TriggerItemData)
{
    data->dkey = aKey;
    data->dtext = text.isEmpty() ? aKey.last()() : text;
}

// const access
Key TriggerItem::key() const { return data->dkey; }
QString TriggerItem::text() const { return data->dtext; }
QString TriggerItem::title() const { return data->dtitle; }



/*
bool TriggerItem::keyEquals(const TriggerItem &other) const
{
    return key() == other.key();
}

bool TriggerItem::keyLess(const TriggerItem &other) const
{
    return key() < other.key();
}

bool TriggerItem::operator ==(const TriggerItem &other) const
{
    return keyEquals(other);
}

bool TriggerItem::operator <(const TriggerItem &other) const
{
    return keyLess(other);
}
*/

// QSharedDataPointer functions
TriggerItem::TriggerItem() : data(new TriggerItemData) {;}
TriggerItem::TriggerItem(const TriggerItem &rhs) : data{rhs.data} {;}
TriggerItem::~TriggerItem() {;}
TriggerItem &TriggerItem::operator=(const TriggerItem &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

