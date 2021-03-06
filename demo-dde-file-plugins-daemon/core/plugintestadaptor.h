/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp com.demo.plugins.daemon.xml -i plugintestservice.h -a plugintestadaptor
 *
 * qdbusxml2cpp is Copyright (C) 2017 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#ifndef PLUGINTESTADAPTOR_H
#define PLUGINTESTADAPTOR_H

#include <QtCore/QObject>
#include <QtDBus/QtDBus>
#include "plugintestservice.h"
QT_BEGIN_NAMESPACE
class QByteArray;
template<class T> class QList;
template<class Key, class Value> class QMap;
class QString;
class QStringList;
class QVariant;
QT_END_NAMESPACE

/*
 * Adaptor class for interface com.demo.plugins.daemon.PluginTestService
 */
class PluginTestServiceAdaptor: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.demo.plugins.daemon.PluginTestService")
    Q_CLASSINFO("D-Bus Introspection", ""
"  <interface name=\"com.demo.plugins.daemon.PluginTestService\">\n"
"    <method name=\"doSomething\"/>\n"
"  </interface>\n"
        "")
public:
    PluginTestServiceAdaptor(QObject *parent);
    virtual ~PluginTestServiceAdaptor();

public: // PROPERTIES
public Q_SLOTS: // METHODS
    void doSomething();
Q_SIGNALS: // SIGNALS
};

#endif
