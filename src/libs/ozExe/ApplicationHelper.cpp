#include "ApplicationHelper.h"

#include <QApplication>
#include <QCoreApplication>
#include <QGuiApplication>

#include "CommandLine.h"

ApplicationHelper::ApplicationHelper(QApplication *parent)
    : mpQApplication(parent)
    , mType(App)
{
    setObjectName("ApplicationHelper:QApplication");
}

ApplicationHelper::ApplicationHelper(QCoreApplication *parent)
    : mpQCoreApplication(parent)
    , mType(Core)
{
    setObjectName("ApplicationHelper:QCoreApplication");

}

ApplicationHelper::ApplicationHelper(QGuiApplication *parent)
    : mpQGuiApplication(parent)
    , mType(Gui)
{
    setObjectName("ApplicationHelper:QGuiApplication");

}

QCoreApplication *ApplicationHelper::core()
{
    QCoreApplication * result = nullptr;
    if (nullptr != mpQApplication)
        result = mpQApplication;
    else if (nullptr != mpQCoreApplication)
        result = mpQCoreApplication;
    else if (nullptr != mpQGuiApplication)
        result = mpQGuiApplication;
    // else still nullptr
    Q_CHECK_PTR(result);
    return result;
}

QGuiApplication *ApplicationHelper::gui()
{
    QGuiApplication * result = nullptr;
    if (nullptr != mpQApplication)
        result = mpQApplication;
    else if (nullptr != mpQGuiApplication)
        result = mpQGuiApplication;
    // else still nullptr
    Q_CHECK_PTR(result);
    return result;
}

QApplication *ApplicationHelper::app()
{
    QApplication * result = nullptr;
    if (nullptr != mpQApplication)
        result = mpQApplication;
    // else still nullptr
    Q_CHECK_PTR(result);
    return result;
}

ApplicationHelper::Type ApplicationHelper::type() const
{
    return mType;
}
