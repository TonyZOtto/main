#pragma once

#include <QObject>

#include <QFlags>
#include <QIcon>
#include <QString>
class QAction;

#include <Boolean.h>
#include <DualMap.h>
#include <Key.h>

class ActionManager : public QObject
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
    };
    Q_DECLARE_FLAGS(BoolRoleFlags, BoolRoleFlag)


public: // ctors
    explicit ActionManager(QObject *parent = nullptr);

public slots:

public: // const
    bool contains(const Key &aKey) const;
    bool contains(QAction * pAction) const;
    Key key(QAction * pAction) const;
    QAction * action(const Key &key) const;
    QString string(const Key &key, const TextRoleFlag aTextFlag);
    Boolean boolean(const Key &key, const BoolRoleFlag aBoolFlag);

public: // non-const
    QAction * add(const Key &key);
    void add(const Key &key, QAction * pAction);
    QAction * action(const Key &key);
    QAction * set(const Key &key, const QString &aText);
    QAction * set(const Key &key, const TextRoleFlag aTextFlag, const QString &aText);
    QAction * set(const Key &key, const TextRoleFlags aTextFlags, const QString &aText);
    QAction * set(const Key &key, const BoolRoleFlag aBoolFlag, const bool is);
    QAction * set(const Key &key, const BoolRoleFlags aBoolFlags, const bool is);
    QAction * set(const Key &key, const QIcon &aIcon, const QString &aIconText=QString());

signals:
    void added(const Key &key, QAction * pAction);
    void removed(const Key &key, QAction * pAction);

private:
    DualMap <Key, QAction *> mKeyActionDMap;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(ActionManager::TextRoleFlags)
Q_DECLARE_OPERATORS_FOR_FLAGS(ActionManager::BoolRoleFlags)

