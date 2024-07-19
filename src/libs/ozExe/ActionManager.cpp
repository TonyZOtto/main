#include "ActionManager.h"

#include <QAction>
#include <QCoreApplication>
#include <QMenu>
#include <QToolBar>

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

Key::List ActionManager::keys() const
{
    return mKeyActionDMap.keys();
}

QAction *ActionManager::action(const Key &aKey) const
{
    QAction * result = nullptr;
    if (contains(aKey))
        result = mKeyActionDMap.at(aKey);
    qDebug() << Q_FUNC_INFO << aKey
             << Qt::hex << qptrdiff(result);
    Q_CHECK_PTR(result);
    return result;
}

QString ActionManager::string(const Key &aKey, const TextRoleFlag aTextFlag)
{
    QString result;
    if (contains(aKey))
    {
        QAction * pAction = action(aKey);
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

Boolean ActionManager::boolean(const Key &aKey, const BoolRoleFlag aBoolFlag)
{
    Boolean result(true, false); // invalid
    if (contains(aKey))
    {
        QAction * pAction = action(aKey);
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

QAction *ActionManager::add(const Key &aKey, QString aText)
{
    (void)remove(aKey);
     if (aText.isEmpty())
        aText = "&" + aKey.last();
    QAction * result = new QAction(aText, this);
    result->setEnabled(true);
    add(aKey, result);
    return result;
}

void ActionManager::add(const Key &aKey, QAction *pAction)
{
    pAction->setObjectName("QAction:" + aKey);
    mKeyActionDMap.insertUnique(aKey, pAction);
    qDebug() << Q_FUNC_INFO << aKey
             << Qt::hex << qptrdiff(pAction);
    emit added(aKey, pAction);
    if (mpMenu)
        mpMenu->addAction(pAction);
    if (mpToolbar)
        mpToolbar->addAction(pAction);
}

bool ActionManager::remove(const Key &aKey)
{
    bool result = contains(aKey);
    if (result)
    {
        QAction * pOld = action(aKey);
        qDebug() << Q_FUNC_INFO << aKey
                 << Qt::hex << qptrdiff(pOld);
        emit removed(aKey, pOld);
        mKeyActionDMap.remove(pOld);
        pOld->deleteLater();
    }
    return result;
}

void ActionManager::remove()
{
    foreach (const Key cKey, keys())
        (void)remove(cKey);
}

QAction *ActionManager::action(const Key &aKey) // non-const
{
    qDebug() << Q_FUNC_INFO << aKey << contains(aKey);
    static QAction sDummyAction;
    QAction * result = &sDummyAction;
    if (contains(aKey))
        result = mKeyActionDMap.at(aKey);
    else
        qWarning() << Q_FUNC_INFO << aKey() << "not found";
    Q_CHECK_PTR(result);
    return result;
}

QAction *ActionManager::set(const Key &aKey, const QIcon &aIcon, const QString &aIconText)
{
    QAction * result = action(aKey);
    if (notContains(aKey))
        qWarning() << Q_FUNC_INFO << aKey() << "not found";
    result->setIcon(aIcon);
    result->setIconText(aIconText);
    return result;
}

QAction *ActionManager::set(const Key &aKey, const QString &aText)
{
    QAction * result = action(aKey);
    if (notContains(aKey))
        qWarning() << Q_FUNC_INFO << aKey() << "not found";
    result->setText(aText);
    return result;
}

QAction *ActionManager::set(const Key &aKey, const TextRoleFlag aTextFlag, const QString &aText)
{
    QAction * result = action(aKey);
    if (notContains(aKey))
        qWarning() << Q_FUNC_INFO << aKey() << "not found";
    else
        switch (aTextFlag)
        {
        case Action:    result->setText(aText);         break;
        case Icon:      result->setIconText(aText);     break;
        case StatusTip: result->setStatusTip(aText);    break;
        case ToolTip:   result->setToolTip(aText);      break;
        case WhatsThis: result->setWhatsThis(aText);    break;
        case $nullText: case $endText: /*do nothing*/   break;
        }
    return result;
}

void ActionManager::set(const Key &aKey, const TextRoleFlags aTextFlags, const QString &aText)
{
    for (TextRoleFlag flag = TextRoleFlag(1 + int($nullText));
         flag < $endText;
         flag = TextRoleFlag(1 + int(flag)))
        if (aTextFlags | flag)
            (void)set(aKey, flag, aText);
}

QAction *ActionManager::set(const Key &aKey, const BoolRoleFlag aBoolFlag, const bool aIs)
{
    QAction * result = action(aKey);
    if (notContains(aKey))
        qWarning() << Q_FUNC_INFO << aKey() << "not found";
    else
        switch (aBoolFlag)
        {
        case AutoRepeat:        result->setAutoRepeat(aIs); break;
        case Checkable:         result->setCheckable(aIs);  break;
        case Checked:           result->setChecked(aIs);    break;
        case Enabled:           result->setEnabled(aIs);    break;
        case MenuVisible:       result->setIconVisibleInMenu(aIs);  break;
        case ContextVisible:    result->setShortcutVisibleInContextMenu(aIs);   break;
        case Visible:           result->setVisible(aIs);    break;
        case Separator:         result->setSeparator(aIs);  break;
        case Disabled:         result->setEnabled( ! aIs);  break;
        case $nullBool: case $endBool: /*do nothing*/       break;
        }
    return result;
}

void ActionManager::set(const Key &aKey, const BoolRoleFlags aBoolFlags, const bool aIs)
{
    for (BoolRoleFlag flag = BoolRoleFlag(1 + int($nullBool));
         flag < $endBool;
         flag = BoolRoleFlag(1 + int(flag)))
        if (aBoolFlags | flag)
            (void)set(aKey, flag, aIs);
}

