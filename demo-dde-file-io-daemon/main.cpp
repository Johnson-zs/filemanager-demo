#include <QCoreApplication>
#include <QDBusConnection>
#include <QDBusConnectionInterface>
#include <QDebug>

#include "singleapp.hpp"
#include "watchdog.hpp"
#include "copymoveservice.h"

static const QString DaemonServicePath = "com.demo.io.daemon";

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
    CopyMoveService *service = new CopyMoveService;
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
