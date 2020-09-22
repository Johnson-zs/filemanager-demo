#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <QObject>

class PluginManager : public QObject
{
    Q_OBJECT
public:
    explicit PluginManager(QObject *parent = nullptr);

    bool loadPlugin(const QString &pluginPath);
};

#endif // PLUGINMANAGER_H
