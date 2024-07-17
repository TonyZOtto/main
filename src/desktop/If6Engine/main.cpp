#include "EngineMainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EngineMainWindow w;
    w.show();
    return a.exec();
}
