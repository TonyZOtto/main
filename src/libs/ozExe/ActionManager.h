#pragma once
#include "ozExe.h"

#include <QObject>

#include <QFlags>
#include <QIcon>
#include <QString>
class QAction;
class QMenu;
class QToolBar;

#include <Boolean.h>
#include <DualMap.h>
#include <Key.h>

class OZEXE_EXPORT ActionManager : public QObject
{
    Q_OBJECT
public:
    enum TextRoleFlag
    {
        $nullText       = 0,
        Action          = 0x00000001,
        Icon            = 0x00000002,
        StatusTip       = 0x00000004,
        ToolTip         = 0x00000008,
        WhatsThis       = 0x00000010,
        $endText
    };
    Q_DECLARE_FLAGS(TextRoleFlags, TextRoleFlag)

    enum BoolRoleFlag
    {
        $nullBool       = 0,
        AutoRepeat      = 0x00000001,
        Checkable       = 0x00000002,
        Checked         = 0x00000004,
        Enabled         = 0x00000008,
        MenuVisible     = 0x00000010,
        ContextVisible  = 0x00000020,
        Visible         = 0x00000040,
        Separator       = 0x00000080,
        Disabled        = 0x00000100,
        $endBool
    };
    Q_DECLARE_FLAGS(BoolRoleFlags, BoolRoleFlag)


public: // ctors
    explicit ActionManager(QObject *parent = nullptr);

public slots:

public: // const
    bool contains(const Key &aKey) const;
    bool notContains(const Key &aKey) const { return ! contains(aKey); }
    bool contains(QAction * pAction) const;
    Key key(QAction * pAction) const;
    Key::List keys() const;
    QAction * action(const Key &aKey) const;
    QString string(const Key &aKey, const TextRoleFlag aTextFlag);
    Boolean boolean(const Key &aKey, const BoolRoleFlag aBoolFlag);

public: // non-const
    void addTo(QMenu * pMenu);
    void addTo(QToolBar * pToolbar);
    void noAddMenu();
    void noAddToolBar();
    QAction * add(const Key &aKey);
    void add(const Key &aKey, QAction * pAction);
    bool remove(const Key &aKey);
    void remove();
    QAction * action(const Key &aKey);
    QAction * set(const Key &aKey, const QIcon &aIcon, const QString &aIconText=QString());
    QAction * set(const Key &aKey, const QString &aText);
    QAction * set(const Key &aKey, const TextRoleFlag aTextFlag, const QString &aText);
    void set(const Key &aKey, const TextRoleFlags aTextFlags, const QString &aText);
    QAction * set(const Key &key, const BoolRoleFlag aBoolFlag, const bool aIs);
    void set(const Key &aKey, const BoolRoleFlags aBoolFlags, const bool aIs);

signals:
    void added(const Key &aKey, QAction * pAction);
    void removed(const Key &aKey, QAction * pAction);

private:
    DualMap <Key, QAction *> mKeyActionDMap;
    QMenu * mpMenu=nullptr;
    QToolBar * mpToolbar=nullptr;
};

inline void ActionManager::addTo(QMenu *pMenu) { Q_CHECK_PTR(pMenu); mpMenu = pMenu; }
inline void ActionManager::addTo(QToolBar *pToolbar) { Q_CHECK_PTR(pToolbar); mpToolbar = pToolbar; }
inline void ActionManager::noAddMenu() { mpMenu = nullptr; }
inline void ActionManager::noAddToolBar()  { mpToolbar = nullptr; }

Q_DECLARE_OPERATORS_FOR_FLAGS(ActionManager::TextRoleFlags)
Q_DECLARE_OPERATORS_FOR_FLAGS(ActionManager::BoolRoleFlags)

