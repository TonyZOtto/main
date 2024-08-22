#include "LogPage.h"

#include <QTextDocument>
#include <QTextEdit>

#include "EvalMainWindow.h"

LogPage::LogPage(EvalMainWindow *parent)
    : StackedMainPage("Log", parent)
    , mpTextEdit(new QTextEdit(this))
    , mpTextDocument(new QTextDocument(this))
{
    setObjectName("LogPage");
}

void LogPage::setup(const QQSize aMaxSize)
{
    (void)aMaxSize;
    gridLayout()->addWidget(textEdit());
    setLayout(gridLayout());
}

void LogPage::addLine(const QString &aString)
{
    mDocumentStrings.append(aString + '\n');
    textDocument()->setPlainText(mDocumentStrings);
    textEdit()->setDocument(textDocument());
}

