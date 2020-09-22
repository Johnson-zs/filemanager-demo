#include "pluginmanager.h"
#include "plugininterface.h"

#include <QDebug>
#include <QDir>
#include <QPluginLoader>

PluginManager::PluginManager(QObject *parent) : QObject(parent)
{

}

bool PluginManager::loadPlugin(const QString &pluginPath)
{
    qDebug() << pluginPath;
    bool ret = true;
    QDir pluginsDir(pluginPath);
    foreach(const QString &fileName, pluginsDir.entryList(QStringList("*.so"), QDir::Files)) {
        QPluginLoader *pluginLoader = new QPluginLoader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader->instance();

        if (plugin) {
            PluginInterface* interface = qobject_cast<PluginInterface*>(plugin);
            if (interface) {
                interface->doAction();
            } else {
                ret = false;
            }
        } else {
            ret = false;
            delete pluginLoader;
        }
    }
    return ret;
}
