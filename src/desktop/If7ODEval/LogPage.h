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
    LogPage(StackedMainWindow *parent);

public slots:
    void addLine(const QString &aString);

signals:

public: // const

public: // non-const
    virtual void initialize() override final;
    virtual void configure() override final;
    virtual void setup() override final;

public: // pointers
    QTextEdit * textEdit();
    QTextDocument * textDocument();

protected slots:
    virtual void handleResize(const QQSize newSize) override final;


private:
    QTextEdit * mpTextEdit=nullptr;
    QTextDocument * mpTextDocument=nullptr;
    QString mDocumentStrings;
};

inline QTextEdit *LogPage::textEdit() { Q_ASSERT(mpTextEdit); return mpTextEdit; }
inline QTextDocument *LogPage::textDocument() { Q_ASSERT(mpTextDocument); return mpTextDocument; }
