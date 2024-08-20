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
    Key d_key;
    QString d_text;
    QString d_title;
    Flags d_flags;
    QString d_toolTip;
    QString d_statisTip;
    QString d_whatsThis;
    QIcon d_icon;
    QSize d_iconSize;
    QFont d_font;
//    AnyColor d_foreColor;
    QColor d_foreColor;
    QColor d_backColor;
    QAction * d_pAction;
    QLabel * d_pLabel;
    QPushButton * d_pPushButton;
    BaseToolButton * d_pToolButton;
    QKeySequence d_shortcut;
    Qt::ToolButtonStyle d_ToolButtonStyle;
    Qt::ArrowType d_arrowType;

public: // ctor
    TriggerItemData()
        : d_flags($null)
        , d_pAction(nullptr)
        , d_pLabel(nullptr)
        , d_pPushButton(nullptr)
        , d_pToolButton(nullptr)
        , d_ToolButtonStyle(Qt::ToolButtonTextBesideIcon)
        , d_arrowType(Qt::NoArrow)
    {;}
};

Q_DECLARE_OPERATORS_FOR_FLAGS(TriggerItemData::Flags)

// QSharedDataPointer functions
TriggerItem::TriggerItem(const Key &aKey)
    : data(new TriggerItemData)
{
    data->d_key = aKey;
}

TriggerItem::TriggerItem() : data(new TriggerItemData) {;}
TriggerItem::TriggerItem(const TriggerItem &rhs) : data{rhs.data} {;}
TriggerItem::~TriggerItem() {;}
TriggerItem &TriggerItem::operator=(const TriggerItem &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

