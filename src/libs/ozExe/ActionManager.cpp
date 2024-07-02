#include "ActionManager.h"

#include <QAction>
#include <QCoreApplication>

ActionManager::ActionManager(QObject *parent)
    : QObject{parent}
{
    setObjectName("ActionManager:" + QCoreApplication::applicationName());
}

bool ActionManager::contains(const Key &aKey) const
{
    return mKeyActionDMap.contains(aKey);
}

bool ActionManager::contains(QAction *pAction) const
{
    return mKeyActionDMap.contains(pAction);
}

Key ActionManager::key(QAction *pAction) const
{
    return mKeyActionDMap.at(pAction);
}

QAction *ActionManager::action(const Key &key) const
{
    QAction * result = nullptr;
    if (contains(key))
        result = mKeyActionDMap.at(key);
    Q_CHECK_PTR(result);
    return result;
}

QString ActionManager::string(const Key &key, const TextRoleFlag aTextFlag)
{
    QString result;
    if (contains(key))
    {
        QAction * pAction = action(key);
        switch (aTextFlag)
        {
        case Action:    result = pAction->text();       break;
        case Icon:      result = pAction->iconText();   break;
        case StatusTip: result = pAction->statusTip();  break;
        case ToolTip:   result = pAction->toolTip();    break;
        case WhatsThis: result = pAction->whatsThis();  break;
        case $nullText: default: /* leave blank */      break;
        }
    }
        return result;
}

Boolean ActionManager::boolean(const Key &key, const BoolRoleFlag aBoolFlag)
{
    Boolean result(true, false); // invalid
    if (contains(key))
    {
        QAction * pAction = action(key);
        switch (aBoolFlag)
        {
        case AutoRepeat:        result = pAction->autoRepeat();     break;
        case Checkable:         result = pAction->isCheckable();    break;
        case Checked:           result = pAction->isChecked();      break;
        case Enabled:           result = pAction->isEnabled();      break;
        case MenuVisible:       result = pAction->isIconVisibleInMenu(); break;
        case ContextVisible:    result = pAction->isShortcutVisibleInContextMenu(); break;
        case Visible:           result = pAction->isVisible();      break;
        case Separator:         result = pAction->isSeparator();    break;
        case $nullText: default: /* leave invalid */                break;
        }
    }
    return result;
}

