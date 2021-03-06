/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp com.demo.io.daemon.xml -i copymoveservice.h -a copymoveadaptor
 *
 * qdbusxml2cpp is Copyright (C) 2017 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#ifndef COPYMOVEADAPTOR_H
#define COPYMOVEADAPTOR_H

#include <QtCore/QObject>
#include <QtDBus/QtDBus>
#include "copymoveservice.h"
QT_BEGIN_NAMESPACE
class QByteArray;
template<class T> class QList;
template<class Key, class Value> class QMap;
class QString;
class QStringList;
class QVariant;
QT_END_NAMESPACE

/*
 * Adaptor class for interface com.demo.io.daemon.CopyMoveService
 */
class CopyMoveServiceAdaptor: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.demo.io.daemon.CopyMoveService")
    Q_CLASSINFO("D-Bus Introspection", ""
"  <interface name=\"com.demo.io.daemon.CopyMoveService\">\n"
"    <method name=\"Copy\">\n"
"      <arg direction=\"in\" type=\"s\" name=\"src\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"dest\"/>\n"
"    </method>\n"
"  </interface>\n"
        "")
public:
    CopyMoveServiceAdaptor(QObject *parent);
    virtual ~CopyMoveServiceAdaptor();

public: // PROPERTIES
public Q_SLOTS: // METHODS
    void Copy(const QString &src, const QString &dest);
Q_SIGNALS: // SIGNALS
};

#endif
