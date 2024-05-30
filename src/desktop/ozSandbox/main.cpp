#include "SandboxMain.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SandboxMain w;
    w.show();
    return a.exec();
}
