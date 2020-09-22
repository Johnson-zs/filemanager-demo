#include <QCoreApplication>
#include <QDBusConnection>
#include <QDBusConnectionInterface>
#include <QDebug>

#include "pluginmanager.h"
#include "singleapp.hpp"
#include "watchdog.hpp"
#include "plugintestservice.h"

static const QString DaemonServicePath = "com.demo.plugins.daemon";

void regiserDBUS()
{
    QDBusConnection connection = QDBusConnection::sessionBus();
    if (!connection.interface()->isServiceRegistered(DaemonServicePath)) {
        qDebug() << connection.registerService(DaemonServicePath) << "register" << DaemonServicePath;
    }
}


void business()
{
    QEventLoop loop;
    regiserDBUS();
    qDebug() << "child pid" << getpid() << "parent pid is: " << getppid();
    PluginManager manager;
    manager.loadPlugin(qApp->applicationDirPath() + "/../plugins");
    PluginTestService *service = new PluginTestService;
    service->doSomething();
    loop.exec();
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
