#include <QCoreApplication>
#include <QDebug>

#include "pluginmanager.h"
#include "singleapp.hpp"
#include "watchdog.hpp"

void business()
{
    qDebug() << "child pid" << getpid() << "parent pid is: " << getppid();
    PluginManager manager;
    manager.loadPlugin(qApp->applicationDirPath() + "/../plugins");
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if (SingleApplication::isRunning()) {
        qDebug() << "Process is already running";
        return 1;
    }

    qDebug() << "main pid: " << getpid();
    bool ret = WatchDog::start(business);
    if (!ret) {
        qDebug() << "Init watch dog failed";
        return 1;
    }

    return a.exec();
}
