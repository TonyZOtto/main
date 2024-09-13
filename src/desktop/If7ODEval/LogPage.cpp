#include "LogPage.h"

#include <QTextDocument>
#include <QTextEdit>

#include "EvalMainWindow.h"

LogPage::LogPage(StackedMainWindow *parent)
    : StackedMainPage("Log", parent)
    , mpTextEdit(new QTextEdit(this))
    , mpTextDocument(new QTextDocument(this))
{
    setObjectName("LogPage");
}

void LogPage::initialize()
{
    qInfo() << Q_FUNC_INFO;
    // TOOD anything?
}

void LogPage::configure()
{
    qInfo() << Q_FUNC_INFO;
    // TOOD anything?
}

void LogPage::setup()
{
    qInfo() << Q_FUNC_INFO;
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

