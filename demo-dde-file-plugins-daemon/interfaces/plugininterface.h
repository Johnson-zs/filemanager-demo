#ifndef PLUGININTERFACE_H
#define PLUGININTERFACE_H

#include <QtCore>

class PluginInterface
{
public:
    virtual ~PluginInterface() {}
    virtual void doAction() = 0;
};

#define PluginInterface_iid "Examples.Plugin.PluginInterface"

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(PluginInterface, PluginInterface_iid)
QT_END_NAMESPACE

#endif
