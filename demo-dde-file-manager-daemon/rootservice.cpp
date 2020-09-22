#include "rootservice.h"
#include "rootadaptor.h"

#include <unistd.h>
#include <sys/types.h>

#include <QDebug>
#include <QFile>

QString RootService::kObjectPath = "/com/demo/filemanager/daemon/RootService";

RootService::RootService(QObject *parent) :
    QObject(parent),
    QDBusContext()
{
    if (!QDBusConnection::systemBus().registerObject(kObjectPath, this)) {
        qFatal("Register Object Failed.");
    } else {
        qDebug() << "Register Object Success!";
    }

    m_adaptor = new RootServiceAdaptor(this);
}

bool RootService::createFileInAnyWhere(const QString &filePath)
{
    if (getuid() != 0) {
        qDebug() << "not root user!";
    }

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);
    out << "you are root!";
    file.close();
    return true;
}
