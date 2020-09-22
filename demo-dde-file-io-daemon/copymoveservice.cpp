#include "copymoveservice.h"
#include "copymoveadaptor.h"

#include <QDebug>
#include <QDBusConnection>

QString CopyMoveService::kObjectPath = "/com/demo/io/daemon/CopyMoveService";

CopyMoveService::CopyMoveService(QObject *parent) :
    QObject(parent),
    QDBusContext()
{
    if (!QDBusConnection::sessionBus().registerObject(kObjectPath, this)) {
        qFatal("Register Object Failed.");
    } else {
        qDebug() << "Register Object Success!";
    }

    m_adaptor = new CopyMoveServiceAdaptor(this);
}

void CopyMoveService::Copy(const QString &src, const QString &dest)
{
    qDebug() << "copy " << src << "to" << dest;
}
