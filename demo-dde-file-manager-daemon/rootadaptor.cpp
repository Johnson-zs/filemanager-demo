/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp com.demo.filemanager.daemon.xml -i rootservice.h -a rootadaptor
 *
 * qdbusxml2cpp is Copyright (C) 2017 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#include "rootadaptor.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

/*
 * Implementation of adaptor class RootServiceAdaptor
 */

RootServiceAdaptor::RootServiceAdaptor(QObject *parent)
    : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

RootServiceAdaptor::~RootServiceAdaptor()
{
    // destructor
}

bool RootServiceAdaptor::createFileInAnyWhere(const QString &filePath)
{
    // handle method call com.demo.filemanager.daemon.RootService.createFileInAnyWhere
    bool out0;
    QMetaObject::invokeMethod(parent(), "createFileInAnyWhere", Q_RETURN_ARG(bool, out0), Q_ARG(QString, filePath));
    return out0;
}

