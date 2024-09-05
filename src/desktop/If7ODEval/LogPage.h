#pragma once

#include <StackedMainPage.h>

#include <QString>
class QTextDocument;
class QTextEdit;

#include <QQSize.h>

class EvalMainWindow;

class LogPage : public StackedMainPage
{
    Q_OBJECT
public:
    LogPage(EvalMainWindow *parent);

public slots:
    void setup();
    void addLine(const QString &aString);


public: // pointers
    QTextEdit * textEdit();
    QTextDocument * textDocument();

private:
    QTextEdit * mpTextEdit=nullptr;
    QTextDocument * mpTextDocument=nullptr;
    QString mDocumentStrings;
};

inline QTextEdit *LogPage::textEdit() { Q_ASSERT(mpTextEdit); return mpTextEdit; }
inline QTextDocument *LogPage::textDocument() { Q_ASSERT(mpTextDocument); return mpTextDocument; }
