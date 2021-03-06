/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp com.demo.plugins.daemon.xml -p pluginservice_interface
 *
 * qdbusxml2cpp is Copyright (C) 2017 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef PLUGINSERVICE_INTERFACE_H
#define PLUGINSERVICE_INTERFACE_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface com.demo.plugins.daemon.PluginTestService
 */
class ComDemoPluginsDaemonPluginTestServiceInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "com.demo.plugins.daemon.PluginTestService"; }

public:
    ComDemoPluginsDaemonPluginTestServiceInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);

    ~ComDemoPluginsDaemonPluginTestServiceInterface();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> doSomething()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("doSomething"), argumentList);
    }

Q_SIGNALS: // SIGNALS
};

namespace com {
  namespace demo {
    namespace plugins {
      namespace daemon {
        typedef ::ComDemoPluginsDaemonPluginTestServiceInterface PluginTestService;
      }
    }
  }
}
#endif
