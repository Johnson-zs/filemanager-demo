#include "plugintestservice.h"
#include "plugintestadaptor.h"

#include <QDebug>
#include <QDBusConnection>

QString PluginTestService::kObjectPath = "/com/demo/plugins/daemon/PluginTestService";

PluginTestService::PluginTestService(QObject *parent) :
    QObject(parent),
    QDBusContext()
{
    if (!QDBusConnection::sessionBus().registerObject(kObjectPath, this)) {
        qFatal("Register Object Failed.");
    } else {
        qDebug() << "Register Object Success!";
    }
    m_adaptor = new PluginTestServiceAdaptor(this);
}

void PluginTestService::doSomething()
{
    qDebug() << "doSomething";
}
