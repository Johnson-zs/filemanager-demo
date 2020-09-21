#ifndef BLUETOOTHPLUGIN_H
#define BLUETOOTHPLUGIN_H

#include "bluetooth_global.h"
#include "plugininterface.h"

class BLUETOOTHSHARED_EXPORT BluetoothPlugin : public QObject, public PluginInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginInterface)
    Q_PLUGIN_METADATA(IID PluginInterface_iid FILE "bluetoothplugin.json")
public:
    explicit BluetoothPlugin(QObject *parent = nullptr);

    void doAction() override;
};

#endif // BLUETOOTHPLUGIN_H
