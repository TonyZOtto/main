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

void LogPage::setup()
{
    StackedMainPage::setup();
    pageGridLayout()->addWidget(textEdit());
    setLayout(pageGridLayout());
}

void LogPage::addLine(const QString &aString)
{
    mDocumentStrings.append(aString + '\n');
    textDocument()->setPlainText(mDocumentStrings);
    textEdit()->setDocument(textDocument());
}

