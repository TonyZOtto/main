#include "EngineApplication.h"

#include <QTimer>

#include <ApplicationHelper.h>
#include <CommandLine.h>

#include "EngineMainWindow.h"
#include "EngineModule.h"
#include "EngineSettings.h"

EngineApplication::EngineApplication(int &argc, char **argv)
    : WidgetApplication(argc, argv)
    , mpHelper(new ApplicationHelper(this))
    , mpSettings(new EngineSettings(this))
    , mpMainWindow(new EngineMainWindow(this))
{
    setObjectName("EngineApplication:" + applicationName());
    QTimer::singleShot(500, this, &EngineApplication::initialize);
}

void EngineApplication::initialize()
{
    for (int mix = EngineModule::$nullModule;
         mix < EngineModule::$maxModule;
         mix++)
        mModuleList.append(
            new EngineModule(EngineModule::Module(mix), this));
    connect(this, &EngineApplication::initialized,
            mainWindow(), &EngineMainWindow::initialize);
    connect(mainWindow(), &EngineMainWindow::initialized,
            mainWindow(), &EngineMainWindow::setup);
    emit initialized();
}

void EngineApplication::configure()
{
    Q_ASSERT(mpSettings);
    helper()->commandLine()->process();
    const KeyMap cCmdMap = helper()->commandLine()
                               ->settingValues();
    settings()->set(cCmdMap);
    connect(settings(), &EngineSettings::watched,
            this, &EngineApplication::watchedSetting);
    settings()->watch("Input/URL");

}

void EngineApplication::actQuit()
{
    QApplication::exit(1);
}

void EngineApplication::showMainWindow()
{
    mainWindow()->showMaximized();
}

EngineModule *EngineApplication::module(const EngineModule::Module mix)
{
    Q_ASSERT(mix > EngineModule::$nullModule);
    Q_ASSERT(mix < EngineModule::$maxModule);
    Q_ASSERT(mix < mModuleList.count());
    Q_ASSERT(mModuleList[mix]);
    return mModuleList[mix];
}

void EngineApplication::watchedSetting(const Key &aKey, const QVariant &aNewValue, const QVariant &aOldValue)
{
    if (false)
        ;
    else if (aKey == "Input/URL")
        emit urlChanged(aNewValue.toUrl());
    else
        ;
}
