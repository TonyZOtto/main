#include "InputModule.h"

#include "EngineSettings.h"

InputModule::InputModule(EngineApplication *parent)
    : EngineModule{Input, parent}
{
    setObjectName("InputModule");

}

void InputModule::initialize()
{
    EngineModule::initialize();
    settings()->flags("FacesProcessed").setFlag(SettingsItem::WriteOnly);
    settings()->flags("FramesProcessed").setFlag(SettingsItem::WriteOnly);
    settings()->flags("Processing").setFlag(SettingsItem::WriteOnly);
    settings()->write(moduleName());
}

Success InputModule::isValid() const
{
    Success success;
    return success;
}

KeyMap InputModule::defaltSettings() const
{
    KeyMap::EntryList tKMEL;
    tKMEL << KeyMap::Entry("DeleteAfter", false);
    tKMEL << KeyMap::Entry("FacesProcessed", 0);        // WO
    tKMEL << KeyMap::Entry("FramesProcessed", 0);       // WO
    tKMEL << KeyMap::Entry("ImageId", "");              // WO?
    tKMEL << KeyMap::Entry("MaxDim", 2048);
    tKMEL << KeyMap::Entry("MaxQueue", 4);
    tKMEL << KeyMap::Entry("Pause", false);
    tKMEL << KeyMap::Entry("Processing", "");           // WO
    tKMEL << KeyMap::Entry("SampleMsec", 0);
    tKMEL << KeyMap::Entry("URL", "");
    return KeyMap(tKMEL);
}
/*
Input/BeginDateTime
Input/
Input/EndDateTime
Input/Junp
Input/Loop
Input/MaxCache
Input/MoveAfter
Input/NewOnly
Input/NullFrames
Input/NumFiles
Input/OrderBy
Input/RestartSecs} = 1
Input/Skip
*/
